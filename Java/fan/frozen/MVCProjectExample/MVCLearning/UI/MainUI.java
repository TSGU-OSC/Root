package fan.frozen.MVCProjectExample.MVCLearning.UI;


import fan.frozen.MVCProjectExample.MVCLearning.bean.LoginUser;
import fan.frozen.MVCProjectExample.MVCLearning.bean.User;
import fan.frozen.MVCProjectExample.MVCLearning.service.Service;
import fan.frozen.MVCProjectExample.MVCLearning.service.delete.DeleteUserInfoImpl;
import fan.frozen.MVCProjectExample.MVCLearning.service.info.UserInfoGetter;
import fan.frozen.MVCProjectExample.MVCLearning.service.info.UserInfoGetterImpl;
import fan.frozen.MVCProjectExample.MVCLearning.service.login.UserLoginImpl;
import fan.frozen.MVCProjectExample.MVCLearning.service.register.UserRegisterImpl;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;
import fan.frozen.MVCProjectExample.MVCLearning.service.update.UserInfoUpdate;
import fan.frozen.MVCProjectExample.MVCLearning.service.update.UserInfoUpdateImpl;

import java.util.Scanner;
/**
 * 此类属于本项目MVC架构中的view层，及视图层<br>
 * 为了保证单个应用仅有单个视图，且采取视图与当前登录用户信息绑定的操作<br>
 * 本对象采用了单例模式设计<br>
 * 在获取视图对象时请使用 {@link MainUI#getInstance()} 获取对象而非通过 new来构造对象
 */
public class MainUI {
    //视图实例
    private static final MainUI instance = new MainUI();
    //与当前视图绑定的登录对象
    private User currentUser;

    private MainUI(){

    }

    /**
     * 生成用户交互UI
     */
    public void generateUI(){
        OutputHandler.outputInfo("欢迎来到MVC测试",true);
        OutputHandler.outputInfo("输入help可获得相关帮助",true);
        Scanner scanner = new Scanner(System.in);
        String command = "";
        //通过Scanner获取控制台信息以获取相关指令
        while (!command.equals("exit")){
            command = scanner.nextLine();
            analyzeCommand(command);
        }
    }

    /**
     * 用于分析与执行指令
     * @param command 用户输入指令
     */
    public void analyzeCommand(String command){

        switch (command){
            case "login" -> {
                //登录状态检查，若已登录则提醒
                if (currentUser==null){
                    login();
                }else {
                    OutputHandler.outputInfo("您已登录账户 " + currentUser.getAccount()+" ,无需再次登录",true);
                    OutputHandler.outputInfo("如需切换账户请输入 logout 后再次登录其他账户",true);
                }
            }
            case "register" -> register();
            case "modify" -> {
                //默认修改当前登录账号的信息，所以需在修改前判断是否已登录，若无则让用户登录
                //modify操作默认只能修改用户的用户名
                if (currentUser==null){
                    OutputHandler.outputInfo("执行此操作前需要先进行登录",true);
                    login();
                }
                modify();
            }
            //登出操作
            case "logout" -> logout();
            case "info" ->{
                //获取账户信息
                if (currentUser==null){
                    OutputHandler.outputInfo("执行此操作前需要先进行登录",true);
                    login();
                }else {
                    OutputHandler.outputInfo("账号: "+currentUser.getAccount(),true);
                    OutputHandler.outputInfo("用户名: "+currentUser.getUserName(),true);
                }
            }
            case "delete" ->{
                //删除账户
                if (currentUser==null){
                    OutputHandler.outputInfo("执行此操作前需要先进行登录",true);
                    login();
                }else {
                   deleteAccount();
                }
            }
            /*将数据库中所有的账户信息都列举出来
             本功能应搭配与权限管理模块一同使用，一般由管理员及以上权限用户才可使用
             但我们这里只是做一个简单的MVC模块演示，所以并没有编写权限管理模块
             各位有兴趣可以尝试自行添加
            */
            case "list" -> listInfo();
            case "help" -> {
                String info = """
                        
                        -login 登录指令
                        -logout 登出指令
                        -register 注册指令
                        -modify 更改用户名
                        -exit 退出系统
                        -info 获取当前账号信息
                        -delete 删除账号
                        -list 列出已有的所有账号信息
                        """;
                OutputHandler.outputInfo(info,false);
            }
            default -> OutputHandler.outputInfo("未知指令,请使用help获取相关帮助",true);
        }
    }

    /**
     * 基于UI的登录操作
     */
    public void login(){
        //登录采用一个LoginUser对象来接收账号与密码
        LoginUser loginUser = constructLoginUser();
        /*
        User对象仅存储用户数据，及账号与用户名，最终在数据库中的实体关系映射为 用户对象的数据映射与字符串密码隐射成键值对关系
        通过用户账号作为唯一标识符查找账号数据
         */
        State call = call(new UserLoginImpl(loginUser));
        if (call.getResultState()){
            OutputHandler.outputInfo("欢迎回来 "+new UserInfoGetterImpl(loginUser.getAccount()).getUserInfo().getUserName(),true);
            //将登录对象与视图绑定
            currentUser = new UserInfoGetterImpl(loginUser.getAccount()).getUserInfo();
        }else {
            OutputHandler.outputError("登录失败",true);
            OutputHandler.outputError(call.getStateInfo(),true);
        }
    }
    /**
     * 基于UI的注册操作
     */
    public void register(){
        /*
            注册操作与登录流程相似
            由LoginUser对象存储账号密码
            User对象存储账号用户名
         */
        User user = new User();
        LoginUser loginUser = constructLoginUser();
        Scanner scanner = new Scanner(System.in);
        OutputHandler.outputInfo("请输入用户名:",false);
        String username = scanner.nextLine();
        user.setAccount(loginUser.getAccount());
        user.setUserName(username);
        State call = call(new UserRegisterImpl(user, loginUser.getPassword()));
        if (call.getResultState()){
            OutputHandler.outputInfo("账号 "+loginUser.getAccount()+" 用户名 "+username+" 注册成功",true);
        }else {
            OutputHandler.outputError("账号 "+loginUser.getAccount()+" 用户名 "+username+" 注册失败",true);
            OutputHandler.outputError(call.getStateInfo(),true);
        }
    }
    /**
     * 基于UI的用户名修改操作
     */
    public void modify(){
        //获取需要修改的信息
        Scanner scanner = new Scanner(System.in);
        OutputHandler.outputInfo("请输入需要修改的用户名:",false);
        String username = scanner.nextLine();
        //修改当前登录账号信息
        currentUser.setUserName(username);
        //新建Service对象方便后面完成用户数据更新操作
        UserInfoUpdate update = new UserInfoUpdateImpl(currentUser.getAccount(),currentUser);
        State call = call(update);//获取操作状态
        if (call.getResultState()){
            OutputHandler.outputInfo("信息修改成功,已将用户名修改为 "+username,true);
        }else {
            //操作失败则返回失败原因
            OutputHandler.outputError(call.getStateInfo(),true);
        }
    }
    /**
     * 基于UI的登出操作
     */
    public void logout(){
        //登出操作
        if(currentUser==null){
            OutputHandler.outputError("未找到登录信息,请在登录后再使用此指令",true);
        }else {
            OutputHandler.outputInfo("已成功从账户 " + currentUser.getAccount() + " 退出",true);
            currentUser = null;//清空当前视图绑定的对象
        }
    }
    /**
     * 基于UI的删除账户操作
     */
    public void deleteAccount(){
        //默认操作删除当前账户
        OutputHandler.outputInfo("你确定要删除账号 "+ currentUser.getAccount()+" 吗?",true);
        Scanner scanner = new Scanner(System.in);
        //删除账户需要再次输入密码确认，我们这里将其抽象化为一次登录验证操作，再次调用login操作来检测密码是是否正确
        OutputHandler.outputInfo("如果是,请再次输入密码:",false);
        String password = scanner.nextLine();
        LoginUser loginUser = new LoginUser(currentUser.getAccount(),password);
        State loginCall = call(new UserLoginImpl(loginUser));
        if (loginCall.getResultState()) {
            //检查密码正确性
            State deleteCall = call(new DeleteUserInfoImpl(currentUser));
            if (deleteCall.getResultState()) {
                //删除账户(指从数据库中删除相关信息)
                OutputHandler.outputInfo("账号 "+currentUser.getAccount()+" 删除成功",true);
                //登出已删除的账户
                logout();
            }else {
                OutputHandler.outputError(deleteCall.getStateInfo(),true);
            }
        }else {
            OutputHandler.outputError(loginCall.getStateInfo(),true);
        }
    }
    /**
     * 基于UI的列举用户数据操作
     */
    public void listInfo(){
        UserInfoGetter getter = new UserInfoGetterImpl();
        //从Dao数据访问层中获取所有的用户数据并遍历输出
        OutputHandler.outputInfo("账号    用户名",true);
        for (User allUser : getter.getAllUsers()) {
            OutputHandler.outputInfo(allUser.getAccount()+"     "+allUser.getUserName(),true);
        }
    }

    /**
     * 将用户输入信息构造为一个LoginUser对象，用于密码校验
     * @return LoginUser临时对象
     */
    public LoginUser constructLoginUser(){
        Scanner scanner = new Scanner(System.in);
        OutputHandler.outputInfo("请输入账号:",false);
        String account = scanner.nextLine();
        OutputHandler.outputInfo("请输入密码:",false);
        String password = scanner.nextLine();
        return new LoginUser(account,password);
    }

    public State call(Service service){
        //接口抽象化调用
        return service.doService();
    }

    /**
     * 获取UI实例
     * @return UI实例
     */
    public static MainUI getInstance() {
        return instance;
    }
}

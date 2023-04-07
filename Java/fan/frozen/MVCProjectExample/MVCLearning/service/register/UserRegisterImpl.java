package fan.frozen.MVCProjectExample.MVCLearning.service.register;

import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDao;
import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDaoImpl;
import fan.frozen.MVCProjectExample.MVCLearning.bean.User;
import fan.frozen.MVCProjectExample.MVCLearning.service.info.UserInfoGetter;
import fan.frozen.MVCProjectExample.MVCLearning.service.info.UserInfoGetterImpl;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;
/**
  用户信息注册服务实现类
 */
public class UserRegisterImpl implements UserRegister {
    /**
     * 需要注册的用户数据
     */
    private User user;
    /**
     * 账户密码
     */
    private String password;

    public UserRegisterImpl(User user,String password){
        this.user = user;
        this.password = password;
    }

    @Override
    public State register(){
        UserDao userDao = new UserDaoImpl("root","root");
        //检查数据库中是否已有该账号对应信息，若有则返回注册失败
        UserInfoGetter infoGetter = new UserInfoGetterImpl(user.getAccount());
        if (infoGetter.getUserInfo().getUserName()!=null){
            return State.ACCOUNT_ALREADY_EXISTS;
        }
        //调用Dao方法操作数据库
        try {
            userDao.createUserData(user,password);
        }catch (Exception e){
            e.printStackTrace();
            return State.ERROR;
        }
        return State.OPERATION_SUCCESS;
    }

    @Override
    public State doService() {
        return register();
    }
}

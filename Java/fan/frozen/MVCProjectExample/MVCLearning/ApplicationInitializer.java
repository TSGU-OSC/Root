package fan.frozen.MVCProjectExample.MVCLearning;

import fan.frozen.MVCProjectExample.MVCLearning.UI.MainUI;

/**
 * @author thework<br>
 * 演示最基本的MVC架构完成CURD操作<br>
 * 用户登录与信息管理系统<br>
 * 编写环境JDK 18<br>
 * 运行需求JRE 16+<br>
 * 注：本演示项目仅做MVC架构分层处理演示用途，部分功能代码实现不严谨<br>
 */
public class ApplicationInitializer {
    /*
       我们这个项目要做什么
       实现用户数据 存储 修改 删除 查询
       服务上就是 登录 注册 注销 查找 改名
     */
    //程序入口
    public static void main(String[] args) {
        MainUI.getInstance().generateUI();
    }
}

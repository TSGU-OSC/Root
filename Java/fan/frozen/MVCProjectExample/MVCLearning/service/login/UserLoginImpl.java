package fan.frozen.MVCProjectExample.MVCLearning.service.login;

import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDao;
import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDaoImpl;
import fan.frozen.MVCProjectExample.MVCLearning.bean.LoginUser;
import fan.frozen.MVCProjectExample.MVCLearning.bean.User;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

import java.sql.ResultSet;

/**
 * 用户登录服务实现类
 */
public class UserLoginImpl implements UserLogin {
    private LoginUser loginUser;
    public UserLoginImpl(LoginUser loginUser){
        this.loginUser = loginUser;
    }

    @Override
    public State login() {
        UserDao userDao = new UserDaoImpl("root","root");
        User user = new User();
        user.setAccount(loginUser.getAccount());
        boolean flag = false;
        /*
            通过Dao查询相关账号的记录获取密码并进行比对
            一般登录操作为从数据库中查找是否有账号与密码对应的记录
            使用一般的Statement可能会有SQL注入风险
            本演示项目不严谨解决方案为从数据库中查找其密码并于输入进行比对，可以规避一部分SQL注入
            正常最优解应为使用 PreparedStatement 构造预编译SQL语句后在填入相关参数时进行参数合法性检查以规避SQL注入风险
         */
        try {
            String resultSetString = null;
            ResultSet resultSet = userDao.searchUserData(user);
            while (resultSet.next()) {
                resultSetString = resultSet.getString("password");
            }
            flag = loginUser.getPassword().equals(resultSetString);
        }catch (Exception e){
            e.printStackTrace();
        }
        if (flag){
            return State.OPERATION_SUCCESS;
        }else {
            return State.INVALID_ACCOUNT_OR_PASSWORD;
        }
    }

    @Override
    public State doService() {
        return login();
    }
}

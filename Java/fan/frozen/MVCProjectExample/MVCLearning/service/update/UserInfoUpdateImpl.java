package fan.frozen.MVCProjectExample.MVCLearning.service.update;

import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDao;
import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDaoImpl;
import fan.frozen.MVCProjectExample.MVCLearning.bean.User;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

/**
 * 用户信息更新服务实现类
 */
public class UserInfoUpdateImpl implements UserInfoUpdate {
    /**
     * 需要更新数据的账号
     */
    private String account;
    /**
     * 更新后的用户数据
     */
    private User user;

    public UserInfoUpdateImpl(String account, User user) {
        this.account = account;
        this.user = user;
    }

    @Override
    public State updateUserInfo() {
        //调用UserDao与数据库交互
        UserDao userDao = new UserDaoImpl("root","root");
        try {
            userDao.updateUserData(account,user);
        }catch (Exception e){
            e.printStackTrace();
            return State.ERROR;
        }
        return State.OPERATION_SUCCESS;
    }

    @Override
    public State doService() {
        return updateUserInfo();
    }
}

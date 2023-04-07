package fan.frozen.MVCProjectExample.MVCLearning.service.delete;

import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDao;
import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDaoImpl;
import fan.frozen.MVCProjectExample.MVCLearning.bean.User;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

public class DeleteUserInfoImpl implements DeleteUserInfo {
    /**
     * 需要删除的指定账户
     */
    private User user;

    public DeleteUserInfoImpl(User user) {
        this.user = user;
    }

    @Override
    public State deleteUserInfo() {
        UserDao userDao = new UserDaoImpl("root","root");
        try {
            userDao.deleteUserData(user);
        }catch (Exception e){
            e.printStackTrace();
            return State.ERROR;
        }
        return State.OPERATION_SUCCESS;
    }

    @Override
    public State doService() {
        return deleteUserInfo();
    }
}

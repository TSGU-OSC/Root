package fan.frozen.MVCProjectExample.MVCLearning.service.info;

import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDao;
import fan.frozen.MVCProjectExample.MVCLearning.Dao.UserDaoImpl;
import fan.frozen.MVCProjectExample.MVCLearning.bean.User;

import java.sql.ResultSet;
import java.util.ArrayList;

public class UserInfoGetterImpl implements UserInfoGetter {
    /**
     * 获取单个用户信息方法所获取的目标用户对象账号
     */
    private String account = "NAN";

    public UserInfoGetterImpl() {
    }

    /**
     * 决定获取单个用户信息方法所获取的目标用户信息
     * @param account 目标用户账号
     */
    public UserInfoGetterImpl(String account){
        this.account = account;
    }

    @Override
    public User getUserInfo() {
        UserDao userDao = new UserDaoImpl("root","root");
        User user = new User();
        user.setAccount(account);
        try {
            ResultSet resultSet = userDao.searchUserData(user);
            while (resultSet.next()) {
                user.setUserName(resultSet.getString("username"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return user;
    }

    @Override
    public User[] getAllUsers() {
        ArrayList<User> users = new ArrayList<>();
        UserDao userDao = new UserDaoImpl("root","root");
        try {
            ResultSet resultSet = userDao.listAllData();
            while (resultSet.next()){
                User user = new User();
                user.setAccount(resultSet.getString("account"));
                user.setUserName(resultSet.getString("username"));
                users.add(user);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
        return users.toArray(User[]::new);
    }
}

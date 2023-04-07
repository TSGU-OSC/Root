package fan.frozen.MVCProjectExample.MVCLearning.Dao;

import fan.frozen.MVCProjectExample.MVCLearning.bean.User;

import java.sql.ResultSet;

/**
 * 数据访问接口
 */
public interface UserDao {
    /**
     * 向数据库中添加信息
     * @param user 账户信息
     * @param password 账户对应的密码
     * @throws Exception 数据库异常
     */
    void createUserData(User user, String password) throws Exception;

    /**
     * 从数据库中删除指定记录
     * @param user 需要删除记录的对象
     * @throws Exception 数据库异常
     */
    void deleteUserData(User user) throws Exception;

    /**
     * 从数据库中查找相关记录
     * @param user 需要查找记录的对象，一般仅用于获取其账号进行记录查询
     * @return 查询结果
     * @throws Exception 数据库异常
     */
    ResultSet searchUserData(User user) throws Exception;

    /**
     * 更新数据库中已有的记录
     * @param account 需要更新记录的账号
     * @param user 需要填入的新数据
     * @throws Exception 数据库异常
     */
    void updateUserData(String account,User user) throws Exception;

    /**
     * 列出数据库中对应表已有的所有记录
     * @return 数据库对应表中所有的记录
     * @throws Exception 数据库异常
     */
    ResultSet listAllData() throws Exception;
}

package fan.frozen.MVCProjectExample.MVCLearning.Dao;

import fan.frozen.MVCProjectExample.MVCLearning.bean.User;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * 数据访问实现类
 */
public class UserDaoImpl implements UserDao{
    //数据交互对象 然后我们需要通过JDBC -> MySQL 所以我们需要先建立链接
    /**
     * 与数据库的链接对象
     */
    private Connection connection;
    /**
     * 与数据库交互的语句对象
     */
    private Statement statement;

    /**
     * 数据访问对象构造器
     * @param username 目标数据库用户名
     * @param password 目标数据库密码
     */
    public UserDaoImpl(String username,String password){
        String url = "jdbc:mysql://127.0.0.1:3306";
        try {
            //初始化链接
            connection = DriverManager.getConnection(url,username,password);
        }catch (Exception e){
            e.printStackTrace();
        }
        initialize();
    }

    private void initialize(){
        try {
            /*
            我们在这个数据访问对象中将statement作为类的成员对象供我们使用
            我们已知每次使用完statement我们需要释放资源
            那么我们就需要在每次使用statement前都进行一次检查
            保证当前资源未被释放，否则将会抛出异常
             */
            //通过与数据库的链接创建statement
            statement = connection.createStatement();
            //确保使用的数据库为test
            statement.executeUpdate("use test");
            //若userData表不存在则创建
            String sql = """
                    CREATE TABLE IF NOT EXISTS userData(
                    username varchar(20),
                    account varchar(20),
                    password varchar(20)
                    )CHARSET=utf8
                    """;
            statement.executeUpdate(sql);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    @Override
    public void createUserData(User user, String password) throws Exception{
        /*
        每次执行数据库操作之前检查statement是否已被释放
        若已被释放则通过initialize方法重新创建
         */
        if (statement.isClosed()){
            initialize();
        }
        String sql = "insert into userData(username,account,password) values ("+"'"+user.getUserName()+"','"+user.getAccount()+"','"+password+"')";
        statement.executeUpdate(sql);
        statement.close();
    }

    @Override
    public void deleteUserData(User user) throws Exception{
        if (statement.isClosed()){
            initialize();
        }
        String sql = "delete from userData where account = " + "'" + user.getAccount() + "'";
        statement.executeUpdate(sql);
    }

    @Override
    public ResultSet searchUserData(User user) throws Exception {
        if (statement.isClosed()){
            initialize();
        }
        String sql = "select * from userData where account = " + "'" +user.getAccount()+"'";
        return statement.executeQuery(sql);
    }

    @Override
    public void updateUserData(String account,User user) throws Exception{
        if (statement.isClosed()){
            initialize();
        }
        String sql = "update userData set username="+"'"+user.getUserName()+"'"+" where account = "+"'"+account+"'";
        statement.executeUpdate(sql);
    }

    @Override
    public ResultSet listAllData() throws Exception {
        if (statement.isClosed()){
            initialize();
        }
        String sql = "select * from userData";
        return statement.executeQuery(sql);
    }
}

package fan.frozen.MVCProjectExample.MVCLearning.bean;

/**
 * 数据模型对象，主要负责存储用户数据<br>
 * 在MVC分层架构中属于 Model层
 */
public class User {
    private String userName;
    private String account;

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getAccount() {
        return account;
    }

    public void setAccount(String account) {
        this.account = account;
    }
}

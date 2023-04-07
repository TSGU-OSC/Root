package fan.frozen.MVCProjectExample.MVCLearning.bean;

/**
 * 数据模型对象，主要负责登录阶段用户身份验证
 */
public class LoginUser {
    private String account;
    private String password;

    public LoginUser() {

    }

    public LoginUser(String account, String password) {
        this.account = account;
        this.password = password;
    }

    public String getAccount() {
        return account;
    }

    public void setAccount(String account) {
        this.account = account;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}

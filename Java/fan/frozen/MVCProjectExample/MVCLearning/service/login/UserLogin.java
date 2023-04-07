package fan.frozen.MVCProjectExample.MVCLearning.service.login;

import fan.frozen.MVCProjectExample.MVCLearning.service.Service;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

/**
 * 用户登录服务接口
 */
public interface UserLogin extends Service {
    /**
     * 主服务方法，用于检查用户是否登录成功
     * @return 是否登录成功
     */
    State login();
}

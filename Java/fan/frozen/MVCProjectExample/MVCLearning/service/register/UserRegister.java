package fan.frozen.MVCProjectExample.MVCLearning.service.register;

import fan.frozen.MVCProjectExample.MVCLearning.service.Service;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

/**
 * 用户信息注册服务接口
 */
public interface UserRegister extends Service {
    /**
     * 主服务方法，用于注册用户数据
     * @return 账号是否注册成功
     */
    State register();
}

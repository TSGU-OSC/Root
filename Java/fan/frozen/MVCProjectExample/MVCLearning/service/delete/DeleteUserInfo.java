package fan.frozen.MVCProjectExample.MVCLearning.service.delete;

import fan.frozen.MVCProjectExample.MVCLearning.service.Service;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

/**
 * 账户删除服务接口
 */
public interface DeleteUserInfo extends Service {
    /**
     * 主服务方法，用于删除指定账户
     * @return 指定账户是否删除成功
     */
    State deleteUserInfo();
}

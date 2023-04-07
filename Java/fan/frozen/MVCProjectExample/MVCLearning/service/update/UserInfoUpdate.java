package fan.frozen.MVCProjectExample.MVCLearning.service.update;

import fan.frozen.MVCProjectExample.MVCLearning.service.Service;
import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

/**
 * 用户信息更新服务接口
 */
public interface UserInfoUpdate extends Service {
    /**
     * 主服务方法，用于更新用户数据
     * @return 用户数据是否更新成功
     */
    State updateUserInfo();
}

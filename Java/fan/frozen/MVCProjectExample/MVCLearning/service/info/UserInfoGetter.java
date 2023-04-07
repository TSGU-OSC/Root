package fan.frozen.MVCProjectExample.MVCLearning.service.info;

import fan.frozen.MVCProjectExample.MVCLearning.bean.User;

/**
 * 用户信息查询服务接口
 */
public interface UserInfoGetter {
    /**
     * 获取单个用户信息
     * @return 单个用户信息
     */
    User getUserInfo();

    /**
     * 获取全部用户信息
     * @return 全部用户信息
     */
    User[] getAllUsers();
}

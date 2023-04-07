package fan.frozen.MVCProjectExample.MVCLearning.service;

import fan.frozen.MVCProjectExample.MVCLearning.service.state.State;

/**
 * 抽象化服务接口，具有返回状态的服务都应实现此接口<br>
 * 其子接口及其实现类在MVC架构分层中应属于 Controller层
 */
public interface Service {
    State doService();
}

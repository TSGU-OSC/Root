package fan.frozen.MVCProjectExample.MVCLearning.service.state;

/**
 * 服务操作执行结果
 */
public enum State {

    ACCOUNT_ALREADY_EXISTS(){
        @Override
        public boolean getResultState() {
            return false;
        }

        @Override
        public String getStateInfo() {
            return "账号已存在";
        }
    },
    ACCOUNT_NOT_EXISTS(){
        @Override
        public boolean getResultState() {
            return false;
        }

        @Override
        public String getStateInfo() {
            return "账号不存在";
        }
    },
    INVALID_ACCOUNT_OR_PASSWORD(){
        @Override
        public boolean getResultState() {
            return false;
        }

        @Override
        public String getStateInfo() {
            return "无效的账号或密码";
        }
    },
    OPERATION_SUCCESS(){
        @Override
        public boolean getResultState() {
            return true;
        }

        @Override
        public String getStateInfo() {
            return  "操作成功";
        }
    },
    ERROR(){
        @Override
        public boolean getResultState() {
            return false;
        }

        @Override
        public String getStateInfo() {
            return "出现未知错误";
        }
    };

    /**
     * 获取操作是否执行成功
     * @return 操作执行成功与否
     */
    public abstract boolean getResultState();

    /**
     * 获取结果信息
     * @return 结果信息
     */
    public abstract String getStateInfo();
}

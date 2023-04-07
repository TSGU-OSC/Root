package fan.frozen.MVCProjectExample.MVCLearning.UI;

/**
 *输出处理类
 */
public class OutputHandler {
    /**
     * 普通信息统一输出
     * @param info 信息
     * @param lineWrapper 是否换行
     */
    public static void outputInfo(String info,boolean lineWrapper){
        if (lineWrapper){
            System.out.println(">> "+info);
        }else {
            System.out.print(">> "+info);
        }
    }

    /**
     * 错误信息统一输出
     * @param info 错误信息
     * @param lineWrapper 是否换行
     */
    public static void outputError(String info,boolean lineWrapper){
        if (lineWrapper){
            System.err.println("[ERROR]: "+info);
        }else {
            System.err.print("[ERROR]: "+info);
        }
    }
}

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * 3N +１猜想找出关键数
 * 当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

 现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
 * Created by zhuxinquan on 16-4-10.
 */
public class Callatz {

    public static void main(String[] args) {
        List<Integer> list = new LinkedList<Integer>();
        int[] guess = new int[10000];
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        for (int i = 0; i < num; i++) {
            int n = in.nextInt();
            if(guess[n] == 0){
                guess[n] = n;
            }else if(guess[n] > 0){
                continue;
            }

            while(n != 1){

                if (n%2 == 0) {
                    n /= 2;
                    guess[n] = 2 * n;
                }else {
                    n = (3 * n + 1) / 2;
                    guess[n] = (2 * n - 1) / 3;
                }
            }
        }
        int i;
        for (i = 9999; i > 1; i--){
            //直接从大到小进行输出
            if (guess[i] == i) {
                System.out.print(i);
                i--;
                break;
            }
            while(i>1)
            {
                if (guess[i] == i) {
                    System.out.print(" "+i);
                }
                i--;
            }
        }
    }
}
/*from dust i have come, dust i will be*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.print("Case " + i + ": ");

            int x=in.nextInt();
            int y=in.nextInt();

            int sum=5*2+3*3;
            sum+=(Math.abs(x-y)+x)*4;

            System.out.println(sum);
        }

    }
}

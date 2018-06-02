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
            int z=in.nextInt();

            if(x*x+y*y==z*z)
                System.out.println("yes");

            else if(x*x+z*z==y*y)
                System.out.println("yes");

            else if(y*y+z*z==x*x)
                System.out.println("yes");

            else
                System.out.println("no");
        }

    }
}

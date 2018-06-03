/*from dust i have come, dust i will be*/

import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    public static int bTod(String s){
        int k=1,cnt=0;
        for(int i=s.length()-1;i>=0;i--){
            cnt+=(k* ((int) s.charAt(i)-48));
            k*=2;
        }

        return cnt;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.print("Case " + i + ": ");

            String s=in.next();
            StringTokenizer st=new StringTokenizer(s,".");

            ArrayList<String> arr=new ArrayList<>();
            while(st.hasMoreTokens()){
                arr.add(st.nextToken());
            }

            String s2;
            int k=0;
            boolean f=true;

            s=in.next();
            st=new StringTokenizer(s,".");
            while(st.hasMoreTokens()){
                s2=st.nextToken();
                //System.out.println(bTod(s2));
                if(Integer.parseInt(arr.get(k))==bTod(s2)){
                    k++;
                }

                else{
                    f=false;
                    break;
                }
            }

            if(f)
                System.out.println("Yes");
            else
                System.out.println("No");
        }

    }
}

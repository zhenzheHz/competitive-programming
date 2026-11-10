import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int D = (int)Math.pow(b,2)-4*a*c;
        if(D == 0){
            int x = (-b+Math.sqrt(D))/2/a;
            System.out.print("Two same roots x=");
            System.out.println(x);
        }else if(D > 0){
            int r1 = (-b+Math.sqrt(D))/2/a;
            int r2 = (-b-Math.sqrt(D))/2/a;
            System.out.println("Two different roots x1="+r1+" , x2="+r2);
        }else{
            System.out.println("No real root");
        }
        sc.close();
    }
}

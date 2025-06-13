import java.io.*;
import java.util.*;
class Compass {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n1 = sc.nextInt(), n2 = sc.nextInt(), dir = 1;
        if (n1 > n2) {
            int aux = n1;
            n1 = n2;
            n2 = aux;
            dir *= -1;
        }
        int ans = (n2 - n1)%360;
        if (ans > 180) {
            ans = 360 - ans;
            dir *= -1;
        }else if (ans == 180 && dir == -1) {
            dir *= -1;
        }
        System.out.println(ans * dir);
        sc.close();
    }
    public static void main(String[] args) {
        (new Compass())._main();
    }
}

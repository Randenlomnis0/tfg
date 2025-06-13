import java.io.*;
import java.util.*;
class Candlebox {
    private boolean isvalid(int b, int x) {
        int lb = 0, hb = x;
        while (lb != hb - 1) {
            int nb = (lb + hb + 1) / 2;
            if (nb * (nb + 1) / 2 - b * (b + 1) / 2 >= x) {
                hb = nb;
            }else {
                lb = nb;
            }
        }
        return hb * (hb + 1) / 2 - b * (b + 1) / 2 == x;
    }
    private int age(int b, int x) {
        int lb = 0, hb = x;
        while (lb != hb - 1) {
            int nb = (lb + hb + 1) / 2;
            if (nb * (nb + 1) / 2 - b * (b + 1) / 2 >= x) {
                hb = nb;
            }else {
                lb = nb;
            }
        }
        return hb;
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int D = sc.nextInt(), R = sc.nextInt(), T = sc.nextInt();
        for (int i = 0; i < R; ++i) {
            if (isvalid(3, R - i) && isvalid(2, T + i) && Math.abs(age(3, R - i) - age(2, T + i)) == D) {
                System.out.println(i);
                break;
            }
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Candlebox())._main();
    }
}

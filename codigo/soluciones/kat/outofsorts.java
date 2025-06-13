import java.io.*;
import java.util.*;
class Outofsorts {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        long m = sc.nextInt(), a = sc.nextInt(), c = sc.nextInt(), x = sc.nextInt();
        long[] X = new long[n];
        X[0] = (a * x + c)%m;
        for (int i = 1; i < n; ++i) {
            X[i] = (a * X[i - 1] + c)%m;
        }
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int lb = 0, hb = n - 1;
            boolean found = false;
            while (lb <= hb) {
                int nb = (hb + lb) / 2;
                if (X[nb] == X[i]) {
                    found = true;
                    break;
                }else if (X[nb] < X[i]) {
                    lb = nb + 1;
                }else {
                    hb = nb - 1;
                }
            }
            if (found) {
                ++ans;
            }
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Outofsorts())._main();
    }
}

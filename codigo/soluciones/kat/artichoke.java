import java.io.*;
import java.util.*;
import java.lang.Math;
class Artichoke {
    private double f(int p, int a, int b, int c, int d, int k) {
        return p * (Math.sin(a * k + b) + Math.cos(c * k + d) + 2);
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int p = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int n = sc.nextInt();
        double m, ans = 0.0;
        m = f(p, a, b, c, d, 1);
        for (int i = 2; i <= n; ++i) {
            double aux = f(p, a, b, c, d, i);
            ans = Math.max(ans, m - aux);
            m = Math.max(m, aux);
        }
        System.out.printf("%.6f\n", ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Artichoke())._main();
    }
}

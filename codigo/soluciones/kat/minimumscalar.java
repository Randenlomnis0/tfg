import java.io.*;
import java.util.*;
class Minimumscalar {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int T = sc.nextInt();
        for (int tcase = 1; tcase <= T; ++tcase) {
            int n = sc.nextInt();
            long[] x = new long[n], y = new long[n];
            for (int i = 0; i < n; ++i) {
                x[i] = sc.nextInt();
            }
            Arrays.sort(x);
            for (int i = 0; i < n; ++i) {
                y[i] = sc.nextInt();
            }
            Arrays.sort(y);
            long ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += x[i] * y[n - i - 1];
            }
            System.out.println("Case #" + tcase + ": " + ans);
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Minimumscalar())._main();
    }
}

import java.io.*;
import java.util.*;
class Cropeasy {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int T = sc.nextInt();
        for (int tcase = 1; tcase <= T; ++tcase) {
            int n = sc.nextInt();
            long A = sc.nextInt(), B = sc.nextInt(), C = sc.nextInt(), D = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt(), M = sc.nextInt();
            long[] treesx = new long[n], treesy = new long[n];
            for (int i = 0; i < n; ++i) {
                treesx[i] = x;
                treesy[i] = y;
                x = (A * x + B)%M;
                y = (C * y + D)%M;
            }
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        if ((treesx[i] + treesx[j] + treesx[k])%3 != 0 || (treesy[i] + treesy[j] + treesy[k])%3 != 0) continue;
                        ++ans;
                    }
                }
            }
            System.out.println("Case #" + tcase + ": " + ans);
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Cropeasy())._main();
    }
}

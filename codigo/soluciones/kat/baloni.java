import java.io.*;
import java.util.*;
class Baloni {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int N = sc.nextInt();
        int[] H = new int[N];
        int mx = 0;
        for (int i = 0; i < N; ++i) {
            H[i] = sc.nextInt();
            mx = Math.max(mx, H[i]);
        }
        int[] arrow = new int[mx + 1];
        for (int i = 0; i < mx + 1; ++i) {
            arrow[i] = 0;
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (arrow[H[i]] == 0) {
                ++ans;
            }else {
                --arrow[H[i]];
            }
            ++arrow[H[i] - 1];
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Baloni())._main();
    }
}

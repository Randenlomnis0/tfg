import java.io.*;
import java.util.*;
class Birds {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int l = sc.nextInt(), d = sc.nextInt(), n = sc.nextInt();
        int[] birds = new int[n + 2];
        for (int i = 0; i < n; ++i) {
            birds[i] = sc.nextInt();
        }
        birds[n++] = 6 - d;
        birds[n++] = l - 6 + d;
        Arrays.sort(birds);
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += Math.max(0, (birds[i] - birds[i - 1]) / d - 1);
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Birds())._main();
    }
}

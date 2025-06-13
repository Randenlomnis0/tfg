import java.io.*;
import java.util.*;
class Froshweek2 {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt(), m = sc.nextInt();
        int[] tasks = new int[n];
        for (int i = 0; i < n; ++i) {
            tasks[i] = sc.nextInt();
        }
        Arrays.sort(tasks);
        int[] intervals = new int[m];
        for (int i = 0; i < m; ++i) {
            intervals[i] = sc.nextInt();
        }
        Arrays.sort(intervals);
        int ans = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m && intervals[j] < tasks[i]) {
                ++j;
            }
            if (j < m) {
                ++ans;
                ++j;
            }
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Froshweek2())._main();
    }
}

import java.io.*;
import java.util.*;
class Buttonbashing {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int T = sc.nextInt();
        while (T > 0) {
            --T;
            int n = sc.nextInt(), t = sc.nextInt();
            int[] buttons = new int[n];
            for (int i = 0; i < n; ++i) {
                buttons[i] = sc.nextInt();
            }
            int[] ans = new int[3601];
            for (int i = 0; i <= 3600; ++i) {
                ans[i] = -1;
            }
            int aux = 0;
            ArrayList<Integer> q = new ArrayList<>();
            q.add(0);
            q.add(-1);
            while (q.size() > 1) {
                int i = q.get(0);
                q.remove(0);
                if (i == -1) {
                    ++aux;
                    q.add(-1);
                    continue;
                }
                if (ans[i] != -1) continue;
                ans[i] = aux;
                for (int button : buttons) {
                    if (ans[Math.max(0, Math.min(3600, i + button))] != -1) continue;
                    q.add(Math.max(0, Math.min(3600, i + button)));
                }
            }
            aux = t;
            while (ans[aux] == -1) {
                ++aux;
            }
            System.out.println(ans[aux] + " " + (aux - t));
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Buttonbashing())._main();
    }
}

import java.io.*;
import java.util.*;
class Birthday {
    private int dfs(int i, HashSet[] AL, boolean[] visited) {
        visited[i] = true;
        int ans = 1;
        for (Object j : AL[i].toArray()) {
            if (visited[(int)j]) continue;
            ans += dfs((int)j, AL, visited);
        }
        return ans;
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        while (true) {
            int p = sc.nextInt(), c = sc.nextInt();
            if (p == 0 && c == 0) break;
            HashSet<Integer>[] AL = new HashSet[p];
            for (int i = 0; i < p; ++i) {
                AL[i] = new HashSet<>();
            }
            int[][] EL = new int[c][2];
            for (int i = 0; i < c; ++i) {
                EL[i][0] = sc.nextInt();
                EL[i][1] = sc.nextInt();
                AL[EL[i][0]].add(EL[i][1]);
                AL[EL[i][1]].add(EL[i][0]);
            }
            boolean ans = true;
            for (int i = 0; i < c; ++i) {
                AL[EL[i][0]].remove(EL[i][1]);
                AL[EL[i][1]].remove(EL[i][0]);
                boolean[] visited = new boolean[p];
                if (dfs(0, AL, visited) != p) {
                    ans = false;
                    break;
                }
                AL[EL[i][0]].add(EL[i][1]);
                AL[EL[i][1]].add(EL[i][0]);
            }
            System.out.println(ans ? "No" : "Yes");
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Birthday())._main();
    }
}

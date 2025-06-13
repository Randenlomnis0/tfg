import java.io.*;
import java.util.*;
class Tenkindsofpeople {
    private void dfs(int i, int j, char[][] m, int[][] ids, int r, int c, int id) {
    Deque<int[]> stack = new ArrayDeque<>();
    stack.push(new int[]{i, j});
    ids[i][j] = id;
    while (!stack.isEmpty()) {
        int[] cur = stack.pop();
        i = cur[0];
        j = cur[1];
        for (int d = -1; d <= 1; d += 2) {
            int ni = i + d, nj = j;
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && m[ni][nj] == m[i][j] && ids[ni][nj] == 0) {
                ids[ni][nj] = id;
                stack.push(new int[]{ni, nj});
            }
            ni = i;
            nj = j + d;
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && m[ni][nj] == m[i][j] && ids[ni][nj] == 0) {
                ids[ni][nj] = id;
                stack.push(new int[]{ni, nj});
            }
        }
    }
}
    private void _main() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
        char[][] m = new char[r][c];
        for (int i = 0; i < r; ++i) {
            String s = br.readLine();
            for (int j = 0; j < c; ++j) {
                m[i][j] = s.charAt(j);
            }
        }
        int[][] ids = new int[r][c];
        int id = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (ids[i][j] != 0) continue;
                dfs(i, j, m, ids, r, c, ++id);
            }
        }
        int n = Integer.parseInt(br.readLine());
        StringBuilder out = new StringBuilder();
        while (n > 0) {
            --n;
            st = new StringTokenizer(br.readLine());
            int r1 = Integer.parseInt(st.nextToken()), c1 = Integer.parseInt(st.nextToken()), r2 = Integer.parseInt(st.nextToken()), c2 = Integer.parseInt(st.nextToken());
            --r1;
            --c1;
            --r2;
            --c2;
            if (ids[r1][c1] == ids[r2][c2]) {
                out.append(m[r1][c1] == '0' ? "binary" : "decimal");
            }else {
                out.append("neither");
            }
            out.append("\n");
        }
        bw.write(out.toString());
        bw.flush();
        bw.close();
    }
    public static void main(String[] args) throws IOException {
        (new Tenkindsofpeople())._main();
    }
}

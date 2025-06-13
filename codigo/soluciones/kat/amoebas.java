import java.io.*;
import java.util.*;
class Amoebas {
    private void dfs(int i, int j, char[][] image, int m, int n) {
        image[i][j] = '.';
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (i + di < 0 || i + di >= m || j + dj < 0 || j + dj >= n || image[i + di][j + dj] == '.') continue;
                dfs(i + di, j + dj, image, m, n);
            }
        }
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int m = sc.nextInt(), n = sc.nextInt();
        sc.nextLine();
        char[][] image = new char[m][n];
        for (int i = 0; i < m; ++i) {
            String s = sc.nextLine();
            for (int j = 0; j < n; ++j) {
                image[i][j] = s.charAt(j);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (image[i][j] == '.') continue;
                ++ans;
                dfs(i, j, image, m, n);
            }
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Amoebas())._main();
    }
}

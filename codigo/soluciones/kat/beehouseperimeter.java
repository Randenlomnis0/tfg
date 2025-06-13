import java.io.*;
import java.util.*;
class Beehouseperimeter {
    private int ffill(int[][] grid, int i, int j, int N) {
        grid[i][j] = -1;
        int ans = 0;
        for (int d = -1; d <= 1; d += 2) {
            if (i + d >= 0 && i + d < N) {
                if (grid[i + d][j] == 0) {
                    ans += ffill(grid, i + d, j, N);
                }else if (grid[i + d][j] == 1) {
                    ++ans;
                }
            }
            if (j + d >= 0 && j + d < N) {
                if (grid[i][j + d] == 0) {
                    ans += ffill(grid, i, j + d, N);
                }else if (grid[i][j + d] == 1) {
                    ++ans;
                }
            }
            if (i + d >= 0 && i + d < N && j + d >= 0 && j + d < N) {
                if (grid[i + d][j + d] == 0) {
                    ans += ffill(grid, i + d, j + d, N);
                }else if (grid[i + d][j + d] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int R = sc.nextInt(), K = sc.nextInt();
        int[][] grid = new int[2 * R + 1][2 * R + 1];
        for (int i = 0; i < 2 * R + 1; ++i) {
            for (int j = 0; j < 2 * R + 1; ++j) {
                grid[i][j] = 0;
            }
        }
        HashMap<Integer, Integer> posi = new HashMap<>(), posj = new HashMap<>();
        int aux = 1;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < R + i; ++j) {
                posi.put(aux, i + 1);
                posj.put(aux, j + 1);
                ++aux;
            }
        }
        for (int i = R; i < 2 * R - 1; ++i) {
            for (int j = i - R + 1; j < 2 * R - 1; ++j) {
                posi.put(aux, i + 1);
                posj.put(aux, j + 1);
                ++aux;
            }
        }
        while (K > 0) {
            --K;
            int idx = sc.nextInt();
            grid[posi.get(idx)][posj.get(idx)] = 1;
        }
        System.out.println(ffill(grid, 0, 0, 2 * R + 1));
        sc.close();
    }
    public static void main(String[] args) {
        (new Beehouseperimeter())._main();
    }
}

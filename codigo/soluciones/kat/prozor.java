import java.io.*;
import java.util.*;
class Prozor {
    private int calc(int[][] flies, int i, int j, int K) {
        return flies[i][j] - flies[i - K][j] - flies[i][j - K] + flies[i - K][j - K];
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int R = sc.nextInt(), S = sc.nextInt(), K = sc.nextInt();
        char[][] picture = new char[R][S];
        int[][] flies = new int[R][S];
        sc.nextLine();
        for (int i = 0; i < R; ++i) {
            String line = sc.nextLine();
            for (int j = 0; j < S; ++j) {
                picture[i][j] = line.charAt(j);
                if (i > 0) flies[i][j] += flies[i - 1][j];
                if (j > 0) flies[i][j] += flies[i][j - 1];
                if (i > 0 && j > 0) flies[i][j] -= flies[i - 1][j - 1];
                if (picture[i][j] == '*') ++flies[i][j];
            }
        }
        int ans = -1, ansi = -1, ansj = -1;
        for (int i = K - 1; i < R; ++i) {
            for (int j = K - 1; j < S; ++j) {
                int aux = calc(flies, i - 1, j - 1, K - 2);
                if (aux > ans) {
                    ans = aux;
                    ansi = i;
                    ansj = j;
                }
            }
        }
        System.out.println(ans);
        for (int i = 0; i < K; ++i) {
            picture[ansi - i][ansj] = '|';
            picture[ansi - i][ansj - K + 1] = '|';
            picture[ansi][ansj - i] = '-';
            picture[ansi - K + 1][ansj - i] = '-';
        }
        picture[ansi - K + 1][ansj - K + 1] = '+';
        picture[ansi - K + 1][ansj] = '+';
        picture[ansi][ansj - K + 1] = '+';
        picture[ansi][ansj] = '+';
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < S; ++j) {
                System.out.print(picture[i][j]);
            }
            System.out.println();
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Prozor())._main();
    }
}

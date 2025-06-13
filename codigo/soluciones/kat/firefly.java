import java.io.*;
import java.util.*;
class Firefly {
    private void _main() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), H = Integer.parseInt(st.nextToken());
        int[][] heights = new int[2][N / 2];
        for (int i = 0; i < N; ++i) {
            heights[i%2][i / 2] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(heights[0]);
        Arrays.sort(heights[1]);
        int ans = 1000000000, cnt = 0;
        for (int i = 0; i < H; ++i) {
            int a = Arrays.binarySearch(heights[0], i + 1);
            if (a < 0) {
                a = -(a + 1);
            }else {
                while (a > 0 && heights[0][a - 1] >= i + 1) {
                    --a;
                }
            }
            a = N / 2 - a;
            int b = Arrays.binarySearch(heights[1], H - i);
            if (b < 0) {
                b = -(b + 1);
            }else {
                while (b > 0 && heights[1][b - 1] >= H - i) {
                    --b;
                }
            }
            b = N / 2 - b;
            if (a + b < ans) {
                ans = a + b;
                cnt = 1;
            }else if (a + b == ans) {
                ++cnt;
            }
        }
        System.out.println(ans + " " + cnt);
    }
    public static void main(String[] args) throws IOException {
        (new Firefly())._main();
    }
}

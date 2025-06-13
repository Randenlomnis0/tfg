import java.io.*;
import java.util.*;
class Browniepoints {
    private void _main() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            long[] x = new long[n], y = new long[n];
            for (int i = 0; i < n; ++i) {
                st = new StringTokenizer(br.readLine());
                x[i] = Integer.parseInt(st.nextToken());
                y[i] = Integer.parseInt(st.nextToken());
            }
            long p = x[n / 2], q = y[n / 2], a = 0, b = 0;
            for (int i = 0; i < n; ++i) {
                a += (((x[i] - p) * (y[i] - q) > 0) ? 1 : 0);
                b += (((x[i] - p) * (y[i] - q) < 0) ? 1 : 0);
            }
            System.out.println(a + " " + b);
        }
    }
    public static void main(String[] args) throws IOException {
        (new Browniepoints())._main();
    }
}

import java.io.*;
import java.util.*;
class Cokolada {
    private int solve(int N, int K) {
        if (N == K) return 0;
        if (N / 2 >= K) {
            return 1 + solve(N / 2, K);
        }else {
            return 1 + solve(N / 2, K - N / 2);
        }
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int K = sc.nextInt();
        int ans = (int)Math.pow(2, Math.ceil(Math.log(K) / Math.log(2)));
        System.out.println(ans + " " + solve(ans, K));
        sc.close();
    }
    public static void main(String[] args) {
        (new Cokolada())._main();
    }
}

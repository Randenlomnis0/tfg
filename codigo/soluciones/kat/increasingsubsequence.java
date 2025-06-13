import java.io.*;
import java.util.*;
class Increasingsubsequence {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;
            int[] A = new int[n], LIS = new int[n], p = new int[n];
            for (int i = 0; i < n; ++i) {
                A[i] = sc.nextInt();
                LIS[i] = 1;
                p[i] = -1;
            }
            int ans = 0;
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (A[j] >= A[i]) continue;
                    if (LIS[i] < LIS[j] + 1) {
                        LIS[i] = LIS[j] + 1;
                        p[i] = j;
                    }else if (LIS[i] == LIS[j] + 1 && A[j] < A[p[i]]) {
                        p[i] = j;
                    }
                }
                if (LIS[i] > LIS[ans]) {
                    ans = i;
                }else if (LIS[i] == LIS[ans] && A[i] < A[ans]) {
                    ans = i;
                }
            }
            System.out.print(LIS[ans]);
            ArrayList<Integer> v = new ArrayList<>();
            while (ans != -1) {
                v.add(A[ans]);
                ans = p[ans];
            }
            for (int i = v.size() - 1; i >= 0; --i) {
                System.out.print(" " + v.get(i));
            }
            System.out.println();
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Increasingsubsequence())._main();
    }
}

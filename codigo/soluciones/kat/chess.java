import java.io.*;
import java.util.*;
class Chess {
    private boolean sameDiag(int a, int b, int c, int d) {
        return a - b == c - d || a + b == c + d;
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int t = sc.nextInt();
        while (t > 0) {
            --t;
            String A, C;
            int a, b, c, d;
            A = sc.next();
            b = sc.nextInt();
            C = sc.next();
            d = sc.nextInt();
            a = A.charAt(0) - 'A' + 1;
            c = C.charAt(0) - 'A' + 1;
            if ((a + b + c + d)%2 != 0) {
                System.out.println("Impossible");
            }else if (a == c && b == d) {
                System.out.println("0 " + A + " " + b);
            }else if (sameDiag(a, b, c, d)) {
                System.out.println("1 " + A + " " + b + " " + C + " " + d);
            }else {
                int p = -1, q = -1;
                for (int i = 1; i < 9; ++i) {
                    for (int j = 1; j < 9; ++j) {
                        if (sameDiag(a, b, i, j) && sameDiag(c, d, i, j)) {
                            p = i;
                            q = j;
                        }
                    }
                }
                System.out.println("2 " + A + " " + b + " " + (char)(p + 'A' - 1) + " " + q + " " + C + " " + d);
            }
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Chess())._main();
    }
}

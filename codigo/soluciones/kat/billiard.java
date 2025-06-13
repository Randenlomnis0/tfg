import java.io.*;
import java.util.*;
class Billiard {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int a, b, s, m, n;
        while (true) {
            a = sc.nextInt();
            b = sc.nextInt();
            s = sc.nextInt();
            m = sc.nextInt();
            n = sc.nextInt();
            if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0) break;
            long x = m * a, y = n * b;
            double delta = Math.atan2(y, x);
            System.out.printf("%.2f %.2f\n", 180 * delta / Math.PI, Math.sqrt(x * x + y * y) / s);
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Billiard())._main();
    }
}

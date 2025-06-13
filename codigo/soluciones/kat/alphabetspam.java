import java.io.*;
import java.util.*;
class Alphabetspam {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        String s = sc.next();
        double a, b, c, d;
        a = b = c = d = 0.0;
        for (char ch : s.toCharArray()) {
            if (ch == '_') {
                ++a;
            }else if (ch >= 'a' && ch <= 'z') {
                ++b;
            }else if (ch >= 'A' && ch <= 'Z') {
                ++c;
            }else {
                ++d;
            }
        }
        System.out.printf("%.6f\n", a / s.length());
        System.out.printf("%.6f\n", b / s.length());
        System.out.printf("%.6f\n", c / s.length());
        System.out.printf("%.6f\n", d / s.length());
        sc.close();
    }
    public static void main(String[] args) {
        (new Alphabetspam())._main();
    }
}

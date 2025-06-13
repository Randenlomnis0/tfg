import java.io.*;
import java.util.*;
class Luhnchecksum {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int T = sc.nextInt();
        while (T > 0) {
            --T;
            StringBuilder s = new StringBuilder(sc.next());
            int ans = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (i%2 != 0) {
                    int aux = 2 * (s.charAt(s.length() - i - 1) - '0');
                    if (aux > 9) aux = aux / 10 + aux%10;
                    s.setCharAt(s.length() - i - 1, (char)(aux + '0'));
                }
                ans += s.charAt(s.length() - i - 1) - '0';
            }
            System.out.println(ans%10 != 0 ? "FAIL" : "PASS");
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Luhnchecksum())._main();
    }
}

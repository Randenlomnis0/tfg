import java.io.*;
import java.util.*;
class Hidden {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        String pword = sc.next(), msg = sc.next();
        int j = 0;
        boolean pass = true;
        for (int i = 0; i < pword.length(); ++i) {
            if (!pass) break;
            boolean found = false;
            while (j < msg.length() && pword.charAt(i) != msg.charAt(j)) {
                for (int k = i + 1; k < pword.length(); ++k) {
                    if (pword.charAt(k) == msg.charAt(j)) {
                        pass = false;
                    }
                }
                ++j;
            }
            if (j < msg.length()) {
                found = true;
                ++j;
            }
            if (!found) pass = false;
        }
        System.out.println(pass ? "PASS" : "FAIL");
        sc.close();
    }
    public static void main(String[] args) {
        (new Hidden())._main();
    }
}

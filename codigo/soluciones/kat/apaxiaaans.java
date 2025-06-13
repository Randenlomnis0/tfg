import java.io.*;
import java.util.*;
class Apaxiaaans {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        String s = sc.next(), ans = "";
        ans += s.charAt(0);
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ans += s.charAt(i);
            }
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Apaxiaaans())._main();
    }
}

import java.io.*;
import java.util.*;
class Irepeatmyself {
    private boolean probar(String s1, String s2) {
        for (int i = 0; i < s2.length(); ++i) {
            if (s2.charAt(i) != s1.charAt(i%s1.length())) return false;
        }
        return true;
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        String line = sc.nextLine();
        while (n > 0) {
            --n;
            line = sc.nextLine();
            for (int i = 1; i < line.length() + 1; ++i) {
                if (probar(line.substring(0, i), line)) {
                    System.out.println(i);
                    break;
                }
            }
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Irepeatmyself())._main();
    }
}

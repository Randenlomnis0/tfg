import java.io.*;
import java.util.*;
class Aliennumbers {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int T = sc.nextInt();
        for (int tcase = 1; tcase <= T; ++tcase) {
            String alien_number = sc.next(), source_language = sc.next(), target_language = sc.next();
            HashMap<Character, Integer> source_pos = new HashMap<>();
            for (int i = 0; i < source_language.length(); ++i) {
                source_pos.put(source_language.charAt(i), i);
            }
            int b10 = 0, aux = 1, base = source_language.length();
            for (int i = 0; i < alien_number.length(); ++i) {
                b10 += aux * source_pos.get(alien_number.charAt(alien_number.length() - 1 - i));
                aux *= base;
            }
            base = target_language.length();
            String ans = "";
            while (b10 > 0) {
                ans += target_language.charAt(b10%base);
                b10 /= base;
            }
            System.out.println("Case #" + tcase + ": " + new StringBuilder(ans).reverse().toString());
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Aliennumbers())._main();
    }
}

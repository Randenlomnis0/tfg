import java.io.*;
import java.util.*;
class Lindenmayorsystem {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt(), m = sc.nextInt();
        HashMap<Character, String> rules = new HashMap<>();
        char left;
        String right;
        while (n > 0) {
            --n;
            left = sc.next().charAt(0);
            sc.next();
            right = sc.next();
            rules.put(left, right);
        }
        String S = sc.next();
        while (m > 0) {
            --m;
            String aux = S;
            S = "";
            for (char c : aux.toCharArray()) {
                if (!rules.containsKey(c)) {
                    S += c;
                }else {
                    S += rules.get(c);
                }
            }
        }
        System.out.println(S);
        sc.close();
    }
    public static void main(String[] args) {
        (new Lindenmayorsystem())._main();
    }
}

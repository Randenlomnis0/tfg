import java.io.*;
import java.util.*;
class Beatspread {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        while (n > 0) {
            --n;
            int s = sc.nextInt(), d = sc.nextInt();
            if (s < d || (s + d)%2 != 0) {
                System.out.println("impossible");
            }else {
                System.out.println(((s + d) / 2) + " " + (s - ((s + d) / 2)));
            }
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Beatspread())._main();
    }
}

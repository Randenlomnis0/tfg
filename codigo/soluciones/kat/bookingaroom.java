import java.io.*;
import java.util.*;
class Bookingaroom {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int r = sc.nextInt(), n = sc.nextInt();
        boolean[] booked = new boolean[r];
        for (int i = 0; i < r; ++i) {
            booked[i] = false;
        }
        while (n > 0) {
            --n;
            int aux = sc.nextInt();
            --aux;
            booked[aux] = true;
        }
        boolean ans = false;
        for (int i = 0; i < r; ++i) {
            if (booked[i]) continue;
            System.out.println(i + 1);
            ans = true;
            break;
        }
        if (!ans) {
            System.out.println("too late");
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Bookingaroom())._main();
    }
}

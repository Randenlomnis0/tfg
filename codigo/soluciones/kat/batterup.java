import java.io.*;
import java.util.*;
class Batterup {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        int nom = 0, denom = 0;
        while (n > 0) {
            --n;
            int aux = sc.nextInt();
            if (aux == -1) continue;
            nom += aux;
            ++denom;
        }
        System.out.printf("%.3f\n", nom / (double)denom);
        sc.close();
    }
    public static void main(String[] args) {
        (new Batterup())._main();
    }
}

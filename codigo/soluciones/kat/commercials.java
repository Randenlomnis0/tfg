import java.io.*;
import java.util.*;
class Commercials {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int N = sc.nextInt(), P = sc.nextInt(), ans = 0, aux = 0;
        while (N > 0) {
            --N;
            int n = sc.nextInt();
            aux += n - P;
            ans = Math.max(ans, aux);
            aux = Math.max(aux, 0);
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Commercials())._main();
    }
}

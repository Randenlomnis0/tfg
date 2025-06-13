import java.io.*;
import java.util.*;
class Awkwardparty {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        int ans = n;
        HashMap<Integer, Integer> prev = new HashMap<>();
        while (n > 0) {
            --n;
            int aux = sc.nextInt();
            if (prev.containsKey(aux)) {
                ans = Math.min(ans, prev.get(aux) - n);
            }
            prev.put(aux, n);
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Awkwardparty())._main();
    }
}

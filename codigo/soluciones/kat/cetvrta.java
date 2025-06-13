import java.io.*;
import java.util.*;
class Cetvrta {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        HashSet<Integer> l = new HashSet<>(), r = new HashSet<>();
        int aux = 3;
        while (aux > 0) {
            --aux;
            int a = sc.nextInt(), b = sc.nextInt();
            if (l.contains(a)) {
                l.remove(a);
            }else {
                l.add(a);
            }
            if (r.contains(b)) {
                r.remove(b);
            }else {
                r.add(b);
            }
        }
        System.out.println(l.toArray()[0] + " " + r.toArray()[0]);
        sc.close();
    }
    public static void main(String[] args) {
        (new Cetvrta())._main();
    }
}

import java.io.*;
import java.util.*;
class Cetiri {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < 3; ++i) {
            int aux = sc.nextInt();
            v.add(aux);
        }
        Collections.sort(v);
        if (v.get(0) - v.get(1) == v.get(1) - v.get(2)) {
            System.out.println(v.get(2) + v.get(2) - v.get(1));
        }else if (Math.abs(v.get(0) - v.get(1)) > Math.abs(v.get(1) - v.get(2))) {
            System.out.println(v.get(0) + v.get(2) - v.get(1));
        }else {
            System.out.println(v.get(1) + v.get(1) - v.get(0));
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Cetiri())._main();
    }
}

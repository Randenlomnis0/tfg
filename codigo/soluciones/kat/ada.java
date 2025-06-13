import java.io.*;
import java.util.*;
class Ada {
    private boolean constant(ArrayList<Integer> v) {
        if (v.size() == 1) return true;
        for (int i = 1; i < v.size(); ++i) {
            if (v.get(i) - v.get(i - 1) != 0) return false;
        }
        return true;
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> v = new ArrayList<>();
        v.add(new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            int aux = sc.nextInt();
            v.get(0).add(aux);
        }
        int i = 0;
        while (!constant(v.get(i))) {
            v.add(new ArrayList<>());
            ++i;
            for (int j = 1; j < v.get(i - 1).size(); ++j) {
                v.get(i).add(v.get(i - 1).get(j) - v.get(i - 1).get(j - 1));
            }
        }
        System.out.print(i + " ");
        while (i > 0) {
            v.get(i - 1).add(v.get(i - 1).get(v.get(i - 1).size() - 1) + v.get(i).get(v.get(i).size() - 1));
            --i;
        }
        System.out.println(v.get(0).get(v.get(0).size() - 1));
        sc.close();
    }
    public static void main(String[] args) {
        (new Ada())._main();
    }
}

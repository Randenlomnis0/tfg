import java.io.*;
import java.util.*;
class Airconditioned {
    private class Pair implements Comparable<Pair> {
        private int a, b;
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
        public int getA() {
            return this.a;
        }
        public int getB() {
            return this.b;
        }
        @Override
        public int compareTo(Pair o) {
            if (this.a == o.a) return Integer.compare(this.b, o.b);
            return Integer.compare(this.a, o.a);
        }
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int N = sc.nextInt();
        ArrayList<Pair> preferences = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            int a = sc.nextInt(), b = sc.nextInt();
            preferences.add(new Pair(a, b));
        }
        Collections.sort(preferences);
        int ans = 0, aux = 0;
        for (int i = 0; i < N; ++i) {
            if (aux < preferences.get(i).getA()) {
                ++ans;
                aux = preferences.get(i).getB();
            }else {
                aux = Math.min(aux, preferences.get(i).getB());
            }
        }
        System.out.println(ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Airconditioned())._main();
    }
}

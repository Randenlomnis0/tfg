import java.io.*;
import java.util.*;
class Carrots {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int N = sc.nextInt();
        int P = sc.nextInt();
        sc.nextLine();
        while (N-- > 0) {
            sc.nextLine();
        }
        System.out.println(P);
        sc.close();
    }
    public static void main(String[] args) {
        (new Carrots())._main();
    }
}

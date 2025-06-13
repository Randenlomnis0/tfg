import java.io.*;
import java.util.*;
class Dvds {
    private void _main() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int k = Integer.parseInt(br.readLine());
        while (k > 0) {
            --k;
            int n = Integer.parseInt(br.readLine()), goal = 1;
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; ++i) {
                if (Integer.parseInt(st.nextToken()) == goal) {
                    ++goal;
                }
            }
            System.out.println(n - goal + 1);
        }
    }
    public static void main(String[] args) throws IOException {
        (new Dvds())._main();
    }
}

import java.io.*;
import java.util.*;
class Bungeebuilder {
    private void _main() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int tallest = -1, smallest = -1, ans = 0;
        while (N > 0) {
            --N;
            int aux = Integer.parseInt(st.nextToken());
            if (tallest != -1) {
                if (smallest != -1) {
                    ans = Math.max(ans, Math.min(aux, tallest) - smallest);
                    smallest = Math.min(smallest, aux);
                }else {
                    smallest = aux;
                }
                if (aux > tallest) {
                    tallest = aux;
                    smallest = -1;
                }
            }else {
                tallest = aux;
            }
        }
        System.out.println(ans);
    }
    public static void main(String[] args) throws IOException {
        (new Bungeebuilder())._main();
    }
}

import java.io.*;
import java.util.*;
class Cursethedarkness {
    private void _main() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int m = Integer.parseInt(br.readLine());
        while (m > 0) {
            --m;
            st = new StringTokenizer(br.readLine());
            double X = Double.parseDouble(st.nextToken()), Y = Double.parseDouble(st.nextToken());
            int n = Integer.parseInt(br.readLine());
            boolean cursethedarkness = true;
            while (n > 0) {
                --n;
                st = new StringTokenizer(br.readLine());
                double x = Double.parseDouble(st.nextToken()), y = Double.parseDouble(st.nextToken());
                x -= X;
                y -= Y;
                if (x * x + y * y > 64.0) continue;
                cursethedarkness = false;
            }
            System.out.println(cursethedarkness ? "curse the darkness" : "light a candle");
        }
    }
    public static void main(String[] args) throws IOException {
        (new Cursethedarkness())._main();
    }
}

import java.io.*;
import java.util.*;
class Gamerank {
    private int starts(int lvl) {
        if (lvl > 20) return 2;
        if (lvl > 15) return 3;
        if (lvl > 10) return 4;
        return 5;
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        String s = sc.next();
        int stars = 0, lvl = 25, wstreak = 0;
        for (char c : s.toCharArray()) {
            if (lvl == 0) break;
            if (c == 'W') {
                ++wstreak;
                if (lvl > 5 && wstreak >= 3) {
                    stars += 2;
                }else {
                    ++stars;
                }
                if (lvl != 0 && stars > starts(lvl)) {
                    stars -= starts(lvl);
                    --lvl;
                }
            }else {
                wstreak = 0;
                if (lvl <= 20) {
                    stars -= 1;
                }
                if (lvl >= 20) {
                    stars = Math.max(stars, 0);
                }
                if (stars < 0) {
                    ++lvl;
                    stars = starts(lvl) - 1;
                }
            }
        }
        if (lvl == 0) {
            System.out.println("Legend");
        }else {
            System.out.println(lvl);
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Gamerank())._main();
    }
}

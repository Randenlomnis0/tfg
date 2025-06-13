import java.io.*;
import java.util.*;
class Acm {
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        HashSet<String> solved = new HashSet<>();
        HashMap<String, Integer> attempts = new HashMap<>();
        int ans = 0;
        while (true) {
            int t = sc.nextInt();
            if (t == -1) break;
            String c = sc.next();
            String s = sc.next();
            if (solved.contains(c)) continue;
            if (s.equals("right")) {
                ans += t;
                solved.add(c);
            }else {
                attempts.put(c, attempts.getOrDefault(c, 0) + 1);
            }
        }
        for (String c : attempts.keySet()) {
            if (!solved.contains(c)) continue;
            ans += attempts.get(c) * 20;
        }
        System.out.println(solved.size() + " " + ans);
        sc.close();
    }
    public static void main(String[] args) {
        (new Acm())._main();
    }
}

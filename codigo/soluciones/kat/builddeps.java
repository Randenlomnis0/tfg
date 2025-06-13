import java.io.*;
import java.util.*;
class Builddeps {
    private void dfs(String changed, HashMap<String, ArrayList<String>> AL, ArrayList<String> ts, HashSet<String> visited) {
        visited.add(changed);
        if (AL.containsKey(changed)) {
            for (String s : AL.get(changed)) {
                if (visited.contains(s)) continue;
                dfs(s, AL, ts, visited);
            }
        }
        ts.add(changed);
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        HashMap<String, ArrayList<String>> AL = new HashMap<>();
        sc.nextLine();
        while (n > 0) {
            --n;
            StringTokenizer st = new StringTokenizer(sc.nextLine());
            String key = null;
            while (st.hasMoreTokens()) {
                String token = st.nextToken();
                if (key == null) {
                    key = token.substring(0, token.length() - 1);
                }else {
                    if (!AL.containsKey(token)) {
                        AL.put(token, new ArrayList<>());
                    }
                    AL.get(token).add(key);
                }
            }
        }
        String changed = sc.next();
        ArrayList<String> ts = new ArrayList<>();
        HashSet<String> visited = new HashSet<>();
        dfs(changed, AL, ts, visited);
        for (int i = ts.size() - 1; i >= 0; --i) {
            System.out.println(ts.get(i));
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Builddeps())._main();
    }
}

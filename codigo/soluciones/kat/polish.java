import java.io.*;
import java.util.*;
class Polish {
    private boolean isIntConst(String s) {
        return !(s.equals("+") || s.equals("-") || s.equals("*") || (s.length() == 1 && s.charAt(0) >= 'a' && s.charAt(0) <= 'z'));
    }
    private void _main() {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int tcase = 1;
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            ArrayList<String> stack = new ArrayList<>();
            Scanner tokenizer = new Scanner(line);
            while (tokenizer.hasNext()) {
                String token = tokenizer.next();
                stack.add(token);
                while (stack.size() > 2 && isIntConst(stack.get(stack.size() - 1))&& isIntConst(stack.get(stack.size() - 2))) {
                    if (stack.get(stack.size() - 3).equals("+")) {
                        stack.set(stack.size() - 3, ((Integer)(Integer.parseInt(stack.get(stack.size() - 2)) + Integer.parseInt(stack.get(stack.size() - 1)))).toString());
                        stack.remove(stack.size() - 1);
                        stack.remove(stack.size() - 1);
                    }else if (stack.get(stack.size() - 3).equals("-")) {
                        stack.set(stack.size() - 3, ((Integer)(Integer.parseInt(stack.get(stack.size() - 2)) - Integer.parseInt(stack.get(stack.size() - 1)))).toString());
                        stack.remove(stack.size() - 1);
                        stack.remove(stack.size() - 1);
                    }else if (stack.get(stack.size() - 3).equals("*")) {
                        stack.set(stack.size() - 3, ((Integer)(Integer.parseInt(stack.get(stack.size() - 2)) * Integer.parseInt(stack.get(stack.size() - 1)))).toString());
                        stack.remove(stack.size() - 1);
                        stack.remove(stack.size() - 1);
                    }else {
                        break;
                    }
                }
            }
            tokenizer.close();
            System.out.print("Case " + tcase + ": ");
            ++tcase;
            boolean first = true;
            for (String s : stack) {
                if (!first) System.out.print(" ");
                else first = false;
                System.out.print(s);
            }
            System.out.println();
        }
        sc.close();
    }
    public static void main(String[] args) {
        (new Polish())._main();
    }
}

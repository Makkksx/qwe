import java.util.Stack;
import java.util.Scanner;

public class LAB3SEM3 {
    public static void main(String[] args) {
        Stack<Character> st = new Stack<>();
        Scanner in = new Scanner(System.in);
        System.out.print("Input string: ");
        StringBuilder str = new StringBuilder(in.nextLine());
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (isBkt(c)) {
                if (isOpen(c)) {
                    for (int j = 0; j < st.size(); j++) {
                        System.out.print("\t");
                    }
                    System.out.println("push " + c);
                    st.push(c);
                } else {
                    if (!st.empty()) {
                        switch (st.peek()) {
                            case '(':
                                if (c == ')') {
                                    popBkt(st);
                                    break;
                                }
                            case '[':
                                if (c == ']') {
                                    popBkt(st);
                                    break;
                                }
                            case '{':
                                if (c == '}') {
                                    popBkt(st);
                                    break;
                                }
                            default:
                                System.out.println(i + " - wrong position");
                                return;
                        }
                    }
                    else{
                        System.out.println(i + " - wrong position");
                        return;
                    }
                }
            }
        }
        System.out.println(st.empty()? "correct" : "wrong, there are not enough closing brackets at the end");
        in.close();
    }

    private static boolean isOpen(char bkt) {
        return (bkt == '(' || bkt == '[' || bkt == '{');
    }

    private static boolean isClose(char bkt) {
        return (bkt == ')' || bkt == ']' || bkt == '}');
    }

    private static boolean isBkt(char bkt) {
        return (isOpen(bkt) || isClose(bkt));
    }

    private static void popBkt(Stack st) {
        //add tabs
        for (int j = 0; j < st.size() - 1; j++)
            System.out.print("\t");
        System.out.println("pop " + st.pop());

    }
}



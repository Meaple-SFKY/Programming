package lrparser;

public class FirstSet {
    // private char[] VN = {'S', 'C'};
    // private char[] VT = {'c', 'd', '#'};
    // public char[] charactor = {'S', 'C', 'c', 'd'};
    // public String[] title = {"Status", "c", "d", "#", "S", "C"};

    // public String[] grammar = {
    //     "S->CC",
    //     "C->cC",
    //     "C->d"
    // };

    // public String[] extendGrammar = {
    //     "E->S",
    //     "S->CC",
    //     "C->cC",
    //     "C->d"
    // };

    // private char[] VN = {'E', 'T', 'F'};
    // private char[] VT = {'i', '+', '*', '(', ')', '#'};
    // public char[] charactor = {'E', 'T', 'F', '+', '*', '(', ')', 'i'};
    // public String[] title = {"Status", "i", "+", "*", "(", ")", "#", "E", "T", "F"};

    // public String[] grammar = {
    //     "E->E+T",
    //     "E->T",
    //     "T->T*F",
    //     "T->F",
    //     "F->(E)",
    //     "F->i"
    // };

    // public String[] extendGrammar = {
    //     "S->E",
    //     "E->E+T",
    //     "E->T",
    //     "T->T*F",
    //     "T->F",
    //     "F->(E)",
    //     "F->i"
    // };

    private char[] VN = { 'S', 'B' };
    private char[] VT = { 'a', 'b', '#' };
    public char[] charactor = { 'S', 'B', 'a', 'b' };
    public String[] title = { "Status", "a", "b", "#", "S", "B" };

    public String[] grammar = { "S->BB", "B->aB", "B->b" };

    public String[] extendGrammar = {
        "T->S",
        "B->aB",
        "S->BB",
        "B->b"
    };

    private String[] FIRST = new String[VN.length];

    public int getLength() {
        return VN.length + VT.length;
    }

    public char[] getVn() {
        return VN;
    }

    public char[] getVt() {
        return VT;
    }

    public void print() {
        for (int i = 0; i < FIRST.length; i++) {
            System.out.println(FIRST[i]);
        }
    }

    public int indexOfGrammar(String str) {
        for (int i = 0; i < extendGrammar.length; i++) {
            if (str.equals(extendGrammar[i])) {
                return i;
            }
        }
        return -1;
    }

    public FirstSet() {
        initFirst();
        addVtToFirOfVn();
        addFirOfVnToFirOfVn();
        tidyFirst();
    }

    private int head = 0;
    private int bodyStart = 3;

    private void initFirst() {
        for (int i = 0; i < FIRST.length; i++) {
            FIRST[i] = "";
        }
    }

    public int indexOfVn(char chVn) {
        int index = -1;
        for (int i = 0; i < VN.length; i++) {
            if (VN[i] == chVn) {
                index = i;
                break;
            }
        }
        return index;
    }

    public int indexOfVt(char chVt) {
        int index = -1;
        for (int i = 0; i < VT.length; i++) {
            if (VT[i] == chVt) {
                index = i;
                break;
            }
        }
        return index;
    }

    private void addVtToFirOfVn() {
        for (int i = 0; i < grammar.length; i++) {
            int indexBodyStartOfVt = indexOfVt(grammar[i].charAt(bodyStart));
            if (indexBodyStartOfVt != -1) {
                int indexHeadOfVn = indexOfVn(grammar[i].charAt(head));
                FIRST[indexHeadOfVn] += grammar[i].charAt(bodyStart);
            }
        }
    }

    private boolean ifContainsOfHead(int headVn, int bodyVn) {
        if (FIRST[bodyVn].length() != 0) {
            if (FIRST[headVn].length() != 0) {
                for (int i = 0; i < FIRST[bodyVn].length(); i++) {
                    if (FIRST[headVn].contains(Character.toString(FIRST[bodyVn].charAt(i))) == false) {
                        return false;
                    }
                }
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }

    private void addFirOfVnToFirOfVn() {
        while (true) {
            int flag = 0;
            for (int i = 0; i < grammar.length - 1; i++) {
                int indexBodyStartOfVn = indexOfVn(grammar[i].charAt(bodyStart));
                if (indexBodyStartOfVn != -1) {
                    int indexHeadOfVn = indexOfVn(grammar[i].charAt(head));
                    if (ifContainsOfHead(indexHeadOfVn, indexBodyStartOfVn) == false) {
                        flag++;
                    }
                    FIRST[indexHeadOfVn] += FIRST[indexBodyStartOfVn];
                }
            }
            if (flag == 0) {
                break;
            }
        }
    }

    private void tidyFirst() {
        for (int firstLab = 0; firstLab < FIRST.length; firstLab++) {
            int len = FIRST[firstLab].length();
            if (len == 0) {
                return;
            }
            String string = "";
            for (int i = 0; i < len; i++) {
                String tempStr = Character.toString(FIRST[firstLab].charAt(i));
                if (string.contains(tempStr) == false) {
                    string += tempStr;
                }
            }
            FIRST[firstLab] = string;
        }
    }

    public void printFirst() {
        for (int i = 0; i < FIRST.length; i++) {
            System.out.println(FIRST[i]);
        }
    }

    public String getFirOfString(String string) {
        if (string.length() != 0) {
            if (indexOfVn(string.charAt(0)) != -1) {
                return FIRST[indexOfVn(string.charAt(0))];
            } else if (indexOfVt(string.charAt(0)) != -1) {
                return Character.toString(string.charAt(0));
            } else {
                return "";
            }
        } else {
            return "";
        }
    }
}

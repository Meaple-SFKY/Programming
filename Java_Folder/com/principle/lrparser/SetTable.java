package com.principle.lrparser;

public class SetTable {
    private SetFamily family = new SetFamily(new FirstSet().extendGrammar);
    private ItemFamily familyItem = family.itemFamily;
    private char[] vnSet = family.firstSet.getVn();
    private char[] vtSet = family.firstSet.getVt();

    private String[][] analysisTable = new String[familyItem.itemSets.size()][vnSet.length + vtSet.length];

    public SetTable() {
        initTable();
        formTable();
        printTable();
        printFamily();
    }

    public String[][] getAnalysisTable() {
        return analysisTable;
    }

    public ItemFamily getFamily() {
        return familyItem;
    }

    public int actionIndex() {
        return 0;
    }

    public int indexOfVt(char ch) {
        for (int i = 0; i < vtSet.length; i++) {
            if (vtSet[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    public int indexOfVn(char ch) {
        for (int i = 0; i < vnSet.length; i++) {
            if (vnSet[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    public int gotoIndex() {
        return vtSet.length;
    }

    private void initTable() {
        for (int i = 0; i < analysisTable.length; i++) {
            for (int j = 0; j < analysisTable[i].length; j++) {
                analysisTable[i][j] = "";
            }
        }
    }

    public void formTable() {
        for (int i = 0; i < familyItem.itemSets.size(); i++) {
            for (int j = 0; j < familyItem.itemSets.get(i).items.size(); j++) {
                Item tempItem = familyItem.itemSets.get(i).items.get(j);
                if (tempItem.indexPoint < tempItem.body.length()) {
                    if (family.firstSet.indexOfVt(tempItem.item.charAt(tempItem.indexPoint)) != -1) {
                        int indexFamily = familyItem.getIndexInFamily(family.goTo(familyItem.itemSets.get(i), tempItem.item.charAt(tempItem.indexPoint)));
                        if (indexFamily != -1) {
                            /* System.out.println("--------" + tempItem.item); */
                            if ((analysisTable[i][family.firstSet.indexOfVt(tempItem.item.charAt(tempItem.indexPoint))].length() == 0) || 
                                analysisTable[i][family.firstSet.indexOfVt(tempItem.item.charAt(tempItem.indexPoint))].equals("s" + indexFamily)) {
                                analysisTable[i][family.firstSet.indexOfVt(tempItem.item.charAt(tempItem.indexPoint))] = "s" + indexFamily;
                            } else {
                                System.out.println("Item existed; Location 1");
                                return;
                            }
                        } else {
                            System.out.println("Set no found; Location 1");
                            return;
                        }
                    } else if (family.firstSet.indexOfVn(tempItem.item.charAt(tempItem.indexPoint)) != -1) {
                        int indexFamily = familyItem.getIndexInFamily(family.goTo(familyItem.itemSets.get(i), tempItem.item.charAt(tempItem.indexPoint)));
                        if (indexFamily != -1) {
                            if ((analysisTable[i][family.firstSet.indexOfVn(tempItem.item.charAt(tempItem.indexPoint)) + vtSet.length].length() == 0) ||
                                analysisTable[i][family.firstSet.indexOfVn(tempItem.item.charAt(tempItem.indexPoint)) + vtSet.length].equals(Integer.toString(indexFamily))) {
                                analysisTable[i][family.firstSet.indexOfVn(tempItem.item.charAt(tempItem.indexPoint)) + vtSet.length] = Integer.toString(indexFamily);
                            } else {
                                System.out.println("Item existed; location 2");
                                return;
                            }
                        } else {
                            System.out.println("Set no found; Location 2");
                            return;
                        }
                    }
                } else {
                    if (tempItem.body.charAt(0) == family.firstSet.extendGrammar[0].charAt(0)) {
                        if (tempItem.nextChar == vtSet[vtSet.length - 1]) {
                            if ((analysisTable[i][family.firstSet.indexOfVt(tempItem.nextChar)].length() == 0) ||
                                analysisTable[i][family.firstSet.indexOfVt(tempItem.nextChar)].equals("acc")) {
                                analysisTable[i][family.firstSet.indexOfVt(tempItem.nextChar)] = "acc";
                            } else {
                                System.out.println("Item existed; Location 3");
                                return;
                            }
                        }
                    } else {
                        int indexOfGram = family.firstSet.indexOfGrammar(tempItem.body);
                        if (indexOfGram != -1) {
                            if (analysisTable[i][family.firstSet.indexOfVt(tempItem.nextChar)].length() == 0 ||
                                analysisTable[i][family.firstSet.indexOfVt(tempItem.nextChar)].equals("r" + indexOfGram)) {
                                analysisTable[i][family.firstSet.indexOfVt(tempItem.nextChar)] = "r" + indexOfGram;
                            } else {
                                System.out.println("Item existed; location 3");
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    public void printTable() {
        for (int i = 0; i < analysisTable.length; i++) {
            for (int j = 0; j < analysisTable[i].length; j++) {
                System.out.print(analysisTable[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public void printFamily() {
        familyItem.printFamily();
    }
}

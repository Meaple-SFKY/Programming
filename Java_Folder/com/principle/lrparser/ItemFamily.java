package com.principle.lrparser;

import java.util.ArrayList;

class Item {
    int indexPoint;
    char nextChar;
    String body;
    String item;
    String firstSet;

    public Item(String itemString, int index) {
        initItem();
        item = itemString;
        indexPoint = index;
        setNextChar();
        setBody();
        setFirstSet();
    }

    public void freshFirst() {
        setFirstSet();
    }

    private void initItem() {
        indexPoint = 3;
        nextChar = 'n';
        body = "";
        item = "";
        firstSet = "";
    }

    private void setNextChar() {
        nextChar = item.charAt(item.length() - 1);
    }

    private void setBody() {
        for (int i = 0; i < item.length(); i++) {
            if (item.charAt(i) != ',') {
                body += item.charAt(i);
            } else {
                break;
            }
        }
    }

    private void setFirstSet() {
        FirstSet set = new FirstSet();
        String string = "";
        for (int i = indexPoint + 1; i < item.length(); i++) {
            if (item.charAt(i) != ',') {
                string += item.charAt(i);
            } else {
                break;
            }
        }
        string += nextChar;
        firstSet = set.getFirOfString(string);
    }

    public void setIndexPoint(int i) {
        indexPoint = i;
    }

    public void setNextChar(char ch) {
        nextChar = ch;
    }
}

class ItemSet {
    ArrayList<Item> items = new ArrayList<Item>();

    public void addItem(Item item) {
        item.freshFirst();
        items.add(item);
    }

    public void printSet() {
        for (int i = 0; i < items.size(); i++) {
            System.out.println(items.get(i).item + ", " + items.get(i).firstSet + ", " + items.get(i).indexPoint);
        }
    }
}

public class ItemFamily {
    ArrayList<ItemSet> itemSets = new ArrayList<ItemSet>();

    public void addItemSet(ItemSet itemSet) {
        itemSets.add(itemSet);
    }

    public void printFamily() {
        for (int i = 0; i < itemSets.size(); i++) {
            for (int j = 0; j < itemSets.get(i).items.size(); j++) {
                System.out.println(itemSets.get(i).items.get(j).item);
            }
            System.out.println();
        }
    }

    public boolean isEqualItems(ItemSet firSet, ItemSet secSet) {
        if (firSet.items.size() == secSet.items.size()) {
            for (int i = 0; i < firSet.items.size(); i++) {
                if (firSet.items.get(i).indexPoint == secSet.items.get(i).indexPoint) {
                    if (firSet.items.get(i).item.length() == secSet.items.get(i).item.length()) {
                        for (int j = 0; j < firSet.items.get(i).item.length(); j++) {
                            if (firSet.items.get(i).item.charAt(j) != secSet.items.get(i).item.charAt(j)) {
                                return false;
                            }
                        }
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    public int getIndexInFamily(ItemSet itemSet) {
        for (int i = 0; i < itemSets.size(); i++) {
            if (isEqualItems(itemSet, itemSets.get(i)) == true) {
                return i;
            }
        }
        return -1;
    }

    public boolean isInFamily(ItemSet itemSet) {
        for (ItemSet tempsSet : this.itemSets) {
            if (isEqualItems(itemSet, tempsSet)) {
                return true;
            }
        }
        return false;
    }
}
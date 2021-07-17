package lrparser;

public class SetFamily {
    ItemFamily itemFamily = new ItemFamily();

    FirstSet firstSet = new FirstSet();

    public SetFamily(String[] grammar) {
        setItemFamily(grammar);
    }

    private ItemSet closure(ItemSet itemSet) {
        ItemSet tempSet = itemSet;
        while (true) {
            int flag = 0;
            int size = tempSet.items.size();
            for (int i = 0; i < size; i++) {
                Item item = tempSet.items.get(i);
                if (item.indexPoint < item.body.length()) {
                    char nowChar = item.body.charAt(item.indexPoint);
                    for (int j = 0; j < firstSet.grammar.length; j++) {
                        if (nowChar == firstSet.grammar[j].charAt(0)) {
                            String newItemString = "";
                            newItemString += firstSet.grammar[j];
                            newItemString += ",";
                            for (char tempChar : item.firstSet.toCharArray()) {
                                String string = newItemString + tempChar;
                                int flagInner = 0;
                                for (int k = 0; k < tempSet.items.size(); k++) {
                                    if (tempSet.items.get(k).item.equals(string) && tempSet.items.get(k).indexPoint == 3) {
                                        flagInner = 1;
                                        break;
                                    }
                                }
                                if (flagInner != 1) {
                                    Item newItem = new Item(string, 3);
                                    tempSet.addItem(newItem);
                                    flag++;
                                }
                            }
                        }
                    }
                } else {
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        return itemSet;
    }

    public ItemSet goTo(ItemSet itemSet, char nowChar) {
        ItemSet goToSet = new ItemSet();
        for (Item item : itemSet.items) {
            if (item.indexPoint < item.body.length()) {
                if (item.body.charAt(item.indexPoint) == nowChar) {
                    int temp = item.indexPoint + 1;
                    Item newItem = new Item(item.item, item.indexPoint);
                    newItem.setIndexPoint(temp);
                    goToSet.addItem(newItem);
                }
            }
        }
        return closure(goToSet);
    }

    public void setItemFamily(String[] grammar) {
        String startBody = "";
        startBody += grammar[0];
        startBody += ",#";
        Item startItem = new Item(startBody, 3);
        ItemSet startItemSet = new ItemSet();
        startItemSet.addItem(startItem);
        itemFamily.addItemSet(closure(startItemSet));

        while (true) {
            int flag = 0;
            for (int size = 0; size < itemFamily.itemSets.size(); size++) {
                ItemSet itemSet = itemFamily.itemSets.get(size);
                for (char symbol : firstSet.charactor) {
                    ItemSet goToSet = goTo(itemSet, symbol);
                    if ((goToSet.items.size() > 0) && (itemFamily.isInFamily(goToSet) == false)) {
                        flag++;
                        itemFamily.addItemSet(goToSet);
                    }
                }
            }
            if (flag == 0) {
                break;
            }
        }
    }
}

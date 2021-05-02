package com.principle.defined;

import java.util.Vector;

public class VectorArguments {
    private Vector<String> vecIdentifiers = new Vector<String>();
    private Vector<String> vecConstants = new Vector<String>();

    public void identifierAdd(String identifier) {
        vecIdentifiers.add(identifier);
    }

    public void constantAdd(String constant) {
        vecConstants.add(constant);
    }

    public void demoIdentifiers() {
        for (int i = 0; i < vecIdentifiers.size(); i++) {
            System.out.println(vecIdentifiers.get(i));
        }
    }

    public void demoConstants() {
        for (int i = 0; i < vecConstants.size(); i++) {
            System.out.println(vecConstants.get(i));
        }
    }

    public Vector<String> getIdentifiers() {
        return vecIdentifiers;
    }

    public Vector<String> getConstants() {
        return vecConstants;
    }
}

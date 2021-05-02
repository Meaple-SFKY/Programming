package com.meaple.interfaces;

interface AnInterface {
    void firstMethod();
    void secondMethod();
    default void newMethod() {
        System.out.println("newMethod");
    }
}
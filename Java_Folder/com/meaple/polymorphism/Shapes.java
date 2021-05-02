package com.meaple.polymorphism;

import com.meaple.polymorphism.shape.*;

public class Shapes {
    public static void main(String[] args) {
        RandomShapes gen = new RandomShapes();
        // Make polymorphic method calls:
        for (Shape shape: gen.array(9)) {
            shape.draw();
        }
    }
}
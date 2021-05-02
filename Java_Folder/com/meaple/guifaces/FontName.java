package com.meaple.guifaces;

import java.awt.*;

public class FontName {
    public static void main(String[] args) {
        String[] fontNames = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
        for (String fontName: fontNames) {
            System.out.println(fontName);
        }
    }
}

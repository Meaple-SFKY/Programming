package com.meaple.interfaces;

import java.nio.*;
import java.util.*;

public class AdaptedRandomDoubles implements RandomDoubles, Readable {
    private int count;
    public AdaptedRandomDoubles(int count) {
        this.count = count;
    }
    
    @Override
    public int read(CharBuffer cb) {
        if (count-- == 0) {
            return -1;
        }
        String result = Double.toString(next()) + " ";
        cb.append(result);
        return result.length();
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(new AdaptedRandomDoubles(7));
        while (s.hasNextDouble()) {
            System.out.println(s.nextDouble() + " ");
        }
    }
}
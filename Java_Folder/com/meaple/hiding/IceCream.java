package com.meaple.hiding;

class Sundae {
    private Sundae() {}
    
    //static void main()
    static Sundae makeASundae() {
        return new Sundae();
    }
}

public class IceCream {
    public static void main(String[] args) {
        //The constructor is not visible
        // Sundae x = new Sundae();
        Sundae x = Sundae.makeASundae();
    }
}

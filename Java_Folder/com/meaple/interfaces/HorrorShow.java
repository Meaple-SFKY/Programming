package com.meaple.interfaces;

interface Monster {
    void menace();
}

interface DangerousMonster extends Monster {
    void destroy();
}

interface Lethal {
    void kill();
}

class DragonZilla implements DangerousMonster {
    @Override
    public void menace() {}

    @Override
    public void destroy() {}
}

interface Vampie extends DangerousMonster, Lethal {
    void drinkBlood();
}

class VeryBadVampie implements Vampie {
    @Override
    public void menace() {}
    @Override
    public void destroy() {}
    @Override
    public void kill() {}
    @Override
    public void drinkBlood() {}
}

public class HorrorShow {
    static void u(Monster b) {
        b.menace();
    }
    static void v(DangerousMonster d) {
        d.menace();
        d.destroy();
    }
    static void w(Lethal l) {
        l.kill();
    }

    public static void main(String[] args) {
        DangerousMonster barney = new DragonZilla();
        u(barney);
        v(barney);
        Vampie vlad = new VeryBadVampie();
        u(vlad);
        v(vlad);
        w(vlad);
    }
}

class Box {
    double width;
    double height;
    double depth;

    Box(double w, double h, double d) {
        width = w;
        height = h;
        depth = d;
    }

    Box() {
        width = 0;
        height = 0;
        depth = 0;
    }

    Box(double len) {
        width = height = depth = len;
    }

    double volume() {
        return width * height * depth;
    }
}

class BoxVol {
    public static void main(String args[]) {
        Box box1 = new Box(10, 20, 15);
        Box box2 = new Box();
        Box box3 = new Box(7);
        double vol;
        vol = box1.volume();
        System.out.println("Volume of Box with default paramaters is " + vol);
        vol = box2.volume();
        System.out.println("Volume of Box with all 3 parameters is " + vol);
        vol = box3.volume();
        System.out.println("Volume of Box with 1 parameter is " + vol);
    }
}
package com.sumeetbalwade;

public class EvenOdd {
    public void evenOdd(int number) {
        if (number % 2 == 0) {
            System.out.println("Number " + number + " is Even. ");

        } else {
            System.out.println("Number " + number + " is Odd. ");
        }
    }
}

public class Cylinder {
    private static final float pi = 3.14f;

    public float surfaceAreaOfCylinder(float radiusOfCylinder, float heightOfCylinder) {
        return (2 * pi * radiusOfCylinder * radiusOfCylinder) + (heightOfCylinder * 2 * pi * radiusOfCylinder);
    }
}


public class Main {

    public static void main(String[] args) {
        int number = 10;
        var check = new EvenOdd();
        check.evenOdd(number);

        var cylinder = new Cylinder();
        float area = cylinder.surfaceAreaOfCylinder(5, 6);
        System.out.println("surface Area of Cylinder is " + area);
    }
}

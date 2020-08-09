package com.sumeetbalwade;

import java.util.Scanner;

public class Overriding {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Radius of Cylinder ");
        float radius = scanner.nextFloat();
        System.out.println("Enter Height of Cylinder ");
        float height = scanner.nextFloat();

        var cylinder = new Cylinder(radius,height);
        cylinder.show();
    }
}

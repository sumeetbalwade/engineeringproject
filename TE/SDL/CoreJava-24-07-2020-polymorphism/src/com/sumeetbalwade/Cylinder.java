package com.sumeetbalwade;

public class Cylinder extends Shape {
    private float radius;
    private float height;

    public Cylinder(float radius, float height) {
        this.radius = radius;
        this.height = height;
    }

    private float areaOfCylinder() {
        return (float) ((2 * 3.14 * radius * height) + (2 * 3.14 * radius * radius));
    }

    @Override
    public void show(){
        System.out.println("Area of Cylinder is : " + areaOfCylinder());
    }


}
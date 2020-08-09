package com.sumeetbalwade;

public class Employee {
    protected int id;
    protected String name;
    protected float salary;

    public Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void show() {
        System.out.println("Id : " + id);
        System.out.println("Name : " + name);
        System.out.println("salary : " + salary);
    }
}

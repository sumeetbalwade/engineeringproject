package com.sumeetbalwade;

public class Main {

    public static void main(String[] args) {
        var employee1 = new FullTimeEmployee(101,"Sschin",10_000,1_500,15);
        employee1.show();

        var employee2 = new PartTimeEmployee(103,"Ayush",1_000,5);
        employee2.show();
    }
}

package com.sumeetbalwade;

import java.util.Scanner;

public class Student {
    private byte rollNo;
    private String name;
    private String mobileNumber;

    public void input() {
        var scanner = new Scanner(System.in);
        System.out.print("\n\n\t\t\tENTER STUDENTS DETAILS");
        System.out.print("\n\t Roll No : ");
        rollNo = scanner.nextByte();
        scanner.nextLine();

        System.out.print("\n\t Name : ");
        name = scanner.nextLine();

        System.out.print("\n\t Mobile Number : ");
        mobileNumber = scanner.nextLine();

    }


    public void display() {
        System.out.print("\n\n\t\t\tENTER STUDENTS DETAILS");
        System.out.println("\n\t Roll No : " + rollNo);

        System.out.println("\n\t Name : " + name);

        System.out.println("\n\t Name : " + mobileNumber);

    }

}

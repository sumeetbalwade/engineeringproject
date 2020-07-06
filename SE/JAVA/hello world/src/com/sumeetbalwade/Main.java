package com.sumeetbalwade;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Customer> customer = new ArrayList<>();
        customer.add(new Customer("A"));
        customer.add(new Customer("C"));
        customer.add(new Customer("B"));
        for (Customer c : customer) {
            System.out.println(c.name);
        }
        Collections.sort(customer);
        System.out.println(customer);

    }
    public static void etx() {
        var obj = new Student();
        obj.input();
        obj.display();



    }
}

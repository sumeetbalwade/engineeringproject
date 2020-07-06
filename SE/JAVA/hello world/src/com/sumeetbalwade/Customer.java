package com.sumeetbalwade;

public class Customer implements  Comparable<Customer> {
    public String name;

    public Customer(String name) {
        this.name = name;
    }

    @Override
    public int compareTo(Customer o) {
        return name.compareTo(o.name);
    }

    @Override
    public String toString() {
        return name;
    }
}

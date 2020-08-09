package com.sumeetbalwade;

public class PartTimeEmployee extends Employee {
    private float hSalary;
    private int employeeHours;

    public PartTimeEmployee(int id, String name, float hSalary, int employeeHours) {
        super(id, name);
        this.hSalary = hSalary;
        this.employeeHours = employeeHours;
        this.salary = calculateSalary();
    }

    private float calculateSalary() {
        //fsalary is base amount and the extra depends on employee hours
        return hSalary * employeeHours;
    }
}

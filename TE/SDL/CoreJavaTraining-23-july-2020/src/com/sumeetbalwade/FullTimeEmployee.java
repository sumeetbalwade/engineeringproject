package com.sumeetbalwade;

public class FullTimeEmployee extends Employee {
    private float fSalary;
    private float hSalary;
    private int employeeHours;

    public FullTimeEmployee(int id, String name, float fSalary, float hSalary, int employeeHours) {
        super(id, name);
        this.fSalary = fSalary;
        this.hSalary = hSalary;
        this.employeeHours = employeeHours;
        this.salary = calculateSalary();

    }

    private float calculateSalary(){
        //fsalary is base amount and the extra depends on employee hours
        return fSalary + (hSalary * employeeHours);
    }

}

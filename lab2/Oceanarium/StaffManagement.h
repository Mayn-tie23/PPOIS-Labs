
#pragma once
#include <string>
#include "MarineAnimals.h"
#include "AquariumSystems.h"

class Task;

class Employee {
protected:
    int id;
    std::string name;
    double salary;
    int experienceYears;
    bool active;

public:
    Employee(int id, std::string name, double salary);

    virtual ~Employee() = default;

    int getId() const { return id; }
    void increaseSalary(double amount);
    void deactivate();
    bool canWork() const;
};

class Aquarist : public Employee {
private:
    int tanksMaintained;
    int animalsFed;

public:
    Aquarist(int id, std::string name, double salary);
    void feedAnimal(MarineAnimal& animal, double amount);
    void maintainTank(AquariumTank& tank, double water);
};

class Manager : public Employee {
private:
    int employeesManaged;
    int tasksAssigned;

public:
    Manager(int id, std::string name, double salary);
    void assignTask(Employee& employee, Task& task);
    void approveRaise(Employee& employee, double amount);
};

class MaintenanceWorker : public Employee {
private:
    int repairsCompleted;
    int equipmentInspected;

public:
    MaintenanceWorker(int id, std::string name, double salary);
    void cleanFilter(WaterFilter& filter);
    void inspectPump(WaterPump& pump);
};

class WorkSchedule {
private:
    int startHour;
    int endHour;
    int assignedEmployees;
    bool active;

public:
    WorkSchedule(int startHour, int endHour);
    void assignEmployee(Employee& employee);
    int calculateHours() const;
    void cancel();
};

class Department {
private:
    std::string name;
    double budget;
    int employeeCount;
    bool operational;

public:
    Department(std::string name, double budget);
    void hire(Employee& employee);
    void allocateBudget(double amount);
    void close();
};

class Task {
private:
    std::string description;
    int priority;
    int assignedEmployeeId;
    bool completed;

public:
    Task(std::string description, int priority);
    void assignTo(Employee& employee);
    void complete();
    void changePriority(int value);
};



#pragma once
#include <string>
#include "MarineAnimals.h"
#include "AnimalCare.h"
#include "VisitorManagement.h"

class Equipment;

class Oceanarium {
private:
    std::string name;
    double budget;
    int animalCount;
    int visitorCount;
    bool operational;

public:
    Oceanarium(std::string name, double budget);
    void admitVisitor(Visitor& visitor);
    void registerAnimal(MarineAnimal& animal);
    void allocateFunds(double amount);
    void close();
};

class Inventory {
private:
    int itemCount;
    double totalValue;
    int capacity;

public:
    Inventory();
    void addFood(Food& food, double quantity);
    void registerEquipment(Equipment& equipment);
    void removeItem();
};

class Supplier {
private:
    int id;
    std::string name;
    int deliveriesCompleted;
    int reliability;

public:
    Supplier(int id, std::string name);
    void deliverFood(Food& food, double quantity);
    void recordFailure();
    void improveReliability();
};

class Equipment {
private:
    int id;
    std::string name;
    double value;
    int condition;
    bool operational;

public:
    Equipment(int id, std::string name, double value);
    void use(int wear);
    void repair();
    void decommission();
    bool isOperational() const;
    double getValue() const;
};

class MaintenanceRecord {
private:
    int id;
    int repairCount;
    double totalCost;
    bool completed;

public:
    MaintenanceRecord(int id);
    void recordRepair(Equipment& equipment, double cost);
    void reset();
};

class Expense {
private:
    std::string category;
    double amount;
    bool approved;

public:
    Expense(std::string category, double amount);
    void approve();
    void reject();
    double getAmount() const;
    bool isApproved() const;
};

class Revenue {
private:
    std::string source;
    double amount;
    bool recorded;

public:
    Revenue(std::string source, double amount);
    void record();
    void increase(double value);
    double getAmount() const;
};

class FinanceManager {
private:
    double balance;
    double totalExpenses;
    double totalRevenue;
    int transactions;

public:
    FinanceManager(double initialBalance);
    void payExpense(Expense& expense);
    void receiveRevenue(Revenue& revenue);
    void purchaseEquipment(Equipment& equipment);
    double calculateProfit() const;
};


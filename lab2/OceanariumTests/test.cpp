
#include "pch.h"
#include <gtest/gtest.h>
#include "../Oceanarium/MarineAnimals.h"
#include "../Oceanarium/AquariumSystems.h"
#include "../Oceanarium/AnimalCare.h"
#include "../Oceanarium/StaffManagement.h"
#include "../Oceanarium/VisitorManagement.h"
#include "../Oceanarium/OperationsFinance.h"

TEST(MarineAnimalTest, ValidAnimal) {
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    SUCCEED();
}

TEST(MarineAnimalTest, InvalidAnimal) {
    EXPECT_ANY_THROW(
        MarineAnimal(0, "Nemo", 3, 10.0)
    );
}

TEST(MarineAnimalTest, RejectNegativeAge) {
    EXPECT_ANY_THROW(
        MarineAnimal(1, "Nemo", -2, 10.0)
    );
}

TEST(MarineAnimalTest, RejectNegativeWeight) {
    EXPECT_ANY_THROW(
        MarineAnimal(1, "Nemo", 3, -10.0)
    );
}

TEST(MarineAnimalTest, FeedValidAmount) {
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(animal.feed(2.0));
}

TEST(MarineAnimalTest, RejectInvalidFeeding) {
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_ANY_THROW(animal.feed(-5.0));
}
TEST(AquariumTankTest, ValidTank) {
    EXPECT_NO_THROW(AquariumTank(1, 1000.0));
}

TEST(AquariumTankTest, RejectInvalidCapacity) {
    EXPECT_ANY_THROW(AquariumTank(1, -100.0));
}

TEST(AquariumTankTest, FillTank) {
    AquariumTank tank(1, 1000.0);
    EXPECT_NO_THROW(tank.fill(500.0));
}

TEST(AquariumTankTest, RejectOverflow) {
    AquariumTank tank(1, 1000.0);
    EXPECT_ANY_THROW(tank.fill(1500.0));
}
TEST(AnimalCareTest, CreateFeedingSchedule) {
    EXPECT_NO_THROW(FeedingSchedule(9, 2.0));
}

TEST(AnimalCareTest, CalculateDietPortion) {
    Diet diet("Balanced", 6.0);
    EXPECT_DOUBLE_EQ(diet.calculatePortion(), 3.0);
}

TEST(AnimalCareTest, RestockFood) {
    Food food("FishFood", 10.0);
    EXPECT_NO_THROW(food.restock(5.0));
}

TEST(AnimalCareTest, StartHealthMonitoring) {
    AnimalHealthMonitor monitor;
    EXPECT_NO_THROW(monitor.start());
}
TEST(StaffTest, CreateEmployee) {
    EXPECT_NO_THROW(Employee(1, "John", 2000.0));
}

TEST(StaffTest, RejectNegativeSalary) {
    EXPECT_ANY_THROW(Employee(1, "John", -500.0));
}

TEST(StaffTest, IncreaseSalary) {
    Employee employee(1, "John", 2000.0);
    EXPECT_NO_THROW(employee.increaseSalary(500.0));
}

TEST(StaffTest, DeactivateEmployee) {
    Employee employee(1, "John", 2000.0);
    employee.deactivate();
    EXPECT_FALSE(employee.canWork());
}

TEST(VisitorTest, CreateVisitor) {
    EXPECT_NO_THROW(Visitor(1, "Mary", 20));
}

TEST(VisitorTest, BanVisitor) {
    Visitor visitor(1, "Mary", 20);
    visitor.ban();
    EXPECT_FALSE(visitor.canEnter());
}

TEST(TicketTest, ApplyDiscount) {
    Ticket ticket(1, 100.0);
    ticket.applyDiscount(20.0);
    EXPECT_DOUBLE_EQ(ticket.getPrice(), 80.0);
}

TEST(TicketTest, RejectNegativePrice) {
    EXPECT_ANY_THROW(Ticket(1, -50.0));
}

TEST(FinanceTest, CreateOceanarium) {
    EXPECT_NO_THROW(Oceanarium("Blue Ocean", 10000.0));
}

TEST(FinanceTest, RejectNegativeBudget) {
    EXPECT_ANY_THROW(Oceanarium("Blue Ocean", -100.0));
}

TEST(FinanceTest, CreateEquipment) {
    Equipment equipment(1, "Pump", 500.0);
    EXPECT_TRUE(equipment.isOperational());
}

TEST(FinanceTest, DecommissionEquipment) {
    Equipment equipment(1, "Pump", 500.0);
    equipment.decommission();
    EXPECT_FALSE(equipment.isOperational());
}

TEST(FinanceTest, RepairEquipment) {
    Equipment equipment(1, "Pump", 500.0);
    equipment.decommission();
    equipment.repair();
    EXPECT_TRUE(equipment.isOperational());
}

TEST(FinanceTest, ApproveExpense) {
    Expense expense("Maintenance", 200.0);
    expense.approve();
    EXPECT_TRUE(expense.isApproved());
}

TEST(FinanceTest, RejectInvalidRevenue) {
    EXPECT_ANY_THROW(Revenue("Tickets", -100.0));
}

TEST(FinanceTest, CalculateProfit) {
    FinanceManager manager(1000.0);
    Revenue revenue("Tickets", 500.0);
    Expense expense("Food", 200.0);

    expense.approve();
    manager.receiveRevenue(revenue);
    manager.payExpense(expense);

    EXPECT_DOUBLE_EQ(manager.calculateProfit(), 300.0);
}


#include "OperationsFinance.h"
#include "OceanariumExceptions.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

// Oceanarium

Oceanarium::Oceanarium(std::string name, double budget)
    : name(std::move(name)), budget(budget),
    animalCount(0), visitorCount(0), operational(true) {
    if (this->name.empty() || budget < 0)
        throw std::invalid_argument("Invalid oceanarium");
}

void Oceanarium::admitVisitor(Visitor& visitor) {
    if (!operational || !visitor.canEnter())
        throw std::logic_error("Admission unavailable");

    visitor.enter();
    visitorCount++;
}

void Oceanarium::registerAnimal(MarineAnimal& animal) {
    if (!operational)
        throw std::logic_error("Oceanarium is closed");

    if (!animal.isHealthy())
        throw InvalidAnimalException();

    animalCount++;
}

void Oceanarium::allocateFunds(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Invalid allocation");

    if (amount > budget)
        throw InsufficientFundsException();

    budget -= amount;
}

void Oceanarium::close() {
    operational = false;
}

// Inventory

Inventory::Inventory()
    : itemCount(0), totalValue(0), capacity(1000) {
}

void Inventory::addFood(Food& food, double quantity) {
    if (quantity <= 0 || itemCount >= capacity)
        throw std::invalid_argument("Invalid inventory addition");

    food.restock(quantity);
    itemCount++;
    totalValue += quantity;
}

void Inventory::registerEquipment(Equipment& equipment) {
    if (!equipment.isOperational())
        throw EquipmentFailureException();

    if (itemCount >= capacity)
        throw std::logic_error("Inventory is full");

    itemCount++;
    totalValue += equipment.getValue();
}

void Inventory::removeItem() {
    if (itemCount <= 0)
        throw std::logic_error("Inventory is empty");

    itemCount--;
}

// Supplier

Supplier::Supplier(int id, std::string name)
    : id(id), name(std::move(name)),
    deliveriesCompleted(0), reliability(100) {
    if (id <= 0 || this->name.empty())
        throw std::invalid_argument("Invalid supplier");
}

void Supplier::deliverFood(Food& food, double quantity) {
    if (quantity <= 0)
        throw std::invalid_argument("Invalid delivery");

    food.restock(quantity);
    deliveriesCompleted++;
}

void Supplier::recordFailure() {
    reliability = std::max(0, reliability - 10);
}

void Supplier::improveReliability() {
    reliability = std::min(100, reliability + 5);
}

// Equipment

Equipment::Equipment(int id, std::string name, double value)
    : id(id), name(std::move(name)), value(value),
    condition(100), operational(true) {
    if (id <= 0 || this->name.empty() || value < 0)
        throw std::invalid_argument("Invalid equipment");
}

void Equipment::use(int wear) {
    if (!operational)
        throw EquipmentFailureException();

    if (wear <= 0)
        throw std::invalid_argument("Invalid equipment wear");

    condition = std::max(0, condition - wear);

    if (condition == 0)
        operational = false;
}

void Equipment::repair() {
    condition = 100;
    operational = true;
}

void Equipment::decommission() {
    operational = false;
}

bool Equipment::isOperational() const {
    return operational;
}

double Equipment::getValue() const {
    return value;
}

// MaintenanceRecord

MaintenanceRecord::MaintenanceRecord(int id)
    : id(id), repairCount(0),
    totalCost(0), completed(false) {
    if (id <= 0)
        throw std::invalid_argument("Invalid maintenance record");
}

void MaintenanceRecord::recordRepair(Equipment& equipment,
    double cost) {
    if (cost < 0)
        throw std::invalid_argument("Invalid repair cost");

    equipment.repair();
    repairCount++;
    totalCost += cost;
    completed = true;
}

void MaintenanceRecord::reset() {
    completed = false;
}

// Expense

Expense::Expense(std::string category, double amount)
    : category(std::move(category)), amount(amount),
    approved(false) {
    if (this->category.empty() || amount <= 0)
        throw std::invalid_argument("Invalid expense");
}

void Expense::approve() {
    approved = true;
}

void Expense::reject() {
    approved = false;
}

double Expense::getAmount() const {
    return amount;
}

bool Expense::isApproved() const {
    return approved;
}

// Revenue

Revenue::Revenue(std::string source, double amount)
    : source(std::move(source)), amount(amount),
    recorded(false) {
    if (this->source.empty() || amount <= 0)
        throw std::invalid_argument("Invalid revenue");
}

void Revenue::record() {
    if (recorded)
        throw std::logic_error("Revenue already recorded");

    recorded = true;
}

void Revenue::increase(double value) {
    if (value <= 0 || recorded)
        throw std::invalid_argument("Cannot change revenue");

    amount += value;
}

double Revenue::getAmount() const {
    return amount;
}

// FinanceManager

FinanceManager::FinanceManager(double initialBalance)
    : balance(initialBalance), totalExpenses(0),
    totalRevenue(0), transactions(0) {
    if (initialBalance < 0)
        throw std::invalid_argument("Invalid initial balance");
}

void FinanceManager::payExpense(Expense& expense) {
    if (!expense.isApproved())
        throw std::logic_error("Expense not approved");

    double amount = expense.getAmount();

    if (amount > balance)
        throw InsufficientFundsException();

    balance -= amount;
    totalExpenses += amount;
    transactions++;
}

void FinanceManager::receiveRevenue(Revenue& revenue) {
    revenue.record();

    double amount = revenue.getAmount();

    balance += amount;
    totalRevenue += amount;
    transactions++;
}

void FinanceManager::purchaseEquipment(Equipment& equipment) {
    if (!equipment.isOperational())
        throw EquipmentFailureException();

    double price = equipment.getValue();

    if (price > balance)
        throw InsufficientFundsException();

    balance -= price;
    totalExpenses += price;
    transactions++;
}

double FinanceManager::calculateProfit() const {
    return totalRevenue - totalExpenses;
}

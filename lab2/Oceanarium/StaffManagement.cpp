
#include "StaffManagement.h"
#include "OceanariumExceptions.h"
#include <stdexcept>
#include <utility>

// Employee

Employee::Employee(int id, std::string name, double salary)
    : id(id), name(std::move(name)), salary(salary),
    experienceYears(0), active(true) {
    if (id <= 0 || this->name.empty() || salary < 0)
        throw std::invalid_argument("Invalid employee data");
}

void Employee::increaseSalary(double amount) {
    if (!active)
        throw EmployeeUnavailableException();

    if (amount <= 0)
        throw std::invalid_argument("Invalid salary increase");

    salary += amount;
}

void Employee::deactivate() {
    active = false;
}

bool Employee::canWork() const {
    return active;
}

// Aquarist

Aquarist::Aquarist(int id, std::string name, double salary)
    : Employee(id, std::move(name), salary),
    tanksMaintained(0), animalsFed(0) {
}

void Aquarist::feedAnimal(MarineAnimal& animal, double amount) {
    if (!canWork())
        throw EmployeeUnavailableException();

    animal.feed(amount);
    animalsFed++;
}

void Aquarist::maintainTank(AquariumTank& tank, double water) {
    if (!canWork())
        throw EmployeeUnavailableException();

    tank.fill(water);
    tanksMaintained++;
}

// Manager

Manager::Manager(int id, std::string name, double salary)
    : Employee(id, std::move(name), salary),
    employeesManaged(0), tasksAssigned(0) {
}

void Manager::assignTask(Employee& employee, Task& task) {
    if (!canWork() || !employee.canWork())
        throw EmployeeUnavailableException();

    task.assignTo(employee);
    tasksAssigned++;
}

void Manager::approveRaise(Employee& employee, double amount) {
    if (!canWork() || !employee.canWork())
        throw EmployeeUnavailableException();

    employee.increaseSalary(amount);
}

// MaintenanceWorker

MaintenanceWorker::MaintenanceWorker(int id, std::string name, double salary)
    : Employee(id, std::move(name), salary),
    repairsCompleted(0), equipmentInspected(0) {
}

void MaintenanceWorker::cleanFilter(WaterFilter& filter) {
    if (!canWork())
        throw EmployeeUnavailableException();

    filter.clean();
    repairsCompleted++;
}

void MaintenanceWorker::inspectPump(WaterPump& pump) {
    if (!canWork())
        throw EmployeeUnavailableException();

    pump.stop();
    equipmentInspected++;
}

// WorkSchedule

WorkSchedule::WorkSchedule(int startHour, int endHour)
    : startHour(startHour), endHour(endHour),
    assignedEmployees(0), active(true) {
    if (startHour < 0 || endHour > 24 || startHour >= endHour)
        throw std::invalid_argument("Invalid working hours");
}

void WorkSchedule::assignEmployee(Employee& employee) {
    if (!active)
        throw std::logic_error("Work schedule is inactive");

    if (!employee.canWork())
        throw EmployeeUnavailableException();

    assignedEmployees++;
}

int WorkSchedule::calculateHours() const {
    return endHour - startHour;
}

void WorkSchedule::cancel() {
    active = false;
}

// Department

Department::Department(std::string name, double budget)
    : name(std::move(name)), budget(budget),
    employeeCount(0), operational(true) {
    if (this->name.empty() || budget < 0)
        throw std::invalid_argument("Invalid department");
}

void Department::hire(Employee& employee) {
    if (!operational)
        throw std::logic_error("Department is closed");

    if (!employee.canWork())
        throw EmployeeUnavailableException();

    employeeCount++;
}

void Department::allocateBudget(double amount) {
    if (amount <= 0 || amount > budget)
        throw std::invalid_argument("Invalid allocation");

    budget -= amount;
}

void Department::close() {
    operational = false;
}

// Task

Task::Task(std::string description, int priority)
    : description(std::move(description)), priority(priority),
    assignedEmployeeId(-1), completed(false) {
    if (this->description.empty() || priority < 1 || priority > 5)
        throw std::invalid_argument("Invalid task");
}

void Task::assignTo(Employee& employee) {
    if (!employee.canWork())
        throw EmployeeUnavailableException();

    assignedEmployeeId = employee.getId();
}

void Task::complete() {
    if (assignedEmployeeId == -1)
        throw std::logic_error("Task is not assigned");

    completed = true;
}

void Task::changePriority(int value) {
    if (value < 1 || value > 5)
        throw std::invalid_argument("Invalid priority");

    priority = value;
}

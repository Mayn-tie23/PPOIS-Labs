
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include "MarineAnimals.h"
#include "AquariumSystems.h"
#include "AnimalCare.h"
#include "StaffManagement.h"
#include "VisitorManagement.h"
#include "OperationsFinance.h"
#include "OceanariumExceptions.h"

using namespace std;

int number() {
    int x;
    while (!(cin >> x)) {
        if (cin.eof()) throw runtime_error("Input ended");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a number: ";
    }
    return x;
}

double amount() {
    double x;
    while (!(cin >> x)) {
        if (cin.eof()) throw runtime_error("Input ended");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter an amount: ";
    }
    return x;
}

int menu(const string& title, const string& options) {
    cout << "\n=== " << title << " ===\n" << options << "0. Back\nChoice: ";
    return number();
}

template <typename F>
void execute(F action) {
    try { action(); }
    catch (const exception& e) { cout << "Error: " << e.what() << '\n'; }
}

void runMarineAnimalsMenu() {
    MarineAnimal animal(1, "Nemo", 3, 10);
    Dolphin dolphin(2, "Flipper", 4, 100);
    Shark shark(3, "Bruce", 5, 200);
    Octopus octopus(4, "Ollie", 2, 15);

    int c;
    do {
        c = menu("MARINE ANIMALS",
            "1. Create animal\n2. Feed animal\n3. Train dolphin\n"
            "4. Shark hunting\n5. Octopus ink\n");

        execute([&] {
            switch (c) {
            case 1: {
                cout << "ID: "; int id = number();
                cout << "Name: "; string name; cin >> name;
                cout << "Age: "; int age = number();
                cout << "Weight: "; double weight = amount();
                animal = MarineAnimal(id, name, age, weight);
                cout << "Animal created.\n";
                break;
            }
            case 2:
                cout << "Food amount: ";
                animal.feed(amount());
                cout << "Animal fed.\n";
                break;
            case 3:
                dolphin.train();
                cout << "Dolphin trained.\n";
                break;
            case 4:
                shark.hunt();
                shark.restAfterHunt();
                cout << "Shark hunting completed.\n";
                break;
            case 5:
                octopus.releaseInk();
                cout << "Regeneration amount: ";
                octopus.regenerateInk(amount());
                cout << "Ink regenerated.\n";
                break;
            case 0: break;
            default: cout << "Invalid option.\n";
            }
            });
    } while (c != 0);
}

void runAquariumSystemsMenu() {
    AquariumTank tank(1, 1000);
    WaterQuality water;
    WaterFilter filter(500);
    TemperatureController temp(24);
    OxygenSystem oxygen;

    int c;
    do {
        c = menu("AQUARIUM SYSTEMS",
            "1. Tank\n2. Water quality\n3. Filter\n"
            "4. Temperature\n5. Oxygen\n");

        execute([&] {
            switch (c) {
            case 1: {
                int op = menu("TANK", "1. Fill\n2. Drain\n3. Add animal\n");
                if (op == 1) {
                    cout << "Liters: "; tank.fill(amount());
                }
                else if (op == 2) {
                    cout << "Liters: "; tank.drain(amount());
                }
                else if (op == 3) tank.addAnimal();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 2: {
                int op = menu("WATER", "1. Check\n2. Pollute\n3. Purify\n");
                if (op == 1) cout << (water.isSafe() ? "Safe\n" : "Unsafe\n");
                else if (op == 2) {
                    cout << "Pollution: "; water.pollute(amount());
                }
                else if (op == 3) {
                    cout << "Efficiency (0-1): "; water.purify(amount());
                }
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 3: {
                int op = menu("FILTER",
                    "1. Start\n2. Filter water\n3. Clean\n4. Stop\n");
                if (op == 1) filter.start();
                else if (op == 2) filter.filter(water);
                else if (op == 3) filter.clean();
                else if (op == 4) filter.stop();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 4: {
                int op = menu("TEMPERATURE",
                    "1. Start\n2. Regulate\n3. Stop\n");
                if (op == 1) temp.start();
                else if (op == 2) temp.regulate();
                else if (op == 3) temp.stop();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 5: {
                int op = menu("OXYGEN",
                    "1. Start\n2. Increase\n3. Stop\n");
                if (op == 1) oxygen.start();
                else if (op == 2) oxygen.increaseOxygen();
                else if (op == 3) oxygen.stop();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 0: break;
            default: cout << "Invalid option.\n";
            }
            });
    } while (c != 0);
}

void runAnimalCareMenu() {
    MarineAnimal animal(10, "CareAnimal", 3, 20);
    Veterinarian vet(1, "DrSmith");
    FeedingSchedule schedule(9, 2);
    Food food("FishFood", 100);
    Diet diet("Balanced", 6);
    Treatment treatment("Medicine", 1);
    AnimalHealthMonitor monitor;
    BreedingProgram breeding("Dolphin");

    int c;
    do {
        c = menu("ANIMAL CARE",
            "1. Feeding\n2. Diet\n3. Veterinary\n"
            "4. Health monitoring\n5. Breeding\n");

        execute([&] {
            switch (c) {
            case 1: {
                int op = menu("FEEDING", "1. Feed\n2. Reset\n");
                if (op == 1) schedule.feedAnimal(animal);
                else if (op == 2) schedule.reset();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 2: {
                int op = menu("DIET",
                    "1. Portion\n2. Change meals\n3. Feed\n4. Restock\n");
                if (op == 1) cout << "Portion: " << diet.calculatePortion() << '\n';
                else if (op == 2) {
                    cout << "Meals: "; diet.changeMeals(number());
                }
                else if (op == 3) diet.feed(animal, food);
                else if (op == 4) {
                    cout << "Quantity: "; food.restock(amount());
                }
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 3: {
                int op = menu("VETERINARY",
                    "1. Examine\n2. Treat\n3. Extend treatment\n");
                if (op == 1) vet.examine(animal);
                else if (op == 2) vet.treat(animal, treatment);
                else if (op == 3) {
                    cout << "Days: "; treatment.extend(number());
                }
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 4: {
                int op = menu("HEALTH",
                    "1. Start\n2. Check\n3. Stop\n");
                if (op == 1) monitor.start();
                else if (op == 2)
                    cout << (monitor.check(animal) ? "Healthy\n" : "Needs attention\n");
                else if (op == 3) monitor.stop();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 5: {
                int op = menu("BREEDING",
                    "1. Start\n2. Add pair\n3. Record birth\n4. Stop\n");
                if (op == 1) breeding.start();
                else if (op == 2) breeding.addPair();
                else if (op == 3) {
                    cout << "Offspring: "; breeding.recordBirth(number());
                }
                else if (op == 4) breeding.stop();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 0: break;
            default: cout << "Invalid option.\n";
            }
            });
    } while (c != 0);
}

void runStaffManagementMenu() {
    Employee employee(1, "Alex", 2500);
    Aquarist aquarist(2, "Sam", 2800);
    Manager manager(3, "Taylor", 4000);
    MaintenanceWorker worker(4, "Chris", 2600);
    WorkSchedule schedule(9, 17);
    Department department("AnimalCare", 10000);
    Task task("Inspect aquarium", 2);
    MarineAnimal animal(20, "Nemo", 2, 10);
    AquariumTank tank(2, 500);
    WaterFilter filter(300);
    WaterPump pump(50);

    int c;
    do {
        c = menu("STAFF MANAGEMENT",
            "1. Employees\n2. Schedules\n3. Departments\n4. Tasks\n");

        execute([&] {
            switch (c) {
            case 1: {
                int op = menu("EMPLOYEES",
                    "1. Raise\n2. Deactivate\n3. Feed animal\n"
                    "4. Maintain tank\n5. Clean filter\n6. Inspect pump\n");
                if (op == 1) {
                    cout << "Raise: "; manager.approveRaise(employee, amount());
                }
                else if (op == 2) employee.deactivate();
                else if (op == 3) {
                    cout << "Food: "; aquarist.feedAnimal(animal, amount());
                }
                else if (op == 4) {
                    cout << "Water: "; aquarist.maintainTank(tank, amount());
                }
                else if (op == 5) worker.cleanFilter(filter);
                else if (op == 6) worker.inspectPump(pump);
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 2: {
                int op = menu("SCHEDULE",
                    "1. Assign\n2. Calculate hours\n3. Cancel\n");
                if (op == 1) schedule.assignEmployee(employee);
                else if (op == 2)
                    cout << "Hours: " << schedule.calculateHours() << '\n';
                else if (op == 3) schedule.cancel();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 3: {
                int op = menu("DEPARTMENT",
                    "1. Hire\n2. Allocate budget\n3. Close\n");
                if (op == 1) department.hire(employee);
                else if (op == 2) {
                    cout << "Budget: "; department.allocateBudget(amount());
                }
                else if (op == 3) department.close();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 4: {
                int op = menu("TASK",
                    "1. Assign\n2. Change priority\n3. Complete\n");
                if (op == 1) manager.assignTask(employee, task);
                else if (op == 2) {
                    cout << "Priority: "; task.changePriority(number());
                }
                else if (op == 3) task.complete();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 0: break;
            default: cout << "Invalid option.\n";
            }
            });
    } while (c != 0);
}

void runVisitorManagementMenu() {
    Visitor visitor(1, "Jordan", 25);
    Ticket ticket(1, 50);
    Booking booking(1, 1);
    TourGuide guide(1, "Morgan");
    GuidedTour tour(1, 20);
    Exhibition exhibition("OceanLife", 100);
    Membership membership(1, 1);
    Payment payment(1, 50);

    int c;
    do {
        c = menu("VISITOR MANAGEMENT",
            "1. Visitors\n2. Tickets\n3. Bookings\n"
            "4. Tours\n5. Memberships\n");

        execute([&] {
            switch (c) {
            case 1: {
                int op = menu("VISITORS",
                    "1. Enter\n2. Ban\n3. Unban\n"
                    "4. Open exhibition\n5. Admit to exhibition\n");
                if (op == 1) visitor.enter();
                else if (op == 2) visitor.ban();
                else if (op == 3) visitor.unban();
                else if (op == 4) exhibition.openExhibition();
                else if (op == 5) exhibition.admitVisitor(visitor);
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 2: {
                int op = menu("TICKETS",
                    "1. Use\n2. Discount\n3. Refund\n4. Price\n5. Pay\n");
                if (op == 1) ticket.use(visitor);
                else if (op == 2) {
                    cout << "Discount %: "; ticket.applyDiscount(amount());
                }
                else if (op == 3) ticket.refund();
                else if (op == 4) cout << "Price: " << ticket.getPrice() << '\n';
                else if (op == 5) payment.payForTicket(ticket);
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 3: {
                int op = menu("BOOKINGS",
                    "1. Add ticket\n2. Confirm\n3. Cancel\n");
                if (op == 1) booking.addTicket();
                else if (op == 2) booking.confirm();
                else if (op == 3) booking.cancel();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 4: {
                int op = menu("TOURS",
                    "1. Add visitor\n2. Start\n3. Conduct\n4. Finish\n");
                if (op == 1) tour.addVisitor(visitor);
                else if (op == 2) tour.start();
                else if (op == 3) guide.conductTour(tour);
                else if (op == 4) guide.finishTour(tour);
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 5: {
                int op = menu("MEMBERSHIP",
                    "1. Earn points\n2. Redeem\n3. Deactivate\n");
                if (op == 1) {
                    cout << "Points: "; membership.earnPoints(number());
                }
                else if (op == 2) {
                    cout << "Points: "; membership.redeemPoints(number());
                }
                else if (op == 3) membership.deactivate();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 0: break;
            default: cout << "Invalid option.\n";
            }
            });
    } while (c != 0);
}

void runOperationsFinanceMenu() {
    Oceanarium oceanarium("BlueOcean", 100000);
    Inventory inventory;
    Supplier supplier(1, "OceanSupplies");
    Food food("FishFood", 100);
    Equipment equipment(1, "WaterPump", 1500);
    MaintenanceRecord maintenance(1);
    Expense expense("Maintenance", 500);
    Revenue revenue("TicketSales", 2000);
    FinanceManager finance(10000);
    Visitor visitor(5, "Guest", 20);
    MarineAnimal animal(5, "Fish", 2, 5);

    int c;
    do {
        c = menu("OPERATIONS AND FINANCE",
            "1. Inventory\n2. Suppliers\n3. Equipment\n"
            "4. Expenses\n5. Finance\n6. Oceanarium\n");

        execute([&] {
            switch (c) {
            case 1: {
                int op = menu("INVENTORY",
                    "1. Add food\n2. Register equipment\n3. Remove item\n");
                if (op == 1) {
                    cout << "Quantity: "; inventory.addFood(food, amount());
                }
                else if (op == 2) inventory.registerEquipment(equipment);
                else if (op == 3) inventory.removeItem();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 2: {
                int op = menu("SUPPLIERS",
                    "1. Deliver food\n2. Record failure\n3. Improve reliability\n");
                if (op == 1) {
                    cout << "Quantity: "; supplier.deliverFood(food, amount());
                }
                else if (op == 2) supplier.recordFailure();
                else if (op == 3) supplier.improveReliability();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 3: {
                int op = menu("EQUIPMENT",
                    "1. Use\n2. Repair\n3. Record maintenance\n4. Decommission\n");
                if (op == 1) {
                    cout << "Wear: "; equipment.use(number());
                }
                else if (op == 2) equipment.repair();
                else if (op == 3) {
                    cout << "Cost: "; maintenance.recordRepair(equipment, amount());
                }
                else if (op == 4) equipment.decommission();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 4: {
                int op = menu("EXPENSES",
                    "1. Approve\n2. Reject\n3. Pay\n4. Show amount\n");
                if (op == 1) expense.approve();
                else if (op == 2) expense.reject();
                else if (op == 3) finance.payExpense(expense);
                else if (op == 4)
                    cout << "Amount: " << expense.getAmount() << '\n';
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 5: {
                int op = menu("FINANCE",
                    "1. Record revenue\n2. Increase revenue\n"
                    "3. Receive revenue\n4. Profit\n5. Purchase equipment\n");
                if (op == 1) revenue.record();
                else if (op == 2) {
                    cout << "Amount: "; revenue.increase(amount());
                }
                else if (op == 3) finance.receiveRevenue(revenue);
                else if (op == 4)
                    cout << "Profit: " << finance.calculateProfit() << '\n';
                else if (op == 5) finance.purchaseEquipment(equipment);
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 6: {
                int op = menu("OCEANARIUM",
                    "1. Admit visitor\n2. Register animal\n"
                    "3. Allocate funds\n4. Close\n");
                if (op == 1) oceanarium.admitVisitor(visitor);
                else if (op == 2) oceanarium.registerAnimal(animal);
                else if (op == 3) {
                    cout << "Amount: "; oceanarium.allocateFunds(amount());
                }
                else if (op == 4) oceanarium.close();
                else if (op != 0) cout << "Invalid option.\n";
                break;
            }
            case 0: break;
            default: cout << "Invalid option.\n";
            }
            });
    } while (c != 0);
}

int main() {
    try {
        int choice;
        do {
            choice = menu("OCEANARIUM MANAGEMENT",
                "1. Marine Animals\n2. Aquarium Systems\n"
                "3. Animal Care\n4. Staff Management\n"
                "5. Visitor Management\n6. Operations and Finance\n");

            switch (choice) {
            case 1: runMarineAnimalsMenu(); break;
            case 2: runAquariumSystemsMenu(); break;
            case 3: runAnimalCareMenu(); break;
            case 4: runStaffManagementMenu(); break;
            case 5: runVisitorManagementMenu(); break;
            case 6: runOperationsFinanceMenu(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option.\n";
            }
        } while (choice != 0);
    }
    catch (const exception& e) {
        cerr << "Application error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

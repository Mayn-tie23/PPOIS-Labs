# Lab 2 — Oceanarium Management System

## Overview

A C++17 object-oriented Oceanarium management application with a console menu. It models marine animals, aquarium equipment, animal care, staffing, visitors, and financial operations. Domain logic is separated into the `Oceanarium/` source groups; the console entry point is `Oceanarium/Oceanarium.cpp`.

## Build and run

Requirements: Visual Studio 2022 C++ build tools, CMake 3.20+, and internet access on first configuration to obtain Google Test.

From the repository root:

```powershell
cmake -S lab2 -B lab2/build -G "Visual Studio 17 2022" -A x64
cmake --build lab2/build --config Debug
ctest --test-dir lab2/build -C Debug --output-on-failure
.\lab2\build\Debug\OceanariumApp.exe
```

## Implementation and design

- **Encapsulation:** fields and operations are organized into classes with public/private/protected access.
- **Inheritance:** specialized marine animals inherit from `MarineAnimal`; staff roles inherit from `Employee`.
- **Associations:** classes interact through typed fields and method parameters; details are listed below.
- **Exceptions:** custom exceptions represent domain-specific failures.
- **Testing:** `OceanariumTests/test.cpp` contains the original 30 Google Test cases. A previous Visual Studio run reported 30 passing; CMake CI and coverage results must be evaluated from their actual runs.

## Class summary (lecturer format)

Row format: `Class | number of fields | number of methods | related classes`. Methods count declared callable members, including constructors, not only unique behaviors.

| **Class** | **Fields** | **Methods** | **Associations (related classes)** |
|---|---:|---:|---|
| MarineAnimal | 4 | 5 | — |
| Fish | 3 | 3 | MarineAnimal (inheritance) |
| Shark | 3 | 4 | MarineAnimal (inheritance) |
| Dolphin | 3 | 4 | MarineAnimal (inheritance) |
| Whale | 3 | 3 | MarineAnimal (inheritance) |
| Jellyfish | 3 | 3 | MarineAnimal (inheritance) |
| Octopus | 3 | 4 | MarineAnimal (inheritance) |
| SeaTurtle | 3 | 3 | MarineAnimal (inheritance) |
| Seahorse | 3 | 3 | MarineAnimal (inheritance) |
| Stingray | 3 | 3 | MarineAnimal (inheritance) |
| AquariumTank | 5 | 4 | — |
| Habitat | 4 | 3 | — |
| WaterQuality | 5 | 4 | — |
| WaterFilter | 4 | 5 | `WaterQuality` |
| TemperatureController | 4 | 4 | — |
| OxygenSystem | 4 | 4 | — |
| LightingSystem | 4 | 5 | — |
| WaterPump | 4 | 4 | — |
| Veterinarian | 4 | 3 | `MarineAnimal`, `Treatment` |
| AnimalTrainer | 4 | 3 | `Dolphin` |
| FeedingSchedule | 3 | 3 | `MarineAnimal` |
| Food | 4 | 4 | — |
| Diet | 3 | 4 | `Food`, `MarineAnimal` |
| MedicalRecord | 4 | 4 | — |
| Treatment | 4 | 3 | `MarineAnimal` |
| AnimalHealthMonitor | 3 | 4 | `MarineAnimal` |
| BreedingProgram | 4 | 5 | — |
| Employee | 5 | 6 | — |
| Aquarist | 2 | 3 | `AquariumTank`, `MarineAnimal`, Employee (inheritance) |
| Manager | 2 | 3 | `Employee`, `Task` |
| MaintenanceWorker | 2 | 3 | `WaterFilter`, `WaterPump`, Employee (inheritance) |
| WorkSchedule | 4 | 4 | `Employee` |
| Department | 4 | 4 | `Employee` |
| Task | 4 | 4 | `Employee` |
| Visitor | 5 | 5 | — |
| Ticket | 4 | 5 | `Visitor` |
| Booking | 4 | 4 | — |
| TourGuide | 4 | 3 | `GuidedTour` |
| GuidedTour | 4 | 4 | `Visitor` |
| Exhibition | 4 | 4 | `Visitor` |
| Membership | 4 | 4 | — |
| Payment | 4 | 4 | `Ticket` |
| Oceanarium | 5 | 5 | `MarineAnimal`, `Visitor` |
| Inventory | 3 | 4 | `Equipment`, `Food` |
| Supplier | 4 | 4 | `Food` |
| Equipment | 5 | 6 | — |
| MaintenanceRecord | 4 | 3 | `Equipment` |
| Expense | 3 | 5 | — |
| Revenue | 3 | 4 | — |
| FinanceManager | 4 | 5 | `Equipment`, `Expense`, `Revenue` |
| OceanariumException | 0 | 1 | std::runtime_error (inheritance) |
| InvalidAnimalException | 0 | 1 | `OceanariumException` |
| AnimalNotFoundException | 0 | 1 | `OceanariumException` |
| TankCapacityException | 0 | 1 | `OceanariumException` |
| UnsafeWaterException | 0 | 1 | `OceanariumException` |
| FeedingException | 0 | 1 | `OceanariumException` |
| TreatmentException | 0 | 1 | `OceanariumException` |
| EmployeeUnavailableException | 0 | 1 | `Employee`, `OceanariumException` |
| InvalidTicketException | 0 | 1 | `OceanariumException` |
| BookingException | 0 | 1 | `Booking`, `OceanariumException` |
| EquipmentFailureException | 0 | 1 | `Oceanarium`, `OceanariumException` |
| InsufficientFundsException | 0 | 1 | `OceanariumException` |

### Exceptions (12)

- `OceanariumException`
- `InvalidAnimalException`
- `AnimalNotFoundException`
- `TankCapacityException`
- `UnsafeWaterException`
- `FeedingException`
- `TreatmentException`
- `EmployeeUnavailableException`
- `InvalidTicketException`
- `BookingException`
- `EquipmentFailureException`
- `InsufficientFundsException`

### Summary statistics

| **Metric** | **Value** |
|---|---:|
| Classes (including exceptions) | 62 |
| Declared fields | 185 |
| Declared methods (including constructors) | 209 |
| Exception classes | 12 |
| Unique domain behaviors | Not independently verified |
| Distinct class associations | Not independently verified |

## Detailed class reference

The inventory below is derived from the declarations in the project's header files. Fields include declared data members; methods include declared constructors and other functions. Forward declarations are excluded. Associations list other project classes mentioned in a class's field or method declarations, and inheritance is listed separately.


### MarineAnimals


#### `MarineAnimal`

- **Fields (4):** `int id`, `std::string name`, `int age`, `double weight`

- **Methods:** `MarineAnimal(int id, std::string name, int age, double weight)`, `void feed(double amount)`, `void grow(double amount)`, `bool isHealthy() const`, `void loseWeight(double amount)`

- **Associations:** None directly declared


#### `Fish`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `std::string species`, `double swimmingSpeed`, `bool freshwater`

- **Methods:** `Fish(int id, std::string name, int age, double weight)`, `void swim(double distance)`, `void changeSpeed(double speed)`

- **Associations:** None directly declared


#### `Shark`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `int teethCount`, `double huntingSpeed`, `bool hungry`

- **Methods:** `Shark(int id, std::string name, int age, double weight)`, `void hunt()`, `void replaceTeeth()`, `void restAfterHunt()`

- **Associations:** None directly declared


#### `Dolphin`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `int intelligenceLevel`, `bool trained`, `double energy`

- **Methods:** `Dolphin(int id, std::string name, int age, double weight)`, `void performTrick()`, `void train()`, `void rest(int hours)`

- **Associations:** None directly declared


#### `Whale`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `double lungCapacity`, `double diveDepth`, `bool migrating`

- **Methods:** `Whale(int id, std::string name, int age, double weight)`, `void dive(double depth)`, `void surface()`

- **Associations:** None directly declared


#### `Jellyfish`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `bool venomous`, `double tentacleLength`, `double glowIntensity`

- **Methods:** `Jellyfish(int id, std::string name, int age, double weight)`, `void glow()`, `void sting()`

- **Associations:** None directly declared


#### `Octopus`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `int tentacles`, `double inkLevel`, `bool camouflaged`

- **Methods:** `Octopus(int id, std::string name, int age, double weight)`, `void releaseInk()`, `void camouflage()`, `void regenerateInk(double amount)`

- **Associations:** None directly declared


#### `SeaTurtle`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `double shellStrength`, `double swimmingSpeed`, `bool nesting`

- **Methods:** `SeaTurtle(int id, std::string name, int age, double weight)`, `void layEggs()`, `void swim()`

- **Associations:** None directly declared


#### `Seahorse`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `bool pregnant`, `int offspringCount`, `double tailStrength`

- **Methods:** `Seahorse(int id, std::string name, int age, double weight)`, `void reproduce()`, `void gripPlant()`

- **Associations:** None directly declared


#### `Stingray`

- **Inherits from:** `MarineAnimal`

- **Fields (3):** `double wingspan`, `bool venomous`, `double energy`

- **Methods:** `Stingray(int id, std::string name, int age, double weight)`, `void glide()`, `void defend()`

- **Associations:** None directly declared


### AquariumSystems


#### `AquariumTank`

- **Fields (5):** `int id`, `double capacity`, `double waterVolume`, `int animalCount`, `bool operational`

- **Methods:** `AquariumTank(int id, double capacity)`, `void fill(double liters)`, `void drain(double liters)`, `void addAnimal()`

- **Associations:** None directly declared


#### `Habitat`

- **Fields (4):** `std::string name`, `double minTemperature`, `double maxTemperature`, `double salinity`

- **Methods:** `Habitat(std::string name, double minTemp, double maxTemp)`, `bool supportsTemperature(double temperature) const`, `void adjustSalinity(double value)`

- **Associations:** None directly declared


#### `WaterQuality`

- **Fields (5):** `double ph`, `double oxygen`, `double ammonia`, `double nitrate`, `double clarity`

- **Methods:** `WaterQuality()`, `bool isSafe() const`, `void pollute(double amount)`, `void purify(double efficiency)`

- **Associations:** None directly declared


#### `WaterFilter`

- **Fields (4):** `double capacity`, `double efficiency`, `double dirtLevel`, `bool active`

- **Methods:** `WaterFilter(double capacity)`, `void start()`, `void stop()`, `void clean()`, `void filter(WaterQuality& water)`

- **Associations:** `WaterQuality`


#### `TemperatureController`

- **Fields (4):** `double targetTemperature`, `double currentTemperature`, `double heatingPower`, `bool active`

- **Methods:** `TemperatureController(double target)`, `void start()`, `void stop()`, `void regulate()`

- **Associations:** None directly declared


#### `OxygenSystem`

- **Fields (4):** `double oxygenLevel`, `double targetLevel`, `double productionRate`, `bool active`

- **Methods:** `OxygenSystem()`, `void start()`, `void stop()`, `void increaseOxygen()`

- **Associations:** None directly declared


#### `LightingSystem`

- **Fields (4):** `int brightness`, `int dailyHours`, `double energyConsumption`, `bool active`

- **Methods:** `LightingSystem()`, `void turnOn()`, `void turnOff()`, `void setBrightness(int value)`, `void simulateHour()`

- **Associations:** None directly declared


#### `WaterPump`

- **Fields (4):** `double flowRate`, `double totalPumped`, `double energyUsed`, `bool active`

- **Methods:** `WaterPump(double flowRate)`, `void start()`, `void stop()`, `void pump(double hours)`

- **Associations:** None directly declared


### AnimalCare


#### `Veterinarian`

- **Fields (4):** `int id`, `std::string name`, `int experienceYears`, `int patientsTreated`

- **Methods:** `Veterinarian(int id, std::string name)`, `void examine(MarineAnimal& animal)`, `void treat(MarineAnimal& animal, Treatment& treatment)`

- **Associations:** `MarineAnimal`, `Treatment`


#### `AnimalTrainer`

- **Fields (4):** `int id`, `std::string name`, `int experienceYears`, `int sessionsCompleted`

- **Methods:** `AnimalTrainer(int id, std::string name)`, `void trainDolphin(Dolphin& dolphin)`, `void conductSession(Dolphin& dolphin, int minutes)`

- **Associations:** `Dolphin`


#### `FeedingSchedule`

- **Fields (3):** `int feedingHour`, `double portionSize`, `bool completed`

- **Methods:** `FeedingSchedule(int hour, double portion)`, `void feedAnimal(MarineAnimal& animal)`, `void reset()`

- **Associations:** `MarineAnimal`


#### `Food`

- **Fields (4):** `std::string name`, `double quantity`, `double caloriesPerUnit`, `bool fresh`

- **Methods:** `Food(std::string name, double quantity)`, `void consume(double amount)`, `void restock(double amount)`, `void spoil()`

- **Associations:** None directly declared


#### `Diet`

- **Fields (3):** `std::string type`, `double dailyAmount`, `int mealsPerDay`

- **Methods:** `Diet(std::string type, double dailyAmount)`, `double calculatePortion() const`, `void changeMeals(int meals)`, `void feed(MarineAnimal& animal, Food& food)`

- **Associations:** `Food`, `MarineAnimal`


#### `MedicalRecord`

- **Fields (4):** `int animalId`, `std::string diagnosis`, `int treatmentCount`, `bool recovered`

- **Methods:** `MedicalRecord(int animalId)`, `void diagnose(std::string condition)`, `void recordTreatment()`, `void markRecovered()`

- **Associations:** None directly declared


#### `Treatment`

- **Fields (4):** `std::string medicine`, `double dosage`, `int durationDays`, `bool completed`

- **Methods:** `Treatment(std::string medicine, double dosage)`, `void apply(MarineAnimal& animal)`, `void extend(int days)`

- **Associations:** `MarineAnimal`


#### `AnimalHealthMonitor`

- **Fields (3):** `int checkCount`, `int alertCount`, `bool monitoringActive`

- **Methods:** `AnimalHealthMonitor()`, `bool check(MarineAnimal& animal)`, `void start()`, `void stop()`

- **Associations:** `MarineAnimal`


#### `BreedingProgram`

- **Fields (4):** `std::string species`, `int breedingPairs`, `int offspringBorn`, `bool active`

- **Methods:** `BreedingProgram(std::string species)`, `void start()`, `void stop()`, `void addPair()`, `void recordBirth(int offspring)`

- **Associations:** None directly declared


### StaffManagement


#### `Employee`

- **Fields (5):** `int id`, `std::string name`, `double salary`, `int experienceYears`, `bool active`

- **Methods:** `Employee(int id, std::string name, double salary)`, `virtual ~Employee() = default`, `int getId() const { return id`, `} void increaseSalary(double amount)`, `void deactivate()`, `bool canWork() const`

- **Associations:** None directly declared


#### `Aquarist`

- **Inherits from:** `Employee`

- **Fields (2):** `int tanksMaintained`, `int animalsFed`

- **Methods:** `Aquarist(int id, std::string name, double salary)`, `void feedAnimal(MarineAnimal& animal, double amount)`, `void maintainTank(AquariumTank& tank, double water)`

- **Associations:** `AquariumTank`, `MarineAnimal`


#### `Manager`

- **Inherits from:** `Employee`

- **Fields (2):** `int employeesManaged`, `int tasksAssigned`

- **Methods:** `Manager(int id, std::string name, double salary)`, `void assignTask(Employee& employee, Task& task)`, `void approveRaise(Employee& employee, double amount)`

- **Associations:** `Employee`, `Task`


#### `MaintenanceWorker`

- **Inherits from:** `Employee`

- **Fields (2):** `int repairsCompleted`, `int equipmentInspected`

- **Methods:** `MaintenanceWorker(int id, std::string name, double salary)`, `void cleanFilter(WaterFilter& filter)`, `void inspectPump(WaterPump& pump)`

- **Associations:** `WaterFilter`, `WaterPump`


#### `WorkSchedule`

- **Fields (4):** `int startHour`, `int endHour`, `int assignedEmployees`, `bool active`

- **Methods:** `WorkSchedule(int startHour, int endHour)`, `void assignEmployee(Employee& employee)`, `int calculateHours() const`, `void cancel()`

- **Associations:** `Employee`


#### `Department`

- **Fields (4):** `std::string name`, `double budget`, `int employeeCount`, `bool operational`

- **Methods:** `Department(std::string name, double budget)`, `void hire(Employee& employee)`, `void allocateBudget(double amount)`, `void close()`

- **Associations:** `Employee`


#### `Task`

- **Fields (4):** `std::string description`, `int priority`, `int assignedEmployeeId`, `bool completed`

- **Methods:** `Task(std::string description, int priority)`, `void assignTo(Employee& employee)`, `void complete()`, `void changePriority(int value)`

- **Associations:** `Employee`


### VisitorManagement


#### `Visitor`

- **Fields (5):** `int id`, `std::string name`, `int age`, `int visits`, `bool banned`

- **Methods:** `Visitor(int id, std::string name, int age)`, `void enter()`, `void ban()`, `void unban()`, `bool canEnter() const`

- **Associations:** None directly declared


#### `Ticket`

- **Fields (4):** `int id`, `double price`, `bool used`, `bool refunded`

- **Methods:** `Ticket(int id, double price)`, `void use(Visitor& visitor)`, `void refund()`, `void applyDiscount(double percent)`, `double getPrice() const`

- **Associations:** `Visitor`


#### `Booking`

- **Fields (4):** `int id`, `int visitorId`, `int ticketCount`, `bool confirmed`

- **Methods:** `Booking(int id, int visitorId)`, `void addTicket()`, `void confirm()`, `void cancel()`

- **Associations:** None directly declared


#### `TourGuide`

- **Fields (4):** `int id`, `std::string name`, `int experienceYears`, `int toursCompleted`

- **Methods:** `TourGuide(int id, std::string name)`, `void conductTour(GuidedTour& tour)`, `void finishTour(GuidedTour& tour)`

- **Associations:** `GuidedTour`


#### `GuidedTour`

- **Fields (4):** `int id`, `int maxVisitors`, `int currentVisitors`, `bool active`

- **Methods:** `GuidedTour(int id, int maxVisitors)`, `void addVisitor(Visitor& visitor)`, `void start()`, `void finish()`

- **Associations:** `Visitor`


#### `Exhibition`

- **Fields (4):** `std::string name`, `int capacity`, `int visitorCount`, `bool open`

- **Methods:** `Exhibition(std::string name, int capacity)`, `void openExhibition()`, `void closeExhibition()`, `void admitVisitor(Visitor& visitor)`

- **Associations:** `Visitor`


#### `Membership`

- **Fields (4):** `int id`, `int visitorId`, `int points`, `bool active`

- **Methods:** `Membership(int id, int visitorId)`, `void earnPoints(int amount)`, `void redeemPoints(int amount)`, `void deactivate()`

- **Associations:** None directly declared


#### `Payment`

- **Fields (4):** `int id`, `double amount`, `bool processed`, `bool refunded`

- **Methods:** `Payment(int id, double amount)`, `void process()`, `void refund()`, `void payForTicket(Ticket& ticket)`

- **Associations:** `Ticket`


### OperationsFinance


#### `Oceanarium`

- **Fields (5):** `std::string name`, `double budget`, `int animalCount`, `int visitorCount`, `bool operational`

- **Methods:** `Oceanarium(std::string name, double budget)`, `void admitVisitor(Visitor& visitor)`, `void registerAnimal(MarineAnimal& animal)`, `void allocateFunds(double amount)`, `void close()`

- **Associations:** `MarineAnimal`, `Visitor`


#### `Inventory`

- **Fields (3):** `int itemCount`, `double totalValue`, `int capacity`

- **Methods:** `Inventory()`, `void addFood(Food& food, double quantity)`, `void registerEquipment(Equipment& equipment)`, `void removeItem()`

- **Associations:** `Equipment`, `Food`


#### `Supplier`

- **Fields (4):** `int id`, `std::string name`, `int deliveriesCompleted`, `int reliability`

- **Methods:** `Supplier(int id, std::string name)`, `void deliverFood(Food& food, double quantity)`, `void recordFailure()`, `void improveReliability()`

- **Associations:** `Food`


#### `Equipment`

- **Fields (5):** `int id`, `std::string name`, `double value`, `int condition`, `bool operational`

- **Methods:** `Equipment(int id, std::string name, double value)`, `void use(int wear)`, `void repair()`, `void decommission()`, `bool isOperational() const`, `double getValue() const`

- **Associations:** None directly declared


#### `MaintenanceRecord`

- **Fields (4):** `int id`, `int repairCount`, `double totalCost`, `bool completed`

- **Methods:** `MaintenanceRecord(int id)`, `void recordRepair(Equipment& equipment, double cost)`, `void reset()`

- **Associations:** `Equipment`


#### `Expense`

- **Fields (3):** `std::string category`, `double amount`, `bool approved`

- **Methods:** `Expense(std::string category, double amount)`, `void approve()`, `void reject()`, `double getAmount() const`, `bool isApproved() const`

- **Associations:** None directly declared


#### `Revenue`

- **Fields (3):** `std::string source`, `double amount`, `bool recorded`

- **Methods:** `Revenue(std::string source, double amount)`, `void record()`, `void increase(double value)`, `double getAmount() const`

- **Associations:** None directly declared


#### `FinanceManager`

- **Fields (4):** `double balance`, `double totalExpenses`, `double totalRevenue`, `int transactions`

- **Methods:** `FinanceManager(double initialBalance)`, `void payExpense(Expense& expense)`, `void receiveRevenue(Revenue& revenue)`, `void purchaseEquipment(Equipment& equipment)`, `double calculateProfit() const`

- **Associations:** `Equipment`, `Expense`, `Revenue`


### OceanariumExceptions


#### `OceanariumException`

- **Inherits from:** `std::runtime_error`

- **Fields (0):** None declared

- **Methods:** `explicit OceanariumException(const std::string& message) : std::runtime_error(message) {}`

- **Associations:** None directly declared


#### `InvalidAnimalException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `InvalidAnimalException() : OceanariumException("Invalid marine animal data") { }`

- **Associations:** `OceanariumException`


#### `AnimalNotFoundException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `AnimalNotFoundException() : OceanariumException("Marine animal not found") { }`

- **Associations:** `OceanariumException`


#### `TankCapacityException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `TankCapacityException() : OceanariumException("Aquarium tank capacity exceeded") { }`

- **Associations:** `OceanariumException`


#### `UnsafeWaterException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `UnsafeWaterException() : OceanariumException("Unsafe aquarium water conditions") { }`

- **Associations:** `OceanariumException`


#### `FeedingException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `FeedingException() : OceanariumException("Animal feeding operation failed") { }`

- **Associations:** `OceanariumException`


#### `TreatmentException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `TreatmentException() : OceanariumException("Animal treatment failed") { }`

- **Associations:** `OceanariumException`


#### `EmployeeUnavailableException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `EmployeeUnavailableException() : OceanariumException("Employee is unavailable") { }`

- **Associations:** `Employee`, `OceanariumException`


#### `InvalidTicketException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `InvalidTicketException() : OceanariumException("Invalid or unavailable ticket") { }`

- **Associations:** `OceanariumException`


#### `BookingException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `BookingException() : OceanariumException("Booking operation failed") { }`

- **Associations:** `Booking`, `OceanariumException`


#### `EquipmentFailureException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `EquipmentFailureException() : OceanariumException("Oceanarium equipment failure") { }`

- **Associations:** `Oceanarium`, `OceanariumException`


#### `InsufficientFundsException`

- **Inherits from:** `OceanariumException`

- **Fields (0):** None declared

- **Methods:** `InsufficientFundsException() : OceanariumException("Insufficient financial resources") { }`

- **Associations:** `OceanariumException`


## Exception classes

The exception hierarchy is declared in `Oceanarium/OceanariumExceptions.h`. `OceanariumException` is the common base exception; the other exception classes specialize it for animal validation, missing animals, tank capacity, water safety, feeding, treatment, employee availability, ticket validity, bookings, equipment failures, and insufficient funds. See the class reference for their exact constructors and inheritance.

## Repository organization

```text
lab2/
├── CMakeLists.txt
├── README.md
├── Oceanarium/           # Domain classes and console application
└── OceanariumTests/      # Google Test unit tests
.github/workflows/lab2-ci.yml
```

## Running automated checks

The repository contains a GitHub Actions workflow at `.github/workflows/lab2-ci.yml`. Review the workflow's run results for build, test, coverage, and static-analysis outcomes; the presence of a workflow file does not by itself establish that all checks have passed.

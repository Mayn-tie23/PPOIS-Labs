# Lab 2 — Oceanarium Management System

This C++17 project models marine animals, aquarium systems, animal care, staff, visitor services, and operational finances. The inventory is based on the Oceanarium header declarations. Method lists include constructors and accessors where declared.

## Requirement inventory

| Requirement | Current implementation |
|---|---:|
| Domain classes (excluding custom exceptions) | 50 |
| Custom exception classes | 12 |
| Declared data fields | 185 |
| Declared methods (including constructors and accessors) | 209 |
| Substantive domain behaviors (excluding constructors/getters/setters) | Not independently verified |
| Typed class associations (excluding inheritance) | Not independently verified |

The method total is **not** a count of unique domain behaviors. Inheritance is shown in the class inventory for clarity but is not counted as an association toward the 30-association requirement.

## Class inventory

| Class | Fields | Public/declared methods | Associations (related classes) |
|---|---:|---|---|
| `MarineAnimal` | 4 | MarineAnimal, feed, grow, isHealthy, loseWeight | — |
| `Fish` | 3 | Fish, swim, changeSpeed | MarineAnimal (inherits) |
| `Shark` | 3 | Shark, hunt, replaceTeeth, restAfterHunt | MarineAnimal (inherits) |
| `Dolphin` | 3 | Dolphin, performTrick, train, rest | MarineAnimal (inherits) |
| `Whale` | 3 | Whale, dive, surface | MarineAnimal (inherits) |
| `Jellyfish` | 3 | Jellyfish, glow, sting | MarineAnimal (inherits) |
| `Octopus` | 3 | Octopus, releaseInk, camouflage, regenerateInk | MarineAnimal (inherits) |
| `SeaTurtle` | 3 | SeaTurtle, layEggs, swim | MarineAnimal (inherits) |
| `Seahorse` | 3 | Seahorse, reproduce, gripPlant | MarineAnimal (inherits) |
| `Stingray` | 3 | Stingray, glide, defend | MarineAnimal (inherits) |
| `AquariumTank` | 5 | AquariumTank, fill, drain, addAnimal | — |
| `Habitat` | 4 | Habitat, supportsTemperature, adjustSalinity | — |
| `WaterQuality` | 5 | WaterQuality, isSafe, pollute, purify | — |
| `WaterFilter` | 4 | WaterFilter, start, stop, clean, filter | `WaterQuality` |
| `TemperatureController` | 4 | TemperatureController, start, stop, regulate | — |
| `OxygenSystem` | 4 | OxygenSystem, start, stop, increaseOxygen | — |
| `LightingSystem` | 4 | LightingSystem, turnOn, turnOff, setBrightness, simulateHour | — |
| `WaterPump` | 4 | WaterPump, start, stop, pump | — |
| `Veterinarian` | 4 | Veterinarian, examine, treat | `MarineAnimal`, `Treatment` |
| `AnimalTrainer` | 4 | AnimalTrainer, trainDolphin, conductSession | `Dolphin` |
| `FeedingSchedule` | 3 | FeedingSchedule, feedAnimal, reset | `MarineAnimal` |
| `Food` | 4 | Food, consume, restock, spoil | — |
| `Diet` | 3 | Diet, calculatePortion, changeMeals, feed | `Food`, `MarineAnimal` |
| `MedicalRecord` | 4 | MedicalRecord, diagnose, recordTreatment, markRecovered | — |
| `Treatment` | 4 | Treatment, apply, extend | `MarineAnimal` |
| `AnimalHealthMonitor` | 3 | AnimalHealthMonitor, check, start, stop | `MarineAnimal` |
| `BreedingProgram` | 4 | BreedingProgram, start, stop, addPair, recordBirth | — |
| `Employee` | 5 | Employee, ~Employee, getId, increaseSalary, deactivate, canWork | — |
| `Aquarist` | 2 | Aquarist, feedAnimal, maintainTank | `AquariumTank`, `MarineAnimal`, Employee (inherits) |
| `Manager` | 2 | Manager, assignTask, approveRaise | `Employee`, `Task` |
| `MaintenanceWorker` | 2 | MaintenanceWorker, cleanFilter, inspectPump | `WaterFilter`, `WaterPump`, Employee (inherits) |
| `WorkSchedule` | 4 | WorkSchedule, assignEmployee, calculateHours, cancel | `Employee` |
| `Department` | 4 | Department, hire, allocateBudget, close | `Employee` |
| `Task` | 4 | Task, assignTo, complete, changePriority | `Employee` |
| `Visitor` | 5 | Visitor, enter, ban, unban, canEnter | — |
| `Ticket` | 4 | Ticket, use, refund, applyDiscount, getPrice | `Visitor` |
| `Booking` | 4 | Booking, addTicket, confirm, cancel | — |
| `TourGuide` | 4 | TourGuide, conductTour, finishTour | `GuidedTour` |
| `GuidedTour` | 4 | GuidedTour, addVisitor, start, finish | `Visitor` |
| `Exhibition` | 4 | Exhibition, openExhibition, closeExhibition, admitVisitor | `Visitor` |
| `Membership` | 4 | Membership, earnPoints, redeemPoints, deactivate | — |
| `Payment` | 4 | Payment, process, refund, payForTicket | `Ticket` |
| `Oceanarium` | 5 | Oceanarium, admitVisitor, registerAnimal, allocateFunds, close | `MarineAnimal`, `Visitor` |
| `Inventory` | 3 | Inventory, addFood, registerEquipment, removeItem | `Equipment`, `Food` |
| `Supplier` | 4 | Supplier, deliverFood, recordFailure, improveReliability | `Food` |
| `Equipment` | 5 | Equipment, use, repair, decommission, isOperational, getValue | — |
| `MaintenanceRecord` | 4 | MaintenanceRecord, recordRepair, reset | `Equipment` |
| `Expense` | 3 | Expense, approve, reject, getAmount, isApproved | — |
| `Revenue` | 3 | Revenue, record, increase, getAmount | — |
| `FinanceManager` | 4 | FinanceManager, payExpense, receiveRevenue, purchaseEquipment, calculateProfit | `Equipment`, `Expense`, `Revenue` |
| `OceanariumException` | 0 | OceanariumException | std::runtime_error (inherits) |
| `InvalidAnimalException` | 0 | InvalidAnimalException | `OceanariumException` |
| `AnimalNotFoundException` | 0 | AnimalNotFoundException | `OceanariumException` |
| `TankCapacityException` | 0 | TankCapacityException | `OceanariumException` |
| `UnsafeWaterException` | 0 | UnsafeWaterException | `OceanariumException` |
| `FeedingException` | 0 | FeedingException | `OceanariumException` |
| `TreatmentException` | 0 | TreatmentException | `OceanariumException` |
| `EmployeeUnavailableException` | 0 | EmployeeUnavailableException | `Employee`, `OceanariumException` |
| `InvalidTicketException` | 0 | InvalidTicketException | `OceanariumException` |
| `BookingException` | 0 | BookingException | `Booking`, `OceanariumException` |
| `EquipmentFailureException` | 0 | EquipmentFailureException | `Oceanarium`, `OceanariumException` |
| `InsufficientFundsException` | 0 | InsufficientFundsException | `OceanariumException` |

## Custom exceptions (12)

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

## Build and test

Requires Visual Studio 2022 C++ build tools, CMake 3.20+, and internet access during the initial CMake configuration to retrieve Google Test. Run from the repository root:

```powershell
cmake -S lab2 -B lab2/build -G "Visual Studio 17 2022" -A x64
cmake --build lab2/build --config Debug
ctest --test-dir lab2/build -C Debug --output-on-failure
.\lab2\build\Debug\OceanariumApp.exe
```

## Tests and coverage

`OceanariumTests/test.cpp` contains 30 Google Test cases. The Visual Studio solution has been rebuilt and the 30 tests were reported passing. The separate CMake/CI coverage threshold and static analysis have not been verified by a successful CI run; their results should be taken from GitHub Actions rather than assumed.

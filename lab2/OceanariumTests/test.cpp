
#include "pch.h"
#include <gtest/gtest.h>
#include "../Oceanarium/MarineAnimals.h"
#include "../Oceanarium/AquariumSystems.h"
#include "../Oceanarium/AnimalCare.h"
#include "../Oceanarium/StaffManagement.h"
#include "../Oceanarium/VisitorManagement.h"
#include "../Oceanarium/OperationsFinance.h"
#include "../Oceanarium/OceanariumExceptions.h"

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


TEST(MarineAnimalTest, Grow) {
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(animal.grow(2.0));
}

TEST(MarineAnimalTest, LoseWeight) {
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(animal.loseWeight(2.0));
}

TEST(MarineAnimalTest, CheckHealth) {
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(animal.isHealthy());
}

TEST(FishTest, Swim) {
    Fish fish(2, "Goldfish", 2, 5.0);
    EXPECT_NO_THROW(fish.swim(10.0));
}

TEST(FishTest, ChangeSpeed) {
    Fish fish(2, "Goldfish", 2, 5.0);
    EXPECT_NO_THROW(fish.changeSpeed(3.0));
}

TEST(SharkTest, Hunt) {
    Shark shark(3, "Bruce", 5, 200.0);
    EXPECT_NO_THROW(shark.hunt());
}

TEST(SharkTest, ReplaceTeeth) {
    Shark shark(3, "Bruce", 5, 200.0);
    EXPECT_NO_THROW(shark.replaceTeeth());
}

TEST(SharkTest, RestAfterHunt) {
    Shark shark(3, "Bruce", 5, 200.0);
    EXPECT_THROW(shark.restAfterHunt(), std::logic_error);
}

TEST(DolphinTest, PerformTrick) {
    Dolphin dolphin(4, "Flipper", 4, 80.0);
    dolphin.train();
    EXPECT_NO_THROW(dolphin.performTrick());
}

TEST(DolphinTest, Train) {
    Dolphin dolphin(4, "Flipper", 4, 80.0);
    EXPECT_NO_THROW(dolphin.train());
}

TEST(DolphinTest, Rest) {
    Dolphin dolphin(4, "Flipper", 4, 80.0);
    EXPECT_NO_THROW(dolphin.rest(2));
}

TEST(WhaleTest, Dive) {
    Whale whale(5, "Blue", 10, 1000.0);
    EXPECT_NO_THROW(whale.dive(20.0));
}

TEST(WhaleTest, Surface) {
    Whale whale(5, "Blue", 10, 1000.0);
    EXPECT_NO_THROW(whale.surface());
}

TEST(JellyfishTest, Glow) {
    Jellyfish jellyfish(6, "Jelly", 1, 2.0);
    EXPECT_NO_THROW(jellyfish.glow());
}
TEST(JellyfishTest, Sting) {
    Jellyfish jellyfish(6, "Jelly", 1, 2.0);
    EXPECT_THROW(jellyfish.sting(), std::logic_error);
}


TEST(OctopusTest, ReleaseInk) {
    Octopus octopus(7, "Ollie", 3, 12.0);
    EXPECT_NO_THROW(octopus.releaseInk());
}

TEST(OctopusTest, Camouflage) {
    Octopus octopus(7, "Ollie", 3, 12.0);
    EXPECT_NO_THROW(octopus.camouflage());
}

TEST(OctopusTest, RegenerateInk) {
    Octopus octopus(7, "Ollie", 3, 12.0);
    EXPECT_NO_THROW(octopus.regenerateInk(10.0));
}

TEST(OctopusTest, RejectInvalidInk) {
    Octopus octopus(7, "Ollie", 3, 12.0);
    EXPECT_THROW(octopus.regenerateInk(-5.0), std::invalid_argument);
}

TEST(SeaTurtleTest, LayEggs) {
    SeaTurtle turtle(8, "Shelly", 5, 40.0);
    EXPECT_NO_THROW(turtle.layEggs());
}

TEST(SeaTurtleTest, RejectRepeatedNesting) {
    SeaTurtle turtle(8, "Shelly", 5, 40.0);
    turtle.layEggs();
    EXPECT_THROW(turtle.layEggs(), std::logic_error);
}

TEST(SeaTurtleTest, Swim) {
    SeaTurtle turtle(8, "Shelly", 5, 40.0);
    EXPECT_NO_THROW(turtle.swim());
}

TEST(SeahorseTest, Reproduce) {
    Seahorse seahorse(9, "Sunny", 2, 1.0);
    EXPECT_NO_THROW(seahorse.reproduce());
    EXPECT_NO_THROW(seahorse.reproduce());
}

TEST(SeahorseTest, GripPlant) {
    Seahorse seahorse(9, "Sunny", 2, 1.0);
    EXPECT_NO_THROW(seahorse.gripPlant());
}

TEST(StingrayTest, Glide) {
    Stingray stingray(10, "Ray", 4, 25.0);
    EXPECT_NO_THROW(stingray.glide());
}

TEST(StingrayTest, Defend) {
    Stingray stingray(10, "Ray", 4, 25.0);
    EXPECT_NO_THROW(stingray.defend());
}

TEST(StingrayTest, RejectLowEnergy) {
    Stingray stingray(10, "Ray", 4, 25.0);
    for (int i = 0; i < 20; ++i) {
        stingray.glide();
    }
    EXPECT_THROW(stingray.glide(), std::logic_error);
}


TEST(AquaristTest, FeedAnimal) {
    Aquarist aquarist(1, "John", 2000.0);
    MarineAnimal animal(2, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(aquarist.feedAnimal(animal, 2.0));
}

TEST(AquaristTest, RejectInactiveAquarist) {
    Aquarist aquarist(1, "John", 2000.0);
    MarineAnimal animal(2, "Nemo", 3, 10.0);
    aquarist.deactivate();
    EXPECT_ANY_THROW(aquarist.feedAnimal(animal, 2.0));
}

TEST(AquaristTest, MaintainTank) {
    Aquarist aquarist(1, "John", 2000.0);
    AquariumTank tank(1, 1000.0);
    EXPECT_NO_THROW(aquarist.maintainTank(tank, 200.0));
}

TEST(ManagerTest, ApproveRaise) {
    Manager manager(1, "Boss", 5000.0);
    Employee employee(2, "John", 2000.0);
    EXPECT_NO_THROW(manager.approveRaise(employee, 500.0));
}

TEST(ManagerTest, AssignTask) {
    Manager manager(1, "Boss", 5000.0);
    Employee employee(2, "John", 2000.0);
    Task task("Feed animals", 2);
    EXPECT_NO_THROW(manager.assignTask(employee, task));
}

TEST(MaintenanceWorkerTest, CleanFilter) {
    MaintenanceWorker worker(1, "Alex", 2000.0);
    WaterFilter filter(100.0);
    EXPECT_NO_THROW(worker.cleanFilter(filter));
}

TEST(WorkScheduleTest, CalculateHours) {
    WorkSchedule schedule(8, 16);
    EXPECT_EQ(schedule.calculateHours(), 8);
}

TEST(WorkScheduleTest, RejectInvalidHours) {
    EXPECT_THROW(WorkSchedule(18, 8), std::invalid_argument);
}

TEST(WorkScheduleTest, AssignEmployee) {
    WorkSchedule schedule(8, 16);
    Employee employee(1, "John", 2000.0);
    EXPECT_NO_THROW(schedule.assignEmployee(employee));
}

TEST(WorkScheduleTest, RejectCancelledSchedule) {
    WorkSchedule schedule(8, 16);
    Employee employee(1, "John", 2000.0);
    schedule.cancel();
    EXPECT_THROW(schedule.assignEmployee(employee), std::logic_error);
}

TEST(DepartmentTest, HireEmployee) {
    Department department("Marine Care", 10000.0);
    Employee employee(1, "John", 2000.0);
    EXPECT_NO_THROW(department.hire(employee));
}

TEST(DepartmentTest, AllocateBudget) {
    Department department("Marine Care", 10000.0);
    EXPECT_NO_THROW(department.allocateBudget(2000.0));
}

TEST(DepartmentTest, RejectInvalidBudget) {
    Department department("Marine Care", 10000.0);
    EXPECT_THROW(department.allocateBudget(20000.0), std::invalid_argument);
}

TEST(TaskTest, CompleteAssignedTask) {
    Employee employee(1, "John", 2000.0);
    Task task("Clean tank", 2);
    task.assignTo(employee);
    EXPECT_NO_THROW(task.complete());
}

TEST(TaskTest, RejectInvalidPriority) {
    Task task("Clean tank", 2);
    EXPECT_THROW(task.changePriority(10), std::invalid_argument);
}

TEST(ExceptionTest, UnsafeWater) {
    UnsafeWaterException e;
    EXPECT_STREQ(e.what(), "Unsafe aquarium water conditions");
}

TEST(ExceptionTest, Feeding) {
    FeedingException e;
    EXPECT_STREQ(e.what(), "Animal feeding operation failed");
}

TEST(ExceptionTest, Treatment) {
    TreatmentException e;
    EXPECT_STREQ(e.what(), "Animal treatment failed");
}

TEST(ExceptionTest, Booking) {
    BookingException e;
    EXPECT_STREQ(e.what(), "Booking operation failed");
}

TEST(ExceptionTest, EquipmentFailure) {
    EquipmentFailureException e;
    EXPECT_STREQ(e.what(), "Oceanarium equipment failure");
}

TEST(ExceptionTest, InsufficientFunds) {
    InsufficientFundsException e;
    EXPECT_STREQ(e.what(), "Insufficient financial resources");
}

TEST(OceanariumExtraTest, AdmitVisitor) {
    Oceanarium ocean("Blue Ocean", 10000.0);
    Visitor visitor(1, "Mary", 20);
    EXPECT_NO_THROW(ocean.admitVisitor(visitor));
}

TEST(OceanariumExtraTest, RejectBannedVisitor) {
    Oceanarium ocean("Blue Ocean", 10000.0);
    Visitor visitor(1, "Mary", 20);
    visitor.ban();
    EXPECT_THROW(ocean.admitVisitor(visitor), std::logic_error);
}

TEST(OceanariumExtraTest, RegisterAnimal) {
    Oceanarium ocean("Blue Ocean", 10000.0);
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(ocean.registerAnimal(animal));
}

TEST(OceanariumExtraTest, AllocateFunds) {
    Oceanarium ocean("Blue Ocean", 10000.0);
    EXPECT_NO_THROW(ocean.allocateFunds(500.0));
    EXPECT_THROW(ocean.allocateFunds(-10.0), std::invalid_argument);
    EXPECT_THROW(ocean.allocateFunds(20000.0), InsufficientFundsException);
}

TEST(OceanariumExtraTest, RejectAdmissionWhenClosed) {
    Oceanarium ocean("Blue Ocean", 10000.0);
    Visitor visitor(1, "Mary", 20);
    ocean.close();
    EXPECT_THROW(ocean.admitVisitor(visitor), std::logic_error);
}

TEST(InventoryExtraTest, AddFood) {
    Inventory inventory;
    Food food("FishFood", 10.0);
    EXPECT_NO_THROW(inventory.addFood(food, 5.0));
    EXPECT_THROW(inventory.addFood(food, -1.0), std::invalid_argument);
}

TEST(InventoryExtraTest, RegisterEquipment) {
    Inventory inventory;
    Equipment equipment(1, "Pump", 500.0);
    EXPECT_NO_THROW(inventory.registerEquipment(equipment));
    equipment.decommission();
    EXPECT_THROW(inventory.registerEquipment(equipment), EquipmentFailureException);
}

TEST(InventoryExtraTest, RemoveItem) {
    Inventory inventory;
    EXPECT_THROW(inventory.removeItem(), std::logic_error);
    Equipment equipment(1, "Pump", 500.0);
    inventory.registerEquipment(equipment);
    EXPECT_NO_THROW(inventory.removeItem());
}

TEST(SupplierExtraTest, DeliverFood) {
    Supplier supplier(1, "Ocean Foods");
    Food food("FishFood", 10.0);
    EXPECT_NO_THROW(supplier.deliverFood(food, 5.0));
    EXPECT_THROW(supplier.deliverFood(food, -2.0), std::invalid_argument);
}

TEST(SupplierExtraTest, Reliability) {
    Supplier supplier(1, "Ocean Foods");
    EXPECT_NO_THROW(supplier.recordFailure());
    EXPECT_NO_THROW(supplier.improveReliability());
}

TEST(EquipmentExtraTest, UseAndRepair) {
    Equipment equipment(1, "Pump", 500.0);
    equipment.use(100);
    EXPECT_FALSE(equipment.isOperational());
    EXPECT_THROW(equipment.use(5), EquipmentFailureException);
    equipment.repair();
    EXPECT_TRUE(equipment.isOperational());
}

TEST(MaintenanceExtraTest, RecordRepair) {
    Equipment equipment(1, "Pump", 500.0);
    MaintenanceRecord record(1);
    equipment.decommission();
    EXPECT_NO_THROW(record.recordRepair(equipment, 100.0));
    EXPECT_TRUE(equipment.isOperational());
    EXPECT_NO_THROW(record.reset());
}

TEST(ExpenseExtraTest, RejectExpense) {
    Expense expense("Food", 200.0);
    expense.approve();
    expense.reject();
    EXPECT_FALSE(expense.isApproved());
}

TEST(RevenueExtraTest, RecordRevenue) {
    Revenue revenue("Tickets", 500.0);
    EXPECT_NO_THROW(revenue.increase(100.0));
    EXPECT_NO_THROW(revenue.record());
    EXPECT_THROW(revenue.record(), std::logic_error);
    EXPECT_THROW(revenue.increase(50.0), std::invalid_argument);
}

TEST(FinanceManagerExtraTest, PurchaseEquipment) {
    FinanceManager manager(1000.0);
    Equipment equipment(1, "Pump", 500.0);
    EXPECT_NO_THROW(manager.purchaseEquipment(equipment));
    equipment.decommission();
    EXPECT_THROW(manager.purchaseEquipment(equipment), EquipmentFailureException);
}


TEST(AquariumExtraTest, DrainWater) {
    AquariumTank tank(1, 1000.0);
    tank.fill(500.0);
    EXPECT_NO_THROW(tank.drain(200.0));
}

TEST(AquariumExtraTest, RejectInvalidDrain) {
    AquariumTank tank(1, 1000.0);
    EXPECT_THROW(tank.drain(100.0), std::invalid_argument);
}

TEST(AquariumExtraTest, AddAnimalToEmptyTank) {
    AquariumTank tank(1, 1000.0);
    EXPECT_THROW(tank.addAnimal(), std::logic_error);
}

TEST(HabitatTest, ValidTemperature) {
    Habitat habitat("Tropical", 20.0, 30.0);
    EXPECT_TRUE(habitat.supportsTemperature(25.0));
    EXPECT_FALSE(habitat.supportsTemperature(35.0));
}

TEST(HabitatTest, InvalidTemperatureRange) {
    EXPECT_THROW(Habitat("Tropical", 30.0, 20.0), std::invalid_argument);
}

TEST(HabitatTest, AdjustSalinity) {
    Habitat habitat("Marine", 15.0, 30.0);
    EXPECT_NO_THROW(habitat.adjustSalinity(35.0));
    EXPECT_THROW(habitat.adjustSalinity(60.0), std::invalid_argument);
}

TEST(WaterQualityTest, CheckSafety) {
    WaterQuality water;
    EXPECT_TRUE(water.isSafe());
    water.pollute(1.0);
    EXPECT_FALSE(water.isSafe());
}

TEST(WaterQualityTest, PurifyWater) {
    WaterQuality water;
    water.pollute(1.0);
    water.purify(1.0);
    EXPECT_TRUE(water.isSafe());
}

TEST(WaterQualityTest, InvalidPollution) {
    WaterQuality water;
    EXPECT_THROW(water.pollute(-1.0), std::invalid_argument);
}

TEST(WaterQualityTest, InvalidEfficiency) {
    WaterQuality water;
    EXPECT_THROW(water.purify(2.0), std::invalid_argument);
}

TEST(WaterFilterTest, InvalidCapacity) {
    EXPECT_THROW(WaterFilter(-10.0), std::invalid_argument);
}

TEST(WaterFilterTest, StartAndStop) {
    WaterFilter filter(100.0);
    EXPECT_NO_THROW(filter.start());
    EXPECT_NO_THROW(filter.stop());
}

TEST(WaterFilterTest, FilterWater) {
    WaterFilter filter(100.0);
    WaterQuality water;
    filter.start();
    EXPECT_NO_THROW(filter.filter(water));
}

TEST(WaterFilterTest, RejectInactiveFilter) {
    WaterFilter filter(100.0);
    WaterQuality water;
    EXPECT_THROW(filter.filter(water), EquipmentFailureException);
}

TEST(WaterFilterTest, CleanFilter) {
    WaterFilter filter(100.0);
    EXPECT_NO_THROW(filter.clean());
}

TEST(TemperatureTest, InactiveController) {
    TemperatureController controller(25.0);
    EXPECT_THROW(controller.regulate(), std::logic_error);
}

TEST(TemperatureTest, RegulateTemperature) {
    TemperatureController controller(25.0);
    controller.start();
    EXPECT_NO_THROW(controller.regulate());
    EXPECT_NO_THROW(controller.stop());
}

TEST(OxygenTest, InactiveSystem) {
    OxygenSystem oxygen;
    EXPECT_THROW(oxygen.increaseOxygen(), std::logic_error);
}

TEST(OxygenTest, IncreaseOxygen) {
    OxygenSystem oxygen;
    oxygen.start();
    EXPECT_NO_THROW(oxygen.increaseOxygen());
    EXPECT_NO_THROW(oxygen.stop());
}

TEST(LightingTest, Brightness) {
    LightingSystem lighting;
    EXPECT_NO_THROW(lighting.setBrightness(80));
    EXPECT_THROW(lighting.setBrightness(150), std::invalid_argument);
}

TEST(LightingTest, SimulateHour) {
    LightingSystem lighting;
    lighting.turnOn();
    EXPECT_NO_THROW(lighting.simulateHour());
    lighting.turnOff();
    EXPECT_NO_THROW(lighting.simulateHour());
}

TEST(WaterPumpTest, InvalidFlowRate) {
    EXPECT_THROW(WaterPump(-5.0), std::invalid_argument);
}

TEST(WaterPumpTest, InactivePump) {
    WaterPump pump(10.0);
    EXPECT_THROW(pump.pump(2.0), EquipmentFailureException);
}

TEST(WaterPumpTest, PumpWater) {
    WaterPump pump(10.0);
    pump.start();
    EXPECT_NO_THROW(pump.pump(2.0));
    EXPECT_NO_THROW(pump.stop());
}

TEST(WaterPumpTest, InvalidDuration) {
    WaterPump pump(10.0);
    pump.start();
    EXPECT_THROW(pump.pump(-2.0), std::invalid_argument);
}


TEST(VeterinarianExtraTest, ExamineHealthyAnimal) {
    Veterinarian vet(1, "Doctor");
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(vet.examine(animal));
}

TEST(VeterinarianExtraTest, InvalidVeterinarian) {
    EXPECT_THROW(Veterinarian(0, "Doctor"), InvalidAnimalException);
}

TEST(VeterinarianExtraTest, TreatAnimal) {
    Veterinarian vet(1, "Doctor");
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    Treatment treatment("Medicine", 2.0);
    EXPECT_NO_THROW(vet.treat(animal, treatment));
}

TEST(AnimalTrainerExtraTest, TrainDolphin) {
    AnimalTrainer trainer(1, "Alex");
    Dolphin dolphin(2, "Flipper", 4, 80.0);
    EXPECT_NO_THROW(trainer.trainDolphin(dolphin));
}

TEST(AnimalTrainerExtraTest, ConductSession) {
    AnimalTrainer trainer(1, "Alex");
    Dolphin dolphin(2, "Flipper", 4, 80.0);
    EXPECT_NO_THROW(trainer.conductSession(dolphin, 30));
}

TEST(AnimalTrainerExtraTest, InvalidSession) {
    AnimalTrainer trainer(1, "Alex");
    Dolphin dolphin(2, "Flipper", 4, 80.0);
    EXPECT_THROW(trainer.conductSession(dolphin, 150), std::invalid_argument);
}

TEST(FeedingExtraTest, FeedAnimal) {
    FeedingSchedule schedule(9, 2.0);
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(schedule.feedAnimal(animal));
}

TEST(FeedingExtraTest, RejectDoubleFeeding) {
    FeedingSchedule schedule(9, 2.0);
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    schedule.feedAnimal(animal);
    EXPECT_THROW(schedule.feedAnimal(animal), FeedingException);
}

TEST(FeedingExtraTest, ResetSchedule) {
    FeedingSchedule schedule(9, 2.0);
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    schedule.feedAnimal(animal);
    schedule.reset();
    EXPECT_NO_THROW(schedule.feedAnimal(animal));
}

TEST(FeedingExtraTest, InvalidSchedule) {
    EXPECT_THROW(FeedingSchedule(25, 2.0), FeedingException);
}

TEST(FoodExtraTest, ConsumeFood) {
    Food food("FishFood", 10.0);
    EXPECT_NO_THROW(food.consume(3.0));
}

TEST(FoodExtraTest, RejectExcessConsumption) {
    Food food("FishFood", 10.0);
    EXPECT_THROW(food.consume(20.0), FeedingException);
}

TEST(FoodExtraTest, SpoiledFood) {
    Food food("FishFood", 10.0);
    food.spoil();
    EXPECT_THROW(food.consume(2.0), FeedingException);
}

TEST(FoodExtraTest, InvalidRestock) {
    Food food("FishFood", 10.0);
    EXPECT_THROW(food.restock(-5.0), std::invalid_argument);
}

TEST(DietExtraTest, ChangeMeals) {
    Diet diet("Balanced", 6.0);
    diet.changeMeals(3);
    EXPECT_DOUBLE_EQ(diet.calculatePortion(), 2.0);
}

TEST(DietExtraTest, InvalidMeals) {
    Diet diet("Balanced", 6.0);
    EXPECT_THROW(diet.changeMeals(0), std::invalid_argument);
}

TEST(DietExtraTest, FeedAnimal) {
    Diet diet("Balanced", 6.0);
    Food food("FishFood", 20.0);
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(diet.feed(animal, food));
}

TEST(MedicalRecordExtraTest, Diagnose) {
    MedicalRecord record(1);
    EXPECT_NO_THROW(record.diagnose("Infection"));
}

TEST(MedicalRecordExtraTest, InvalidDiagnosis) {
    MedicalRecord record(1);
    EXPECT_THROW(record.diagnose(""), std::invalid_argument);
}

TEST(MedicalRecordExtraTest, RecordTreatment) {
    MedicalRecord record(1);
    EXPECT_NO_THROW(record.recordTreatment());
}

TEST(MedicalRecordExtraTest, MarkRecovered) {
    MedicalRecord record(1);
    EXPECT_NO_THROW(record.markRecovered());
}

TEST(TreatmentExtraTest, ApplyTreatment) {
    Treatment treatment("Medicine", 2.0);
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_NO_THROW(treatment.apply(animal));
}

TEST(TreatmentExtraTest, RejectRepeatedTreatment) {
    Treatment treatment("Medicine", 2.0);
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    treatment.apply(animal);
    EXPECT_THROW(treatment.apply(animal), TreatmentException);
}

TEST(TreatmentExtraTest, ExtendTreatment) {
    Treatment treatment("Medicine", 2.0);
    EXPECT_NO_THROW(treatment.extend(5));
}

TEST(TreatmentExtraTest, InvalidExtension) {
    Treatment treatment("Medicine", 2.0);
    EXPECT_THROW(treatment.extend(-1), std::invalid_argument);
}

TEST(HealthMonitorExtraTest, CheckAnimal) {
    AnimalHealthMonitor monitor;
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    EXPECT_TRUE(monitor.check(animal));
}

TEST(HealthMonitorExtraTest, InactiveMonitor) {
    AnimalHealthMonitor monitor;
    MarineAnimal animal(1, "Nemo", 3, 10.0);
    monitor.stop();
    EXPECT_THROW(monitor.check(animal), std::logic_error);
}

TEST(BreedingExtraTest, StartAndStop) {
    BreedingProgram program("Dolphin");
    EXPECT_NO_THROW(program.start());
    EXPECT_NO_THROW(program.stop());
}

TEST(BreedingExtraTest, AddPair) {
    BreedingProgram program("Dolphin");
    program.start();
    EXPECT_NO_THROW(program.addPair());
}

TEST(BreedingExtraTest, RecordBirth) {
    BreedingProgram program("Dolphin");
    program.start();
    program.addPair();
    EXPECT_NO_THROW(program.recordBirth(2));
}

TEST(BreedingExtraTest, RejectInactiveBreeding) {
    BreedingProgram program("Dolphin");
    EXPECT_THROW(program.addPair(), std::logic_error);
    EXPECT_THROW(program.recordBirth(2), std::logic_error);
}

TEST(TourGuideExtraTest, CreateGuide) {
    EXPECT_NO_THROW(TourGuide(1, "Alex"));
}

TEST(TourGuideExtraTest, RejectInvalidGuide) {
    EXPECT_THROW(TourGuide(0, "Alex"), std::invalid_argument);
}

TEST(TourGuideExtraTest, ConductAndFinishTour) {
    TourGuide guide(1, "Alex");
    GuidedTour tour(1, 5);
    Visitor visitor(1, "Mary", 20);

    tour.addVisitor(visitor);
    EXPECT_NO_THROW(guide.conductTour(tour));
    EXPECT_NO_THROW(guide.finishTour(tour));
}

TEST(GuidedTourExtraTest, RejectInvalidTour) {
    EXPECT_THROW(GuidedTour(0, 5), std::invalid_argument);
}

TEST(GuidedTourExtraTest, AddVisitor) {
    GuidedTour tour(1, 5);
    Visitor visitor(1, "Mary", 20);

    EXPECT_NO_THROW(tour.addVisitor(visitor));
}

TEST(GuidedTourExtraTest, RejectEmptyTourStart) {
    GuidedTour tour(1, 5);
    EXPECT_THROW(tour.start(), BookingException);
}

TEST(GuidedTourExtraTest, RejectFinishBeforeStart) {
    GuidedTour tour(1, 5);
    EXPECT_THROW(tour.finish(), BookingException);
}

TEST(GuidedTourExtraTest, RejectFullTour) {
    GuidedTour tour(1, 1);
    Visitor first(1, "Mary", 20);
    Visitor second(2, "John", 25);

    tour.addVisitor(first);
    EXPECT_THROW(tour.addVisitor(second), BookingException);
}

TEST(GuidedTourExtraTest, RejectVisitorAfterStart) {
    GuidedTour tour(1, 5);
    Visitor first(1, "Mary", 20);
    Visitor second(2, "John", 25);

    tour.addVisitor(first);
    tour.start();
    EXPECT_THROW(tour.addVisitor(second), BookingException);
}

TEST(ExhibitionExtraTest, OpenAndClose) {
    Exhibition exhibition("Sharks", 10);
    EXPECT_NO_THROW(exhibition.openExhibition());
    EXPECT_NO_THROW(exhibition.closeExhibition());
}

TEST(ExhibitionExtraTest, RejectInvalidCapacity) {
    EXPECT_THROW(Exhibition("Sharks", 0), std::invalid_argument);
}

TEST(ExhibitionExtraTest, AdmitVisitor) {
    Exhibition exhibition("Sharks", 10);
    Visitor visitor(1, "Mary", 20);

    exhibition.openExhibition();
    EXPECT_NO_THROW(exhibition.admitVisitor(visitor));
}

TEST(ExhibitionExtraTest, RejectClosedExhibition) {
    Exhibition exhibition("Sharks", 10);
    Visitor visitor(1, "Mary", 20);

    EXPECT_THROW(exhibition.admitVisitor(visitor), std::logic_error);
}

TEST(ExhibitionExtraTest, RejectFullExhibition) {
    Exhibition exhibition("Sharks", 1);
    Visitor first(1, "Mary", 20);
    Visitor second(2, "John", 25);

    exhibition.openExhibition();
    exhibition.admitVisitor(first);
    EXPECT_THROW(exhibition.admitVisitor(second), std::logic_error);
}

TEST(MembershipExtraTest, CreateMembership) {
    EXPECT_NO_THROW(Membership(1, 1));
}

TEST(MembershipExtraTest, RejectInvalidMembership) {
    EXPECT_THROW(Membership(0, 1), std::invalid_argument);
}

TEST(MembershipExtraTest, EarnAndRedeemPoints) {
    Membership membership(1, 1);

    EXPECT_NO_THROW(membership.earnPoints(100));
    EXPECT_NO_THROW(membership.redeemPoints(40));
}

TEST(MembershipExtraTest, RejectExcessRedemption) {
    Membership membership(1, 1);
    membership.earnPoints(20);

    EXPECT_THROW(membership.redeemPoints(50), std::logic_error);
}

TEST(MembershipExtraTest, RejectInvalidPoints) {
    Membership membership(1, 1);
    EXPECT_THROW(membership.earnPoints(-10), std::invalid_argument);
}

TEST(MembershipExtraTest, RejectInactiveMembership) {
    Membership membership(1, 1);
    membership.deactivate();

    EXPECT_THROW(membership.earnPoints(10), std::invalid_argument);
}

TEST(PaymentExtraTest, CreatePayment) {
    EXPECT_NO_THROW(Payment(1, 100.0));
}

TEST(PaymentExtraTest, RejectInvalidPayment) {
    EXPECT_THROW(Payment(1, -100.0), std::invalid_argument);
}

TEST(PaymentExtraTest, ProcessPayment) {
    Payment payment(1, 100.0);
    EXPECT_NO_THROW(payment.process());
}

TEST(PaymentExtraTest, RejectDuplicatePayment) {
    Payment payment(1, 100.0);
    payment.process();

    EXPECT_THROW(payment.process(), std::logic_error);
}

TEST(PaymentExtraTest, RefundPayment) {
    Payment payment(1, 100.0);
    payment.process();

    EXPECT_NO_THROW(payment.refund());
}

TEST(PaymentExtraTest, RejectRefundBeforePayment) {
    Payment payment(1, 100.0);
    EXPECT_THROW(payment.refund(), std::logic_error);
}

TEST(PaymentExtraTest, PayForTicket) {
    Payment payment(1, 100.0);
    Ticket ticket(1, 80.0);

    EXPECT_NO_THROW(payment.payForTicket(ticket));
}

TEST(PaymentExtraTest, RejectInsufficientPayment) {
    Payment payment(1, 50.0);
    Ticket ticket(1, 100.0);

    EXPECT_THROW(payment.payForTicket(ticket), InvalidTicketException);
}




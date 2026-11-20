#pragma once
#include <string>
#include "MarineAnimals.h"

class Treatment;

class Veterinarian {
private:
    int id;
    std::string name;
    int experienceYears;
    int patientsTreated;

public:
    Veterinarian(int id, std::string name);
    void examine(MarineAnimal& animal);
    void treat(MarineAnimal& animal, Treatment& treatment);
};

class AnimalTrainer {
private:
    int id;
    std::string name;
    int experienceYears;
    int sessionsCompleted;

public:
    AnimalTrainer(int id, std::string name);
    void trainDolphin(Dolphin& dolphin);
    void conductSession(Dolphin& dolphin, int minutes);
};

class FeedingSchedule {
private:
    int feedingHour;
    double portionSize;
    bool completed;

public:
    FeedingSchedule(int hour, double portion);
    void feedAnimal(MarineAnimal& animal);
    void reset();
};

class Food {
private:
    std::string name;
    double quantity;
    double caloriesPerUnit;
    bool fresh;

public:
    Food(std::string name, double quantity);
    void consume(double amount);
    void restock(double amount);
    void spoil();
};

class Diet {
private:
    std::string type;
    double dailyAmount;
    int mealsPerDay;

public:
    Diet(std::string type, double dailyAmount);
    double calculatePortion() const;
    void changeMeals(int meals);
    void feed(MarineAnimal& animal, Food& food);
};

class MedicalRecord {
private:
    int animalId;
    std::string diagnosis;
    int treatmentCount;
    bool recovered;

public:
    MedicalRecord(int animalId);
    void diagnose(std::string condition);
    void recordTreatment();
    void markRecovered();
};

class Treatment {
private:
    std::string medicine;
    double dosage;
    int durationDays;
    bool completed;

public:
    Treatment(std::string medicine, double dosage);
    void apply(MarineAnimal& animal);
    void extend(int days);
};

class AnimalHealthMonitor {
private:
    int checkCount;
    int alertCount;
    bool monitoringActive;

public:
    AnimalHealthMonitor();
    bool check(MarineAnimal& animal);
    void start();
    void stop();
};

class BreedingProgram {
private:
    std::string species;
    int breedingPairs;
    int offspringBorn;
    bool active;

public:
    BreedingProgram(std::string species);
    void start();
    void stop();
    void addPair();
    void recordBirth(int offspring);
};
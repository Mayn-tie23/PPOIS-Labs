
#include "AnimalCare.h"
#include "OceanariumExceptions.h"
#include <stdexcept>
#include <utility>

// Veterinarian

Veterinarian::Veterinarian(int id, std::string name)
    : id(id), name(std::move(name)),
    experienceYears(0), patientsTreated(0) {
    if (id <= 0 || this->name.empty())
        throw InvalidAnimalException();
}

void Veterinarian::examine(MarineAnimal& animal) {
    if (!animal.isHealthy())
        throw TreatmentException();

    patientsTreated++;
}

void Veterinarian::treat(MarineAnimal& animal, Treatment& treatment) {
    treatment.apply(animal);
    patientsTreated++;
}

// AnimalTrainer

AnimalTrainer::AnimalTrainer(int id, std::string name)
    : id(id), name(std::move(name)),
    experienceYears(0), sessionsCompleted(0) {
}

void AnimalTrainer::trainDolphin(Dolphin& dolphin) {
    dolphin.train();
    sessionsCompleted++;
}

void AnimalTrainer::conductSession(Dolphin& dolphin, int minutes) {
    if (minutes <= 0 || minutes > 120)
        throw std::invalid_argument("Invalid training duration");

    dolphin.train();
    sessionsCompleted++;
}

// FeedingSchedule

FeedingSchedule::FeedingSchedule(int hour, double portion)
    : feedingHour(hour), portionSize(portion),
    completed(false) {
    if (hour < 0 || hour > 23 || portion <= 0)
        throw FeedingException();
}

void FeedingSchedule::feedAnimal(MarineAnimal& animal) {
    if (completed)
        throw FeedingException();

    animal.feed(portionSize);
    completed = true;
}

void FeedingSchedule::reset() {
    completed = false;
}

// Food

Food::Food(std::string name, double quantity)
    : name(std::move(name)), quantity(quantity),
    caloriesPerUnit(100), fresh(true) {
    if (this->name.empty() || quantity < 0)
        throw FeedingException();
}

void Food::consume(double amount) {
    if (!fresh || amount <= 0 || amount > quantity)
        throw FeedingException();

    quantity -= amount;
}

void Food::restock(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Invalid restock amount");

    quantity += amount;
}

void Food::spoil() {
    fresh = false;
}

// Diet

Diet::Diet(std::string type, double dailyAmount)
    : type(std::move(type)), dailyAmount(dailyAmount),
    mealsPerDay(2) {
    if (dailyAmount <= 0)
        throw FeedingException();
}

double Diet::calculatePortion() const {
    return dailyAmount / mealsPerDay;
}

void Diet::changeMeals(int meals) {
    if (meals <= 0)
        throw std::invalid_argument("Invalid meal count");

    mealsPerDay = meals;
}

void Diet::feed(MarineAnimal& animal, Food& food) {
    double portion = calculatePortion();

    food.consume(portion);
    animal.feed(portion);
}

// MedicalRecord

MedicalRecord::MedicalRecord(int animalId)
    : animalId(animalId), diagnosis("None"),
    treatmentCount(0), recovered(false) {
    if (animalId <= 0)
        throw InvalidAnimalException();
}

void MedicalRecord::diagnose(std::string condition) {
    if (condition.empty())
        throw std::invalid_argument("Empty diagnosis");

    diagnosis = std::move(condition);
    recovered = false;
}

void MedicalRecord::recordTreatment() {
    treatmentCount++;
}

void MedicalRecord::markRecovered() {
    recovered = true;
}

// Treatment

Treatment::Treatment(std::string medicine, double dosage)
    : medicine(std::move(medicine)), dosage(dosage),
    durationDays(1), completed(false) {
    if (this->medicine.empty() || dosage <= 0)
        throw TreatmentException();
}

void Treatment::apply(MarineAnimal& animal) {
    if (completed)
        throw TreatmentException();

    if (!animal.isHealthy())
        throw TreatmentException();

    completed = true;
}

void Treatment::extend(int days) {
    if (days <= 0)
        throw std::invalid_argument("Invalid duration");

    durationDays += days;
}

// AnimalHealthMonitor

AnimalHealthMonitor::AnimalHealthMonitor()
    : checkCount(0), alertCount(0),
    monitoringActive(true) {
}

bool AnimalHealthMonitor::check(MarineAnimal& animal) {
    if (!monitoringActive)
        throw std::logic_error("Monitoring is inactive");

    checkCount++;

    if (!animal.isHealthy()) {
        alertCount++;
        return false;
    }

    return true;
}

void AnimalHealthMonitor::start() {
    monitoringActive = true;
}

void AnimalHealthMonitor::stop() {
    monitoringActive = false;
}

// BreedingProgram

BreedingProgram::BreedingProgram(std::string species)
    : species(std::move(species)),
    breedingPairs(0),
    offspringBorn(0),
    active(false) {
}

void BreedingProgram::start() {
    active = true;
}

void BreedingProgram::stop() {
    active = false;
}

void BreedingProgram::addPair() {
    if (!active)
        throw std::logic_error("Breeding program is inactive");

    breedingPairs++;
}

void BreedingProgram::recordBirth(int offspring) {
    if (!active || breedingPairs == 0 || offspring <= 0)
        throw std::logic_error("Invalid breeding event");

    offspringBorn += offspring;
}

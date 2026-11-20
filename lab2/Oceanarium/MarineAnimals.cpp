
#include "MarineAnimals.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

// MarineAnimal

MarineAnimal::MarineAnimal(int id, std::string name, int age, double weight)
    : id(id), name(std::move(name)), age(age), weight(weight) {
    if (id <= 0 || this->name.empty() || age < 0 || weight <= 0)
        throw std::invalid_argument("Invalid animal data");
}

void MarineAnimal::feed(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Invalid food amount");

    weight += amount;
}

void MarineAnimal::grow(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Invalid growth amount");

    weight += amount;
}

bool MarineAnimal::isHealthy() const {
    return weight > 0 && age >= 0;
}

// NEW BEHAVIOR 1
void MarineAnimal::loseWeight(double amount) {
    if (amount <= 0 || amount >= weight)
        throw std::invalid_argument("Invalid weight loss");

    weight -= amount;
}

// Fish

Fish::Fish(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    species("Unknown"), swimmingSpeed(0), freshwater(false) {
}

void Fish::swim(double distance) {
    if (distance < 0)
        throw std::invalid_argument("Invalid distance");

    swimmingSpeed = distance;
}

void Fish::changeSpeed(double speed) {
    if (speed < 0)
        throw std::invalid_argument("Invalid speed");

    swimmingSpeed = speed;
}

// Shark

Shark::Shark(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    teethCount(100), huntingSpeed(0), hungry(true) {
}

void Shark::hunt() {
    if (!hungry)
        throw std::logic_error("Shark is not hungry");

    hungry = false;
    huntingSpeed += 5;
}

void Shark::replaceTeeth() {
    teethCount++;
}

// NEW BEHAVIOR 2
void Shark::restAfterHunt() {
    if (hungry)
        throw std::logic_error("Shark has not hunted");

    huntingSpeed = std::max(0.0, huntingSpeed - 5.0);
    hungry = true;
}

// Dolphin

Dolphin::Dolphin(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    intelligenceLevel(5), trained(false), energy(100) {
}

void Dolphin::performTrick() {
    if (!trained)
        throw std::logic_error("Dolphin is not trained");

    if (energy < 10)
        throw std::logic_error("Not enough energy");

    energy -= 10;
}

void Dolphin::train() {
    if (energy < 5)
        throw std::logic_error("Not enough energy");

    trained = true;
    energy -= 5;
}

// NEW BEHAVIOR 3
void Dolphin::rest(int hours) {
    if (hours <= 0)
        throw std::invalid_argument("Invalid resting hours");

    energy = std::min(100.0, energy + hours * 10.0);
}

// Whale

Whale::Whale(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    lungCapacity(100), diveDepth(0), migrating(false) {
}

void Whale::dive(double depth) {
    if (depth < 0 || depth > lungCapacity * 10)
        throw std::invalid_argument("Invalid diving depth");

    diveDepth = depth;
}

void Whale::surface() {
    diveDepth = 0;
}

// Jellyfish

Jellyfish::Jellyfish(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    venomous(false), tentacleLength(1), glowIntensity(0) {
}

void Jellyfish::glow() {
    glowIntensity += 1;
}

void Jellyfish::sting() {
    if (!venomous)
        throw std::logic_error("Jellyfish is not venomous");
}

// Octopus

Octopus::Octopus(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    tentacles(8), inkLevel(100), camouflaged(false) {
}

void Octopus::releaseInk() {
    if (inkLevel < 10)
        throw std::logic_error("Not enough ink");

    inkLevel -= 10;
}

void Octopus::camouflage() {
    camouflaged = true;
}

// NEW BEHAVIOR 4
void Octopus::regenerateInk(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Invalid ink amount");

    inkLevel = std::min(100.0, inkLevel + amount);
}

// SeaTurtle

SeaTurtle::SeaTurtle(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    shellStrength(100), swimmingSpeed(0), nesting(false) {
}

void SeaTurtle::layEggs() {
    if (nesting)
        throw std::logic_error("Already nesting");

    nesting = true;
}

void SeaTurtle::swim() {
    swimmingSpeed += 1;
}

// Seahorse

Seahorse::Seahorse(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    pregnant(false), offspringCount(0), tailStrength(10) {
}

void Seahorse::reproduce() {
    if (pregnant) {
        offspringCount += 5;
        pregnant = false;
    }
    else {
        pregnant = true;
    }
}

void Seahorse::gripPlant() {
    if (tailStrength <= 0)
        throw std::logic_error("Tail is too weak");

    tailStrength -= 1;
}

// Stingray

Stingray::Stingray(int id, std::string name, int age, double weight)
    : MarineAnimal(id, std::move(name), age, weight),
    wingspan(2), venomous(true), energy(100) {
}

void Stingray::glide() {
    if (energy < 5)
        throw std::logic_error("Not enough energy");

    energy -= 5;
}

void Stingray::defend() {
    if (!venomous)
        throw std::logic_error("Stingray is not venomous");

    if (energy < 10)
        throw std::logic_error("Not enough energy");

    energy -= 10;
}
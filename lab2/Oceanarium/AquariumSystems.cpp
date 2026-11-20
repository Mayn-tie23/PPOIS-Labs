

#include "AquariumSystems.h"
#include "OceanariumExceptions.h"
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <utility>

// AquariumTank

AquariumTank::AquariumTank(int id, double capacity)
    : id(id), capacity(capacity), waterVolume(0),
    animalCount(0), operational(true) {
    if (id <= 0 || capacity <= 0)
        throw std::invalid_argument("Invalid tank");
}

void AquariumTank::fill(double liters) {
    if (liters <= 0)
        throw std::invalid_argument("Invalid water amount");

    if (waterVolume + liters > capacity)
        throw TankCapacityException();

    waterVolume += liters;
}

void AquariumTank::drain(double liters) {
    if (liters <= 0 || liters > waterVolume)
        throw std::invalid_argument("Invalid drain amount");

    waterVolume -= liters;
}

void AquariumTank::addAnimal() {
    if (!operational || waterVolume <= 0)
        throw std::logic_error("Tank is not ready");

    animalCount++;
}

// Habitat

Habitat::Habitat(std::string name, double minTemp, double maxTemp)
    : name(std::move(name)),
    minTemperature(minTemp),
    maxTemperature(maxTemp),
    salinity(35) {
    if (minTemp > maxTemp)
        throw std::invalid_argument("Invalid temperature range");
}

bool Habitat::supportsTemperature(double temperature) const {
    return temperature >= minTemperature &&
        temperature <= maxTemperature;
}

void Habitat::adjustSalinity(double value) {
    if (value < 0 || value > 50)
        throw std::invalid_argument("Invalid salinity");

    salinity = value;
}

// WaterQuality

WaterQuality::WaterQuality()
    : ph(8.1), oxygen(7), ammonia(0),
    nitrate(0), clarity(100) {
}

bool WaterQuality::isSafe() const {
    return ph >= 7.8 && ph <= 8.5 &&
        oxygen >= 5 && ammonia < 0.1 &&
        nitrate < 20;
}

void WaterQuality::pollute(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Invalid pollution");

    ammonia += amount;
    nitrate += amount * 2;
    clarity = std::max(0.0, clarity - amount * 10);
}

void WaterQuality::purify(double efficiency) {
    if (efficiency < 0 || efficiency > 1)
        throw std::invalid_argument("Invalid efficiency");

    ammonia *= (1 - efficiency);
    nitrate *= (1 - efficiency);
    clarity = std::min(100.0, clarity + efficiency * 20);
}

// WaterFilter

WaterFilter::WaterFilter(double capacity)
    : capacity(capacity), efficiency(0.9),
    dirtLevel(0), active(false) {
    if (capacity <= 0)
        throw std::invalid_argument("Invalid filter capacity");
}

void WaterFilter::start() {
    if (dirtLevel >= 100)
        throw EquipmentFailureException();

    active = true;
}

void WaterFilter::stop() {
    active = false;
}

void WaterFilter::clean() {
    dirtLevel = 0;
    efficiency = 0.9;
}

void WaterFilter::filter(WaterQuality& water) {
    if (!active || dirtLevel >= 100)
        throw EquipmentFailureException();

    water.purify(efficiency);

    dirtLevel = std::min(100.0, dirtLevel + 10);

    if (!water.isSafe())
        throw UnsafeWaterException();
}

// TemperatureController

TemperatureController::TemperatureController(double target)
    : targetTemperature(target),
    currentTemperature(20),
    heatingPower(2),
    active(false) {
}

void TemperatureController::start() {
    active = true;
}

void TemperatureController::stop() {
    active = false;
}

void TemperatureController::regulate() {
    if (!active)
        throw std::logic_error("Controller is inactive");

    double difference =
        targetTemperature - currentTemperature;

    if (std::abs(difference) <= heatingPower)
        currentTemperature = targetTemperature;
    else if (difference > 0)
        currentTemperature += heatingPower;
    else
        currentTemperature -= heatingPower;
}

// OxygenSystem

OxygenSystem::OxygenSystem()
    : oxygenLevel(7), targetLevel(8),
    productionRate(0.5), active(false) {
}

void OxygenSystem::start() {
    active = true;
}

void OxygenSystem::stop() {
    active = false;
}

void OxygenSystem::increaseOxygen() {
    if (!active)
        throw std::logic_error("Oxygen system is inactive");

    oxygenLevel = std::min(
        targetLevel,
        oxygenLevel + productionRate
    );
}

// LightingSystem

LightingSystem::LightingSystem()
    : brightness(50), dailyHours(12),
    energyConsumption(0), active(false) {
}

void LightingSystem::turnOn() {
    active = true;
}

void LightingSystem::turnOff() {
    active = false;
}

void LightingSystem::setBrightness(int value) {
    if (value < 0 || value > 100)
        throw std::invalid_argument("Invalid brightness");

    brightness = value;
}

void LightingSystem::simulateHour() {
    if (active)
        energyConsumption += brightness * 0.01;
}

// WaterPump

WaterPump::WaterPump(double flowRate)
    : flowRate(flowRate), totalPumped(0),
    energyUsed(0), active(false) {
    if (flowRate <= 0)
        throw std::invalid_argument("Invalid flow rate");
}

void WaterPump::start() {
    active = true;
}

void WaterPump::stop() {
    active = false;
}

void WaterPump::pump(double hours) {
    if (!active)
        throw EquipmentFailureException();

    if (hours <= 0)
        throw std::invalid_argument("Invalid duration");

    totalPumped += flowRate * hours;
    energyUsed += hours * 0.5;
}

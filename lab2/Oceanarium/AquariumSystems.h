
#pragma once
#include <string>

class AquariumTank {
private:
    int id;
    double capacity;
    double waterVolume;
    int animalCount;
    bool operational;

public:
    AquariumTank(int id, double capacity);
    void fill(double liters);
    void drain(double liters);
    void addAnimal();
};

class Habitat {
private:
    std::string name;
    double minTemperature;
    double maxTemperature;
    double salinity;

public:
    Habitat(std::string name, double minTemp, double maxTemp);
    bool supportsTemperature(double temperature) const;
    void adjustSalinity(double value);
};

class WaterQuality {
private:
    double ph;
    double oxygen;
    double ammonia;
    double nitrate;
    double clarity;

public:
    WaterQuality();
    bool isSafe() const;
    void pollute(double amount);
    void purify(double efficiency);
};

class WaterFilter {
private:
    double capacity;
    double efficiency;
    double dirtLevel;
    bool active;

public:
    WaterFilter(double capacity);
    void start();
    void stop();
    void clean();
    void filter(WaterQuality& water);
};

class TemperatureController {
private:
    double targetTemperature;
    double currentTemperature;
    double heatingPower;
    bool active;

public:
    TemperatureController(double target);
    void start();
    void stop();
    void regulate();
};

class OxygenSystem {
private:
    double oxygenLevel;
    double targetLevel;
    double productionRate;
    bool active;

public:
    OxygenSystem();
    void start();
    void stop();
    void increaseOxygen();
};

class LightingSystem {
private:
    int brightness;
    int dailyHours;
    double energyConsumption;
    bool active;

public:
    LightingSystem();
    void turnOn();
    void turnOff();
    void setBrightness(int value);
    void simulateHour();
};

class WaterPump {
private:
    double flowRate;
    double totalPumped;
    double energyUsed;
    bool active;

public:
    WaterPump(double flowRate);
    void start();
    void stop();
    void pump(double hours);
};


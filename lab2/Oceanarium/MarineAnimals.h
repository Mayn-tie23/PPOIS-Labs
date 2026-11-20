
#pragma once
#include <string>

class MarineAnimal {
protected:
    int id;
    std::string name;
    int age;
    double weight;

public:
    MarineAnimal(int id, std::string name, int age, double weight);

    void feed(double amount);
    void grow(double amount);
    bool isHealthy() const;
    void loseWeight(double amount);
};

class Fish : public MarineAnimal {
private:
    std::string species;
    double swimmingSpeed;
    bool freshwater;

public:
    Fish(int id, std::string name, int age, double weight);

    void swim(double distance);
    void changeSpeed(double speed);
};

class Shark : public MarineAnimal {
private:
    int teethCount;
    double huntingSpeed;
    bool hungry;

public:
    Shark(int id, std::string name, int age, double weight);

    void hunt();
    void replaceTeeth();
    void restAfterHunt();
};

class Dolphin : public MarineAnimal {
private:
    int intelligenceLevel;
    bool trained;
    double energy;

public:
    Dolphin(int id, std::string name, int age, double weight);

    void performTrick();
    void train();
    void rest(int hours);
};

class Whale : public MarineAnimal {
private:
    double lungCapacity;
    double diveDepth;
    bool migrating;

public:
    Whale(int id, std::string name, int age, double weight);

    void dive(double depth);
    void surface();
};

class Jellyfish : public MarineAnimal {
private:
    bool venomous;
    double tentacleLength;
    double glowIntensity;

public:
    Jellyfish(int id, std::string name, int age, double weight);

    void glow();
    void sting();
};

class Octopus : public MarineAnimal {
private:
    int tentacles;
    double inkLevel;
    bool camouflaged;

public:
    Octopus(int id, std::string name, int age, double weight);

    void releaseInk();
    void camouflage();
    void regenerateInk(double amount);
};

class SeaTurtle : public MarineAnimal {
private:
    double shellStrength;
    double swimmingSpeed;
    bool nesting;

public:
    SeaTurtle(int id, std::string name, int age, double weight);

    void layEggs();
    void swim();
};

class Seahorse : public MarineAnimal {
private:
    bool pregnant;
    int offspringCount;
    double tailStrength;

public:
    Seahorse(int id, std::string name, int age, double weight);

    void reproduce();
    void gripPlant();
};

class Stingray : public MarineAnimal {
private:
    double wingspan;
    bool venomous;
    double energy;

public:
    Stingray(int id, std::string name, int age, double weight);

    void glide();
    void defend();
};

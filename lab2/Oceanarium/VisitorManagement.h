
#pragma once
#include <string>

class Visitor {
private:
    int id;
    std::string name;
    int age;
    int visits;
    bool banned;

public:
    Visitor(int id, std::string name, int age);
    void enter();
    void ban();
    void unban();
    bool canEnter() const;
};

class Ticket {
private:
    int id;
    double price;
    bool used;
    bool refunded;

public:
    Ticket(int id, double price);
    void use(Visitor& visitor);
    void refund();
    void applyDiscount(double percent);
    double getPrice() const;
};

class Booking {
private:
    int id;
    int visitorId;
    int ticketCount;
    bool confirmed;

public:
    Booking(int id, int visitorId);
    void addTicket();
    void confirm();
    void cancel();
};

class GuidedTour;

class TourGuide {
private:
    int id;
    std::string name;
    int experienceYears;
    int toursCompleted;

public:
    TourGuide(int id, std::string name);
    void conductTour(GuidedTour& tour);
    void finishTour(GuidedTour& tour);
};

class GuidedTour {
private:
    int id;
    int maxVisitors;
    int currentVisitors;
    bool active;

public:
    GuidedTour(int id, int maxVisitors);
    void addVisitor(Visitor& visitor);
    void start();
    void finish();
};

class Exhibition {
private:
    std::string name;
    int capacity;
    int visitorCount;
    bool open;

public:
    Exhibition(std::string name, int capacity);
    void openExhibition();
    void closeExhibition();
    void admitVisitor(Visitor& visitor);
};

class Membership {
private:
    int id;
    int visitorId;
    int points;
    bool active;

public:
    Membership(int id, int visitorId);
    void earnPoints(int amount);
    void redeemPoints(int amount);
    void deactivate();
};

class Payment {
private:
    int id;
    double amount;
    bool processed;
    bool refunded;

public:
    Payment(int id, double amount);
    void process();
    void refund();
    void payForTicket(Ticket& ticket);
};


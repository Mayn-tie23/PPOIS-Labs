
#include "VisitorManagement.h"
#include "OceanariumExceptions.h"
#include <stdexcept>
#include <utility>

// Visitor

Visitor::Visitor(int id, std::string name, int age)
    : id(id), name(std::move(name)), age(age),
    visits(0), banned(false) {
    if (id <= 0 || this->name.empty() || age < 0)
        throw std::invalid_argument("Invalid visitor");
}

void Visitor::enter() {
    if (banned)
        throw std::logic_error("Visitor is banned");

    visits++;
}

void Visitor::ban() {
    banned = true;
}

void Visitor::unban() {
    banned = false;
}

bool Visitor::canEnter() const {
    return !banned;
}

// Ticket

Ticket::Ticket(int id, double price)
    : id(id), price(price), used(false),
    refunded(false) {
    if (id <= 0 || price < 0)
        throw InvalidTicketException();
}

void Ticket::use(Visitor& visitor) {
    if (used || refunded || !visitor.canEnter())
        throw InvalidTicketException();

    visitor.enter();
    used = true;
}

void Ticket::refund() {
    if (used || refunded)
        throw InvalidTicketException();

    refunded = true;
}

void Ticket::applyDiscount(double percent) {
    if (percent < 0 || percent > 100)
        throw std::invalid_argument("Invalid discount");

    price *= (1 - percent / 100);
}

double Ticket::getPrice() const {
    return price;
}

// Booking

Booking::Booking(int id, int visitorId)
    : id(id), visitorId(visitorId),
    ticketCount(0), confirmed(false) {
    if (id <= 0 || visitorId <= 0)
        throw BookingException();
}

void Booking::addTicket() {
    if (confirmed)
        throw BookingException();

    ticketCount++;
}

void Booking::confirm() {
    if (ticketCount <= 0 || confirmed)
        throw BookingException();

    confirmed = true;
}

void Booking::cancel() {
    confirmed = false;
    ticketCount = 0;
}

// TourGuide

TourGuide::TourGuide(int id, std::string name)
    : id(id), name(std::move(name)),
    experienceYears(0), toursCompleted(0) {
    if (id <= 0 || this->name.empty())
        throw std::invalid_argument("Invalid guide");
}

void TourGuide::conductTour(GuidedTour& tour) {
    tour.start();
    toursCompleted++;
}

void TourGuide::finishTour(GuidedTour& tour) {
    tour.finish();
}

// GuidedTour

GuidedTour::GuidedTour(int id, int maxVisitors)
    : id(id), maxVisitors(maxVisitors),
    currentVisitors(0), active(false) {
    if (id <= 0 || maxVisitors <= 0)
        throw std::invalid_argument("Invalid tour");
}

void GuidedTour::addVisitor(Visitor& visitor) {
    if (active || currentVisitors >= maxVisitors ||
        !visitor.canEnter())
        throw BookingException();

    currentVisitors++;
}

void GuidedTour::start() {
    if (active || currentVisitors == 0)
        throw BookingException();

    active = true;
}

void GuidedTour::finish() {
    if (!active)
        throw BookingException();

    active = false;
    currentVisitors = 0;
}

// Exhibition

Exhibition::Exhibition(std::string name, int capacity)
    : name(std::move(name)), capacity(capacity),
    visitorCount(0), open(false) {
    if (this->name.empty() || capacity <= 0)
        throw std::invalid_argument("Invalid exhibition");
}

void Exhibition::openExhibition() {
    open = true;
}

void Exhibition::closeExhibition() {
    open = false;
    visitorCount = 0;
}

void Exhibition::admitVisitor(Visitor& visitor) {
    if (!open || visitorCount >= capacity ||
        !visitor.canEnter())
        throw std::logic_error("Exhibition unavailable");

    visitor.enter();
    visitorCount++;
}

// Membership

Membership::Membership(int id, int visitorId)
    : id(id), visitorId(visitorId),
    points(0), active(true) {
    if (id <= 0 || visitorId <= 0)
        throw std::invalid_argument("Invalid membership");
}

void Membership::earnPoints(int amount) {
    if (!active || amount <= 0)
        throw std::invalid_argument("Invalid points");

    points += amount;
}

void Membership::redeemPoints(int amount) {
    if (!active || amount <= 0 || amount > points)
        throw std::logic_error("Insufficient points");

    points -= amount;
}

void Membership::deactivate() {
    active = false;
}

// Payment

Payment::Payment(int id, double amount)
    : id(id), amount(amount),
    processed(false), refunded(false) {
    if (id <= 0 || amount <= 0)
        throw std::invalid_argument("Invalid payment");
}

void Payment::process() {
    if (processed || refunded)
        throw std::logic_error("Payment unavailable");

    processed = true;
}

void Payment::refund() {
    if (!processed || refunded)
        throw std::logic_error("Cannot refund payment");

    refunded = true;
}

void Payment::payForTicket(Ticket& ticket) {
    if (processed || refunded || amount < ticket.getPrice())
        throw InvalidTicketException();

    process();
}

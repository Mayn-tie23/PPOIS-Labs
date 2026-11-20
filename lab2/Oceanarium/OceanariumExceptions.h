
#pragma once
#include <stdexcept>
#include <string>

class OceanariumException : public std::runtime_error {
public:
    explicit OceanariumException(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidAnimalException : public OceanariumException {
public:
    InvalidAnimalException()
        : OceanariumException("Invalid marine animal data") {
    }
};

class AnimalNotFoundException : public OceanariumException {
public:
    AnimalNotFoundException()
        : OceanariumException("Marine animal not found") {
    }
};

class TankCapacityException : public OceanariumException {
public:
    TankCapacityException()
        : OceanariumException("Aquarium tank capacity exceeded") {
    }
};

class UnsafeWaterException : public OceanariumException {
public:
    UnsafeWaterException()
        : OceanariumException("Unsafe aquarium water conditions") {
    }
};

class FeedingException : public OceanariumException {
public:
    FeedingException()
        : OceanariumException("Animal feeding operation failed") {
    }
};

class TreatmentException : public OceanariumException {
public:
    TreatmentException()
        : OceanariumException("Animal treatment failed") {
    }
};

class EmployeeUnavailableException : public OceanariumException {
public:
    EmployeeUnavailableException()
        : OceanariumException("Employee is unavailable") {
    }
};

class InvalidTicketException : public OceanariumException {
public:
    InvalidTicketException()
        : OceanariumException("Invalid or unavailable ticket") {
    }
};

class BookingException : public OceanariumException {
public:
    BookingException()
        : OceanariumException("Booking operation failed") {
    }
};

class EquipmentFailureException : public OceanariumException {
public:
    EquipmentFailureException()
        : OceanariumException("Oceanarium equipment failure") {
    }
};

class InsufficientFundsException : public OceanariumException {
public:
    InsufficientFundsException()
        : OceanariumException("Insufficient financial resources") {
    }
};


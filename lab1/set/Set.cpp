
#include "Set.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace {

    constexpr std::size_t kMaxPowerSetElements = 16;

    // Skip whitespace while parsing.
    void skipSpaces(const std::string& text, std::size_t& position) {
        while (position < text.size() &&
            std::isspace(static_cast<unsigned char>(text[position]))) {
            ++position;
        }
    }

    // Remove whitespace around a symbolic element.
    std::string trim(const std::string& text) {
        const auto start = text.find_first_not_of(" \t\r\n\f\v");
        if (start == std::string::npos) return "";

        const auto end = text.find_last_not_of(" \t\r\n\f\v");
        return text.substr(start, end - start + 1);
    }

    // Determine whether an element is an integer.
    bool tryParseInteger(const std::string& text, int& number) {
        try {
            std::size_t parsedLength = 0;
            const int parsedNumber = std::stoi(text, &parsedLength);
            if (parsedLength != text.size()) {
                return false;
            }
            number = parsedNumber;
            return true;
        }
        catch (const std::invalid_argument&) {
            return false;
        }
        catch (const std::out_of_range&) {
            return false;
        }
    }

    // Read one element from a set expression.
    void addParsedAtom(Set& result, const std::string& text,
        std::size_t& position) {

        const auto start = position;

        while (position < text.size() && text[position] != ',' &&
            text[position] != '}' && text[position] != '{') {
            ++position;
        }

        const auto atom = trim(text.substr(start, position - start));

        if (atom.empty()) {
            throw std::invalid_argument("Empty set element");
        }

        result.add(atom);
    }

    // Parse a set, including nested sets.
    Set parseSet(const std::string& text, std::size_t& position) {
        skipSpaces(text, position);

        if (position == text.size() || text[position] != '{') {
            throw std::invalid_argument("Expected '{' in set expression");
        }

        ++position;
        Set result;
        skipSpaces(text, position);

        if (position < text.size() && text[position] == '}') {
            ++position;
            return result;
        }

        while (position < text.size()) {
            skipSpaces(text, position);

            if (position == text.size() ||
                text[position] == '}' || text[position] == ',') {
                throw std::invalid_argument("Missing set element");
            }

            if (text[position] == '{') {
                result.add(parseSet(text, position));
            }
            else {
                addParsedAtom(result, text, position);
            }

            skipSpaces(text, position);

            if (position == text.size()) break;

            if (text[position] == '}') {
                ++position;
                return result;
            }

            if (text[position++] != ',') {
                throw std::invalid_argument("Expected ','");
            }
        }

        throw std::invalid_argument("Missing '}' in set expression");
    }

    // Expand a collection of subsets with one element.
    template <typename T>
    void extendSubsets(std::vector<Set>& subsets, const T& element) {
        const auto oldSize = subsets.size();

        for (std::size_t index = 0; index < oldSize; ++index) {
            Set larger = subsets[index];
            larger.add(element);
            subsets.push_back(std::move(larger));
        }
    }

} // namespace

// Constructors and assignment
Set::Set() = default;

Set::Set(const std::string& text)
    : Set(fromString(text)) {
}

Set::Set(const Set& other) = default;

Set& Set::operator=(const Set& other) = default;

Set::~Set() = default;

// Add elements
void Set::add(int value) {
    if (!contains(value)) {
        elements.push_back(value);
    }
}

void Set::add(const std::string& value) {
    const auto token = trim(value);

    if (token.empty() ||
        token.find_first_of("{},") != std::string::npos) {
        throw std::invalid_argument("Invalid symbolic set element");
    }

    int number = 0;

    if (tryParseInteger(token, number)) {
        add(number);
        return;
    }

    if (!contains(token)) {
        labels.push_back(token);
    }
}

void Set::add(const Set& value) {
    if (!contains(value)) {
        nestedSets.push_back(value);
    }
}

// Remove elements
void Set::remove(int value) {
    elements.erase(
        std::remove(elements.begin(), elements.end(), value),
        elements.end()
    );
}

void Set::remove(const std::string& value) {
    const auto token = trim(value);
    int number = 0;

    if (tryParseInteger(token, number)) {
        remove(number);
        return;
    }

    labels.erase(
        std::remove(labels.begin(), labels.end(), token),
        labels.end()
    );
}

void Set::remove(const Set& value) {
    nestedSets.erase(
        std::remove(nestedSets.begin(), nestedSets.end(), value),
        nestedSets.end()
    );
}

// Check membership
bool Set::contains(int value) const {
    return std::find(elements.begin(), elements.end(), value)
        != elements.end();
}

bool Set::contains(const std::string& value) const {
    const auto token = trim(value);
    int number = 0;

    if (tryParseInteger(token, number)) {
        return contains(number);
    }

    return std::find(labels.begin(), labels.end(), token)
        != labels.end();
}

bool Set::contains(const Set& value) const {
    return std::find(nestedSets.begin(), nestedSets.end(), value)
        != nestedSets.end();
}

// Membership operators
bool Set::operator[](int value) const {
    return contains(value);
}

bool Set::operator[](const std::string& value) const {
    return contains(value);
}

bool Set::operator[](const Set& value) const {
    return contains(value);
}

// Display and basic information
void Set::display() const {
    std::cout << toString() << '\n';
}

int Set::size() const {
    return static_cast<int>(
        elements.size() + labels.size() + nestedSets.size()
        );
}

bool Set::isEmpty() const {
    return size() == 0;
}

void Set::clear() {
    elements.clear();
    labels.clear();
    nestedSets.clear();
}

int Set::getElement(int index) const {
    return elements.at(index);
}

// Union
Set Set::setUnion(const Set& other) const {
    Set result(*this);

    for (int value : other.elements) {
        result.add(value);
    }

    for (const auto& label : other.labels) {
        result.add(label);
    }

    for (const auto& nested : other.nestedSets) {
        result.add(nested);
    }

    return result;
}

// Intersection
Set Set::intersection(const Set& other) const {
    Set result;

    for (int value : elements) {
        if (other.contains(value)) result.add(value);
    }

    for (const auto& label : labels) {
        if (other.contains(label)) result.add(label);
    }

    for (const auto& nested : nestedSets) {
        if (other.contains(nested)) result.add(nested);
    }

    return result;
}

// Difference
Set Set::difference(const Set& other) const {
    Set result;

    for (int value : elements) {
        if (!other.contains(value)) result.add(value);
    }

    for (const auto& label : labels) {
        if (!other.contains(label)) result.add(label);
    }

    for (const auto& nested : nestedSets) {
        if (!other.contains(nested)) result.add(nested);
    }

    return result;
}

// Construct the power set
Set Set::powerSet() const {
    if (size() > static_cast<int>(kMaxPowerSetElements)) {
        throw std::length_error("Power set has too many subsets");
    }

    std::vector<Set> subsets(1);

    for (int value : elements) {
        extendSubsets(subsets, value);
    }

    for (const auto& label : labels) {
        extendSubsets(subsets, label);
    }

    for (const auto& nested : nestedSets) {
        extendSubsets(subsets, nested);
    }

    Set result;
    result.nestedSets = std::move(subsets);
    return result;
}

// Arithmetic operators
Set Set::operator+(const Set& other) const {
    return setUnion(other);
}

Set Set::operator*(const Set& other) const {
    return intersection(other);
}

Set Set::operator-(const Set& other) const {
    return difference(other);
}

Set& Set::operator+=(const Set& other) {
    *this = setUnion(other);
    return *this;
}

Set& Set::operator*=(const Set& other) {
    *this = intersection(other);
    return *this;
}

Set& Set::operator-=(const Set& other) {
    *this = difference(other);
    return *this;
}

// Equality operators
bool Set::operator==(const Set& other) const {
    if (size() != other.size()) return false;

    for (int value : elements) {
        if (!other.contains(value)) return false;
    }

    for (const auto& label : labels) {
        if (!other.contains(label)) return false;
    }

    for (const auto& nested : nestedSets) {
        if (!other.contains(nested)) return false;
    }

    return true;
}

bool Set::operator!=(const Set& other) const {
    return !(*this == other);
}

// Convert set to a string
std::string Set::toString() const {
    std::ostringstream output;
    output << '{';

    bool first = true;

    const auto separator = [&]() {
        if (!first) output << ", ";
        first = false;
        };

    for (int value : elements) {
        separator();
        output << value;
    }

    for (const auto& label : labels) {
        separator();
        output << label;
    }

    for (const auto& nested : nestedSets) {
        separator();
        output << nested.toString();
    }

    output << '}';
    return output.str();
}

// Construct a set from text
Set Set::fromString(const std::string& text) {
    std::size_t position = 0;
    Set result = parseSet(text, position);

    skipSpaces(text, position);

    if (position != text.size()) {
        throw std::invalid_argument("Unexpected trailing text");
    }

    return result;
}

// Write a set to a stream
std::ostream& operator<<(std::ostream& out, const Set& set) {
    out << set.toString();
    return out;
}

namespace {

    // Read a set written using braces
    std::istream& readBracedSet(std::istream& in, Set& set) {
        std::string text;
        int depth = 0;

        do {
            char character = 0;

            if (!in.get(character)) {
                in.setstate(std::ios::failbit);
                return in;
            }

            text.push_back(character);

            if (character == '{') ++depth;
            if (character == '}') --depth;

        } while (depth > 0);

        try {
            set = Set::fromString(text);
        }
        catch (const std::invalid_argument&) {
            in.setstate(std::ios::failbit);
        }

        return in;
    }

    // Support the old integer-count input format
    std::istream& readCountSet(std::istream& in, Set& set) {
        int count = 0;

        if (!(in >> count)) return in;

        if (count < 0) {
            in.setstate(std::ios::failbit);
            return in;
        }

        Set parsed;

        for (int index = 0; index < count; ++index) {
            int value = 0;

            if (!(in >> value)) return in;
            parsed.add(value);
        }

        set = parsed;
        return in;
    }

} // namespace

// Read a set from a stream
std::istream& operator>>(std::istream& in, Set& set) {
    in >> std::ws;

    if (!in) return in;

    if (in.peek() == '{') {
        return readBracedSet(in, set);
    }

    return readCountSet(in, set);
}



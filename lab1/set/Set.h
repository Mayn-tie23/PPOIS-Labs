
#pragma once

#include <vector>
#include <string>
#include <iosfwd>

/**
 * @brief Represents an unordered mathematical set.
 *
 * Supports unique integers, symbolic elements,
 * nested sets, set operations, and power sets.
 */
class Set {
private:
    std::vector<int> elements;
    std::vector<std::string> labels;
    std::vector<Set> nestedSets;

public:
    /** @brief Creates an empty set. */
    Set();

    /**
     * @brief Creates a set from text.
     * @param text Set expression such as {a, b, {a, b}}.
     */
    explicit Set(const std::string& text);

    /**
     * @brief Creates a copy of another set.
     * @param other Set to copy.
     */
    Set(const Set& other);

    /**
     * @brief Assigns another set.
     * @param other Set to copy.
     * @return Reference to this set.
     */
    Set& operator=(const Set& other);

    /** @brief Destroys the set. */
    ~Set();

    /**
     * @brief Adds an integer without duplicates.
     * @param value Integer to add.
     */
    void add(int value);

    /**
     * @brief Adds a symbolic element.
     * @param value Symbol to add.
     */
    void add(const std::string& value);

    /**
     * @brief Adds another set as an element.
     * @param value Nested set to add.
     */
    void add(const Set& value);

    /**
     * @brief Removes an integer.
     * @param value Integer to remove.
     */
    void remove(int value);

    /**
     * @brief Removes a symbolic element.
     * @param value Symbol to remove.
     */
    void remove(const std::string& value);

    /**
     * @brief Removes a nested set.
     * @param value Nested set to remove.
     */
    void remove(const Set& value);

    /**
     * @brief Checks whether an integer belongs to the set.
     * @param value Integer to find.
     * @return True if present.
     */
    bool contains(int value) const;

    /**
     * @brief Checks whether a symbol belongs to the set.
     * @param value Symbol to find.
     * @return True if present.
     */
    bool contains(const std::string& value) const;

    /**
     * @brief Checks whether a nested set is an element.
     * @param value Nested set to find.
     * @return True if present.
     */
    bool contains(const Set& value) const;

    /**
     * @brief Checks integer membership using [].
     * @param value Integer to find.
     * @return True if present.
     */
    bool operator[](int value) const;

    /**
     * @brief Checks symbolic membership using [].
     * @param value Symbol to find.
     * @return True if present.
     */
    bool operator[](const std::string& value) const;

    /**
     * @brief Checks nested-set membership using [].
     * @param value Nested set to find.
     * @return True if present.
     */
    bool operator[](const Set& value) const;

    /** @brief Displays the set. */
    void display() const;

    /**
     * @brief Returns the number of elements.
     * @return Cardinality of the set.
     */
    int size() const;

    /**
     * @brief Checks whether the set is empty.
     * @return True if empty.
     */
    bool isEmpty() const;

    /** @brief Removes all elements. */
    void clear();

    /**
     * @brief Gets an integer by its storage index.
     * @param index Index among integer elements.
     * @return Integer at the specified index.
     */
    int getElement(int index) const;

    /**
     * @brief Computes the union.
     * @param other Second set.
     * @return Union of both sets.
     */
    Set setUnion(const Set& other) const;

    /**
     * @brief Computes the intersection.
     * @param other Second set.
     * @return Common elements.
     */
    Set intersection(const Set& other) const;

    /**
     * @brief Computes the difference.
     * @param other Second set.
     * @return Elements absent from the second set.
     */
    Set difference(const Set& other) const;

    /**
     * @brief Constructs the power set.
     * @return Set containing every subset.
     * @throws std::length_error If too many elements
     * would make the result impractically large.
     */
    Set powerSet() const;

    /** @brief Returns the union of two sets. */
    Set operator+(const Set& other) const;

    /** @brief Returns the intersection of two sets. */
    Set operator*(const Set& other) const;

    /** @brief Returns the difference of two sets. */
    Set operator-(const Set& other) const;

    /** @brief Updates this set with the union. */
    Set& operator+=(const Set& other);

    /** @brief Updates this set with the intersection. */
    Set& operator*=(const Set& other);

    /** @brief Updates this set with the difference. */
    Set& operator-=(const Set& other);

    /**
     * @brief Checks equality regardless of element order.
     * @param other Set to compare.
     * @return True if the sets are equal.
     */
    bool operator==(const Set& other) const;

    /**
     * @brief Checks whether sets differ.
     * @param other Set to compare.
     * @return True if they differ.
     */
    bool operator!=(const Set& other) const;

    /**
     * @brief Converts the set to text.
     * @return Set expression with braces.
     */
    std::string toString() const;

    /**
     * @brief Parses a set expression.
     * @param text Set expression.
     * @return Parsed set.
     */
    static Set fromString(const std::string& text);
};

/**
 * @brief Writes a set to an output stream.
 * @param out Output stream.
 * @param set Set to write.
 * @return Output stream reference.
 */
std::ostream& operator<<(std::ostream& out, const Set& set);

/**
 * @brief Reads a set from an input stream.
 * @param in Input stream.
 * @param set Set to populate.
 * @return Input stream reference.
 */
std::istream& operator>>(std::istream& in, Set& set);

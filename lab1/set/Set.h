
#pragma once

#include <vector>
#include <iosfwd>

/**
 * @brief Represents a mathematical set of unique integers.
 *
 * Supports adding, removing, checking elements,
 * and performing union, intersection, and difference.
 */
class Set {
private:
    std::vector<int> elements;

public:
    /**
     * @brief Creates an empty set.
     */
    Set();

    /**
     * @brief Adds a unique integer to the set.
     * @param value Integer to add.
     */
    void add(int value);

    /**
     * @brief Removes an integer from the set if present.
     * @param value Integer to remove.
     */
    void remove(int value);

    /**
     * @brief Checks whether an integer exists in the set.
     * @param value Integer to search for.
     * @return True if found, otherwise false.
     */
    bool contains(int value) const;

    /**
     * @brief Displays all elements of the set.
     */
    void display() const;

    /**
     * @brief Returns the number of elements in the set.
     * @return Number of elements.
     */
    int size() const;

    /**
     * @brief Combines elements from two sets without duplicates.
     * @param other The second set.
     * @return A new set containing all unique elements.
     */
    Set setUnion(const Set& other) const;

    /**
     * @brief Finds elements common to both sets.
     * @param other The second set.
     * @return A new set containing common elements.
     */
    Set intersection(const Set& other) const;

    /**
     * @brief Finds elements in this set but not in another.
     * @param other The second set.
     * @return A new set containing the difference.
     */
    Set difference(const Set& other) const;

    /**
     * @brief Checks whether two sets contain the same elements.
     * @param other The set to compare.
     * @return True if both sets are equal, otherwise false.
     */
    bool operator==(const Set& other) const;

    /**
     * @brief Checks whether two sets are different.
     * @param other The set to compare.
     * @return True if the sets are different, otherwise false.
     */
    bool operator!=(const Set& other) const;

    /**
     * @brief Creates a copy of another set.
     * @param other The set to copy.
     */
    Set(const Set& other);

    /**
     * @brief Assigns another set to this set.
     * @param other The set to copy from.
     * @return Reference to this set.
     */
    Set& operator=(const Set& other);

    /**
     * @brief Removes all elements from the set.
     */
    void clear();

    /**
     * @brief Checks whether the set is empty.
     * @return True if the set has no elements, otherwise false.
     */
    bool isEmpty() const;

    /**
     * @brief Returns an element at the specified index.
     * @param index Position of the element.
     * @return Integer stored at the specified index.
     */
    int getElement(int index) const;

    /**
     * @brief Destroys the Set object.
     */
    ~Set();
};

/**
 * @brief Writes the elements of a set to an output stream.
 * @param out Output stream.
 * @param set Set to write.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& out, const Set& set);

/**
 * @brief Reads elements into a set from an input stream.
 * @param in Input stream.
 * @param set Set to populate.
 * @return Reference to the input stream.
 */
std::istream& operator>>(std::istream& in, Set& set);


#include "../set/Set.h"
#include <cassert>
#include <iostream>

int main() {
    Set mySet;

    // Test empty Set
    assert(mySet.isEmpty());
    assert(mySet.size() == 0);

    // Test adding elements
    mySet.add(10);
    assert(mySet.contains(10));
    assert(mySet.size() == 1);

    // Test duplicate elements
    mySet.add(10);
    assert(mySet.size() == 1);

    // Test adding another element
    mySet.add(20);
    assert(mySet.contains(20));
    assert(mySet.size() == 2);

    // Test getting element by index
    assert(mySet.getElement(0) == 10);
    assert(mySet.getElement(1) == 20);

    // Test removing elements
    mySet.remove(10);
    assert(!mySet.contains(10));
    assert(mySet.size() == 1);

    // Test removing a missing element
    mySet.remove(99);
    assert(mySet.size() == 1);

    // Test comparing equal Sets
    Set otherSet;
    otherSet.add(20);
    assert(mySet == otherSet);
    assert(!(mySet != otherSet));

    // Test comparing different Sets
    otherSet.add(30);
    assert(mySet != otherSet);
    assert(!(mySet == otherSet));
// Test equality with different insertion order
Set firstSet;
firstSet.add(10);
firstSet.add(20);
Set secondSet;
secondSet.add(20);
secondSet.add(10);

assert(firstSet == secondSet);

    // Test copy constructor
    Set copiedSet(mySet);
    assert(copiedSet == mySet);

    // Test assignment operator
    Set assignedSet;
    assignedSet = mySet;
    assert(assignedSet == mySet);

// Test copying an empty Set
Set emptySet;
Set emptyCopy(emptySet);
assert(emptyCopy.isEmpty());
assert(emptyCopy == emptySet);

// Test assigning an empty Set
Set emptySource;
Set filledSet;
filledSet.add(50);

filledSet = emptySource;

assert(filledSet.isEmpty());
assert(filledSet.size() == 0);

    // Test clearing the Set
    mySet.clear();
    assert(mySet.isEmpty());
    assert(mySet.size() == 0);

    // Test display
    mySet.display();
    // Test union
    firstSet.clear();
    secondSet.clear();
    firstSet.add(10);
    firstSet.add(20);

    secondSet.add(20);
    secondSet.add(30);

    Set unionResult = firstSet.setUnion(secondSet);

    assert(unionResult.size() == 3);
    assert(unionResult.contains(10));
    assert(unionResult.contains(20));
    assert(unionResult.contains(30));
    // Test intersection
    Set intersectionResult = firstSet.intersection(secondSet);

    assert(intersectionResult.size() == 1);
    assert(intersectionResult.contains(20));
    assert(!intersectionResult.contains(10));
    assert(!intersectionResult.contains(30));
    // Test difference
    Set differenceResult = firstSet.difference(secondSet);

    assert(differenceResult.size() == 1);
    assert(differenceResult.contains(10));
    assert(!differenceResult.contains(20));
    assert(!differenceResult.contains(30));
    // Test displaying a non-empty Set
    firstSet.display();
    std::cout << "All Set tests passed!\n";
    return 0;
}


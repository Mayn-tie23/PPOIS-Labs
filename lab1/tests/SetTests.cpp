
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

    // Test copy constructor
    Set copiedSet(mySet);
    assert(copiedSet == mySet);

    // Test assignment operator
    Set assignedSet;
    assignedSet = mySet;
    assert(assignedSet == mySet);

    // Test clearing the Set
    mySet.clear();
    assert(mySet.isEmpty());
    assert(mySet.size() == 0);

    // Test display
    mySet.display();

    std::cout << "All Set tests passed!\n";
    return 0;
}



#include "../set/Set.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int main() {
    Set mySet;

    // Test empty Set
    assert(mySet.isEmpty());
    assert(mySet.size() == 0);

    // Test adding elements and ignoring duplicates
    mySet.add(10);
    assert(mySet.contains(10));
    assert(mySet.size() == 1);

    mySet.add(10);
    assert(mySet.size() == 1);

    mySet.add(20);
    assert(mySet.contains(20));
    assert(mySet.size() == 2);

    // Test getting elements by index
    assert(mySet.getElement(0) == 10);
    assert(mySet.getElement(1) == 20);

    // Test removing present and missing elements
    mySet.remove(10);
    assert(!mySet.contains(10));
    assert(mySet.size() == 1);

    mySet.remove(99);
    assert(mySet.size() == 1);

    // Test equality and inequality
    Set otherSet;
    otherSet.add(20);

    assert(mySet == otherSet);
    assert(!(mySet != otherSet));

    otherSet.add(30);
    assert(mySet != otherSet);
    assert(!(mySet == otherSet));

    // Test equality regardless of insertion order
    Set firstSet;
    firstSet.add(10);
    firstSet.add(20);

    Set secondSet;
    secondSet.add(20);
    secondSet.add(10);

    assert(firstSet == secondSet);

    // Test copy constructor and assignment operator
    Set copiedSet(mySet);
    assert(copiedSet == mySet);

    Set assignedSet;
    assignedSet = mySet;
    assert(assignedSet == mySet);

    // Test copying and assigning an empty Set
    Set emptySet;
    Set emptyCopy(emptySet);

    assert(emptyCopy.isEmpty());
    assert(emptyCopy == emptySet);

    Set filledSet;
    filledSet.add(50);
    filledSet = emptySet;

    assert(filledSet.isEmpty());
    assert(filledSet.size() == 0);

    // Test clearing and displaying a Set
    mySet.clear();
    assert(mySet.isEmpty());
    assert(mySet.size() == 0);
    mySet.display();

    // Test union, intersection, and difference
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

    Set intersectionResult = firstSet.intersection(secondSet);

    assert(intersectionResult.size() == 1);
    assert(intersectionResult.contains(20));
    assert(!intersectionResult.contains(10));
    assert(!intersectionResult.contains(30));

    Set differenceResult = firstSet.difference(secondSet);

    assert(differenceResult.size() == 1);
    assert(differenceResult.contains(10));
    assert(!differenceResult.contains(20));
    assert(!differenceResult.contains(30));

    firstSet.display();

    // Test output and input streams
    Set originalSet;
    originalSet.add(10);
    originalSet.add(20);

    std::stringstream stream;
    stream << originalSet;

    Set loadedSet;
    stream >> loadedSet;

    assert(loadedSet == originalSet);

    // Test parsing nested and symbolic sets
    Set parsed = Set::fromString("{a, b, {a, b}, {}}");

    assert(parsed.size() == 4);
    assert(parsed.contains("a"));
    assert(parsed.contains("b"));
    assert(parsed.contains(Set::fromString("{a, b}")));
    assert(parsed.contains(Set::fromString("{}")));

    parsed.add("a");
    assert(parsed.size() == 4);

    // Test a power set with two elements
    Set powerBase = Set::fromString("{1, 2}");
    Set power = powerBase.powerSet();

    assert(power.size() == 4);
    assert(power.contains(Set::fromString("{}")));
    assert(power.contains(Set::fromString("{1}")));
    assert(power.contains(Set::fromString("{2}")));
    assert(power.contains(Set::fromString("{1, 2}")));

    // Test arithmetic operators
    Set first = Set::fromString("{1, 2}");
    Set second = Set::fromString("{2, 3}");

    assert((first + second) == Set::fromString("{1, 2, 3}"));
    assert((first * second) == Set::fromString("{2}"));
    assert((first - second) == Set::fromString("{1}"));

    // Test compound assignment operators
    Set compound = first;

    compound += second;
    assert(compound == Set::fromString("{1, 2, 3}"));

    compound = first;
    compound *= second;
    assert(compound == Set::fromString("{2}"));

    compound = first;
    compound -= second;
    assert(compound == Set::fromString("{1}"));

    // Test membership operators
    assert(first[1]);
    assert(!first[3]);

    // Additional tests for previously uncovered branches
    {
        // Mixed sets with integers, symbols, and nested sets
        Set mixedA = Set::fromString("{1, 2, a, b, {7}, {8}}");
        Set mixedB = Set::fromString("{2, 3, b, c, {8}, {9}}");

        assert((mixedA + mixedB).size() == 9);
        assert((mixedA * mixedB) ==
            Set::fromString("{2, b, {8}}"));
        assert((mixedA - mixedB) ==
            Set::fromString("{1, a, {7}}"));

        assert(mixedA["a"]);
        assert(mixedA[Set::fromString("{7}")]);
        assert(!mixedA["missing"]);
        assert(!mixedA[Set::fromString("{9}")]);

        // Remove numeric, symbolic, and nested elements
        Set removable = Set::fromString("{1, 2, a, {7}}");

        removable.remove("2");
        removable.remove("a");
        removable.remove(Set::fromString("{7}"));

        assert(removable == Set::fromString("{1}"));

        removable.add("  3  ");
        assert(removable.contains(3));

        removable.clear();
        assert(removable.isEmpty());

        // Power sets with mixed types and no elements
        Set mixedPower = Set::fromString("{1, a, {2}}");
        Set mixedSubsets = mixedPower.powerSet();

        assert(mixedSubsets.size() == 8);
        assert(mixedSubsets.contains(Set::fromString("{}")));
        assert(mixedSubsets.contains(mixedPower));

        assert(Set::fromString("{}").powerSet() ==
            Set::fromString("{{}}"));

        // Power set size limit
        Set largeSet;

        for (int index = 0; index < 17; ++index) {
            largeSet.add(index);
        }

        bool tooLarge = false;

        try {
            (void)largeSet.powerSet();
        }
        catch (const std::length_error&) {
            tooLarge = true;
        }

        assert(tooLarge);

        // Invalid set expressions must be rejected
        const auto checkInvalid = [](const std::string& text) {
            bool rejected = false;

            try {
                (void)Set::fromString(text);
            }
            catch (const std::invalid_argument&) {
                rejected = true;
            }

            assert(rejected);
            };

        checkInvalid("not a set");
        checkInvalid("{a,}");
        checkInvalid("{a,,b}");
        checkInvalid("{a");
        checkInvalid("{a{b}}");
        checkInvalid("{a} extra");
        checkInvalid("{a, {b}");

        // Invalid symbolic values must be rejected
        bool badSymbol = false;

        try {
            removable.add("a,b");
        }
        catch (const std::invalid_argument&) {
            badSymbol = true;
        }

        assert(badSymbol);

        badSymbol = false;

        try {
            removable.add("   ");
        }
        catch (const std::invalid_argument&) {
            badSymbol = true;
        }

        assert(badSymbol);

        // Symbols that are not valid integers
        Set unusual;

        unusual.add("42x");
        unusual.add("9999999999999999999999999");

        assert(unusual.contains("42x"));
        assert(unusual.contains("9999999999999999999999999"));

        unusual.remove("42x");
        assert(!unusual.contains("42x"));

        // Inequality with different element types
        assert(Set::fromString("{1}") !=
            Set::fromString("{1, 2}"));

        assert(Set::fromString("{1}") !=
            Set::fromString("{2}"));

        assert(Set::fromString("{a}") !=
            Set::fromString("{b}"));

        assert(Set::fromString("{{1}}") !=
            Set::fromString("{{2}}"));

        // Construct from text and access elements
        Set constructed("{1, a, {2}}");

        assert(constructed.size() == 3);
        assert(constructed.getElement(0) == 1);

        bool badIndex = false;

        try {
            (void)constructed.getElement(100);
        }
        catch (const std::out_of_range&) {
            badIndex = true;
        }

        assert(badIndex);

        // Stream input: braces and old integer-count format
        std::stringstream bracedStream("{a, {2}, 1}");

        Set bracedLoaded;
        bracedStream >> bracedLoaded;

        assert(bracedLoaded == constructed);

        std::stringstream oldStream("3 1 2 3");

        Set oldLoaded;
        oldStream >> oldLoaded;

        assert(oldLoaded == Set::fromString("{1, 2, 3}"));

        // Stream output can be parsed again
        std::stringstream output;
        output << constructed;

        assert(Set::fromString(output.str()) == constructed);

        // Invalid streams must fail
        Set unchanged("{5}");

        std::stringstream invalidBraces("{a,}");
        invalidBraces >> unchanged;

        assert(invalidBraces.fail());
        assert(unchanged == Set::fromString("{5}"));

        std::stringstream incompleteBraces("{a");
        incompleteBraces >> unchanged;

        assert(incompleteBraces.fail());

        std::stringstream invalidCount("-1 2");
        invalidCount >> unchanged;

        assert(invalidCount.fail());

        std::stringstream incompleteCount("2 1 bad");
        incompleteCount >> unchanged;

        assert(incompleteCount.fail());

        std::stringstream notCount("bad");
        notCount >> unchanged;

        assert(notCount.fail());

        std::stringstream emptyInput;
        emptyInput >> unchanged;

        assert(emptyInput.fail());
    }

    std::cout << "All Set tests passed!\n";

    return 0;
}

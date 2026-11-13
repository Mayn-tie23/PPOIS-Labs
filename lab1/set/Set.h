#pragma once

#include <vector>
#include<iosfwd>

class Set {
private:
	std::vector<int> elements;

public:
	Set();
	void add(int value);
	void remove(int value);
	bool contains(int value) const;
	void display() const;
	int size() const;
	Set setUnion(const Set& other) const;
	Set intersection(const Set& other) const;
	Set difference(const Set& other)  const;
	bool operator==(const Set& other) const;
	bool operator!=(const Set& other) const;
	Set(const Set& other);
	Set& operator=(const Set& other);
	void clear();
	bool isEmpty() const;
	int getElement(int index) const;
	~Set();
};
std::ostream& operator<<(std::ostream& out, const Set& set);
std::istream& operator>>(std::istream& in, Set& set);

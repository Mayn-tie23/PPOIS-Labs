#pragma once

#include <vector>
class Multiset {
private:
	std::vector<int> elements;

public:
	Multiset();
	~Multiset();
	void add(int value);
	void remove(int value);
	int count(int value) const;
	bool contains(int value)const;
	void display() const;
	int size()const;
	Multiset setUnion(const Multiset& other)const;
	Multiset intersection(const Multiset& other)const;
	Multiset difference(const Multiset& other)const;
	bool operator==(const Multiset& other)const;
	bool operator!=(const Multiset& other)const;
	Multiset(const Multiset& other);
	Multiset& operator=(const Multiset& other);
	void clear();
	bool isEmpty()const;
	int getElement(int index)
		const;
};

#include"Multiset.h"
#include<iostream>
#include<algorithm>

Multiset::Multiset() {
}
Multiset::~Multiset() {
}
void  Multiset::add(int value) {
	elements.push_back(value);
}
void Multiset::remove(int value) {
	auto it =
		std::find(elements.begin(), elements.end(), value);
	if (it != elements.end()) {
		elements.erase(it);
		}
}
int Multiset::count(int value) const {
	return
		std::count(elements.begin(), elements.end(), value);
}
bool Multiset::contains(int value)const {
	return count(value) > 0;
}
void Multiset::display() const {
	for (int value : elements)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
}
int Multiset::size()const {
	return
		static_cast<int>(elements.size());
}
Multiset
Multiset::setUnion(const Multiset& other)const {
	Multiset result = *this; 
	for (int value : other.elements)
	{
		if (result.count(value) < other.count(value)) {
			result.add(value);
		}
	}
	return result;
}
Multiset
Multiset::intersection(const Multiset& other)const {
	Multiset result;
	for (int value : elements)
	{
		if (result.count(value) < other.count(value)) {
			result.add(value);
		}
	}
	return result;
}
Multiset
Multiset::difference(const Multiset& other)const {
	Multiset result = *this;
	for (int value : other.elements)
	{
			result.remove(value);
		}
	return result;
	}
bool Multiset::operator==(const Multiset& other)const {
	if (size() != other.size())
		return false;
	for (int value : elements) {
		if (count(value)!=other.count(value))
			return false;
	}
	return true;
}
bool Multiset::operator!=(const Multiset& other) const {
	return!(*this == other);
}
Multiset::Multiset(const Multiset& other) {
	elements = other.elements;
}
Multiset&
Multiset::operator=(const Multiset& other) {
	if (this != &other) {
		elements = other.elements;
	}
	return *this;
}
void Multiset::clear() {
	elements.clear();
}
bool Multiset::isEmpty() const {
	return elements.empty();
}
int Multiset::getElement(int index) const {
	return elements.at(index);
}

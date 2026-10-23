#include "Set.h"
#include <iostream>
#include <algorithm>

Set::Set() {

}
Set::~Set() {
}
void Set::add(int value){
	if (!contains(value))
	{
		elements.push_back(value);
	}
	}
void Set::remove(int value) {
	auto it =
		std::find(elements.begin(), elements.end(), value);
	if (it != elements.end()) {
		elements.erase(it);
	}
}
bool Set::contains(int value)
const {
	return
		std::find(elements.begin(), elements.end(), value)
		!= elements.end();
}
void Set::display() const {
	for (int value : elements)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
}
int Set::size()const{
	return
		static_cast<int>(elements.size());
}
Set Set::setUnion(const Set& other) const {
	Set result;
	for (int value : elements) {
		result.add(value);
	}
	for (int value : other.elements) {
		result.add(value);
	}
	return result;
}
Set Set::intersection(const Set& other) const {
	Set result;
	for (int value : elements) {
		if (other.contains(value))
		{
			result.add(value);
		}
	}
	return result;
}
Set Set::difference(const Set& other) const {
	Set result;
	for (int value : elements) {
		if (!other.contains(value)) {
			result.add(value);
		}
	}
	return result;
}
bool Set::operator==(const Set& other)const {
	if (size() != other.size())
		return false;
	for (int value : elements) {
		if (!other.contains(value))
			return false;
	}
	return true;
}
bool Set::operator!=(const Set& other) const {
	return!(*this == other);
}
Set::Set(const Set& other) {
	elements = other.elements;
}
Set& Set::operator=(const Set& other){
	if (this != &other) {
		elements = other.elements;
	}
	return *this;
}
void Set::clear() {
	elements.clear();
}
bool Set::isEmpty() const {
	return elements.empty();
}
	int Set::getElement(int index) const {
		return elements.at(index);
	}
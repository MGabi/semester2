#include "DynamicVector.h"


DynamicVector::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector() {
	delete[] this->elems;
}

int DynamicVector::operator-(const TElement &elem) {
	int pos = this->findElemPosition(elem);
	if (pos != -1){
		this->remove(pos);
		return 1;
	}
	return 0;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v) {
	if (this == &v)
		return *this;
	
	this->size = v.size;
	this->capacity = v.capacity;
	
	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

void DynamicVector::add(const TElement& e) {
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

void DynamicVector::update(int position, const TElement &e) {
	this->elems[position] = e;
}


void DynamicVector::remove(int position) {
	for (int i=position; i<this->size; i++)
		this->elems[i] = this->elems[i+1];
	//delete &this->elems[size-1];
	this->size--;
}

void DynamicVector::resize(double factor) {
	this->capacity *= static_cast<int>(factor);
	
	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

TElement* DynamicVector::getAllElems() const {
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}

int DynamicVector::findElemPosition(const TElement elem) {
	for (int i=0; i<this->size; i++)
        if (this->elems[i] == elem)
			return i;

	return -1;
}

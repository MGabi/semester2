#pragma once
#include "Tutorial.h"

typedef Tutorial TElement;

class DynamicVector {

private:
	TElement* elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	explicit DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector.
	void add(const TElement& e);

	void remove(int position);
	int operator-(const TElement& elem);

	void update(int position, const TElement& e);

	int getSize() const;
	int findElemPosition(const TElement elem);
	TElement* getAllElems() const;

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};


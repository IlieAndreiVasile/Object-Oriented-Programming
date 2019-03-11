#pragma once

template <class T>

class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;

public:
	DynamicVector(int capacity = 10);		// default constructor for a DynamicVector

	DynamicVector(const DynamicVector& v);		// copy constructor for a DynamicVector

	~DynamicVector();		// destructor

	DynamicVector& operator=(const DynamicVector& v);		// assignment operator for a DynamicVector
		
	//bool DynamicVector<T>::operator==(const T& rhs);		// overloads the "==" operator

	T& operator[](int pos);
	/*
	Overloading the subscript operator
	Input: pos - a valid position within the vector.
	Output: a reference to the element o position pos.
	*/

	DynamicVector& operator+(T e)		// overloads the "+" operator for an element of DynamicVector
	{
		if (this->size == this->capacity)
			this->resize();
		this->elems[this->size] = e;
		this->size++;
		return *this;
	}		

	void operator-(T e);		// overloads the "-" operator

	int find(T e);
	// Searches for an element in the DynamiVector.

	void add(T e);
	// Adds an element to the current DynamicVector.

	void del(int pos);
	// Deletes an element from the current DynamicVector.

	T* getAllElems();
	int getSize() const;

private:
	void resize(double factor = 2);
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
};

template <class T>
DynamicVector<T>::DynamicVector(int capacity = 10)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <class T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <class T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <class T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

//template <class T>
//bool DynamicVector<T>::operator==(const T& rhs)
//{
//	if (this.getSize() == rhs.getSize() && this.getColour() == rhs.getColour())
//		return true;
//	else
//		return false;
//}

template <class T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <class T>
DynamicVector <T> operator+(T e, DynamicVector<T> v)
{
	v.add(e);
	return v;
}

template <class T>
void DynamicVector<T>::operator-(T e)
{
	int pos = this->find(e);
	this->del(pos);
}

template <typename T>
int DynamicVector<T>::find(T e)
{
	for (int i = 0; i < this->size; i++)
		if (e.getSize() == elems[i].getSize() && e.getColour() == elems[i].getColour())
			return i;
	return -1;
}

template <class T>
void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <class T>
void DynamicVector<T>::del(int pos)
{
	this->elems[pos] = this->elems[this->size - 1];
	this->size--;
}

template <class T>
T* DynamicVector<T>::getAllElems()
{
	return this->elems;
}

template <class T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <class T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}
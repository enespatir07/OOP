#include "pfarray.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace my_namespace;
// ITERATOR

// No parameter constructor to assign ptr to a null pointer
template <typename T>
PFarray<T>::Iterator::Iterator() : ptr(nullptr) {}

// iterator constructor with shared_ptr parameter
template <typename T>
PFarray<T>::Iterator::Iterator(shared_ptr<T> p) : ptr(p.get()) {}

// overloaded operator to dereference ptr
template <typename T>
T &PFarray<T>::Iterator::operator*() const { return *ptr; }

// overloaded arrow operator
template <typename T>
T *PFarray<T>::Iterator::operator->() const { return ptr; }

// it returns the difference between the indices of the two iterators
template <typename T>
T PFarray<T>::Iterator::operator-(const Iterator &other) const { return ptr - other.ptr; }

// moves the iterator n steps forward (to the right) in the array.
template <typename T>
typename PFarray<T>::Iterator PFarray<T>::Iterator::operator+(int n) const
{
    Iterator result = *this;
    result.ptr += n;
    return result;
}
// moves the iterator n steps backwards (to the left) in the array.
template <typename T>
typename PFarray<T>::Iterator PFarray<T>::Iterator::operator-(int n) const
{
    Iterator result = *this;
    result.ptr -= n;
    return result;
}

// overloaded prefix increment operator
template <typename T>
typename PFarray<T>::Iterator &PFarray<T>::Iterator::operator++()
{
    // move to next address
    ptr++;
    // then return reference of the class
    return *this;
}
// overloaded prefix decrement operator
template <typename T>
typename PFarray<T>::Iterator &PFarray<T>::Iterator::operator--()
{
    // move to previous address
    --ptr;
    // then return reference of the class
    return *this;
}

// copy constructor
template <typename T>
typename PFarray<T>::Iterator &PFarray<T>::Iterator::operator=(const Iterator &rightSide)
{
    ptr = rightSide.ptr;
    return *this;
}
// compares the two iterators in terms of their position in the array
template <typename T>
bool PFarray<T>::Iterator::operator<(const Iterator &other) const
{
    return ptr < other.ptr;
}

// overloaded equal operator to check if two iterator points to same address
template <typename T>
bool PFarray<T>::Iterator::operator==(const Iterator &rightSide) const { return ptr == rightSide.ptr; }

// opposite of equal operator
template <typename T>
bool PFarray<T>::Iterator::operator!=(const Iterator &rightSide) const { return !(*this == rightSide); }

// getter
template <typename T>
T *PFarray<T>::Iterator::getPtr() const { return ptr; }

// CONSTITERATOR

// No parameter constructor to assign ptr to a null pointer
template <typename T>
PFarray<T>::ConstIterator::ConstIterator() : ptr(nullptr) {}

// ConstIterator constructor with shared_ptr parameter
template <typename T>
PFarray<T>::ConstIterator::ConstIterator(shared_ptr<T> p) : ptr(p.get()) {}

// overloaded operator to dereference ptr
template <typename T>
const T &PFarray<T>::ConstIterator::operator*() const { return *ptr; }

// overloaded arrow operator
template <typename T>
const T *PFarray<T>::ConstIterator::operator->() const { return ptr; }

// overloaded prefix increment operator
template <typename T>
typename PFarray<T>::ConstIterator &PFarray<T>::ConstIterator::operator++()
{
    // move to next addres
    ptr++;
    return *this;
}

// overloaded prefix decrement operator
template <typename T>
typename PFarray<T>::ConstIterator &PFarray<T>::ConstIterator::operator--()
{
    // move to previous addres
    ptr--;
    return *this;
}

// copy constructor
template <typename T>
typename PFarray<T>::ConstIterator &PFarray<T>::ConstIterator::operator=(const ConstIterator &other)
{
    ptr = other.ptr;
    return *this;
}
// overloaded equal operator
template <typename T>
bool PFarray<T>::ConstIterator::operator==(const ConstIterator &rightSide) const { return ptr == rightSide.ptr; }

// opposite of equal operator
template <typename T>
bool PFarray<T>::ConstIterator::operator!=(const ConstIterator &rightSide) const { return !(*this == rightSide); }

// PFARRAY

// Returns container size
template <typename T>
int PFarray<T>::size() const { return used; }

// no parameter constructor
template <typename T>
PFarray<T>::PFarray() : capacity(2), used(0), dataArray(nullptr) {}

// Tests whether container is empty
template <typename T>
bool PFarray<T>::empty() const { return dataArray == nullptr; }

// Clear all content
template <typename T>
void PFarray<T>::clear()
{
    dataArray.reset();
    dataArray = nullptr;
    used = 0;
    capacity = 2;
}

// append element to dataArray
template <typename T>
void PFarray<T>::addElement(const T &element)
{
    // if addElement called for the first time for this object then allocate some space for dataArray
    if (used == 0)
    {
        shared_ptr<T> temp(new T[capacity]);
        dataArray = temp;
    }
    // if used reachs up to capacity then double the capacity
    if (capacity == used)
    {
        capacity *= 2;
        shared_ptr<T> newPtr(new T[capacity]);
        // assigning data array contents to a temporary array
        for (int i = 0; i < used; i++)
            newPtr.get()[i] = dataArray.get()[i];

        dataArray.reset();
        dataArray = newPtr;
    }
    // appending the element to array
    dataArray.get()[used++] = element;
}

// Returns iterator to beginning
template <typename T>
typename PFarray<T>::Iterator PFarray<T>::begin() const
{
    // if data array is empty then throw exception
    if (dataArray == nullptr)
        throw invalid_argument("Invalid");
    return PFarray<T>::Iterator(dataArray);
}

// Returns iterator to end
template <typename T>
typename PFarray<T>::Iterator PFarray<T>::end() const
{
    // if data array is empty then throw exception
    if (dataArray == nullptr)
        throw invalid_argument("Invalid");
    shared_ptr<T> temp(dataArray, dataArray.get() + used);
    return PFarray<T>::Iterator(temp);
}

// Returns a constant iterator to beginning
template <typename T>
typename PFarray<T>::ConstIterator PFarray<T>::cbegin() const
{
    // if data array is empty then throw exception
    if (dataArray == nullptr)
        throw invalid_argument("Invalid");
    return ConstIterator(dataArray);
}

// Returns a constant iterator to end
template <typename T>
typename PFarray<T>::ConstIterator PFarray<T>::cend() const
{
    // if data array is empty then throw exception
    if (dataArray == nullptr)
        throw invalid_argument("Invalid");
    shared_ptr<T> temp(dataArray, dataArray.get() + used);
    return ConstIterator(temp);
}

// Erase element pointed by the given iterator
template <typename T>
void PFarray<T>::erase(Iterator it)
{
    // if given iterator is empty then throw exception
    if (it.getPtr() == nullptr)
        throw invalid_argument("Invalid");

    // checking if given iterator is in array or not
    bool flag = false;
    for (int i = 0; i < used; i++)
    {
        if (dataArray.get()[i] == *it)
        {
            flag = true;
            break;
        }
    }
    // if not then throw exception
    if (!flag)
        throw invalid_argument("Invalid");
    //
    int i = 0;
    while (i < used)
    {
        // Looping through the array till finding the content given by iterator
        if (dataArray.get()[i] == *it)
        {
            // When found, Shift the elements after the iterator one position to the left
            for (int j = i; j < used - 1; j++)
                dataArray.get()[j] = dataArray.get()[j + 1];
            // Decrease the used variable by 1
            --used;
            break;
        }
        i++;
    }
}

bool my_namespace::compare(int a, int b) { return a > b; }

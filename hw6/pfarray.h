#ifndef PFARRAY_H
#define PFARRAY_H
#include <iostream>
#include <memory>
using namespace std;
namespace my_namespace
{
template <class T>
class PFarray
{
public:
    class Iterator
    {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::forward_iterator_tag iterator_category;
        // Constructors and destructor
        Iterator();
        Iterator(shared_ptr<T>);
        // Overloaded operators
        T &operator*() const;                             // overloaded operator to dereference ptr
        T *operator->() const;                            // overloaded arrow operator
        T operator-(const Iterator &other) const;         // it returns the difference between the indices of the two iterators
        Iterator operator+(int n) const;                  // moves the iterator n steps forward (to the right) in the array.
        Iterator operator-(int n) const;                  // moves the iterator n steps backwards (to the left) in the array.
        Iterator &operator++();                           // overloaded prefix increment operator
        Iterator &operator--();                           // overloaded prefix decrement operator
        Iterator &operator=(const Iterator &);            // copy constructor
        bool operator<(const Iterator &other) const;      // compares the two iterators in terms of their position in the array
        bool operator==(const Iterator &rightSide) const; // overloaded equal operator to check if two iterator points to same address
        bool operator!=(const Iterator &rightSide) const; // opposite of equal operator
        // getter
        T *getPtr() const;

    private:
        T *ptr;
    };

    class ConstIterator
    {
    public:
        // Constructors
        ConstIterator();
        ConstIterator(shared_ptr<T>);
        // Overloaded operators
        const T &operator*() const;                               // overloaded operator to dereference ptr
        const T *operator->() const;                              // overloaded arrow operator
        ConstIterator &operator++();                              // overloaded prefix increment operator
        ConstIterator &operator--();                              // overloaded prefix decrement operator
        ConstIterator &operator=(const ConstIterator &rightSide); // copy constructor
        bool operator==(const ConstIterator &rightSide) const;    // overloaded equal operator to check if two iterator points to same address
        bool operator!=(const ConstIterator &rightSide) const;    // opposite of equal operator

    private:
        const T *ptr;
    };
    PFarray();                         // no parameter constructor
    int size() const;                  // Returns container size
    bool empty() const;                // Tests whether container is empty
    void addElement(const T &element); // appends element to data array
    void erase(Iterator pos);          // Erases element pointed by the given iterator
    void clear();                      // Clears all content
    Iterator begin() const;            // Returns iterator to beginning
    Iterator end() const;              // Returns iterator to end
    ConstIterator cbegin() const;      // Returns a constant iterator to beginning
    ConstIterator cend() const;        // Returns a constant iterator to end

private:
    std::shared_ptr<T> dataArray; // array of PFarray object
    int capacity;                 // amount of storage space currently allocated
    int used;                     // number of elements currently stored
};
bool compare(int, int);
template class PFarray<int>;
template class PFarray<char>;

} // namespace my_namespace
#endif
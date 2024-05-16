#ifndef _UTIL_H_
#define _UTIL_H_
#include <iostream>
#include <list>
using namespace std;
namespace my_namespace
{
class DayofYearSet
{
public:
    class DayofYear
    {
    public:
        // CONSTRUCTORS
        DayofYear(const int, const int);
        DayofYear();
        // OTHER FUNCTION
        bool checkDate(const int, const int) const;
        void set(const int, const int);
        // GETTER
        int getMonth() const;
        int getDay() const;

    private:
        int month, day;
    };
    // CONSTRUCTOR
    DayofYearSet(const list<DayofYear>);
    // DESTRUCTOR
    ~DayofYearSet();
    // OTHER FUNCTIONS
    void remove(const int, const int);
    int size() const;
    // OVERLOADED OPERATORS
    friend ostream &operator<<(ostream &, const DayofYearSet &);
    bool operator==(const DayofYearSet &) const;
    bool operator!=(const DayofYearSet &) const;
    DayofYearSet operator+(const DayofYearSet &) const;
    DayofYearSet operator+(const DayofYear &) const;
    DayofYearSet operator-(const DayofYearSet &) const;
    DayofYearSet operator-(const DayofYear &) const;
    DayofYearSet operator^(const DayofYearSet &) const;
    DayofYearSet operator!() const;
    DayofYearSet operator[](const int i) const;
    // GETTERS
    DayofYear *getSet() const;

private:
    DayofYear *mySet;
    int length;
};
} // namespace my_namespace
#endif
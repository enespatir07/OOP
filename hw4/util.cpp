#include "util.h"
#include <iostream>
#include <list>
using namespace std;

namespace my_namespace
{

// CONSTRUCTORS
// No-parameter DayofYear constructor
DayofYearSet::DayofYear::DayofYear() : day(1), month(1) {}
// DayofYear constructor
DayofYearSet::DayofYear::DayofYear(const int day_, const int month_)
{
    // checks and set correct values
    if (checkDate(day_, month_))
        set(day_, month_);
    // if invalid then throw error
    else
        throw invalid_argument("Invalid Input Throwed");
}

DayofYearSet::DayofYearSet(const list<DayofYear> temp)
{
    // assigning values of list to * mySet
    length = temp.size();
    mySet = new DayofYear[length];
    int i = 0;
    for (auto it = temp.begin(); it != temp.end(); it++, i++)
        mySet[i] = *it;

    // Creating a temp array with values at 1 repetition
    DayofYear *newone = new DayofYear[length];
    int counter = 0;
    for (int j = 0; j < length; j++)
    {
        bool status = false;
        for (int i = 0; i < counter; i++)
        {
            if (getSet()[j].getDay() == newone[i].getDay() && getSet()[j].getMonth() == newone[i].getMonth())
            {
                status = true;
                break;
            }
        }
        if (!status)
            newone[counter++] = getSet()[j];
    }
    // assigning new one to mySet * and updating length of the set
    length = counter;
    delete[] mySet;
    mySet = newone;
}
// DESTRUCTOR
DayofYearSet::~DayofYearSet() { delete[] mySet; }

// OTHER FUNCTIONS
void DayofYearSet::remove(const int day, const int month)
{
    // checking if given day and month are in the list
    bool status = false;
    for (int i = 0; i < length; i++)
    {
        if (getSet()[i].getDay() == day && getSet()[i].getMonth() == month)
            status = true;
    }
    // if not, then throw error
    if (!status)
        throw invalid_argument("Invalid Input Throwed");

    // finding the index of wanted date
    int indexofTarget = -1;
    for (int i = 0; i < length; i++)
    {
        if (getSet()[i].getDay() == day && getSet()[i].getMonth() == month)
        {
            indexofTarget = i;
            break;
        }
    }
    // then shifting array
    if (indexofTarget != -1)
    {
        for (int i = indexofTarget; i < length - 1; i++)
        {
            mySet[i] = getSet()[i + 1];
        }
        // and updating length
        length--;
    }
}

// OVERLOADED OPERATORS
ostream &operator<<(ostream &os, const DayofYearSet &other)
{
    // printing DayofYearSet details
    for (int i = 0; i < other.size(); i++)
    {
        os << "(" << other.getSet()[i].getDay() << ", " << other.getSet()[i].getMonth() << ")" << endl;
    }
    return os;
}

bool DayofYearSet::operator==(const DayofYearSet &other) const
{
    // if lengths are noth same return false
    if (length != other.size())
        return false;

    // checks if two sets are the same
    for (size_t i = 0; i < length; i++)
    {
        bool status = false;
        for (size_t j = 0; j < length; j++)
        {
            if (getSet()[i].getDay() == other.getSet()[j].getDay() && getSet()[i].getMonth() == other.getSet()[j].getMonth())
                status = true;
        }
        if (status == false)
            return false;
    }

    return true;
}

bool DayofYearSet::operator!=(const DayofYearSet &other) const { return !(*this == other); }

DayofYearSet DayofYearSet::operator+(const DayofYearSet &other) const
{

    list<DayofYear> temp;
    int myLen = size(), otherLen = other.size();
    // appending mySet values to temporary list
    for (int i = 0; i < myLen; i++)
        temp.push_back(getSet()[i]);
    // // appending mySet values of other object to temporary list
    for (int i = 0; i < otherLen; i++)
        temp.push_back(other.getSet()[i]);
    return DayofYearSet(temp);
}

DayofYearSet DayofYearSet::operator+(const DayofYear &other) const 
{
    // appending mySet values to temporary list
    list<DayofYear> temp;
    for (int i = 0; i < length; i++)
        temp.push_back(getSet()[i]);
    // appending DayofYear object to temporary list
    temp.push_back(other);
    return DayofYearSet(temp);
}

DayofYearSet DayofYearSet::operator-(const DayofYearSet &other) const
{
    list<DayofYear> temp;
    for (int i = 0; i < length; i++)
    {
        bool flag = false;
        for (int j = 0; j < other.size(); j++)
        {
            // chechking if there is same vale
            if (getSet()[i].getDay() == other.getSet()[j].getDay() && getSet()[i].getMonth() == other.getSet()[j].getMonth())
                flag = true;
        }
        // if it cant find same value then append that object to list
        if (flag == false)
            temp.push_back(getSet()[i]);
    }

    return DayofYearSet(temp);
}

DayofYearSet DayofYearSet::operator-(const DayofYear &other) const
{
    list<DayofYear> temp;
    bool status = false;
    // checking if DayofYear object(date) is in the set
    for (int i = 0; i < length; i++)
    {
        if (getSet()[i].getDay() == other.getDay() && getSet()[i].getMonth() == other.getMonth())
        {
            status = true;
            break;
        }
    }
    // if not then return the original one
    if (!status)
    {
        for (int i = 0; i < length; i++)
        {
            temp.push_back(getSet()[i]);
        }
        return DayofYearSet(temp);
    }

    else
    {
        // finding the index of wanted date
        int indexofTarget = -1;
        for (int i = 0; i < length; i++)
        {
            if (getSet()[i].getDay() == other.getDay() && getSet()[i].getMonth() == other.getMonth())
            {
                indexofTarget = i;
                break;
            }
        }

        for (int i = 0; i < indexofTarget; i++)
            temp.push_back(getSet()[i]);

        // shift values
        if (indexofTarget != -1)
        {
            for (int i = indexofTarget; i < length - 1; i++)
                temp.push_back(getSet()[i + 1]);
        }
        return DayofYearSet(temp);
    }
}

DayofYearSet DayofYearSet::operator^(const DayofYearSet &other) const
{
    list<DayofYear> temp;
    for (size_t i = 0; i < length; ++i)
    {
        for (size_t j = 0; j < other.size(); ++j)
        {
            // checking if there are same values
            if (getSet()[i].getDay() == other.getSet()[j].getDay() && getSet()[i].getMonth() == other.getSet()[j].getMonth())
            {
                // if yes then append it to temp list and switch to next index
                temp.push_back(getSet()[i]);
                break;
            }
        }
    }
    return DayofYearSet(temp);
}

DayofYearSet DayofYearSet::operator[](const int i) const
{
    //if index is invalid then throw error
    if (i < 0 || i >= length)
        throw invalid_argument("Invalid Input Throwed");
    // if not then simply return the object at the wanted index
    list<DayofYear> temp;
    temp.push_back(getSet()[i]);
    return DayofYearSet(temp);
}

DayofYearSet DayofYearSet::operator!() const
{
    list<DayofYear> temp;
    // counter for mySet dates
    int counter = 0;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= 31; j++)
        {
            // if mySet dates are encountered then continue
            if (getSet()[counter].getDay() == j && getSet()[counter].getMonth() == i)
            {
                counter++;
                continue;
            }
            // months with 30 days
            else if (i == 4 || i == 6 || i == 9 || i == 11)
            {
                if (j == 31)
                    break;
                temp.push_back(DayofYear(j, i));
            }
            // februray
            else if (i == 2)
            {
                if (j == 29)
                    break;
                temp.push_back(DayofYear(j, i));
            }
            // months with 31 days
            else
            {
                temp.push_back(DayofYear(j, i));
            }
        }
    }

    return DayofYearSet(temp);
}
// OTHER FUNCTION

bool DayofYearSet::DayofYear::checkDate(const int day_, int month) const
{
    if (day_ < 1 || day_ > 31 || month < 1 || month > 12)
        return false;
    // checks february month
    else if (month == 2 && day_ > 29)
        return false;
    // checks month with 30 days
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day_ > 30)
        return false;
    else
        return true;
}

void DayofYearSet::DayofYear::set(const int day_, const int month_)
{
    // assigns day and month
    day = day_;
    month = month_;
}
// GETTERS
DayofYearSet::DayofYear *DayofYearSet::getSet() const { return mySet; }
int DayofYearSet::size() const { return length; }
int DayofYearSet::DayofYear::getMonth() const { return month; }
int DayofYearSet::DayofYear::getDay() const { return day; }
} // namespace my_namespace
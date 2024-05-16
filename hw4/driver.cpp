#include "util.h"
#include <fstream>
#include <iostream>
#include <list>
using namespace std;
using namespace my_namespace;

int main()
{
    cout << "Testing DayofYear constructor" << endl;
    cout << "------------------" << endl;
    DayofYearSet::DayofYear testDate(2, 1);
    cout << "testDate object created with values:";
    cout << "(" << testDate.getDay() << ", " << testDate.getMonth() << ")" << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing DayofYear constructor with no parameter" << endl;
    cout << "------------------" << endl;
    DayofYearSet::DayofYear testDate2;
    cout << "testDate2 object created with values:";
    cout << "(" << testDate2.getDay() << ", " << testDate2.getMonth() << ")" << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing DayofYear constructor with invalid input" << endl;
    cout << "------------------" << endl;
    try
    {
        // Invalid values on purpose
        DayofYearSet::DayofYear(0, 0);
    }
    catch (const invalid_argument &e)
    {
        std::cerr << "Output: " << e.what() << endl;
    }
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing checkDate function" << endl;
    cout << "------------------" << endl;
    cout << "Entering invalid values (0, 0)" << endl;
    cout << (testDate.checkDate(0, 0) ? "true" : "false") << endl;
    cout << "Entering valid values (1, 1)" << endl;
    cout << (testDate.checkDate(1, 1) ? "true" : "false") << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing set function for testDate" << endl;
    cout << "------------------" << endl;
    testDate.set(3, 3);
    cout << "testDate after: " << endl
         << "(" << testDate.getDay() << ", " << testDate.getMonth() << ")" << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing getDay function for testDate" << endl;
    cout << "------------------" << endl;
    cout << "Output: " << testDate.getDay() << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing getMonth function for testDate" << endl;
    cout << "------------------" << endl;
    cout << "Output: " << testDate.getMonth() << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing DayofYearSet constructor and creating testSet1, testSet2 and testSet3" << endl;
    cout << "------------------" << endl;
    list<DayofYearSet::DayofYear> l1, l2, l3;
    for (int i = 1; i <= 4; i++)
    {
        l1.push_back(DayofYearSet::DayofYear(i, 1));
        if (i != 1)
            l2.push_back(DayofYearSet::DayofYear(i, 1));
        if (i != 4)
            l3.push_back(DayofYearSet::DayofYear(i + 3, 1));
    }
    DayofYearSet testSet1(l1);
    DayofYearSet testSet2(l2);
    DayofYearSet testSet3(l3);
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing size function for testSet1" << endl;
    cout << "------------------" << endl;
    cout << "Size of testSet1: " << testSet1.size() << endl;
    cout << "Size of testSet2: " << testSet2.size() << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator<< on DayofYear objects" << endl;
    cout << "------------------" << endl;
    cout << "testSet1, testSet2, testSet3" << endl;
    cout << testSet1 << endl
         << endl;
    cout << testSet2 << endl
         << endl;
    cout << testSet3 << endl
         << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing remove function for testSet1 and testSet3" << endl;
    cout << "------------------" << endl;
    testSet1.remove(1, 1);
    testSet3.remove(6, 1);
    cout << "After removing (1,1) and (6,1) from testSet1 and testSet3 respectively" << endl;
    cout << testSet1 << endl;
    cout << testSet3 << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing remove function with invalid input" << endl;
    cout << "------------------" << endl;
    try
    {
        // Invalid values on purpose (day (10, 10) is not on the set)
        list<DayofYearSet::DayofYear> temp;
        temp.push_back(DayofYearSet::DayofYear(1, 1));
        temp.push_back(DayofYearSet::DayofYear(2, 1));
        DayofYearSet tempset(temp);
        tempset.remove(10, 10);
    }
    catch (const invalid_argument &e)
    {
        std::cerr << "Output: " << e.what() << endl;
    }
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator==" << endl;
    cout << "------------------" << endl;
    cout << "testSet1 == testSet2 is " << (testSet1 == testSet2 ? "true" : "false") << endl;
    cout << "testSet1 == testSet3 is " << (testSet1 == testSet3 ? "true" : "false") << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator!=" << endl;
    cout << "------------------" << endl;
    cout << "testSet1 != testSet2 is " << (testSet1 != testSet2 ? "true" : "false") << endl;
    cout << "testSet1 != testSet3 is " << (testSet1 != testSet3 ? "true" : "false") << endl;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator+ with (const DayofYearSet &) parameter" << endl;
    cout << "------------------" << endl;
    cout << "After testSet1 + testSet3" << endl;
    cout << testSet1 + testSet3;
    cout << "After testSet1 + testSet2" << endl;
    cout << testSet1 + testSet2;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator+ with (const DayofYear &) parameter" << endl;
    cout << "------------------" << endl;
    cout << "After testSet3 + testDate" << endl;
    cout << testSet3 + testDate;
    cout << "After testSet3 + testDate2" << endl;
    cout << testSet3 + testDate2;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator- with (const DayofYearSet &) parameter" << endl;
    cout << "------------------" << endl;
    cout << "After testSet1 - testSet3" << endl;
    cout << testSet1 - testSet3;
    cout << "After testSet2 - testSet3" << endl;
    cout << testSet2 - testSet3;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator- with (const DayofYear &) parameter" << endl;
    cout << "------------------" << endl;
    cout << "After testSet1 - testDate" << endl;
    cout << testSet1 - testDate;
    cout << "After testSet1 - testDate2" << endl;
    cout << testSet1 - testDate2;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator^" << endl;
    cout << "------------------" << endl;
    cout << "After testSet1 ^ testSet3" << endl;
    cout << (testSet1 ^ testSet3);
    cout << "After testSet1 ^ testSet2" << endl;
    cout << (testSet1 ^ testSet2);
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator!" << endl;
    cout << "------------------" << endl;
    cout << "After !testSet1" << endl;
    cout << !testSet1;
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator[]" << endl;
    cout << "------------------" << endl;
    cout << "After testset1[0]" << endl;
    cout << testSet1[0];
    cout << "After testset1[1]" << endl;
    cout << testSet1[1];
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing overloaded operator[] with invalid input" << endl;
    cout << "------------------" << endl;
    try
    {
        // Invalid values on purpose
        testSet1[-1];
    }
    catch (const invalid_argument &e)
    {
        std::cerr << "Output: " << e.what() << endl;
    }
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    cout << "Testing getSet function" << endl;
    cout << "------------------" << endl;
    testSet1.getSet();
    cout << "------------------" << endl;
    cout << "Test complete" << endl
         << endl;

    fstream my_file, my_file2;
    my_file.open("set1.txt", ios::out);
    my_file2.open("set3.txt", ios::out);
    if (!my_file || !my_file2)
    {
        cerr << "File is not created\n";
        my_file.close();
        my_file2.close();
    }
    else
    {
        my_file << testSet1;
        my_file2 << testSet3;
    }
    cout << "testSet1 is written to the text file\n";
    cout << "testSet3 is written to the text file\n";
    my_file.close();
    my_file2.close();
}

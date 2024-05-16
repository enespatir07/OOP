#include "pfarray.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
using namespace my_namespace;
int main()
{
    PFarray<int> pfInt;
    PFarray<char> pfChar;
    PFarray<int> pfEmpty;
    cout << "Creating pfInt, pfChar and pfEmpty objects out of PFarray class" << endl
         << endl;
    cout << "Testing addElemenet function for pfInt and pfChar objects" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        pfInt.addElement(10 * (i + 1));
        pfChar.addElement(97 + i);
    }
    cout << "Printing them using range based for loop" << endl;
    for (auto it : pfInt)
        cout << it << " ";
    cout << endl;
    for (auto it : pfChar)
        cout << it << " ";
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "addElement and range based for loop test done" << endl;
    cout << endl
         << endl;

    cout << "Testing empty function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Is pfInt empty: " << (pfInt.empty() ? "true" : "false") << endl;
    cout << "Is pfEmpty empty: " << (pfEmpty.empty() ? "true" : "false") << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "empty done" << endl;
    cout << endl
         << endl;

    cout << "Testing size function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Size of pfInt: " << pfInt.size() << endl;
    cout << "Size of pfChar: " << pfChar.size() << endl;
    cout << "Size of pfEmpty: " << pfEmpty.size() << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "size done" << endl;
    cout << endl
         << endl;

    cout << "Testing begin function" << endl;
    cout << "------------------------------------------------------------------" << endl;

    try
    {
        cout << "begin of pfInt: " << *(pfInt.begin()) << endl;
        cout << "begin of pfChar: " << *(pfChar.begin()) << endl;
        cout << "begin of pfEmpty: ";
        cout << *(pfEmpty.begin());
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "begin done" << endl;
    cout << endl
         << endl;

    cout << "Testing cbegin function" << endl;
    cout << "------------------------------------------------------------------" << endl;

    try
    {
        cout << "cbegin of pfInt: " << *(pfInt.cbegin()) << endl;
        cout << "cbegin of pfChar: " << *(pfChar.cbegin()) << endl;
        cout << "cbegin of pfEmpty: ";
        cout << *(pfEmpty.cbegin());
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "cbegin done" << endl;
    cout << endl
         << endl;

    cout << "Testing end function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    try
    {
        cout << "end of pfInt: " << *(--pfInt.end()) << endl;
        cout << "end of pfChar: " << *(--pfChar.end()) << endl;
        cout << "end of pfEmpty: ";
        cout << *(pfEmpty.end());
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "end done" << endl;
    cout << endl
         << endl;

    cout << "Testing cend function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    try
    {
        cout << "cend of pfInt: " << *(--pfInt.cend()) << endl;
        cout << "cend of pfChar: " << *(--pfChar.cend()) << endl;
        cout << "cend of pfEmpty: ";
        cout << *(pfEmpty.cend());
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "cend done" << endl;
    cout << endl
         << endl;

    cout << "Testing erase function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Erasing first element of pfInt and pfChar" << endl;

    try
    {
        pfInt.erase(pfInt.begin());
        cout << "pfInt after the process" << endl;
        for (auto it : pfInt)
            cout << it << " ";
        cout << endl;
        pfChar.erase(pfChar.begin());
        cout << "pfChar after the process" << endl;
        for (auto it : pfChar)
            cout << it << " ";
        cout << endl;
        cout << "Erasing an element of pfEmpty" << endl;
        pfEmpty.erase(pfInt.begin());
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "erase done" << endl;
    cout << endl
         << endl;

    cout << "Testing clear function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Creating a temporary PFarray object and clearing it" << endl;
    PFarray<int> temp;
    temp.addElement(1);
    temp.addElement(2);
    try
    {
        cout << "Before clear works: ";
        for (auto it : temp)
            cout << it << " ";
        cout << endl;
        temp.clear();
        cout << "After clear worked: ";
        for (auto it : temp)
            cout << it << " ";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "clear done" << endl;
    cout << endl
         << endl;

    cout << "Creating Iterator objects named it1 and it2 for pfInt and pfChar" << endl;
    cout << "Creating ConstIterator objects named cit1 and cit2 for pfInt and pfChar" << endl
         << endl;
    auto it1 = pfInt.begin();
    auto it2 = pfChar.begin();
    auto cit1 = ++pfInt.cbegin();
    auto cit2 = ++pfChar.cbegin();
    cout << "Testing overloaded operator*" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Performing operator* on it1: " << *(it1) << endl;
    cout << "Performing operator* on it2: " << *(it2) << endl;
    cout << "Performing operator* on cit1: " << *(cit1) << endl;
    cout << "Performing operator* on cit2: " << *(cit2) << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "operator* done" << endl;
    cout << endl
         << endl;

    cout << "Testing overloaded operator->" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Performing operator-> on it1: " << it1.operator->() << endl;
    cout << "Performing operator-> on it2: " << it2.operator->() << endl;
    cout << "Performing operator-> on it1: " << cit1.operator->() << endl;
    cout << "Performing operator-> on it2: " << cit2.operator->() << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "operator-> done" << endl;
    cout << endl
         << endl;

    cout << "Testing overloaded operator++" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "*it1 before prefix applied: " << *(it1) << endl;
    cout << "*it2 before prefix applied: " << *(it2) << endl;
    cout << "*cit1 before prefix applied: " << *(cit1) << endl;
    cout << "*cit2 before prefix applied: " << *(cit2) << endl
         << endl;
    cout << "*it1 after prefix applied: " << *(++it1) << endl;
    cout << "*it2 after prefix applied: " << *(++it2) << endl;
    cout << "*cit1 after prefix applied: " << *(++cit1) << endl;
    cout << "*cit2 after prefix applied: " << *(++cit2) << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "operator++ done" << endl;
    cout << endl
         << endl;

    cout << "Testing overloaded operator-- " << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "*it1 before prefix applied: " << *(it1) << endl;
    cout << "*it2 before prefix applied: " << *(it2) << endl;
    cout << "*cit1 before prefix applied: " << *(cit1) << endl;
    cout << "*cit2 before prefix applied: " << *(cit2) << endl
         << endl;
    cout << "*it1 after prefix applied: " << *(--it1) << endl;
    cout << "*it2 after prefix applied: " << *(--it2) << endl;
    cout << "*cit1 after prefix applied: " << *(--cit1) << endl;
    cout << "*cit2 after prefix applied: " << *(--cit2) << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "operator-- done" << endl;
    cout << endl
         << endl;

    cout << "Testing overloaded operator=" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "creating an iterator named tempIt and assigning it to it1" << endl;
    auto tempIt = ++pfInt.begin();
    cout << "before assignment it1 and tempIt: " << *it1 << ", " << *tempIt << endl;
    it1 = tempIt;
    cout << "after assignment it1 and tempIt: " << *it1 << ", " << *tempIt << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "operator= done" << endl;
    cout << endl
         << endl;

    cout << "Testing overloaded operator==" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Creating two same iterators named x1 and x2 and a different one named x3" << endl;
    auto x1 = pfInt.begin();
    auto x2 = pfInt.begin();
    auto x3 = (--pfInt.end());
    cout << "Are x1 and x2 the same: " << (x1 == x2 ? "true" : "false") << endl;
    cout << "Are x3 and x2 the same: " << (x3 == x2 ? "true" : "false") << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "operator==done" << endl;
    cout << endl
         << endl;

    cout << "Testing overloaded operator!=" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Are x1 and x2 not the same: " << (x1 != x2 ? "true" : "false") << endl;
    cout << "Are x3 and x2 not the same: " << (x3 != x2 ? "true" : "false") << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "operator!= done" << endl;
    cout << endl
         << endl;

    cout << "Testing std::move function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Creating temp2 and temp3 objects out of PFarray class" << endl;
    cout << "And moving from temp3 to temp2" << endl;
    PFarray<int> temp2, temp3;
    temp2.addElement(3);
    temp2.addElement(4);
    temp3.addElement(5);
    temp3.addElement(6);
    try
    {
        cout << "temp2 before move works: ";
        for (auto it : temp2)
            cout << it << " ";
        cout << "\ntemp3 before move works: ";
        for (auto it : temp3)
            cout << it << " ";
        cout << endl;
        temp2 = move(temp3);
        cout << "temp2 After move works : ";
        for (auto it : temp2)
            cout << it << " ";
        cout << endl;
        cout << "temp3 After move works : ";

        for (auto it : temp3)
            cout << it << " ";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }

    cout << "------------------------------------------------------------------" << endl;
    cout << "std::move done" << endl;
    cout << endl
         << endl;

    cout << "Testing std::find function" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Search for the value 30 in pfInt" << endl;
    auto iterator1 = find(pfInt.begin(), pfInt.end(), 30);
    if (iterator1 != pfInt.end())
        cout << "Found value: " << *iterator1 << '\n';
    else
        cout << "Value not found\n";
    cout << "Search for the value 'c' in pfChar" << endl;
    auto iterator2 = find(pfChar.begin(), pfChar.end(), 'c');
    if (iterator2 != pfChar.end())
        cout << "Found value: " << *iterator2 << '\n';
    else
        cout << "Value not found\n";

    cout << "Search for the value 35 in pfInt" << endl;
    auto iterator3 = find(pfInt.begin(), pfInt.end(), 35);
    if (iterator3 != pfInt.end())
        cout << "Found value: " << *iterator3 << '\n';
    else
        cout << "Value not found\n";
    cout << "Search for the value 'k' in pfChar" << endl;
    auto iterator4 = find(pfChar.begin(), pfChar.end(), 'k');
    if (iterator4 != pfChar.end())
        cout << "Found value: " << *iterator4 << '\n';
    else
        cout << "Value not found\n";
    cout << "------------------------------------------------------------------" << endl;
    cout << "std::find done" << endl;
    cout << endl
         << endl;

    cout << "Testing std::for_each" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for_each(pfInt.begin(), pfInt.end(), [&](int x)
             { cout << x << " "; });
    cout << endl;
    for_each(pfChar.begin(), pfChar.end(), [&](char x)
             { cout << x << " "; });
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "std::for_each done" << endl;
    cout << endl
         << endl;

    cout << "Testing std::sort" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "pfInt before sorted" << endl;
    for (auto it : pfInt)
        cout << it << " ";
    cout << endl;
    cout << "pfInt after sorted" << endl;
    sort(pfInt.begin(), pfInt.end(), compare);
    for (auto it : pfInt)
        cout << it << " ";
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "std::sort done" << endl;
    cout << endl
         << endl;
}
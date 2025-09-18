#include "DoublyList.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    // testing with integers
    cout << "Testing with integers" << endl;
    DoublyList<int> intList;
    cout << "Empty? " << intList.isEmpty() << endl;

    intList.append(1);
    intList.append(2);
    intList.append(3);
    cout << "Appended 1, 2, & 3: " << intList << endl;
    
    intList.insert(1, 4);
    cout << "Insert 4 at Node 2: " << intList << endl;
    
    cout << "Index 2: " << intList << endl;
    
    intList.replace(2, 5);
    cout << "Replaced Node 3 with 5: " << intList << endl;

    cout << "Search 1: " << intList.search(1) << endl;
    cout << "Search 100: " << intList.search(100) << endl;

    intList.remove(1);
    cout << "Removed Node 2: " << intList << endl;
    cout << "Length: " << intList.getLength() << endl;

    // testing with strings
    cout << endl;
    cout << "Testing with strings" << endl;
    DoublyList<string> strList;

    strList.append("burger");
    strList.append("taco");
    strList.append("burrito");
    cout << "Appended burger, taco, and burrito: " << strList;
    
    strList.insert(1, "noodles");
    cout << "Inserted noodles at Node 2: " << strList << endl;

    strList.replace(0, "pizza");
    cout << "Replaced Node 1 with pizza: " << strList << endl;
    
    cout << "Search for taco: " << strList.search("taco") << endl;
    cout << "Search for banana: " << strList.search("banana") << endl;

    strList.remove(2);
    cout << "Removed Node 2: " << strList << endl;
    cout << "Length: " << strList.getLength() << endl;

    // other test cases
    cout << endl;
    cout << "Other test/edge cases" << endl;
    DoublyList<int> testList;
    intList.append(1);
    cout << testList;

    testList.remove(0); // removing the only element in list
    cout << "After remove: " << testList << endl;

    cout << "Empty? " << testList.isEmpty() << endl;

    return 0;
}
#include <iostream>
#include "unorderedSetType.h"

using namespace std;

int main()
{
    // Create an array of integers and an array of strings
    int intArray[] = { 1, 2, 3, 4, 5 };
    string strArray[] = { "apple", "banana", "orange", "kiwi", "grape" };

    // Create unorderedSet objects for integers and strings
    unorderedSetType<int> intSet;
    unorderedSetType<string> strSet;

    // Add values from the integer array to the integer set
    for (int i = 0; i < sizeof(intArray) / sizeof(intArray[0]); ++i)
    {
        intSet.insertEnd(intArray[i]);
    }

    // Add values from the string array to the string set
    for (int i = 0; i < sizeof(strArray) / sizeof(strArray[0]); ++i)
    {
        strSet.insertEnd(strArray[i]);
    }

    // Verify that insertEnd does not allow duplicate entries
    cout << "Integer Set: ";
    intSet.print();
    cout << "String Set: ";
    strSet.print();

    // Verify that insertAt allows unique items 
    intSet.insertAt(3, 6);       
    strSet.insertAt(3, "mango"); 

    cout << "After insertAt:" << endl;
    cout << "Integer Set: ";
    intSet.print();
    cout << "String Set: ";
    strSet.print();

    // Verify that the replaceAt function allows a unique item 
    intSet.replaceAt(4, 7);     
    strSet.replaceAt(4, "pear"); 

    cout << "After replaceAt:" << endl;
    cout << "Integer Set: ";
    intSet.print();
    cout << "String Set: ";
    strSet.print();

    // Test union as well as intersection operations
    unorderedSetType<int> intSet1, intSet2, intUnion, intIntersection;
    intSet1.insertEnd(1);
    intSet1.insertEnd(2);
    intSet1.insertEnd(3);
    intSet2.insertEnd(3);
    intSet2.insertEnd(4);
    intSet2.insertEnd(5);

    intUnion = intSet1 + intSet2;
    intIntersection = intSet1 - intSet2;

    cout << "Union of integer sets: ";
    intUnion.print();
    cout << "Intersection of integer sets: ";
    intIntersection.print();

    return 0;
}


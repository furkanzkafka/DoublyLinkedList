/// Mowen Tan and Furkan Ozdemir
/// Testing doubly linked list
#include <iostream>
#include <cstdlib>
#include "unorderedDoubleLinkedList.h"

using namespace std;
int main()
{
    unorderedDoubleLinkedList<int> exampleList;

    cout << "----- Testing insert functions ----- " << endl;
    exampleList.insertFirst(12);
    exampleList.insertFirst(24);
    exampleList.insertLast(36);
    exampleList.insertLast(48);
    cout << "Testing reverse print -- Expected Output: 48 36 12 24" << endl;
    exampleList.print(false);
    cout << "Testing forward print -- Expected Output: 24 12 36 48" << endl;
    exampleList.print(true);

    cout << endl;
    cout << "--- Testing insertNode --- " << endl;
    exampleList.insertNode(256, 1);
    exampleList.insertNode(512, 3);
    cout << "Expected Output: 24 256 12 512 36 48" << endl;
    exampleList.print(true);
    cout << "Expected Output: 48 36 512 12 256 24" << endl;
    exampleList.print(false);

    cout << endl;
    cout << "--- Testing deleteNode --- " << endl;
    cout << "Deleting 36 from list" << endl;
    exampleList.deleteNode(36);
    cout << "Forward print -- Expected Output: 24 256 12 512 48" << endl;
    exampleList.print(true);
    cout << "Deleting first and last from list" << endl;
    exampleList.deleteNode(24);
    cout << "test";
    exampleList.deleteNode(48);
    cout << "Forward print -- Expected Output: 256 12 512" << endl;
    exampleList.print(true);

    exampleList.deleteNodeByIndex(1);
    cout << "Forward print -- Expected Output: 12 512" << endl;
    exampleList.print(true);



    cout << "All tests executed\n";
    return 0;
}

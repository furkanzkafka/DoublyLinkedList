#include <iostream>
#include <cassert>
using namespace std;
//Definition of the double linking node
template <class Type>
struct dNodeType
{
    Type info;
    dNodeType<Type>* next;
    dNodeType<Type>* prev;
};
//*****************  class DoubleLinkedList   ****************
template <class Type>
class DoubleLinkedList
{
public:
    const DoubleLinkedList<Type>& operator=
        (const DoubleLinkedList<Type>&);
    //Overload the assignment operator.
    void initializeList();
    //Initialize the list to an empty state.
    //Postcondition: first = NULL, last = NULL, count = 0;
    bool isEmptyList() const;
    //Function to determine whether the list is empty. 
    //Postcondition: Returns true if the list is empty,
    //               otherwise it returns false.
    void print(bool) const;
    //Function to output the data contained in each node.
    //Argument specifies order of print - true = forward, false = reverse print
    int length() const;
    //Function to return the number of nodes in the list.
    //Postcondition: The value of count is returned.
    void destroyList();
    //Function to delete all the nodes from the list.
    //Postcondition: first = NULL, last = NULL, count = 0;
    Type front() const;
    //Function to return the first element of the list.
    //Precondition: The list must exist and must not be 
    //              empty.
    //Postcondition: If the list is empty, the program
    //               terminates; otherwise, the first 
    //               element of the list is returned.
    Type back() const;
    //Function to return the last element of the list.
    //Precondition: The list must exist and must not be 
    //              empty.
    //Postcondition: If the list is empty, the program
    //               terminates; otherwise, the last  
    //               element of the list is returned.
    virtual bool search(const Type& searchItem) const = 0;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the 
    //               list, otherwise the value false is 
    //               returned.
    virtual void insertFirst(const Type& newItem) = 0;
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               last points to the last node in the list, 
    //               and count is incremented by 1.
    virtual void insertLast(const Type& newItem) = 0;
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem 
    //               is inserted at the end of the list,
    //               last points to the last node in the list,
    //               and count is incremented by 1.
    virtual void insertNode(const Type& newItem, int index) = 0;
    //Function to insert newItem to be the element at location index.
    //Postcondition: If index is valid newItem will inserted at that location and
    //count is incremented by 1.

        virtual void deleteNode(const Type & deleteItem) = 0;
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing 
    //               deleteItem is deleted from the list.
    //               first points to the first node, last
    //               points to the last node of the updated 
    //               list, and count is decremented by 1.
    DoubleLinkedList();
    //default constructor
    //Initializes the list to an empty state.
    //Postcondition: first = NULL, last = NULL, count = 0; 
    DoubleLinkedList(const DoubleLinkedList<Type>& otherList);
    //copy constructor
    ~DoubleLinkedList();
    //destructor
    //Deletes all the nodes from the list.
    //Postcondition: The list object is destroyed. 
    void insertAt(const Type& item, int index);
    //Insert the given item at the index
    //Index must be valid (between 0 and count)
    //If index==count add to end of list
    //If list is empty index must be 0
protected:
    int count;   //variable to store the number of 
                 //elements in the list
    dNodeType<Type>* first; //pointer to the first node of the list
    dNodeType<Type>* last;  //pointer to the last node of the list
private:
    void copyList(const DoubleLinkedList<Type>& otherList);
    //Function to make a copy of otherList.
    //Postcondition: A copy of otherList is created and
    //               assigned to this list.
};
template <class Type>
bool DoubleLinkedList<Type>::isEmptyList() const
{
    return(first == NULL);
}
template <class Type>
DoubleLinkedList<Type>::DoubleLinkedList() //default constructor
{
    first = NULL;
    last = NULL;
    count = 0;
}
template <class Type>
void DoubleLinkedList<Type>::destroyList()
{
    dNodeType<Type>* temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != NULL)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->next; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
                 //been set to NULL by the while loop
    count = 0;
}
template <class Type>
void DoubleLinkedList<Type>::initializeList()
{
    destroyList(); //if the list has any nodes, delete them
}
template <class Type>
void DoubleLinkedList<Type>::print(bool forward) const
{
    dNodeType<Type>* current; //pointer to traverse the list
    if (forward) {
        current = first;    //set current so that it points to
                            //the first node
        while (current != NULL) //while more data to print
        {
            cout << current->info << " ";
            current = current->next;
        }
    }
    else {
        current = last;    //set current so that it points to
                            //the first node
        while (current != NULL) //while more data to print
        {
            cout << current->info << " ";
            current = current->prev;
        }
    }
    cout << endl;
}//end print
template <class Type>
int DoubleLinkedList<Type>::length() const
{
    return count;
}  //end length
template <class Type>
Type DoubleLinkedList<Type>::front() const
{
    assert(first != NULL);
    return first->info; //return the info of the first node
}//end front
template <class Type>
Type DoubleLinkedList<Type>::back() const
{
    assert(last != NULL);
    return last->info; //return the info of the last node
}//end back
template <class Type>
void DoubleLinkedList<Type>::copyList
(const DoubleLinkedList<Type>& otherList)
{
    dNodeType<Type>* newNode; //pointer to create a node
    dNodeType<Type>* previous; //pointer to traverse the origin list
    dNodeType<Type>* current; //pointer to traverse the list in process
    if (first != NULL) //if the list is nonempty, make it empty
        destroyList();
    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the
                                   //list to be copied
        count = otherList.count;
        //copy the first node
        first = new dNodeType<Type>;  //create the node
        first->info = current->info; //copy the info
        first->next = NULL;        //set the link field of
        first->prev = NULL;         //the node to NULL

        previous = first;
        last = first;              //make last point to the
                                   //first node
        current = current->next;     //make current point to
                                     //the next node
           //copy the remaining list
        while (current != NULL)
        {
            newNode = new dNodeType<Type>;  //create a node
            newNode->info = current->info; //copy the and pointers
            newNode->next = NULL;
            newNode->prev = previous;

            last->next = newNode;  //attach newNode after last
            last = newNode;        //make last point to
                                   //the actual last node
            current = current->next;   //make current point
                                       //to the next node
            previous = newNode; // newNode will be previous to next nodes
        }//end while
    }//end else
}//end copyList
template <class Type>
DoubleLinkedList<Type>::~DoubleLinkedList() //destructor
{
    destroyList();
}//end destructor
template <class Type>
DoubleLinkedList<Type>::DoubleLinkedList
(const DoubleLinkedList<Type>& otherList)
{
    first = NULL;
    copyList(otherList);
}//end copy constructor
         //overload the assignment operator
template <class Type>
const DoubleLinkedList<Type>& DoubleLinkedList<Type>::operator=
(const DoubleLinkedList<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    return *this;
}

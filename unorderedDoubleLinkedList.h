#ifndef H_UnorderedDoubleLinkedList
#define H_UnorderedDoubleLinkedList

#include "DoubleLinkedList.h"
using namespace std;
template <class Type>
class unorderedDoubleLinkedList : public DoubleLinkedList<Type>
{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the 
    //               list, otherwise the value false is 
    //               returned.
    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: this->first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               this->last points to the this->last node in the  
    //               list, and this->count is incremented by 1.
    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: this->first points to the new list, newItem 
    //               is inserted at the end of the list,
    //               this->last points to the this->last node in the 
    //               list, and this->count is incremented by 1.

    void insertNode(const Type& newItem, int index);
    //Function to insert newItem to be the element at location index.
    //Postcondition: If index is valid newItem will inserted at that location and
    // count is incremented by 1.

        void deleteNode(const Type & deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing 
    //               deleteItem is deleted from the list.
    //               this->first points to the this->first node, this->last
    //               points to the this->last node of the updated 
    //               list, and this->count is decremented by 1.

        void deleteNodeByIndex(int index);
        //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing 
        //               deleteItem is deleted from the list.
        //               this->first points to the this->first node, this->last
        //               points to the this->last node of the updated 
        //               list, and this->count is decremented by 1.
};
template <class Type>
bool unorderedDoubleLinkedList<Type>::
search(const Type& searchItem) const
{
    dNodeType<Type>* current; //pointer to traverse the list
    bool found = false;

    current = this->first; //set current to point to the this->first 
                     //node in the list
    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->next; //make current point to
                                     //the next node
    return found;
}//end search
template <class Type>
void unorderedDoubleLinkedList<Type>::insertFirst(const Type& newItem)
{

    dNodeType<Type>* new_node = new dNodeType<Type>;
    new_node->info = newItem;

    if (this->first != NULL)
    {
        new_node->next = this->first;
        this->first->prev = new_node;
        new_node->prev = NULL;
        this->first = new_node;

        this->count += 1;
    }
    else {
        this->first = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;

        this->count += 1;
    }

    this->last = this->first;

    while (this->last->next != NULL)
    {
        this->last = this->last->next;
    }

}//end insertFirst
template <class Type>
void unorderedDoubleLinkedList<Type>::insertLast(const Type& newItem)
{
    dNodeType<Type>* new_node = new dNodeType<Type>;
    new_node->info = newItem;

    if (this->first != NULL)
    {
        new_node->prev = this->last;
        this->last->next = new_node;
        new_node->next = NULL;
        this->last = new_node;

        this->count += 1;
    }
    else {
        this->last = new_node;
        new_node->next = NULL;;
        new_node->prev = NULL;;

        this->count += 1;
    }


}//end insertLast
template <class Type>
void unorderedDoubleLinkedList<Type>::insertNode(const Type& newItem, int index)
{

    dNodeType<Type>*  new_node = new dNodeType<Type>;
    dNodeType<Type>* index_current = this->first;


    new_node->info = newItem;
    this->count += 1;

    for (int i = 0; i < index; i++)
    {
        index_current = index_current->next;
    }

    dNodeType<Type>* temp = index_current->prev;


    if (index == 0) {

        new_node->next = this->first;
        this->first->prev = new_node;
        new_node->prev = NULL;
        this->first = new_node;
    }
    else if (index == this->count) {
        new_node->prev = this->last;
        this->last->next = new_node;
        new_node->next = NULL;
        this->last = new_node;
    }
    else {
        new_node->next = index_current;
        index_current->prev = new_node;
        new_node->prev = temp;
        
        if (temp != NULL)
        {
            temp->next = new_node;
        }
    }

}//end insertNode
template <class Type>
void unorderedDoubleLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    dNodeType<Type>* previous = this->first; //empty header
    dNodeType<Type>* temp;
    dNodeType<Type>* carry_temp;

    while (previous != NULL)
    {
        if (previous->info == deleteItem)
        {
            if (previous->prev == NULL)
            {
                temp = previous->next;
                this->first = temp;
                this->first->prev = NULL;
            }
            else if (previous->next == NULL) {
                temp = previous->prev;
                this->last = temp;
                this->last->next = NULL;
            }
            else {
                temp = previous->prev;
                carry_temp = previous->next;
                temp->next = carry_temp;
                carry_temp->prev = temp;
            }
            previous = NULL;
        }
        else {
            previous = previous->next;
        }
    }
}
//end deleteNode

template <class Type>
void unorderedDoubleLinkedList<Type>::deleteNodeByIndex(int index)
{
    if (index == 1 && this->first != NULL) {

        dNodeType<Type>* node_delete = this->first;

        this->first = this->first->next;

        delete node_delete;
        if (this->first != NULL)
            this->first->prev = NULL;
    }
    else {
        dNodeType<Type>* temp = this->first;

        for (int i = 1; i < index - 1; i++) {
            if (temp != NULL) {
                temp = temp->next;
            }
        }
        if (temp != NULL && temp->next != NULL) {
            dNodeType<Type>* node_delete = temp->next;
            temp->next = temp->next->next;
            if (temp->next->next != NULL)
                temp->next->next->prev = temp->next;
            delete node_delete;
        }
        else {
            return;
        }
    }
}
//end deleteNodeByIndex


#endif

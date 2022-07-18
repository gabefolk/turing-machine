// DOUBLY LINKED LIST IMPLEMENTATION FILE

#include "DoublyLinkList.hpp"

DoublyLinkList::DoublyLinkList() { // this is the constructor // initializes the list
    p = NULL;
    head = NULL;
    length = 0;
}

void DoublyLinkList::ResetP() { // sets p
    p = NULL;
    return;
}

void DoublyLinkList::IterateRight() { // sets p to point ot the next node in the list
    // always call ResetP prior to the intial call to IterateRight
    // always call IsPSet after each call to IterateRight
    if (p == NULL)
        p = head;
    else
        p = p->next;
    return;
}

void DoublyLinkList::IterateLeft() { // sets p to point to the previous node in the list
    // always call IsPSet prior to each call to IterateLeft
    // always call IsPSet after each call to IterateLeft
    p = p->previous;
    return;
}

bool DoublyLinkList::IsPSet() { // checks whether p points to a node in the list
    if (p == NULL)
        return false;
    return true;
}

Node* DoublyLinkList::GetP() { // returns the current value of p
    return p;
}

void DoublyLinkList::SetP(Node* q) { // have to send a node memory address
    // always call IsEmpty prior to calling SetP
    // always call IsPSet after each call to SetP
    // sets p
    p = head;
    while (p != NULL && q != p)
        p = p->next;
    return;
}

char DoublyLinkList::Read() { // returns the value of the node pointed to by p
    // p must be set prior to calling Read
    // always call IsPSet prior to calling Read
    return p->value;
}

void DoublyLinkList::Write(char x) {
    // writes a new value into the node pointed to by p
    // p must be set prior to calling Write
    // always call IsPSet prior to calling Write
    // will cause a problem in a sorted list if the key is changed
    p->value = x;
    return;
}

bool DoublyLinkList::IsEmpty() { // checks whether the list is empty
    if (length == 0)
        return true;
    return false;
}

void DoublyLinkList::InsertHead(char x) {// inserts a new node at the beginning of the list
// always call IsFull prior to calling InsertHead
// sets p
    Node* q = new Node;
    q->value = x;
    q->previous = NULL;
    if (head == NULL)
        q->next = NULL;
    else {
        head->previous = q;
        q->next = head;
    }
    head = q;
    p = head;
    length++;
    return;
}

void DoublyLinkList::InsertTail(char x) { // inserts a new node at the end of the list
// always call IsFull prior to calling InsertTail
// always call IsEmpty prior to calling InsertTail
// p must be set prior to calling InsertTail
// always call IsPSet prior to calling InsertTail
// starts scanning at the node p is pointing to
// scans from left to right
// sets p
    Node* q = new Node;
    q->value = x;
    q->next = NULL;
    prevP = p->previous;
    while (p != NULL) {
        prevP = p;
        p = p->next;
    }
    prevP->next = q;
    q->previous = prevP;
    p = q;
    length++;
    return;
}

bool DoublyLinkList::Find(char x) {// scans the list from left to right
// always call IsEmpty prior to calling Find
// sets p
    p = head;
    while (p != NULL) {
        if (x == p->value)
            return true;
        p = p->next;
    }
    return false;
}

void DoublyLinkList::Delete() { // deletes a node from the list
    // p must be set prior to calling Delete
    // always call IsPSet prior to calling Delete
    // sets p
    Node* q = new Node;
    prevP = p->previous;
    if (prevP == NULL) {
        head = head->next;
        if (head != NULL)
            head->previous = NULL;
        q = head;
    }
    else
        if (p->next == NULL)
            prevP->next = NULL;
        else {
            prevP->next = p->next;
            prevP->next->previous = prevP;
        }
        q = p->next;
        delete p;
        p = q;
        length--;
        return;
}

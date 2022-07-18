//  DOUBLY LINKED LIST HEADER FILE

#ifndef DOUBLYLINKLIST_H
#define DOUBLYLINKLIST_H
#include <cstdlib>
#include <iostream>
using namespace std;

struct Node;
struct Node
{
    char value;
    Node* next;
    Node* previous;
};


class DoublyLinkList
{
private:
    Node* head;        // head pointer, always points to the head
    Node* p;        // p pointer, this pointer can bounce around the list. pointer is a part of the doubly linked list class
    Node* prevP;    // prevP pointer, keep track of the previous node
    int length;        // length of doubly linked list

public:
    DoublyLinkList();
    void ResetP();
    void IterateRight();
    void IterateLeft();
    bool IsPSet();
    Node* GetP();
    void SetP(Node*);
    char Read();
    void Write(char); // chars can hold one byte of data, so '0' or '1' is valid
    bool IsEmpty();
    void InsertHead(char);
    void InsertTail(char);
    bool Find(char x);
    void Delete();
};

#endif

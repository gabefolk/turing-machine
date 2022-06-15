//  PART 1 ARRAY HEADER FILE

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX_LENGTH = 50;
struct Rule;
struct Rule
{
	int currentState;
	int nextState;
	char symbolRead;
	char symbolWrite;
	char direction;
};

class ArrayList
{	
private:
	int p; // place marker variable
	int length;
	Rule a[MAX_LENGTH]; // 'a' array of rule items of size 50

public:
	ArrayList(); // this is the constructor, initializes the array 
	void ResetP();
	void Iterate();	
	bool IsPSet();
	int GetP();
	void SetP(int);		
	Rule Read();
	void Write(Rule);
	int Length();
	bool IsEmpty();
	bool IsFull();
	void InsertUnsorted(Rule);
	//bool FindUnsorted(int);
	//void DeleteUnsorted();
	//void InsertSorted(int);
	//bool FindSorted(int);
	//void DeleteSorted();
	void Clear();
};

#endif

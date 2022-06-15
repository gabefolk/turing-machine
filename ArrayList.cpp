// PART 1 ARRAY IMPLEMENTATION FILE

#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP

#include <cstdlib>
#include <cassert>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList() { // this is the constructor, initializes the array
	length = 0;
	p = -1;
}
void ArrayList::ResetP() { // sets p
	p = -1;
	return; // return control back to the calling function
}
void ArrayList::Iterate() {	// sets p to point to the next element in the array
	// always call ResetP prior to the initial call to Iterate
	// always call IsPSet after each call to Iterate
	p++;
	return; 
}
bool ArrayList::IsPSet() { // checks whether p points to an element in the array
	if (p < 0 || p > length - 1) // if p is before the array or if p is further than the end of the array
		return false;
	else return true;
}
int ArrayList::GetP() { // returns the current value of p
	return p;
}

void ArrayList::SetP(int q){ // send this guy 'q' value and assign it to p. // sets p
	// always call IsPSet after each call to SetP
	p = q;
	return;
}

Rule ArrayList::Read() {// returns the value of the element pointed to by p
	// p must be set prior to calling Read
	// always call IsPSet prior to calling Read
	return a[p];
}

void ArrayList::Write(Rule x) {
	// writes a new value into the element pointed to by p
	// p must be set prior to calling Write
	// always call IsPSet prior to calling Write
	// could cause a problem in a sorted array if the key is changed
	a[p] = x;
	return;
}

int ArrayList::Length() { // returns the number of elements in the array
	return length;
}

bool ArrayList::IsEmpty() { // checks whether the array is empty
	if (length == 0)
		return true;
	else return false;
}

bool ArrayList::IsFull() { // checks whether the array is full
	if (length == MAX_LENGTH)
		return true;
	else return false;
}

void ArrayList::InsertUnsorted(Rule x) { // inserts a new element at the end of the array
	// always call IsFull prior to calling InsertUnsorted
	// sets p
	p = length;
	a[p] = x;
	length++;
	return;
}

//bool Array::FindUnsorted(int x) { // always call IsEmpty prior to calling FindUnsorted
//	// sets p
//	p = 0;
//	while (p < length) {
//		if (x == a[p])
//			return true;
//		p++;
//	}
//	return false;
//}

//void Array::DeleteUnsorted() { // deletes element pointed to by p
//	// p must be set prior to calling DeleteUnsorted
//	// always call IsPSet prior to calling DeleteUnsorted
//	// moves the last element into the element pointed to by p
//	a[p] = a[length - 1];
//	length--;
//	return;
//}

//void Array::InsertSorted(int x) {
//	// inserts a new element into the array in sorted order
//	// always call IsFull prior to calling InsertSorted
//	// p will point to where the new element should be inserted
//	// moves all elements to the right of p one element to the right to make space for the new element
//	// sets p
//	p = 0;
//	while (p < length && x > a[p])
//		p++;
//	int q = length;
//	while (q > p) {
//		a[q] = a[q - 1];
//		q--;
//	}
//	a[p] = x;
//	length++;
//	return;
//}

//bool Array::FindSorted(int x) {// binary search
//	// always call IsEmpty prior to calling FindSorted
//	// sets p
//	int q = 0;
//	int r = length - 1;
//	while (q <= r) {
//		p = (q + r) / 2;
//		if (x < a[p])
//			r = p - 1;
//		else if (x > a[p])
//			q = p + 1;
//		else
//			return true;
//	}
//	return false;
//}

//void Array::DeleteSorted() { // deletes element pointed to by p
//	// p must be set prior to calling DeleteSorted
//	// always call IsPSet prior to calling DeleteSorted
//	// all elements following the one pointed to by p are moved one element to the left
//	// sets p
//	int q = p;
//	p++;
//	while (p < length) {
//		a[p - 1] = a[p];
//		p++;
//	}
//	length--;
//	p = q;
//	return;
//}

void ArrayList::Clear() { // reinitializes the array
	length = 0;
	p = -1;
	return;
}

#endif
// Main.cpp file
//
// Turing Machine Assignment for Dr. Robert Hilderman University of Regina

#include "ArrayList.hpp"
#include "DoublyLinkList.hpp"
#include <fstream>
#include <string>
    
void print(DoublyLinkList);

void print(DoublyLinkList q) {
    cout << "the tape reads: " << endl;
    Node* tempP = q.GetP();
    q.ResetP();
    q.IterateRight();
    while (q.IsPSet()) {
        cout << q.Read();
        q.IterateRight();
    }
    cout << endl;
    q.ResetP();
    q.IterateRight();
    while (q.GetP() != tempP) { // tempP should be holding pointer position
        cout << " ";
        q.IterateRight();
    }
    cout << "^"; // pointer is left where it should be
    cout << endl;
}

int main() {
    DoublyLinkList tape;
    ArrayList actionTable;
    int state; // program state variable
    char val; // to load the tape
    ifstream inData; // create a program variable to access file input

    //****** bind program variable 'inData' to external text file
    inData.open("count.txt");
    if (!inData) // if there was a problem...
        cout << "cant open file successfully!" << endl;

    inData.ignore(100, '\n'); // skip to the next line
    //****** get initial state
    inData >> state;
    cout << "current state is: " << state << endl;
    inData.ignore(100, '\n');

    //****** get initial cell values on tape
    inData >> val; // >> ignores whitespace
    while (val != '/') {
        if (tape.IsEmpty())
            tape.InsertHead(val);
        else (tape.InsertTail(val));
        inData >> val; // use get because it's a char
    }
    inData.ignore(100, '\n');

    //****** fill action table array
    int test;
    inData >> test;
    while (test != -1){
        Rule temp;
        temp.currentState = test;
        inData >> temp.symbolRead;
        inData >> temp.nextState;
        inData >> temp.symbolWrite;
        inData >> temp.direction;
        inData.ignore(100, '\n'); // jump to next line

        actionTable.InsertUnsorted(temp);
        inData >> test;
    }
    inData.ignore(100, '\n');
    int position;
    inData >> position;
    cout << "position variable: " << position << endl;
    
    //****** iterate through the tape to set p to the right position
    tape.ResetP();
    for (int i = 0; i < position; i++)
        tape.IterateRight();

    //******** print out tape
    cout << "initially, ";
    print(tape);


    //******** turing machine
    bool keepGoing = true;
    while (keepGoing) // while we dont halt
    {
        // read in tape
        // read in state
        // find their match in the arraylist
            // iterate through the entire action table everytime
        // do the commands
        // repeat
        actionTable.ResetP(); // start from the begining
        actionTable.Iterate(); // step into the arraylist
        while (actionTable.IsPSet())
        {
            if (state == actionTable.Read().currentState && tape.Read() == actionTable.Read().symbolRead) // if state = current state and tape = symbol read
            {
                state = actionTable.Read().nextState; // and change state
                tape.Write(actionTable.Read().symbolWrite); // then write a different symbol
                if      (actionTable.Read().direction == 'L') // and move pointer
                    tape.IterateLeft();
                else if (actionTable.Read().direction == 'R')
                    tape.IterateRight();
                // else if == '-'
                else if (actionTable.Read().direction == 'H')
                    keepGoing = false;
                if (tape.Read() == 'B'){
                    print(tape);
                }
            }
            actionTable.Iterate();
        }
    }
    cout << "******** machine  has halted *********" << endl;
    cout << "\nand finally, ";
    print(tape);
    cout << "have a nice day my dude!\n" << endl;

    return 0;
}

//
// Created by or on 11/20/17.
//

#include "ConsoleMenu.h"
#include <limits>


void ConsoleMenu:: printWrongChose()const{
    cout<<"Illegal Input. Please try again."<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void  ConsoleMenu:: printOptionsMenu() const{
    cout<<"Before we start, against who you want to play:"
        <<endl<<"press 'H' -to play against Human Player"<<endl
        <<"press 'A' -to play against AIPlayer"<<endl;
}
 char ConsoleMenu::getSelection() const {
     char selection;
     cin >> selection;
     return selection;
 }
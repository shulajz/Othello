//
// Created by or on 11/20/17.
//

#include "ConsoleMenu.h"
#include <limits>


void ConsoleMenu:: printWrongChoice()const{
    cout<<"Illegal Input. Please try again."<<endl;
    cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void ConsoleMenu:: printOptionsMenu(TypeMenu typeMenu) const{
    if (typeMenu == MainMenu) {
        cout << "Before we start, against who do you want to play:"
             << endl << "press 'H' -to play against Human Player" << endl
             << "press 'A' -to play against AIPlayer" << endl
             << "press 'R' -to play against RemotePlayer" << endl;
    } else if (typeMenu == SubMenu){
            cout<<endl<<"Choose one of the options:"
             <<endl<< "1. write 'start <name>' - to open a new game in the name you choose, for example: start Shula;)" << endl
             << "2. write 'join <name>' -to join to existing game with a specific name, for example: join Shula;)" << endl
             << "3. write 'list_games' -to see all the available game that you can join" << endl;
    }
}

 string ConsoleMenu::getSelection() const {
     string selection, string;
     bool firstTime = true;
     do {
         if (!firstTime){
             selection += " ";
         }
         cin >> string;
         selection += string;
         firstTime = false;
     } while(cin.get()!='\n');
     return selection;
 }

void ConsoleMenu:: printSpecialSituation(Situation message) const {
    if (message == WaitToJoin) {
        cout << "Waiting for other player to join..." << endl;
    }
}

void ConsoleMenu::printList(string listOfAvailableGames) const{
    cout << listOfAvailableGames << endl;
}

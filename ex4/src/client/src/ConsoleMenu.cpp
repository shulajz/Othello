//
// Created by or on 11/20/17.
//

#include "ConsoleMenu.h"
#include <limits>
void ConsoleMenu::printWhoPlay(TokenValue tv)const{
    if (tv == Black ) {
        cout<< endl << "You play black ('X')"<< endl;
    } else{
        cout << endl << "You play white ('O')"<< endl;
    }
}

void ConsoleMenu:: printWrongChoice()const{
    cout<<"Illegal Input. Please try again."<<endl;
    cin.clear();
}

void ConsoleMenu:: printOptionsMenu(TypeMenu typeMenu) const{
    if (typeMenu == MainMenu) {
        cout << "Before we start, against who do you want to play:"
             << endl << "press 'H' -to play against Human Player" << endl
             << "press 'A' -to play against AIPlayer" << endl
             << "press 'R' -to play against RemotePlayer" << endl;
    } else if (typeMenu == SubMenu){
            cout<<endl<<"Choose one of the options:"
             <<endl<< "1. write 'start <name>' - to open a new game in the name you choose, for example: start dana" << endl
             << "2. write 'join <name>' -to join to existing game with a specific name, for example: join dana" << endl
             << "3. write 'list_games' -to see all the available game that you can join" << endl;
    }
}
//
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
    if(listOfAvailableGames.empty()) {
        cout << "There are no available games" << endl;
    } else {
        cout << listOfAvailableGames << endl;
    }
}

void ConsoleMenu::printServerClosed()const {
    cout << "the server closed!" << endl;
}
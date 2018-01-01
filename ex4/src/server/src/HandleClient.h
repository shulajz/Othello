//
// Created by shulamit on 01/01/18.
//

#ifndef OTHELLO_HANDLECLIENT_H
#define OTHELLO_HANDLECLIENT_H

#endif //OTHELLO_HANDLECLIENT_H
class HandleClient { 
public:
    virtual void sendCloseToEveryOne() = 0;
    virtual void run(int clientSocket) = 0; //vir
};
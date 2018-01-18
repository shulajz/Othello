//
// Created by shulamit on 18/01/18.
//

#ifndef OTHELLO_TASK_H
#define OTHELLO_TASK_H



class Task {
public:
    Task(void * (*func)(void *arg), void* arg) :
            func(func), arg(arg) {}
    void execute() {
        func(arg);
    }
    virtual ~Task() {}
private:
    void * (*func)(void *arg);
    void *arg;
};


#endif //OTHELLO_TASK_H

//
// Created by shulamit on 18/01/18.
//

#ifndef OTHELLO_THREADPOOL_H
#define OTHELLO_THREADPOOL_H


#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;
class ThreadPool {
public:
    ThreadPool(int threadsNum);
    void addTask(Task *task);
    void terminate();
    virtual ~ThreadPool();
private:
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;
    static void *execute(void *arg);
};


#endif //OTHELLO_THREADPOOL_H

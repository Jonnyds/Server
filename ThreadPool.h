/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include "Task.h"
#include <queue>
#include <pthread.h>
#include <iostream>
using namespace std;
/**
 * this class represent ThreadPool
 */
class ThreadPool {
public:
    /**
     * threadpool constructor
     * @param threasNum the number of maximum threads running at a time
     */
    ThreadPool(int threasNum);
    /**
     * adds a task to the queue
     * @param task the Task to add
     */
    void addTask(Task *task);
    /**
     * terminates the task execution and deletes the mutex
     */
    void terminate();
    /**
     * destructor
     */
    virtual ~ThreadPool();
private:
    queue <Task *> tasksQueue; // the task queue
    pthread_t* threads; // the threads to be made
    /**
     * execute the tasks added to the queue
     */
    void executeTasks();
    bool stopped; // terminates the task execution
    pthread_mutex_t lock;
    /**
     * executes a single task
     * @param arg the arguments given to the thread
     */
    static void *execute(void *arg);
};

#endif /* THREADPOOL_H_ */
/*
 * Name: Noam Itzhaki
 * ID: 315773465
 * Name: Jonathan Schwarz
 * ID: 203672910
 */

#ifndef TASK_H_
#define TASK_H_
/**
 * this class represent Task
 */
class Task {
public:
    /**
     * a task constructor
     * @param func the function to be called from the thread
     * @param arg the arguments to be sent to the threads
     */
    Task(void * (*func)(void *arg), void* arg):
            func(func), arg(arg) {}
    /**
     * executes the call to the thread
     */
    void execute() {
        func(arg);
    }
    /**
     * default task destructor
     */
    virtual ~Task(){}
private:
    void * (*func)(void *arg);
    void *arg;
};


#endif /* TASK_H_ */
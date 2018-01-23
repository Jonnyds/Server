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
     * construct a Task
     * @param func the function that does task
     * @param arg the arguments for the task
     */
    Task(void * (*func)(void *arg), void* arg):
            func(func), arg(arg) {}
    /**
     * execute the function of the task
     */
    void execute() {
        func(arg);
    }
    /**
     * default destructor
     */
    virtual ~Task(){}
private:
    void * (*func)(void *arg);
    void *arg;
};


#endif /* TASK_H_ */
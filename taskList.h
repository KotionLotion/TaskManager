#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"

using namespace std;

class TaskList
{
private:
    Task *head;
    Task *tail;
    int count;

public:
    TaskList();
    ~TaskList();

    void addTask(string description, string priority, string dueDate);
    bool removeTask(string description);
    bool markTaskComplete(string description);
    void displayAllTasks();
    void displayByPriority(string priority);
    Task *searchTask(string description);
    int getTaskCount();
};

#endif
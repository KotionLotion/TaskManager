#include "task.h"

Task::Task(string desc, string prio, string date)
{
    description = desc;
    priority = prio;
    dueDate = date;
    isComplete = false;
    next = nullptr;
}

string Task::getDescription()
{
    return description;
}

string Task::getPriority()
{
    return priority;
}

string Task::getDueDate()
{
    return dueDate;
}

bool Task::getIsComplete()
{
    return isComplete;
}

Task *Task::getNext()
{
    return next;
}

void Task::setDescription(string desc)
{
    description = desc;
}

void Task::setPriority(string prio)
{
    priority = prio;
}

void Task::setDueDate(string date)
{
    dueDate = date;
}

void Task::setIsComplete(bool complete)
{
    isComplete = complete;
}

void Task::setNext(Task *nextTask)
{
    next = nextTask;
}
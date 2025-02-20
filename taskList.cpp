#include "taskList.h"
#include <iostream>

using namespace std;

TaskList::TaskList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

TaskList::~TaskList()
{
    Task *current = head;
    while (current != nullptr)
    {
        Task *next = current->getNext();
        delete current;
        current = next;
    }
}

void TaskList::addTask(string description, string priority, string dueDate)
{
    Task *newTask = new Task(description, priority, dueDate);
    if (head == nullptr)
    {
        head = newTask;
        tail = newTask;
    }
    else
    {
        tail->setNext(newTask);
        tail = newTask;
    }
    count++;
}

bool TaskList::removeTask(string description)
{
    Task *current = head;
    Task *previous = nullptr;

    while (current != nullptr)
    {
        if (current->getDescription() == description)
        {
            if (previous == nullptr)
            {
                head = current->getNext();
            }
            else
            {
                previous->setNext(current->getNext());
            }
            if (current == tail)
            {
                tail = previous;
            }
            delete current;
            count--;
            return true;
        }
        previous = current;
        current = current->getNext();
    }
    return false;
}

bool TaskList::markTaskComplete(string description)
{
    Task *task = searchTask(description);
    if (task != nullptr)
    {
        task->setIsComplete(true);
        return true;
    }
    return false;
}

void TaskList::displayAllTasks()
{
    Task *current = head;
    while (current != nullptr)
    {
        cout << "Description: " << current->getDescription() << ", Priority: " << current->getPriority()
             << ", Due Date: " << current->getDueDate() << ", Complete: " << (current->getIsComplete() ? "Yes" : "No") << endl;
        current = current->getNext();
    }
}

void TaskList::displayByPriority(string priority)
{
    Task *current = head;
    while (current != nullptr)
    {
        if (current->getPriority() == priority)
        {
            cout << "Description: " << current->getDescription() << ", Priority: " << current->getPriority()
                 << ", Due Date: " << current->getDueDate() << ", Complete: " << (current->getIsComplete() ? "Yes" : "No") << endl;
        }
        current = current->getNext();
    }
}

Task *TaskList::searchTask(string description)
{
    Task *current = head;
    while (current != nullptr)
    {
        if (current->getDescription() == description)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

int TaskList::getTaskCount()
{
    return count;
}
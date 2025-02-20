#include "taskList.h"
#include <iostream>

using namespace std;

TaskList::TaskList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

TaskList::~TaskList() {
    Task* current = head;
    while (current != nullptr) {
        Task* next = current->getNext();
        delete current;
        current = next;
    }
}

void TaskList::addTask(string description, string priority, string dueDate) {
    Task* newTask = new Task(description, priority, dueDate);
    if (head == nullptr) {
        head = newTask;
        tail = newTask;
    } else {
        tail->setNext(newTask);
        tail = newTask;
    }
    count++;
}

void TaskList::removeTask(string description) {
    Task* current = head;
    Task* previous = nullptr;

    while (current != nullptr) {
        if (current->getDescription() == description) {
            if (previous == nullptr) {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }
            if (current == tail) {
                tail = previous;
            }
            delete current;
            count--;
            return true;
        }
        previous = current;
        current = current->getNext();
    }
    return false; // So this basically says that the code will return false if there is no task found with the description given.
}

void TaskList::markTaskComplete(string description) {
    // TODO: Implement markTaskComplete
}

void TaskList::displayAllTasks() {
    // TODO: Implement displayAllTasks
}

void TaskList::displayByPriority(string priority) {
    // TODO: Implement displayByPriority
}

Task* TaskList::searchTask(string description)  {
    // TODO: Implement searchTask
}

int TaskList::getTaskCount() {
     // TODO: Implement getTaskCount

}

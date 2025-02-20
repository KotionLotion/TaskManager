#include "taskList.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu()
{
    cout << "\n=== Task Manager Menu ===\n"
         << "1. Add New Task\n"
         << "2. Remove Task\n"
         << "3. Mark Task as Complete\n"
         << "4. Display All Tasks\n"
         << "5. Display Tasks by Priority\n"
         << "6. Search for Task\n"
         << "7. Exit\n\n"
         << "############################# \n Enter your choice: ";
}

int main()
{

    TaskList taskList;
    int choice;
    string description;
    string priority;
    string dueDate;

    while (true)
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter task description: ";
            getline(cin, description);
            cout << "Enter priority (High/Medium/Low): ";
            getline(cin, priority);
            cout << "Enter due date: ";
            getline(cin, dueDate);
            taskList.addTask(description, priority, dueDate);
            break;
        }

        case 2:
        {
            cout << "Enter task description to remove: ";
            getline(cin, description);
            if (!taskList.removeTask(description))
            {
                cout << "Task not found!\n"; //does this count as error handling? xd
            }
            break;
        }

        case 3:
        {
            cout << "Which task would you like to mark as complete? : ";
            getline(cin, description);
            if (!taskList.markTaskComplete(description)) {
                cout << "Task not found!\n";
            }
            break;
        }

        case 4:
        {

        }

        case 5:
        {

        }

        case 6:
        {

        }

        case 7:
        {

        }

        }
    }
    return 0;
}
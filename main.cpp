#include <iostream>
#include <string>
#include "Task.h"
#include "TaskManager.h"

int main()
{
    TaskManager taskManager;
    taskManager.loadFromFile("tasks.txt");
    int nextId = 1;
    int choice = 0;

    while (choice != 6)
    {
        std::cout << "\n===== Task Management API =====\n";
        std::cout << "1. Add task\n";
        std::cout << "2. Show tasks\n";
        std::cout << "3. Remove task\n";
        std::cout << "4. Update task status\n";
        std::cout << "5. Search task by title\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string title;
            std::string description;

            std::cin.ignore();

            std::cout << "Enter task title: ";
            std::getline(std::cin, title);

            std::cout << "Enter task description: ";
            std::getline(std::cin, description);

            taskManager.createTask(title, description, "pending");

            std::cout << "Task added successfully.\n";
        }
        else if (choice == 2)
        {
            taskManager.printTasks();
        }
        else if (choice == 3)
        {
            int id;
            std::cout << "Enter task ID to remove: ";
            std::cin >> id;

            if (taskManager.removeTask(id))
                std::cout << "Task removed successfully.\n";
            else
                std::cout << "Task not found.\n";
        }
        else if (choice == 4)
        {
            int id;
            std::string status;

            std::cout << "Enter task ID to update: ";
            std::cin >> id;

            std::cin.ignore();

            std::cout << "Enter new status: ";
            std::getline(std::cin, status);

            if (taskManager.updateTaskStatus(id, status))
                std::cout << "Task updated successfully.\n";
            else
                std::cout << "Task not found.\n";
        }
        else if (choice == 5)
        {
            std::string keyword;

            std::cin.ignore();

            std::cout << "Enter title keyword: ";
            std::getline(std::cin, keyword);

            taskManager.searchTasksByTitle(keyword);
        }
        else if (choice == 6)
        {
            std::cout << "Exiting application.\n";
        }
        else
        {
            std::cout << "Invalid option.\n";
        }
    }
    taskManager.saveToFile("tasks.txt");
    return 0;
}
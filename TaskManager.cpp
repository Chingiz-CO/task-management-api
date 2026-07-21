#include "TaskManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

void TaskManager::addTask(const Task& task)
{
    tasks_.push_back(task);
}

bool TaskManager::removeTask(int id)
{
    for (auto it = tasks_.begin(); it != tasks_.end(); ++it)
    {
        if (it->getId() == id)
        {
            tasks_.erase(it);
            return true;
        }
    }

    return false;
}

void TaskManager::printTasks() const
{
    if (tasks_.empty())
    {
        std::cout << "No tasks found.\n";
        return;
    }

    for (const Task& task : tasks_)
    {
        std::cout << "ID: " << task.getId() << '\n';
        std::cout << "Title: " << task.getTitle() << '\n';
        std::cout << "Description: " << task.getDescription() << '\n';
        std::cout << "Status: " << task.getStatus() << '\n';
        std::cout << "Priority: " << task.getPriority() << '\n';
        std::cout << "-------------------------\n";
    }
}

    bool TaskManager::updateTaskStatus(int id, const std::string & newStatus)
    {
        Task* task = findTaskById(id);

        if (task == nullptr)
        {
            return false;
        }

        task->setStatus(newStatus);
        return true;
    }

    Task* TaskManager::findTaskById(int id)
    {
        for (Task& task : tasks_)
        {
            if (task.getId() == id)
            {
                return &task;
            }
        }

        return nullptr;
    }

    int TaskManager::getTaskCount() const
    {
        return static_cast<int>(tasks_.size());
    }

    void TaskManager::saveToFile(const std::string& filename) const
    {
        std::ofstream file(filename);

        for (const Task& task : tasks_)
        {
            file << task.getId() << "|"
                << task.getTitle() << "|"
                << task.getDescription() << "|"
                << task.getStatus() << "|"
                << task.getPriority() << "\n";
        }
    }

    void TaskManager::loadFromFile(const std::string& filename)
    {
        std::ifstream file(filename);

        if (!file.is_open())
        {
            return;
        }

        tasks_.clear();
        nextId_ = 1;

        std::string line;

        while (std::getline(file, line))
        {
            if (line.empty())
            {
                continue;
            }

            std::stringstream ss(line);

            std::string idText;
            std::string title;
            std::string description;
            std::string status;
            std::string priority;

            std::getline(ss, idText, '|');
            std::getline(ss, title, '|');
            std::getline(ss, description, '|');
            std::getline(ss, status, '|');
            std::getline(ss, priority, '|');

            if (idText.empty())
            {
                continue;
            }

            if (priority.empty())
            {
                priority = "medium";
            }

            Task task(
                std::stoi(idText),
                title,
                description,
                status,
                priority
            );

            tasks_.push_back(task);

            if (task.getId() >= nextId_)
            {
                nextId_ = task.getId() + 1;
            }
        }

        file.close();
    }

    Task TaskManager::createTask(const std::string& title,
        const std::string& description,
        const std::string& status,
        const std::string& priority)
    {
        Task task(nextId_, title, description, status, priority);

        tasks_.push_back(task);
        nextId_++;

        return task;
    }

    void TaskManager::searchTasksByTitle(const std::string& keyword) const
    {
        bool found = false;

        for (const Task& task : tasks_)
        {
            if (task.getTitle().find(keyword) != std::string::npos)
            {
                std::cout << "Task #" << task.getId() << std::endl;
                std::cout << "Title: " << task.getTitle() << std::endl;
                std::cout << "Description: " << task.getDescription() << std::endl;
                std::cout << "Status: " << task.getStatus() << std::endl;
                std::cout << std::endl;

                found = true;
            }
        }

        if (!found)
        {
            std::cout << "No tasks found." << std::endl;
        }
    }
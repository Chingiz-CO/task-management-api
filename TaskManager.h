#pragma once

#include <vector>
#include "Task.h"
#include <string>

class TaskManager
{
public:
    void addTask(const Task& task);
    bool removeTask(int id);
    bool updateTaskStatus(int id, const std::string& newStatus);
    Task* findTaskById(int id);
    int getTaskCount() const;
    void printTasks() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    Task createTask(const std::string& title,
        const std::string& description,
        const std::string& status,
        const std::string& priority);
    void searchTasksByTitle(const std::string& keyword) const;

private:
    std::vector<Task> tasks_;
    int nextId_ = 1;

};
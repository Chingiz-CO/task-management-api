#pragma once

#include <string>

class Task
{
public:
    Task();

    Task(int id,
        const std::string& title,
        const std::string& description,
        const std::string& status,
        const std::string& priority,
        const std::string& dueDate);

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getStatus() const;
    const std::string& getPriority() const;
    std::string getDueDate() const;

    void setDueDate(const std::string& dueDate);
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setStatus(const std::string& status);
    void setPriority(const std::string& priority);
    void sortByPriority();

private:
    int id_;
    std::string title_;
    std::string description_;
    std::string status_;
    std::string priority_;
    std::string dueDate_;
};
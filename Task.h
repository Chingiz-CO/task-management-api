#pragma once

#include <string>

class Task
{
public:
    Task();

    Task(int id,
        const std::string& title,
        const std::string& description,
        const std::string& status);

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getStatus() const;

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setStatus(const std::string& status);

private:
    int id_;
    std::string title_;
    std::string description_;
    std::string status_;
};

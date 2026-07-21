#include "Task.h"

Task::Task()
    : id_(0),
    title_(""),
    description_(""),
    status_("pending"),
    priority_("medium")
{
}

Task::Task(int id,
    const std::string& title,
    const std::string& description,
    const std::string& status,
    const std::string& priority)
    : id_(id),
    title_(title),
    description_(description),
    status_(status),
    priority_(priority)
{
}

int Task::getId() const
{
    return id_;
}

const std::string& Task::getTitle() const
{
    return title_;
}

const std::string& Task::getDescription() const
{
    return description_;
}

const std::string& Task::getStatus() const
{
    return status_;
}

const std::string& Task::getPriority() const
{
    return priority_;
}

void Task::setTitle(const std::string& title)
{
    title_ = title;
}

void Task::setDescription(const std::string& description)
{
    description_ = description;
}

void Task::setStatus(const std::string& status)
{
    status_ = status;
}

void Task::setPriority(const std::string& priority)
{
    priority_ = priority;
}
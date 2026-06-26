#include <iostream>
#include "User.h"
#include "Task.h"

int main()
{
    User user("Chingiz", "20chingiz01@gmail.com", "password123");

    Task task(
        1,
        "Finish C++ project",
        "Build the first version of Task Management API",
        "pending"
    );

    std::cout << "User: " << user.getUsername() << std::endl;
    std::cout << "Email: " << user.getEmail() << std::endl;

    std::cout << "Task #" << task.getId() << std::endl;
    std::cout << "Title: " << task.getTitle() << std::endl;
    std::cout << "Status: " << task.getStatus() << std::endl;

    return 0;
}
#pragma once

#include <string>

class User
{
public:
    User();

    User(const std::string& username,
        const std::string& email,
        const std::string& password);

    const std::string& getUsername() const;
    const std::string& getEmail() const;
    const std::string& getPassword() const;

    void setUsername(const std::string& username);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);

private:
    std::string username_;
    std::string email_;
    std::string password_;
};
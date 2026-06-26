#include "User.h"

User::User()
{
}

User::User(const std::string& username,
    const std::string& email,
    const std::string& password)
    : username_(username),
    email_(email),
    password_(password)
{
}

const std::string& User::getUsername() const
{
    return username_;
}

const std::string& User::getEmail() const
{
    return email_;
}

const std::string& User::getPassword() const
{
    return password_;
}

void User::setUsername(const std::string& username)
{
    username_ = username;
}

void User::setEmail(const std::string& email)
{
    email_ = email;
}

void User::setPassword(const std::string& password)
{
    password_ = password;
}
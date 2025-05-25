// === File: User.cpp ===
#include "User.h"

User::User(const std::string& id, const std::string& username, const std::string& password)
    : id(id), username(username), password(password) {}

std::string User::getId() const {
    return id;
}

std::string User::getUsername() const {
    return username;
}

bool User::authenticate(const std::string& uname, const std::string& pwd) const {
    return username == uname && password == pwd;
}

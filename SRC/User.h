// === File: User.h ===
#ifndef USER_H
#define USER_H
#include <string>

class User {
protected:
    std::string id;
    std::string username;
    std::string password;
public:
    User(const std::string& id, const std::string& username, const std::string& password);
    virtual ~User() = default;
    std::string getId() const;
    std::string getUsername() const;
    bool authenticate(const std::string& uname, const std::string& pwd) const;
};

#endif // USER_H

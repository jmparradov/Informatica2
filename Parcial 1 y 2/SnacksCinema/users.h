#ifndef USERS_H
#define USERS_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class users
{

private:
    std::string type;
    std::string username;
    std::string password;
public:
    users();
    std::string get_type();
    std::string get_username();
    std::string get_password();

    void set_type(std::string stype);
    void set_username(std::string);
    void set_password(std::string);

    bool validate(std::string username, std::string password);
};

std::vector<std::string> opensudo();

#endif // USERS_H

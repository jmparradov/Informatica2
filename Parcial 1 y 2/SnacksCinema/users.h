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
bool login(std::string type, users user);
void admin_session();
void client_session();
void append_users_info(std::string input);

std::string p_encriptado(std::string text);
std::string p_desencriptado(std::string binary);
std::vector<std::string> get_userinfo();
std::vector<std::string> split_text(std::string value);

#endif // USERS_H

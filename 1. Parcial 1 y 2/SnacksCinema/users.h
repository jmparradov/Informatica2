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
    std::vector<std::string> all_users;
    std::string type;

public:
    users(std::string s_type);
    std::vector<std::string> get_allusers();
    void append_users_info(std::string input);
    void set_type(std::string s_type);
    std::string get_type();
    bool validate(std::string username, std::string password);
};

std::vector<std::string> opensudo();
bool login(users user);
void admin_session();
void client_session();

std::string p_encriptado(std::string text);
std::string p_desencriptado(std::string binary);
std::vector<std::string> get_userinfo();
std::vector<std::string> split_text(std::string value);

#endif // USERS_H

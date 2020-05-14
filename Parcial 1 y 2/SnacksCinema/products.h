#ifndef PRODUCTS_H
#define PRODUCTS_H
#include <string>
#include <map>
#include <vector>
#include <iostream>

class products
{

public:
    products();
    ~products();

    void set_inventario(std::map<int,std::vector<std::string>> s_inventario);
    void set_combos(std::map<int,std::vector<std::string>> s_combos);

    std::map<int,std::vector<std::string>> get_inventario();
    std::map<int,std::vector<std::string>> get_combos();

    void udpdate_inventory();

private:
    std::map<int,std::vector<std::string>> inventario;
    std::map<int,std::vector<std::string>> combos;

};

int string_to_int(std::string s);
std::vector<std::string> get_inventory_info();
std::vector<std::string> split_text(std::string value);
std::string p_encriptado(std::string text);
std::string p_desencriptado(std::string binary);
void save_inventory(std::map<int,std::vector<std::string>> inventory);

#endif // PRODUCTS_H

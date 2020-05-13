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

    void set_inventario(std::map<int,std::vector<std::string>>);
    void set_combos(std::map<int,std::vector<std::string>>);

    std::map<int,std::vector<std::string>> get_inventario();
    std::map<int,std::vector<std::string>> get_combos();

    void udpdate_inventory();

private:
    std::map<int,std::vector<std::string>> inventario;
    std::map<int,std::vector<std::string>> combos;

};

int string_to_int(std::string s);
#endif // PRODUCTS_H

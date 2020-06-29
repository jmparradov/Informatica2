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

    void set_transactions(std::vector<std::vector<std::string>> s_transactions);
    std::vector<std::vector<std::string>> get_transactions();

    void udpdate_inventory();
    void update_combos();

    void nueva_compra(int n_combo);

private:
    std::map<int,std::vector<std::string>> inventario;
    std::map<int,std::vector<std::string>> combos;
    std::vector<std::vector<std::string>> transactions;
    void agregar_combo(int id, std::map<int,std::vector<std::string>> combo, std::map<int,std::vector<std::string>> inventory, bool nuevo);

};

int string_to_int(std::string s);
std::string in_to_string(int n);

std::map<int,std::vector<std::string>> get_inventory_info();
std::map<int,std::vector<std::string>> get_combos_info();

std::vector<std::string> split_text(std::string value);
std::string p_encriptado(std::string text);
std::string p_desencriptado(std::string binary);

void save_inventory(std::map<int,std::vector<std::string>> inventory);
void save_combos(std::map<int,std::vector<std::string>> combos);

void save_transactions(std::vector<std::vector<std::string>> transactions);
std::vector<std::vector<std::string>> get_transactions_info();

#endif // PRODUCTS_H

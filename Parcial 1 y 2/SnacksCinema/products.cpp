#include "products.h"
#include <bits/stdc++.h>
using namespace std;

products::products(){
    vector<string> info = get_inventory_info();
    map<int,vector<string>> newinfo;
    vector<string> newvector;
    vector<string>::iterator it = info.begin();

    while(it != info.end()){
         newvector = split_text(*it);
         int id = string_to_int(newvector[0]);
         newinfo[id].push_back(newvector[1]);
         newinfo[id].push_back(newvector[2]);
         newinfo[id].push_back(newvector[3]);
        it++;
    }
    set_inventario(newinfo);
}

products::~products(){
    map<int,vector<string>> tosave;
    tosave = get_inventario();
    save_inventory(tosave);

}

void products::set_inventario(map<int,vector<string>> s_inventario){
    inventario = s_inventario;
}

void products::set_combos(map<int,vector<string>> s_combos){
    combos = s_combos;
}

map<int,vector<string>> products::get_inventario(){
    return inventario;
}

map<int,vector<string>> products::get_combos(){
    return combos;
}


void products::udpdate_inventory(){
    int id;
    map<int,vector<string>> inventory;
    inventory = inventario;
    map<int,vector<string>>::iterator it = inventory.begin();

    while (true){
        cout<<"Inventario actual"<<endl;

        if (inventory.size() != 0){
            while(it != inventory.end()){
                cout<<"ID: "<<it->first;
                cout<<"Producto: "<<it->second[0]<<endl;
                cout<<"Cantidad: "<<it->second[1]<<endl;
                cout<<"Costo: "<<it->second[2]<<endl;
                it++;
            }
        }

        cout<<"Ingrese el ID del producto a ingresar:"<<endl;
        cin>>id;
        bool ingresado = false;
        it = inventory.begin();

        while(it != inventory.end()){
            if (it->first == id){
                ingresado = true;
            }
            it++;
        }

        if (ingresado){
            int cantidad;
            int value;
            cout<<"Ingrese la cantidad a adicionar de "<<inventario[id][0]<<endl;
            cin>>cantidad;

            cout<<inventory[id][1]<<endl;
            value = string_to_int(inventory[id][1]) + cantidad;
            cout<<value<<endl;
            string ss(1, char(value));
            inventory[id][1] = ss;
            cout<<inventory[id][1]<<endl;
        }

        else{
            int opti;
            cout<<"El id no existe en la base de datos, desea agregar un nuevo item con este id"<<endl;
            cout<<"1. Ingresar nuevo producto"<<endl;
            cout<<"0. Volver al menu anterior"<<endl;
            cin>>opti;

            if (opti == 1){
                string nombre;
                string cantidad;
                string costo;

                cout<<"Ingrese el nombre del item nuevo:"<<endl;
                cin>>nombre;
                inventory[id].push_back(nombre);
                cout<<"Ingrese la cantidad inicial: (solo numeros)"<<endl;
                cin>>cantidad;
                inventory[id].push_back(cantidad);
                cout<<"Ingrese el costo por unidad del item: (solo numeros)"<<endl;
                cin>>costo;
                inventory[id].push_back(costo);
                system("cls");
                cout<<"Item satisfactoriamente agregado al inventario"<<endl;

            }
            break;
        }
    }
  set_inventario(inventory);
}


int string_to_int(string s){
    int value = 0;

    for (int n = 0; n < s.length();n++){
        value = s[n]*pow(10,n);
    }
    return value;
}

vector <string> split_text(string value);

vector<string> get_inventory_info(){
    string data = "";
    string ndata = "";
    vector<string> seglist;

       ifstream infile;
       infile.open("../SnacksCinema/data/inventory.txt");

       if (!infile.is_open())
       {
         return seglist;
       }

       while (getline(infile, data))
       {
           if(data.size() > 0){
               ndata = p_desencriptado(data);
               seglist.push_back(ndata);
           }
       }
       infile.close();

       return seglist;
  }

void save_inventory(map<int,vector<string>> inventory){
    string crypted = "";
    string input;
    ofstream outfile;
    outfile.open("../SnacksCinema/data/inventory.txt");

    if (!outfile.is_open())
    {
      cout<<"fuck"<<endl;
    }

    map<int,vector<string>>::iterator it = inventory.begin();
    while(it != inventory.end()){
        string ss(1, char(it->first));
        input = ss + "," + it->second[0] + "," + it->second[1] + "," + it->second[2];
        crypted = p_encriptado(input);
        outfile << crypted + "\n";
        it++;
    }

    outfile.close();
}

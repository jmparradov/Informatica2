#include "products.h"
#include <bits/stdc++.h>
using namespace std;

products::products(){
    map<int,vector<string>> info = get_inventory_info();
    set_inventario(info);

    map<int,vector<string>> info_combos = get_combos_info();
    set_combos(info_combos);
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

        while (!cin){
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Ingrese solo numeros." << endl;
           cin >> id;
        }

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

            while (!cin){
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Ingrese solo numeros." << endl;
               cin >> cantidad;
            }

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

            while (!cin){
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Ingrese solo numeros." << endl;
               cin >> opti;
            }

            while(opti > 2){
                cout<<"Ingrese un numero entre las opciones"<<endl;
                cin >>opti;
            }

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


void products::update_combos(){
    int id;
    map<int,vector<string>> combo;
    combo = combos;
    map<int,vector<string>> inventory = inventario;
    map<int,vector<string>>::iterator it = combo.begin();

    while (true){
        int cc;
        cout<<"Combos actuales"<<endl;

        if (combo.size() != 0){
            while(it != combo.end()){
                cout<<"ID: "<<it->first;
                vector<string>::iterator ii = it->second.begin();
                int ci = 0;
                ii++;
                cout<<"Productos: ";
                while (ii != it->second.end()){
                    ci += 1;
                    if (ci-2==ii->size()){
                        cout<<endl<<"Costo: "<<*ii<<endl;
                    }
                    else{
                        cout<<*ii<<" ";
                    }
                }
                it++;
            }
        }

        cout<<"1. Actualizar combos."<<endl;
        cout<<"0. Guardar cambios y volver al menu anterior"<<endl;
        cin>>cc;

        while (!cin){
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Ingrese solo numeros." << endl;
           cin >> cc;
        }

        while(cc > 2){
            cout<<"Ingrese un numero entre las opciones"<<endl;
            cin >>cc;
        }

        if (cc==0){
            break;
        }

        cout<<"Ingrese el numero de un nuevo combo o ingrese el numero del combo a modificar:"<<endl;
        cin>>id;

        while (!cin){
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Ingrese solo numeros." << endl;
           cin >> id;
        }

        bool ingresado = false;
        it = combo.begin();

        while(it != combo.end()){
            if (it->first == id){
                ingresado = true;
            }
            it++;
        }

        if (ingresado){
            int opt3;
            int value;
            cout<<"Que dese modificar?"<<endl;
            cout<<"1. Cambiar productos."<<endl;
            cout<<"2. Cambiar precio."<<endl;
            cin>>opt3;

            while (!cin){
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Ingrese solo numeros." << endl;
               cin >> opt3;
            }

            while(opt3 > 2){
                cout<<"Ingrese un numero entre las opciones"<<endl;
                cin >>opt3;
            }

            if (opt3 == 1){
                int opt4 = 0;
                cout<<"Que dese modificar?"<<endl;
                cout<<"1. Agregar un producto."<<endl;
                cout<<"2. Eliminar un producto."<<endl;
                cin>>opt4;

                while (!cin){
                   cin.clear();
                   cin.ignore(10000, '\n');
                   cout << "Ingrese solo numeros." << endl;
                   cin >> opt4;
                }

                while(opt4 > 2){
                    cout<<"Ingrese un numero entre las opciones"<<endl;
                    cin >>opt4;
                }

                if (opt4 ==1){
                    // funcion agregar nuevo combo
                    agregar_combo(id);
                }

                if (opt4 ==2){
                    int confirm = 0;
                    cout<<"Esta seguro que desea eliminar el combo "<<id<<"?"<<endl;
                    cout<<"1. Continuar"<<endl;
                    cout<<"0. Cancelar"<<endl;

                    cin>>confirm;

                    while (!cin){
                       cin.clear();
                       cin.ignore(10000, '\n');
                       cout << "Ingrese solo numeros." << endl;
                       cin >> opt3;
                    }

                    while(confirm > 2){
                        cout<<"Ingrese un numero entre las opciones"<<endl;
                        cin >>confirm;
                    }

                    if (confirm == 1){
                        combos.erase(id);
                        cout<<"Combo eliminado satisfactoriamente"<<endl;
                    }
                }
            }

            if (opt3 == 2){
                int newprice;
                cout<<"Ingrese el nuevo precio que desea para el combo (ingrese solo numeros)"<<endl;
                cin>>newprice;

                while (!cin){
                   cin.clear();
                   cin.ignore(10000, '\n');
                   cout << "Ingrese solo numeros." << endl;
                   cin >> opt3;
                }
                string ss(1, char(newprice));
                combo[id][combo[id].size()-1] = ss;
                cout<<"Nuevo valor ingresado satisfactoriamente."<<endl;
            }
        }

        else{
            int opti;
            cout<<"El combo no existe en la base de datos, desea agregar un nuevo combo con este id"<<endl;
            cout<<"1. Ingresar nuevo combo"<<endl;
            cout<<"0. Volver al menu anterior"<<endl;
            cin>>opti;

            while (!cin){
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Ingrese solo numeros." << endl;
               cin >> opti;
            }

            while(opti > 2){
                cout<<"Ingrese un numero entre las opciones"<<endl;
                cin >>opti;
            }

            if (opti == 1){
                agregar_combo(id);
            }
        }
    }
  set_inventario(inventory);
}

void products::agregar_combo(int id){
    int cantidad;
    int products;
    map<int,vector<string>> combo = combos;
    map<int,vector<string>> inventory = inventario;

    while(true){
        cout<<"Seleccione el producto a adicionar en el combo, seleccionado el id:"<<endl;
        cout<<"Continue agregando y presione 0 para continuar."<<endl;

        map<int,vector<string>> ::iterator it = inventory.begin();
        if (inventory.size() != 0){
            while(it != inventory.end()){
                cout<<it->first<<". ";
                cout<<"Producto: "<<it->second[0]<<endl;
                it++;
            }
        }

        cin>>products;

        while (!cin){
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Ingrese solo numeros." << endl;
           cin >> products;
        }

        if (products == 0){
            break;
        }
        bool ingresado = false;
        do {
            it = inventory.begin();
            while(it != inventory.end()){
                if (it->first == id){
                        ingresado = true;
                        break;
                    }
                it++;
            }
            if (not(ingresado)){
                cout<<"Ingrese un numero entre las opciones"<<endl;
                cin >>products;
            }
        } while(not(ingresado));


        cout<<"Ingrese la cantidad del producto que tendra el combo"<<endl;
        cin>>cantidad;

        while (!cin){
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Ingrese solo numeros." << endl;
           cin >> cantidad;
        }
        // funcion para ingresar el producto al combo
        string ss(1, char(cantidad));
        combo[id].push_back(ss);
        combo[id].push_back(inventory[products][0]);

        cout<<"El producto fue agregado satisfactoriamente"<<endl;
    }
    int precio = 0;
    cout<<"Ingrese el precio total del combo"<<endl;
    cin>>precio;
    string ss(1, char(precio));
    combo[id].push_back(ss);

    cout<<"Informacion del combo anadida satisfactoriamente"<<endl;
}

int string_to_int(string s){
    int value = 0;

    for (int n = 0; n < s.length();n++){
        value = s[n]*pow(10,n);
    }
    return value;
}

vector <string> split_text(string value);

map<int,vector<string>> get_inventory_info(){
    string data = "";
    string ndata = "";
    vector<string> seglist;
    map<int,vector<string>> newinfo;
    vector<string> newvector;

    ifstream infile;
    infile.open("../SnacksCinema/data/inventory.txt");

    if (!infile.is_open())
    {
     return newinfo;
    }

    while (getline(infile, data))
    {
       if(data.size() > 0){
           ndata = p_desencriptado(data);
           seglist.push_back(ndata);
       }
    }
    infile.close();


    vector<string>::iterator it = seglist.begin();

    while(it != seglist.end()){
        newvector = split_text(*it);
        int id = string_to_int(newvector[0]);
        newinfo[id].push_back(newvector[1]);
        newinfo[id].push_back(newvector[2]);
        newinfo[id].push_back(newvector[3]);
       it++;
    }

    return newinfo;
  }

void save_inventory(map<int,vector<string>> inventory){
    string crypted = "";
    string input;
    ofstream outfile;
    outfile.open("../SnacksCinema/data/inventory.txt");

    if (!outfile.is_open())
    {
      //cout<<"fuck"<<endl;
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

map<int,vector<string>> get_combos_info(){
    string data = "";
    string ndata = "";
    vector<string> seglist;
    map<int,vector<string>> newinfo;
    vector<string> newvector;

    ifstream infile;
    infile.open("../SnacksCinema/data/combos.txt");

    if (!infile.is_open())
    {
     return newinfo;
    }

    while (getline(infile, data))
    {
       if(data.size() > 0){
           ndata = p_desencriptado(data);
           seglist.push_back(ndata);
       }
    }
    infile.close();


    vector<string>::iterator it = seglist.begin();

    while(it != seglist.end()){
        newvector = split_text(*it);
        int id = string_to_int(newvector[0]);
        vector<string>::iterator ii = it;

        ii++;
        while (ii != newvector.end()){
            newinfo[id].push_back(*ii);
            ii++;
        }
       it++;
    }

    return newinfo;
}

void save_combos(map<int,vector<string>> combos){
    string crypted = "";
    string input;
    ofstream outfile;
    outfile.open("../SnacksCinema/data/inventory.txt");

    if (!outfile.is_open())
    {
      //cout<<"fuck"<<endl;
    }

    map<int,vector<string>>::iterator it = combos.begin();
    while(it != combos.end()){
        string ss(1, char(it->first));
        vector<string>::iterator ii = it->second.begin();
        input = ss;
        while (ii != it->second.end()){
                input += "," + *ii;
            ii++;
        }
        crypted = p_encriptado(input);
        outfile << crypted + "\n";
        it++;
    }
    outfile.close();
}

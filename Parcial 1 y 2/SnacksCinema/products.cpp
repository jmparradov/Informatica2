#include "products.h"
#include <bits/stdc++.h>
using namespace std;

products::products()
{}

void products::udpdate_inventory(){
    int id;
    map<int,vector<string>>::iterator it = inventario.begin();

    while (true){
        cout<<"Inventario actual"<<endl;

        if (inventario.size() != 0){
            while(it != inventario.end()){
                cout<<"ID: "<<it->first;
                cout<<"Producto: "<<it->second[0];
                cout<<"Cantidad: "<<it->second[1];
                cout<<"Costo: "<<it->second[2];
                it++;
            }
        }

        cout<<"Ingrese el ID del producto a ingresar:"<<endl;
        cin>>id;
        bool ingresado = false;
        it = inventario.begin();

        while(it != inventario.end()){
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

            cout<<inventario[id][1]<<endl;
            value = string_to_int(inventario[id][1]) + cantidad;
            cout<<value<<endl;
            string ss(1, char(value));
            inventario[id][1] = ss;
            cout<<inventario[id][1]<<endl;
        }

        else{
            int opti;
            cout<<"El id no existe en la base de datos, desea agregar un nuevo item con este id"<<endl;
            cout<<"Ingrese 1 para aceptar, cualquier tecla para volver al menu anterior"<<endl<<endl;
            cin>>opti;

            if (opti == 1){
                string nombre;
                string cantidad;
                string costo;

                cout<<"Ingrese el nombre del item nuevo:"<<endl;
                cin>>nombre;
                cout<<"Ingrese la cantidad inicial: (solo numeros)"<<endl;
                cin>>cantidad;
                cout<<"Ingrese el costo por unidad del item: (solo numeros)"<<endl;
                cin>>costo;
            }
            break;
        }
    }
}

int string_to_int(string s){
    int value = 0;

    for (int n = 0; n < s.length();n++){
        value = s[n]*pow(10,n);
    }
    return value;
}


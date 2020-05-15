#include <iostream>
#include <products.h>
#include <users.h>
#include <products.h>
#include <limits>
#include <ctime>

using namespace std;

users admin_user("Admin");
users client_user("Client");
products snacks;

//funcion que muestra el valor de la devuelta en terminos de monedas y billetes existentes.
void change(int valor);

//funcion que registra toda nueva compra en trascciones
void nueva_compra(products snacks, int n_combo);

int main(){

    while (true){
        // Main Menu
        int opt = 10;
        cout << "Bienvenido a Snacks Cinema!" << endl<<endl;
        cout << "Ingrese una opcion para continuar" << endl;
        cout << "1. Acceder al sistema como usuario administrador." << endl;
        cout << "2. Acceder como usuario." << endl<<endl;
        cout << "0. Salir." << endl<<endl;

        cin>>opt;

        while (!cin){
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Ingrese solo numeros." << endl;
               cin >> opt;
        }

        while(opt > 2){
            cout<<"Ingrese un numero entre las opciones"<<endl;
            cin >>opt;
        }


        if(opt == 1){
            if (login(admin_user)){
                admin_session();
            }
        }

        if(opt == 2){
            if (login(client_user)){
                client_session();
            }
        }

        if(opt == 0){
            //system("cls");
            cout<<"Hasta pronto!"<<endl;
            break;
        }
    }
    return 0;
}

// ********************            SESSIONS MODULES       ********************************:

// Login module

bool login(users user){
    string username;
    string password;
    bool successfull = false;
    string type = user.get_type();

    int cnt = 0;
    user.set_type(type);

    while (true){
        cout<<"Ingrese el usuario:"<<endl;
        cin>>username;

        cout<<"Ingrese la contrasena:"<<endl;
        cin>>password;

        if (user.validate(username,password)){
            system("cls");
            cout<<"Bienvenido "<<username<<endl<<endl;
            successfull = true;
            break;
        }
        else {
            system("cls");
            cout<<"El usuario y/o contrasena es incorrecto"<<endl<<endl;
            cnt += 1;
        }

        if (cnt >=3){
            cout<<"Intentos agotados"<<endl;
            break;
        }
        if(cnt ==0){
            break;
        }
    }
return  successfull;
}

// administador session
void admin_session(){

    while (true){
        int optt = 10;
        cout << "Ingrese una opcion para continuar" << endl;
        cout << "1. Ingresar productos al inventario." << endl;
        cout << "2. Crear o modificar combos." << endl;
        cout << "3. Generar reporte con ventas del dia." << endl;
        cout << "4. Agregar usuarios." << endl<<endl;
        cout << "0. Cerrar session de administrador"<<endl<<endl;

        cin>>optt;

        while (!cin){
               cin.clear();
               cin.ignore(10000, '\n');
               cout << "Ingrese solo numeros." << endl;
               cin >> optt;
        }

        while(optt > 4){
            cout<<"Ingrese un numero entre las opciones"<<endl;
            cin >>optt;
        }


        if (optt == 1){
            // input products to inventory
            snacks.udpdate_inventory();
        }

        if (optt == 2){
            snacks.update_combos();
        }

        if (optt == 3){
            // generate daily report
            std::stringstream ss;
            vector<vector<string>> transacciones = snacks.get_transactions();
            vector<vector<string>>::iterator iter  = transacciones.begin();

            time_t rawtime;
            struct tm * timeinfo;
            char buffer[80];

            time (&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
            string str(buffer);


            cout<<"Este es el resumen de las transacciones de hoy:"<<endl;

            if(transacciones.size() == 0){
                cout<<"No hay transacciones registradas."<<endl;
            }
            while(iter != transacciones.end()){
                if(str == (*iter)[0]){
                       cout<<"Transaccion realizada en "<<str<<":"<<endl;
                       cout<<"Combo "<<(*iter)[1]<<" comprado."<<endl<<endl;
                }
                iter ++;
            }
        }

        if (optt == 4){
            string username;
            string password;

            // add users
            cout<<"Ingresar nombre de usuario (sin espacios ni carateres especiales)" << endl;
            cin>>username;
            cout<<"Ingresar contrasena (sin espacios ni carateres especiales)" << endl;
            cin>>password;

            admin_user.append_users_info(username + "," + password);
            system("cls");
            cout<<"Usuario satisfactoriamente ingresado"<<endl<<endl;
        }


        if (optt == 0){
            //system("cls");
            cout<<"Cerrando sesion de administrador"<<endl;
            break;
        }
    }
}


//client session

void client_session(){
    int opt = 10;

    while (true){
        map<int,vector<string>> combo = snacks.get_combos();
        map<int,vector<string>>::iterator it = combo.begin();

        cout << "Seleccione el combo que desea comprar" << endl;

        while(it != combo.end()){
            cout<<it->first<<". ";
            vector<string>::iterator ii = it->second.begin();
            int ci = 0;
            //ii++;
            cout<<"Combo: ";
            while (ii != it->second.end()){
                if ((ci+1)==int(it->second.size())){
                    cout<<"Precio: $"<<*ii<<endl;
                }
                else{
                    cout<<*ii<<" ";
                }
                ci += 1;
                ii++;
            }
            it++;
        }
        cout<<endl;

        cout << "0. Cerrar session"<<endl<<endl;
        cin>>opt;

        while (!cin){
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Ingrese solo numeros." << endl;
           cin >> opt;
        }

        if (opt == 0){
            system("cls");
            cout<<"Cerrando sesion de usuario"<<endl;
            break;
        }

        bool ingresado = false;
        while(not(ingresado)){
            it = combo.begin();
            while(it != combo.end()){
                if (it->first == opt){
                    ingresado = true;
                }
                it++;
            }
            if (not(ingresado)){
                cout<<"Ingrese un numero entre las opciones"<<endl;
                cin >>opt;
            }
        }

        int plata = 0;
        int precio = string_to_int(combo[opt][combo[opt].size()-1]);
        cout<<"Por favor cancelar $"<<combo[opt][combo[opt].size()-1]<<", ingresar el valor de su billete."<<endl;
        cin>>plata;

        while (!cin){
           cin.clear();
           cin.ignore(10000, '\n');
           cout << "Ingrese solo numeros." << endl;
           cin >> plata;
        }

        while(plata<precio){
            cout<<"El billete ingresado no alcanza para pagar el valor del combo"<<endl;
            cout<<"Ingrese un valor de nuevo"<<endl;
            cin>>plata;
        }

        // pago y devuelta de la practica 2
        change(plata-precio);

        string hora;
        string lugar;
        cout<<"Por favor ingrese la hora de su pelicula"<<endl;
        cin>>hora;

        cout<<"Por favor la sala y lugar (ejemplo 1-A1)"<<endl;
        cin>>lugar;
        snacks.nueva_compra(opt);
        //system("cls");
        cout<<"Gracias por confirmar, su pedido le sera entregado de acuerdo a la informacion recibida"<<endl;
        cout<<"Disfrute su estadia"<<endl<<endl;

        break;
    }
}

void change(int valor){
    int result[10] = {0,0,0,0,0,0,0,0,0,0};
    int number[10] = {50000,20000,10000,5000,2000,1000,500,200,100,50};

    cout<<"Reciba su devuelta por favor"<<endl;

    for (int i=0;i<10;i++){
        if (valor/number[i]>0){
            *(result +i) = valor/ (*(number +i));
            valor -= number[i]*result[i];

        }
    }
    for (int i = 0; i<10; i++){
        cout<<*(number+i)<<" : "<<*(result+i)<<endl;
    }
    cout<<endl;
}


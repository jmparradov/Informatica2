#include <iostream>
#include <products.h>
#include <users.h>
#include <products.h>

using namespace std;

users user;
products snacks;

int main(){


    int opt = 10;
    while (true){
        cout << "Bienvenido a Snacks Cinema!" << endl<<endl;
        cout << "Ingrese una opcion para continuar" << endl;
        cout << "1. Acceder al sistema como usuario administrador." << endl;
        cout << "2. Acceder como usuario." << endl<<endl;
        cout << "0. Salir." << endl<<endl;
        cin>>opt;

        if(opt == 1){
            if (login("Admin", user)){
                admin_session();
            }
        }

        if(opt == 2){
            if (login("Client", user)){
                client_session();
            }
        }

        if(opt == 0){
            system("cls");
            cout<<"Hasta pronto!"<<endl;
            break;
        }
    }
    return 0;
}

// ********************            SESSIONS MODULES       ********************************:

// Login module

bool login(string type, users user){
    string username;
    string password;
    bool successfull = false;

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
    }
return  successfull;
}

// administador session
void admin_session(){
    int opt = 10;

    while (true){
        cout << "Ingrese una opcion para continuar" << endl;
        cout << "1. Ingresar productos al inventario." << endl;
        cout << "2. Crear o modificar combos." << endl;
        cout << "3. Generar reporte con ventas del dia." << endl;
        cout << "4. Agregar usuarios." << endl<<endl;
        cout << "0. Cerrar session de administrador"<<endl<<endl;
        cin>>opt;

        if (opt == 1){
            // input products to inventory
            snacks.udpdate_inventory();
        }

        if (opt == 2){
            // create and modify combos !!!!
        }

        if (opt == 3){
            // generate daily report  !!!!
        }

        if (opt == 4){
            string user;
            string password;

            // add users
            cout<<"Ingresar nombre de usuario (sin espacios ni carateres especiales)" << endl;
            cin>>user;
            cout<<"Ingresar contrasena (sin espacios ni carateres especiales)" << endl;
            cin>>password;

            append_users_info(user + "," + password);
            system("cls");
            cout<<"Usuario satisfactoriamente ingresado"<<endl<<endl;
        }

        if (opt == 0){
            system("cls");
            cout<<"Cerrando sesion de administrador"<<endl;
            break;
        }
    }
}


//client session

void client_session(){
    int opt = 10;

    while (true){
        // import combos

        cout << "Seleccione el combo que desea comprar" << endl;
        cout << "1. Combo 1." << endl;
        cout << "2. Combo 2." << endl;
        cout << "3. Combo 3." << endl<<endl;

        cout << "0. Cerrar session"<<endl<<endl;
        cin>>opt;

        if (opt == 1){
            // combo 1..
        }

        if (opt == 2){
            // combo 2..
        }

        if (opt == 3){
            // combo 3..
        }

        if (opt == 0){
            system("cls");
            cout<<"Cerrando sesion de administrador"<<endl;
            break;
        }
    }

}


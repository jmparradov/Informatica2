#include <iostream>
#include <products.h>
#include <users.h>

using namespace std;

int main()
{
    users user;
    int opt = 10;
    while (true){
        cout << "Bienvenido a Snacks Cinema!" << endl<<endl;
        cout << "Ingrese una opcion para continuar" << endl;
        cout << "1. Acceder al sistema como usuario administrador." << endl;
        cout << "2. Acceder como usuario." << endl<<endl;
        cout << "0. Salir." << endl<<endl;
        cin>>opt;

        if(opt == 1){
            string username;
            string password;
            int cnt = 0;
            user.set_type("Admin");

            while (true){
                cout<<"Ingrese el usuario administrador"<<endl;
                cin>>username;

                cout<<"Ingrese la contrasena del administrador"<<endl;
                cin>>password;

                if (user.validate(username,password)){
                    system("cls");
                    cout<<"Bienvenido administrador"<<endl<<endl;
                    // admin_session();
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
        }

        if(opt == 2){

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

// administador session
void admin_session(){


}





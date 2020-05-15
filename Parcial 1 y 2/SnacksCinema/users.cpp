#include "users.h"

using namespace std;

users::users(string s_type){
    type = s_type;
}

void users::set_type(string s_type){
    type = s_type;
}

std::string users::get_type(){
    return type;
}

vector<string> users::get_allusers(){
    return all_users;
}

bool users::validate(std::string s_username, std::string s_password){
    bool validation = false;

    if (type == "Admin"){
        vector<string> admin_auth = opensudo();
        if (s_username == admin_auth[0] && s_password == admin_auth[1]){
            validation = true;
        }
    }
    if (type == "Client"){
        vector<string> users_auth = get_userinfo();
        vector<string>::iterator it = users_auth.begin();

        while(it != users_auth.end()){
            vector <string> user_content = split_text(*it);
            if (user_content[0] == s_username && user_content[1] == s_password){
                validation = true;
            }
            it++;
        }

    }
    return validation;
}

void users::append_users_info(string input){
    string crypted = "";
    crypted = p_encriptado(input);
    ofstream outfile;

    outfile.open("../SnacksCinema/Data/users.txt", std::ios_base::app);
    outfile << crypted + "\n";
    outfile.close();
}

// functions outside the class

vector <string> split_text(string value){
    stringstream test(value);
    string segment;
    vector<string> seglist;
    while(getline(test, segment, ','))
    {
       seglist.push_back(segment);
    }
    return seglist;
}


vector<string> opensudo(){
   string file = "sudo.txt";
   string data = "";
   vector<string> splitted;

   ifstream infile;
   infile.open("../SnacksCinema/Data/" + file);

   if (!infile.is_open())
   {
     cout << "Error opening file" << endl;
     exit(1);
   }

   infile >> data;
   infile.close();

   splitted = split_text(data);
   return splitted;
  }


vector <string> get_userinfo(){
string data = "";
string ndata = "";
vector<string> seglist;

   ifstream infile;
   infile.open("../SnacksCinema/Data/users.txt");

   if (!infile.is_open())
   {
     cout << "No hay usuarios ingresados" << endl;
     cout << "Ingrese usuarios desde el perfil administrador para habilitar esta seccion." << endl;
     exit(1);
   }

   while (std::getline(infile, data))
   {
       if(data.size() > 0)
           ndata = p_desencriptado(data);
           seglist.push_back(ndata);
   }
   infile.close();

   return seglist;
  }


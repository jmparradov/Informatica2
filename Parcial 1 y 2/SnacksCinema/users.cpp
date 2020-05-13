#include "users.h"
using namespace std;

users::users(){}

string users::get_type(){
    return type;
}

string users::get_username(){
    return username;
}

string users::get_password(){
    return password;
}

void users::set_type(string stype){
    type = stype;
}

void users::set_username(string susername){
    username = susername;
}

void users::set_password(string spassword){
    password = spassword;
}

bool users::validate(std::string s_username, std::string s_password){
    bool validation = false;

    if (type == "Admin"){
        vector<string> admin_auth = opensudo();
        if (s_username == admin_auth[0] && s_password == admin_auth[1]){
            validation = true;
        }
    }
    if (type == "client"){
        validation = true;
    }
    return validation;
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

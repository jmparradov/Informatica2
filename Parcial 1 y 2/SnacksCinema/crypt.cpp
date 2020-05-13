#include <users.h>
#include <bits/stdc++.h>
using namespace std;

int n = 4;

string strToBinary(string s){
    int n = s.length();
    string binary = "";
    for (int i = 0; i < n; i++)
    {

        int val = int(s[i]);
        string bin = "";
        int j = 0;
        while (j < 8)
        {
            (val % 2)? bin.push_back('1') :
                       bin.push_back('0');
            val /= 2;
            j += 1;
        }
        reverse(bin.begin(), bin.end());
    binary += bin;
    }
    return binary;
}

string BinaryTostr(string s){
    int n = s.length();
    string original = "";
    int sum = 0;
    int j = 7;
    int i = 0;

    while (i < n){
        while (j >= 0){
            if (s.at(i) == '1'){
                sum += pow(2,j);
            }
            j -= 1;
            i += 1;
        }

        std::string ss(1, char(sum));
        original += ss;
        j = 7;
        sum = 0;
    }
    return original;
}

string p_encriptado(string text){

    int l_binary = 0;
    string binary = "";
    int i = 0;
    int j = 0;
    int cnt_group = 0;
    int one_count = 0;
    int zero_count = 0;

    int n_one_count = 0;
    int n_zero_count = 0;
    string crypted = "";

    binary = strToBinary(text);
    l_binary = binary.length();

    while (i<l_binary){
        while (j<n){
            if (cnt_group == 0){
                if (binary[i] =='0'){
                    crypted.push_back('1');
                    n_zero_count += 1;
                }
                else{
                    n_one_count += 1;
                    crypted.push_back('0');
                }
            }
            else {
                if(zero_count == one_count){
                    if (binary[i] =='0'){
                        crypted.push_back('1');
                        n_zero_count += 1;
                    }
                    else{
                        n_one_count += 1;
                        crypted.push_back('0');
                    }
                }
                else if(zero_count > one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%2==0){
                            crypted.push_back('1');
                        }
                        else{
                            crypted.push_back('0');
                        }
                        n_zero_count += 1;
                    }
                    else{
                        n_one_count += 1;
                        if ((j+1)%2==0){
                            crypted.push_back('0');
                        }
                        else{
                            crypted.push_back('1');
                        }
                    }

                }
                else if(zero_count < one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%3==0){
                            crypted.push_back('1');
                        }
                        else {
                            crypted.push_back('0');
                        }
                        n_zero_count += 1;
                    }
                    else{
                        n_one_count += 1;
                        if ((j+1)%3==0){
                            crypted.push_back('0');
                        }
                        else {
                            crypted.push_back('1');
                        }
                    }
                }
            }
            j += 1;
            i += 1;
        }
        cnt_group += 1;
        j =0;
        zero_count = n_zero_count;
        n_zero_count = 0;
        one_count = n_one_count;
        n_one_count = 0;
    }
    return crypted;
}

string p_desencriptado(string binary){
    int l_binary = 0;
    int i = 0;
    int j = 0;
    int cnt_group = 0;
    int one_count = 0;
    int zero_count = 0;

    int n_one_count = 0;
    int n_zero_count = 0;
    string crypted = "";
    string decrypted = "";

    l_binary = binary.length();

    while (i<l_binary){
        while (j<n){
            if (cnt_group == 0){
                if (binary[i] =='0'){
                    crypted.push_back('1');
                    n_one_count += 1;
                }
                else{
                    n_zero_count += 1;
                    crypted.push_back('0');
                }
            }
            else {
                if(zero_count == one_count){
                    if (binary[i] =='0'){
                        crypted.push_back('1');
                        n_one_count += 1;
                    }
                    else{
                        n_zero_count += 1;
                        crypted.push_back('0');
                    }
                }
                else if(zero_count > one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%2==0){
                            crypted.push_back('1');
                            n_one_count += 1;
                        }
                        else{
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }

                    }
                    else{
                        if ((j+1)%2==0){
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }
                        else{
                            crypted.push_back('1');
                            n_one_count += 1;
                        }
                    }

                }
                else if(zero_count < one_count){
                    if (binary[i] =='0'){
                        if ((j+1)%3==0){
                            crypted.push_back('1');
                            n_one_count += 1;
                        }
                        else {
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }

                    }
                    else{
                        if ((j+1)%3==0){
                            crypted.push_back('0');
                            n_zero_count += 1;
                        }
                        else {
                            crypted.push_back('1');
                            n_one_count += 1;
                        }
                    }
                }
            }
            j += 1;
            i += 1;
        }
        cnt_group += 1;
        j =0;
        zero_count = n_zero_count;
        n_zero_count = 0;
        one_count = n_one_count;
        n_one_count = 0;
    }

    decrypted = BinaryTostr(crypted);
    return decrypted;
}

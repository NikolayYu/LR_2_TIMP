#include "modRoutingCipher.h"

void check(const string& Text, const string& key)
{
    try {
        string cipherText;
        string decryptedText;
        if (key.empty())
            throw cipher_error("Empty key");
        if (stoi(key) > 0) {
            modRoutingCipher cipher(stoi(key));
            cipherText = cipher.encrypt(Text);
            decryptedText = cipher.decrypt(cipherText);
            cout<<"key="<<key<<endl;
            cout<<"Encrypted text:  "<<cipherText<<endl;
            cout<<"Decrypted text:  "<<decryptedText<<endl;
        } else
            throw cipher_error(std::string("Invalid key ")+key);
    } catch (const cipher_error & e) {
        cerr<<"Error:  "<<e.what()<<endl;
    }
    cout<<""<<endl;
}

int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check ("CAR","0");
    check ("CAR","");
    check ("mahina", "7");
    check("ma    h i n a","7");
    check("123","4");
}

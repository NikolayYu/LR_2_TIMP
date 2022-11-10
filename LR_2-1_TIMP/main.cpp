#include <iostream>
#include <cctype>
#include "modAlphaCiper.hpp"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
try {
wstring cipherText;
wstring decryptedText;
modAlphaCipher cipher(key);
cipherText = cipher.encrypt(Text);
if (destructCipherText)
cipherText.front() = towlower(cipherText.front());
decryptedText = cipher.decrypt(cipherText);
wcout<<L"key="<<key<<endl;
wcout<<Text<<endl;
wcout<<cipherText<<endl;
wcout<<decryptedText<<endl;
} catch (const cipher_error & e) {
wcerr<<"Error: "<<e.what()<<endl;
}

}

int main()
{
locale loc("ru_RU.UTF-8");
locale::global(loc);
check(L"МАШИНА",L"ГРАНТА");
check(L"ГРАНТА",L"");
check(L"ГРАНТА",L"МАШИНА666");
check(L"Г Р А Н Т А",L"МАШИНА");
check(L"666",L"МАШИНА");
}

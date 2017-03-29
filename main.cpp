#include <iostream>
#include "document.h"
#include "tags.h"

using namespace std;
void menu(int &angka){
string mes[]={

"1.List All Document With The Tags \n","2.Find  Document  \n","3.Create Something\n",
"4.Find The most popular tags\n","5.\n"

};
/*use sizeof function to determine size of array*/
for (size_t i = 0; i < sizeof(mes)/sizeof(string); i++) {
  cout << mes[i] << '\n';
}
int dumb;
cout << "Pilih Angka : " << '\n';
cin >> dumb;
angka=dumb;

}

int main() {
int angka;
  menu(angka);
  cout <<angka;
    return 0;
}

#include <iostream>
#include "document.h"
#include "tags.h"

using namespace std;
void menu(bool &stats){
    int pil;
    docList listD;
    tagsList listT;
    infotype x;
    createList(listT);
    createlist(listD);
    cout << "Menu :"<<endl;
    cout << "1.  Add a new document"<<endl;//udah
    cout << "2.  Add a new tag"<<endl;//udah
    cout << "3.  Pin tag to document"<<endl;//udah
    cout << "4.  Delete a certain document"<<endl;//udah
    cout << "4.  Delete a certain tag"<<endl;//udah
    cout << "5.  Show all documents and all of each tag"<<endl;//udah
    cout << "6.  Find the most popular tags"<<endl;//udah
    cout << "7.  List all documents tagged having the most popular tag"<<endl;//udah
    cout << "8.  Find a document with the largest and smallest number of tags"<<endl;
    cout << "9.  Given two tags, find documents having both tags or one of them"<<endl;
    cout << "10. Lists all papers that do not have any tag"<<endl;
    cout << "11. Given a paper, find the most similar paper"<<endl;
    cout << "12. Quit"<<endl;//udah
    cout << "Pilih menu : ";
    cin >> pil;
    switch(pil) {
        case 1:
            cout<<"Document title: ";
            cin>> x;
            addDoc(listD,x);
            break;
        case 2:
            cout<<"Tag name: ";
            cin>> x;
            newTags(listT,x);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            cout << "GoodBye!!"<<endl;
            stats = false;
            break;
        default:
            break;
    }
};
int main(){
    bool stats = true;
    while(stats){
        menu(stats);
    }
    return 0;
}

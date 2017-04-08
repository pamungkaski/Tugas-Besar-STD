#include <iostream>
#include "document.h"

using namespace std;
void menu(bool &stats){
    int pil;
    docList listD;
    tagsList listT;
    infotype x,y;
    createList(listT);
    createlist(listD);
    cout << "Menu :"<<endl;
    cout << "1.  Add a new document"<<endl;//udah
    cout << "2.  Add a new tag"<<endl;//udah
    cout << "3.  Pin tag to document"<<endl;//udah
    cout << "4.  Delete a certain document"<<endl;//udah
    cout << "5.  Delete a certain tag"<<endl;//udah
    cout << "6.  Show all documents and all of each tag"<<endl;//udah
    cout << "7.  Find the most popular tags"<<endl;//udah
    cout << "8.  List all documents tagged having the most popular tag"<<endl;//udah
    cout << "9.  Find a document with the largest and smallest number of tags"<<endl;//udah
    cout << "10. Given two tags, find documents having both tags or one of them"<<endl;
    cout << "11. Lists all papers that do not have any tag"<<endl;//udah
    cout << "12. Given a paper, find the most similar paper"<<endl;//udah
    cout << "13. Quit"<<endl;//udah
    cout << "Pilih menu : ";
    cin >> pil;
    switch(pil) {
        case 1:
            cout<<"Document title: ";
            cin>> x;
            addDoc(listD,x);
            cout<<"Document Added"<<endl;
            break;
        case 2:
            cout<<"Tag name: ";
            cin>> x;
            newTags(listT,x);
            cout<<"Tag Added"<<endl;
            break;
        case 3:
            cout<<"Document title: ";
            cin>> x;
            cout<<"Tag name: ";
            cin>> y;
            createRelation(listD,listT,x,y);
            cout<<"Relation Added"<<endl;
            break;
        case 4:
            cout<<"Document title: ";
            cin>> x;
        	deleteDoc(listD,listT,x);
        	cout<<"Document Deleted"<<endl;
            break;
        case 5:
            cout<<"Tag name: ";
            cin>> x;
            deleteCertTags(listD,listT,x);
            cout<<"Tag Deleted"<<endl;
            break;
        case 6:
            cout<<"Document List"<<endl;
        	showdoc(listD);
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
            break;
        case 13:
            cout << "GoodBye!!"<<endl;
            stats = false;
            break;
        default:
            cout << "False Input"<<endl;
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

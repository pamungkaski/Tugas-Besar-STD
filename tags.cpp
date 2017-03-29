//
// Created by Ki Ageng Satria Pamungkas on 3/23/17.
//

#include "tags.h"
void createList(tagsList &L){
    L.first = NULL;
    L.last = NULL;
};
tagsAddress findTags(tagsList &L, infotype x){
    tagsAddress P=L.first;
    while((P->info!=x)and(P->next!=NULL)){
        P=P->next;
    }
    if(P->info==x){
        return P;
    }else{
        return NULL;
    }
};
// allocate and insert the new tags
void newTags(tagsList &L, infotype x){
    tagsAddress P = new tagsElm;
    P->tagsUsed =0;
    P->info = x;
    P->next = NULL;
    if (L.first==NULL){
        L.first=P;
        L.last =P;
    }else {
        L.last->next = P;
        L.last = P;
    };
};
void deleteTags(tagsList &L, infotype x){
    if(L.first!=NULL) {
        tagsAddress P1 = L.first;
        if(P1->info==x){
            if(L.first==L.last){
                L.first = NULL;
                L.Last = NULL;
                delete(P1);
            }else{
                L.first= P1->next;
                delete(P1);
            }
        }else {
            while (P1->next->info != x) {
                P1 = P1->next;
            };
            if(P1->next==L.last){
                L.last=P1;
                P1= P1->next;
                delete(P1);
            }else{
                P1->next=P1->next->next;
                P1=P1->next;
                delete(P1);
            }
        };
    }else{
        cout<<"Empty List"<<endl;
    }
};
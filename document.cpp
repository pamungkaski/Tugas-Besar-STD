//
// Created by Ki Ageng Satria Pamungkas on 3/23/17.
//
#include "document.h"
void createlist (docList &L){
	L.first = NULL;
	L.last = NULL;
};

void addDoc (docList &L, infotype x){
	docAddress P = new docElm;
	P->tagCount = 0;
	P->info = x;
	P->next = NULL;
	P->child.first = NULL;
	P->child.last = NULL;
	if (L.first = NULL){
		L.first = P;
		L.last = P;
	}else {
		L.last->next = P;
		L.last = P;
	};
};

tagAddress findElm (docList &L, infotype x){
	docAddress P=L.first;
	while (P->info != x) and (P->next != NULL){
		P = P->next;
	}if (P->info = x){
		return P;
	}else {
		return NULL;
	};
};


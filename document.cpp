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
	P->tagsCount = 0;
	P->info = x;
	P->next = NULL;
	P->child.first = NULL;
	P->child.last = NULL;
	if (L.first == NULL){
		L.first = P;
		L.last = P;
	}else {
		L.last->next = P;
		L.last = P;
	};
};

docAddress findElm(docList &L, infotype x){
	docAddress P=L.first;
	while ((P->info != x) and (P->next != NULL)){
		P = P->next;
	}if (P->info == x){
		return P;
	}else {
		return NULL;
	};
};
void createRelation(docList &Ld,tagsList &Lt, infotype x, infotype y){
    docAddress Pd = findElm(Ld,x);
    tagsAddress Pt = findTags(Lt,y);
    Pd->tagsCount+=1;
    Pt->tagsUsed+=1;
    childAddress P = new childElm;
    P->info = Pt;
    if(Pd->child.first == NULL){
        Pd->child.first = P;
        Pd->child.last = P;
    }else{
        Pd->child.last->next =P;
        Pd->child.last = P;
    }
};
void showdoc(docList &L){
	docAddress P=L.first;
	while (P!= NULL){
		cout<<"Document="<<P->info<<endl;
		childAddress Pt = P->child.first;
        cout<<"Tags:"<<endl;
        while (Pt != NULL){
			cout<<"#"<<Pt->info->info<<" ";
			Pt = Pt->next;
		};
		P = P->next;
	};
};
tagsAddress popTag(tagsList &L){
    tagsAddress P = L.first;
    tagsAddress max = P;
    P = P->next;
    while(P != NULL){
        if(P->tagsUsed > max->tagsUsed){
            max = P;
        }
        P = P->next;
    }
    return max;
}
childAddress findTagsInDoc(docAddress doc, infotype x){
    childAddress P = doc->child.first;
    while ((P->info->info != x) and (P->next != NULL)){
        P = P->next;
    }if (P->info->info == x){
        return P;
    }else {
        return NULL;
    };
}
void docPop(docList &dL, tagsList &tL){
	docAddress P = dL.first;
	while(P != NULL){
		if(findTagsInDoc(P,popTag(tL)->info) != NULL){
			cout<<P->info<<endl;
		}
        P = P->next;
	}
}

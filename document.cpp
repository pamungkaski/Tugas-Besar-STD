//
// Created by Ki Ageng Satria Pamungkas on 3/23/17.
//
#include "document.h"
void createList (docList &L){
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
void showDoc(docList &L){
	docAddress P = L.first;
    int i = 1;
	while (P!= NULL){
        cout<<"#"<<i<<endl;
		cout<<"Document: "<<P->info<<endl;
		childAddress Pt =  new childElm;
        Pt = P->child.first;
        cout<<"Tags:"<<endl;
        while (Pt != NULL){
			cout<<"#"<<Pt->info->info<<" ";
			Pt = Pt->next;
		};
        cout << endl;
		P = P->next;
        i+=1;
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
};
childAddress findTagsInDoc(docAddress doc, infotype x){
    childAddress P = new childElm;
    P = doc->child.first;
    while ((P->info->info != x) and (P->next != NULL)){
        P = P->next;
    }if (P->info->info == x){
        return P;
    }else {
        return NULL;
    };
};
void docPop(docList &dL, tagsList &tL){
	docAddress P = dL.first;
	while(P != NULL){
		if(findTagsInDoc(P,popTag(tL)->info) != NULL){
			cout<<P->info<<endl;
		}
        P = P->next;
	}
}
void deleteDoc(docList &dL,tagsList &tL, infotype x){
    docAddress Pd = findElm(dL,x);
    childAddress dC = new childElm;
    dC = Pd->child.first;
    while(dC != NULL){
        dC->info->tagsUsed-=1;
        dC= dC->next;
    }
    if(Pd == dL.first){
        if(dL.first == dL.last){
            dL.first = NULL;
            dL.last = NULL;
        }else {
            dL.first = Pd->next;
        }
    }else if(Pd == dL.last){
        docAddress dP = dL.first;
        while(dP->next != Pd){
            dP = dP->next;
        }
        dL.last = dP;
        dP->next = Pd->next;
    }else{
        docAddress dP = dL.first;
        while(dP->next != Pd){
            dP = dP->next;
        }
        dP->next = Pd->next;
    }
    delete(Pd);
};
void deleteCertTags(docList &dL,tagsList &tL, infotype x){
    docAddress Pd = dL.first;
    childAddress Pc1,Pc2 = new childElm;
    while(Pd != NULL){
        Pc1 = Pd->child.first;
        if(Pc1->info->info == x){
            if(Pd->child.first == Pd->child.last){
                Pd->child.first = NULL;
                Pd->child.last = NULL;
                delete Pc1;
            } else {
                Pd->child.first = Pc1->next;
                delete Pc1;
            }
        }else{
            while(Pc1->next->info->info != x){
                Pc1 = Pc1->next;
            }
            Pc2 = Pc1->next;
            if(Pc2 == Pd->child.last){
                Pd->child.last = Pc1;
            }
            Pc1->next = Pc2->next;
            delete Pc2;
        }
        Pd = Pd->next;
    }
    deleteTags(tL,x);
};
void showDocWithSmallnLargeTag(docList &dL){
    docAddress min = dL.first;
    docAddress max = dL.first;
    docAddress P = dL.first->next;
    while(P != NULL){
        if(min->tagsCount > P->tagsCount){
            min = P;
        }else if(max->tagsCount < P->tagsCount){
            max = P;
        }
        P = P->next;
    }
    cout << "Document with smallest number of tags: " << min->info <<"(Tags: "<<min->tagsCount<<")"<< endl;
    cout << "Document with biggest number of tags: " << max->info <<"(Tags: "<<max->tagsCount<<")"<< endl;
};
void noTagDoc(docList &dL){
    docAddress P = dL.first;
    while(P != NULL){
        if(P->tagsCount == 0){
            cout<< P->info<<endl;
        }
        P = P->next;
    }
};
void findMostSimillarPaper(docList &dL, infotype x){
    docAddress Pd = findElm(dL,x);
    docAddress P = dL.first;
    struct simillarity{
        infotype name;
        int count = 0;
    };
    simillarity simList[100];
    int i = 0;
    while(P != NULL){
        if(P->info != x){
            simList[i].name = P->info;
            simList[i].count = 0;
            childAddress Pc = new childElm;
            Pc = P->child.first;
            while (Pc != NULL){
                if(findTagsInDoc(Pd,Pc->info->info) != NULL){
                    simList[i].count +=1;
                }
            }
        }
        P =P->next;
        i+=1;
    }
    int max = simList[0].count;
    for (int j = 1; j <=i; ++j) {
        if(max < simList[j].count){
            max = simList[j].count;
        }
    }
    cout << "Most Simmilar Document(has "<<max<<" same tag(s)"<<endl;
    for (int j = 0; j <=i; ++j) {
        if(max == simList[j].count){
            cout << simList[j].name <<endl;
        }
    }
};
void findDocBasedOnTag(docList &dL,infotype x,infotype y){
    docAddress P = dL.first;
    while (P != NULL){
        if((findTagsInDoc(P,x) != NULL) or (findTagsInDoc(P,y) != NULL)){
            cout<<P->info<<endl;
        }
    }
}
//
// Created by Ki Ageng Satria Pamungkas on 3/23/17.
//
#include <iostream>
#include <string>
#include "tags.h"
using namespace std;
#ifndef TUGASBESARSTD_DOCUMENT_H
#define TUGASBESARSTD_DOCUMENT_H
typedef string infotype;
typedef struct docElm *docAddress;
typedef childElm *childAddress;
typedef tagsElm *childInfo;
struct childElm{
    childInfo info;
    childAddress next;
};
struct childList{
    childAddress first;
    childAddress last;
};
struct docList{
    docAddress first;
    docAddress last;
};
struct docElm{
    infotype info;
    int tagsCount;//The number of tags in the document
    childList child;
    docAddress next;
};
void createlist (docList &L);
void addDoc (docList &L, infotype x);
docAddress findElm(docList &L, infotype x);
void createRelation(infotype x, infotype y);
void showdoc (docList &L);
void popTag (tagsList &L);
#endif //TUGASBESARSTD_DOCUMENT_H

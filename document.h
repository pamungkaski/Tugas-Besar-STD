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
typedef struct childElm *childAddress;
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
void createRelation(docList &Ld,tagsList &Lt, infotype x, infotype y);
void showdoc (docList &L);
tagsAddress popTag (tagsList &L);
childAddress findTagsInDoc(docAddress doc, infotype x);
void docPop(docList &dL, tagsList &tL);
void deleteDoc(docList &dL,tagsList &tL, infotype x);
void deleteCertTags(docList &dL,tagsList &tL, infotype x);
tagsAddress smallTag(taglist &L);
void showSmallTag(docList &dL,tagsList &tL);
void notagDOc(docList &dL,tagsList &tL);
docAddress findbothtag(docList &dL,taglist &tL);
#endif //TUGASBESARSTD_DOCUMENT_H

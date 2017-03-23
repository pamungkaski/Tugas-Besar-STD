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
typedef tagsAddress *childAddress;
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
    childList child;
    docAddress next;
};
#endif //TUGASBESARSTD_DOCUMENT_H

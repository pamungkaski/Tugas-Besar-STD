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

struct docElm{
    infotype info;

};
struct docList{
    docAddress first;
    docAddress last;
};
#endif //TUGASBESARSTD_DOCUMENT_H

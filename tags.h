//
// Created by Ki Ageng Satria Pamungkas on 3/23/17.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef TUGASBESARSTD_TAGS_H
#define TUGASBESARSTD_TAGS_H
#define
typedef string infotype;

typedef struct tagsElm *tagsAddress;

struct tagsElm {
    int tagsUsed;// the number tags being used
    infotype info;
    tagsAddress next;
};

struct tagsList{
    tagsAddress first;
    int popular;
    tagsAddress last;
};
void createList(tagsList &L);
tagsAddress findTags(tagsList &L, infotype x);
void newTags(tagsList &L, infotype x);// allocate and insert the new tags
void deleteTags(tagsList &L, infotype x);
#endif //TUGASBESARSTD_TAGS_H

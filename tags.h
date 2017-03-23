//
// Created by Ki Ageng Satria Pamungkas on 3/23/17.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef TUGASBESARSTD_TAGS_H
#define TUGASBESARSTD_TAGS_H
typedef string infotype;
typedef struct tagsElm *tagsAddress;
struct tagsElm {
    infotype info;
    tagsAddress next;
};
struct tagsList{
    tagsAddress first;
    tagsAddress last;
};
#endif //TUGASBESARSTD_TAGS_H

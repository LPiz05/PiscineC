//
// Created by louis on 08/11/2020.
//
#ifndef PISCINEC_GENERATE_H
#define PISCINEC_GENERATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tag {
    char * startTag;
    char * endTag;
    char * content;
    struct Tag ** childTags; //array of child tag structs
    int childsAmount;
} Tag;

struct DtdTag {
    char * tagName;
    struct DtdAttr ** attributs;
    struct DtdTag ** childTags; //array of child dtdTag structs
    int childsAmount;
    char * contentType;
} DtdTag;

struct DtdAttr {
    char * name;
    char ** values;
    int valuesSize;
    char * type; //keep empty if values et and define type if no determined values
} DtdAttr;

struct Tag *createTag();
struct DtdTag *createDtdTag();
struct DtdAttr *createDtdAttr();
struct DtdAttr **createAttrList();

#endif //PISCINEC_GENERATE_H

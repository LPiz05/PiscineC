//
// Created by louis on 08/11/2020.
//
#include "generate.h"

struct DtdAttr *createDtdAttr(char *name, char ** values, int valuesSize, char * type) {
    struct DtdAttr *newDtdAttr = malloc(sizeof(DtdAttr));

    newDtdAttr->name = malloc(sizeof(char) * 100);
    strcpy(newDtdAttr->name, "name");

    if (valuesSize > 0) {
        newDtdAttr->type = malloc(sizeof(char) * 100);
        strcpy(newDtdAttr->type, "0");
        newDtdAttr->valuesSize = valuesSize;
        newDtdAttr->values = malloc(sizeof(char *));
        for (int i = 0; i < valuesSize; ++i) {
            newDtdAttr->values[i] = malloc(sizeof(char) * strlen(values[i]));
            strcpy(newDtdAttr->values[i], values[i]);
        }
    }
    else {
        newDtdAttr->type = malloc(sizeof(char) * 100);
        strcpy(newDtdAttr->type, type);
        newDtdAttr->values = NULL;
        newDtdAttr->valuesSize = 0;
        newDtdAttr->name = NULL;
    }

    return newDtdAttr;
}

struct DtdAttr ** createDtdAttrList(int nbAttr) {

    struct DtdAttr **attrList = malloc(sizeof(DtdAttr) * nbAttr);

    attrList[0] = createDtdAttr("name", NULL, 0, "string");

    return attrList;
}

struct Tag * createTag(char * start, struct Attr ** attrList, int attrAmount, char * content, char * end) {
    struct Tag * newTag = malloc(sizeof(Tag));

    newTag->start = malloc(sizeof(char) * strlen(start));
    strcpy(newTag->start, start);

    newTag->attributsAmount = attrAmount;
    newTag->attributs = attrList;

    newTag->content = malloc(sizeof(char) * strlen(content));
    strcpy(newTag->content, content);

    newTag->end = malloc(sizeof(char) * strlen(end));
    strcpy(newTag->end, end);

    return newTag;
}

struct Attr ** createAttrList(int nbAttr) {

    struct Attr **attrList = malloc(sizeof(Attr) * nbAttr);

    attrList[0] = createAttr("name", "Charles");
    attrList[1] = createAttr("name", "Jack");

    return attrList;
}

struct Attr *createAttr(char* name, char* value) {
    struct Attr * newAttr = malloc(sizeof(Attr));

    newAttr->name = malloc(sizeof(char) * strlen(name));
    strcpy(newAttr->name, name);
    newAttr->value = malloc(sizeof(char) * strlen(value));
    strcpy(newAttr->value, value);

    return newAttr;
}



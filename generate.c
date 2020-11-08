//
// Created by louis-keolio on 08/11/2020.
//
#include "generate.h"

struct Tag *createTag() {
    struct Tag *newTag = malloc(sizeof(Tag));

    newTag->startTag = malloc(sizeof(char) * 100);
    strcpy(newTag->startTag, "<student type='boy'>");
    newTag->endTag = malloc(sizeof(char) * 100);
    strcpy(newTag->endTag, "</student>");
    newTag->content = malloc(sizeof(char) * 100);
    strcpy(newTag->content, "Jean");
    newTag->childTags =  NULL; //no child tag for this one
    newTag->childsAmount = 0;

    return newTag;
}

struct DtdTag *createDtdTag() {
    struct DtdTag *newDtdTag = malloc(sizeof(Tag));

    newDtdTag->tagName = malloc(sizeof(char) * 100);
    strcpy(newDtdTag->tagName, "student");

    newDtdTag->contentType = malloc(sizeof(char) * 100);
    strcpy(newDtdTag->contentType, "#PCDATA");

    newDtdTag->childTags = NULL;
    newDtdTag->childsAmount = 0;

    newDtdTag->attributs = createAttrList(1);

    return newDtdTag;
}

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

struct DtdAttr ** createAttrList(int nbAttr) {

    struct DtdAttr **attrList = malloc(sizeof(DtdAttr) * nbAttr);

    attrList[0] = createDtdAttr("name", NULL, 0, "string");

    return attrList;
}


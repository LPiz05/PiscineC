#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tag {
    char * startTag;
    char * endTag;
    char * content;
    struct Tag ** childTags; //array of child tag structs
} Tag;

struct DtdTag {
    char * tagName;
    struct DtdAttr ** attributs;
    struct DtdTag ** childTags; //array of child dtdTag structs
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

int main (int    argc, char **argv)
{
    printf("It works !");

    struct Tag *tag = createTag();
    struct DtdTag *dtdTag = createDtdTag();

    return 0;
}

struct Tag *createTag() {
    struct Tag *newTag = malloc(sizeof(Tag));

    strcpy(newTag->startTag, "<student type='boy'>");
    strcpy(newTag->endTag, "</student>");
    strcpy(newTag->content, "Jean");
    newTag->childTags =  NULL; //no child tag for this one

    return newTag;
}

struct DtdTag *createDtdTag() {
    struct DtdTag *newDtdTag = malloc(sizeof(Tag));

    strcpy(newDtdTag->tagName, "student");
    strcpy(newDtdTag->contentType, "#PCDATA");
    newDtdTag->childTags = NULL;
    newDtdTag->attributs = createAttrList(1);

    return newDtdTag;
}

struct DtdAttr *createDtdAttr(char *name, char ** values, int valuesSize, char * type) {
    struct DtdAttr *newDtdAttr = malloc(sizeof(DtdAttr));

    strcpy(newDtdAttr->name, "name");

    if (valuesSize > 0) {
        strcpy(newDtdAttr->type, "0");
        newDtdAttr->valuesSize = valuesSize;
        newDtdAttr->values = malloc(sizeof(char *));
        for (int i = 0; i < valuesSize; ++i) {
            newDtdAttr->values[i] = malloc(sizeof(char) * strlen(values[i]));
            strcpy(newDtdAttr->values[i], values[i]);
        }
    }
    else {
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

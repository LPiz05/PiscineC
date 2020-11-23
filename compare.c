//
// Created by louis-keolio on 08/11/2020.
//
#include "compare.h"

int compare(struct Tag *tag, struct DtdTag *dtdTag) {

    //compare parent

    return compareChilds(tag, dtdTag);
}

int compareChilds(struct Tag *tag, struct DtdTag *dtdTag) {

    int find; //defini si on a trouvé un correspondance entre le tag et une dtd, permet de renvoyer 0 si on a pas trouver de cmparaison possible

    for (int i = 0; i < tag->childsAmount; ++i) {
        find = 0;
        for (int j = 0; j < dtdTag->childsAmount; ++j) {

            if (checkTagName(tag->childTags[i]->start, tag->childTags[i]->end,
                             dtdTag->childTags[j]->tagName)) { //find a corresponding dtd for each child
                find = 1;

                struct Tag *tagToCheck = tag->childTags[i];
                struct DtdTag *dtdToCheck = dtdTag->childTags[j];

                if (!checkAttributs(tagToCheck->attributs, tagToCheck->attributsAmount, dtdToCheck->attributs,
                                    dtdToCheck->attributsAmount))
                    return 0;

                if (tag->childsAmount > 0) { //si il a des enfants on les checks car c'est une balise parent
                    if (!compareChilds(tagToCheck, dtdToCheck)) return 0;
                } else { //pas d'enfants donc on check son content car c'est une balise enfant
                    if (!checkContent(tagToCheck->content, dtdToCheck->contentType)) return 0;
                }

            }
        }
    }
    if (!find) return 0;

    return 0;
}

int checkTagName(char *start, char *end, char *tagName) {
    if (strstr(start, tagName) == NULL) return 0; //check in both way
    if (strstr(tagName, start) == NULL) return 0; //check in both way
    if (strstr(end, tagName) == NULL) return 0; //check in both way
    if (strstr(tagName, end) == NULL) return 0; //check in both way

    return 1;
}

int checkAttributs(struct Attr **attrList, int sizeAttr, struct DtdAttr **dtdAttrList, int sizeDtdAttr) {

    int find;

    for (int i = 0; i < sizeAttr; ++i) {
        find = 0;
        for (int j = 0; j < sizeDtdAttr; ++j) {
            if (checkAttrName(attrList[i]->name, dtdAttrList[j]->name)) {
                find = 1;

                //check

            }
        }
        if (!find) return 0; //pas trouvé d'occurrence
    }

    return 1;
}

int checkAttrName(char *attrName, char *dtdAttrName) {
    if (strstr(attrName, dtdAttrName) == NULL) return 0; //check in both way
    if (strstr(dtdAttrName, attrName) == NULL) return 0; //check in both way
    return 1;
}

int checkContent(char *content, char *contentType) {
    if (strstr(contentType, "EMPTY")) {
        if (strlen(content) > 0) return 0;
    }
    //#PCDATA et ANY pas pris en compte pour le moment

    return 1;
}



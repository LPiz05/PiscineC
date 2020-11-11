//
// Created by louis-keolio on 08/11/2020.
//
#include "compare.h"

int compare(struct Tag *tag, struct DtdTag *dtdTag) {

    //compare parent

    return compareChilds(tag, dtdTag);
}

int compareChilds(struct Tag *tag, struct DtdTag *dtdTag) {

    if (tag->childsAmount > 0) {
        if (dtdTag->childsAmount > 0) {
            for (int i = 0; i < tag->childsAmount; ++i) {
                isvalid(tag->childTags[i], dtdTag->childTags, dtdTag->childsAmount);
            }
        }
    }

    return 0;
}

int isvalid(struct Tag *tag, struct DtdTag **dtdTags, int dtdTagsAmount) {

    for (int i = 0; i < dtdTagsAmount; ++i) {
        if (checkStartTag(tag, dtdTags[i]->tagName, dtdTags[i]->attributs, dtdTags[i]->attributsAmount)) {
            return 1;
        }
    }
    return 0;
}

int checkStartTag(struct Tag *tag, char *tagName, struct DtdAttr **attrList, int attrAmount) {
    if (strstr(tag->start, tagName) == NULL) return 0; //check in bot way
    if (strstr(tagName, tag->start) == NULL) return 0; //check in bot way

    for (int i = 0; i < tag->attributsAmount; ++i) {
        
    }

    return 1;
}



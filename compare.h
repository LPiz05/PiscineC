//
// Created by louis-keolio on 08/11/2020.
//

#ifndef PISCINEC_COMPARE_H
#define PISCINEC_COMPARE_H

#include "generate.h"

int compare(struct Tag *, struct DtdTag *);

int compareChilds(struct Tag *tag, struct DtdTag *dtdTag);

int isvalid(struct Tag *tag, struct DtdTag **dtdTags, int dtdTagsAmount);

int checkStartTag(struct Tag *, char *, struct DtdAttr **, int);

int isValidName(char *startTag, char *tagName);

#endif //PISCINEC_COMPARE_H

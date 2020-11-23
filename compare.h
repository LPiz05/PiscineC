//
// Created by louis-keolio on 08/11/2020.
//

#ifndef PISCINEC_COMPARE_H
#define PISCINEC_COMPARE_H

#include "generate.h"

int compare(struct Tag *, struct DtdTag *);

int compareChilds(struct Tag *tag, struct DtdTag *dtdTag);

int checkTagName(char *, char *, char *);

int checkAttributs(struct Attr**, int size, struct DtdAttr **, int sizeDtdAttr);
int checkAttrName(char *attrName, char *dtdAttrName);

int checkContent(char * content, char * contentType);

#endif //PISCINEC_COMPARE_H

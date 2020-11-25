#include "generate.h"
#include "compare.h"

int main (int argc, char **argv)
{
    //init ids
    ids = malloc(sizeof(Ids));
    ids->size = 0;

    int ligne =0; //voir avec gab
    struct Tag **tab = malloc(sizeof(Tag) * ligne);

    //init parent because only one level read :'(


    //init dtd because no dtd reader :'(
    struct DtdTag **childList = malloc(sizeof(DtdTag) * 3);
    childList[0] = createDtdTag("bonjour", createDtdAttrList("bonjour"), 2, NULL, 0, "#PCDATA", 1);
    childList[1] = createDtdTag("foot", createDtdAttrList("foot"), 1, NULL, 0, "#PCDATA", 1);
    childList[2] = createDtdTag("etrange", createDtdAttrList("etrange"), 1, NULL, 0, "#PCDATA", 1);
    struct DtdTag *dtdParent = createDtdTag("parent", NULL, 0, childList, 3, "#PCDATA", 1);



    return 0;
}
#include "generate.h"
#include "compare.h"

int main (int    argc, char **argv)
{

    //struct Tag *tag = createTag(); sigsev ?
    //struct DtdTag *dtdTag = createDtdTag(); sigsev ?

    struct Tag * tag = createTag("student", createAttrList(2), 2, "blabla", "student");

    printf("%d", checkStartTag(tag, "student", createDtdAttrList(1), 1));

    return 0;
}
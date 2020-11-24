#include "generate.h"
#include "compare.h"

int main (int argc, char **argv)
{
    ids = malloc(sizeof(Ids));
    ids->size = 0;

    addId("test");
    addId("test2");
    addId("haha");

    for (int i = 0; i < ids->size; ++i) {
        printf("%s", ids->ids[i]);
    }
}
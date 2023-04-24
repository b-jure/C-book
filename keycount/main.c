#include <stdio.h>
#include <ctype.h>
#include "keycount.h"
#define LIMIT   1000
#define NKEYS   sizeof(keytab)/sizeof(keytab[0])

static struct key keytab[] = {
    "auto",     0,
    "break",    0,
    "case",     0,
    "char",     0,
    "const",    0,
    "continue", 0,
    "default",  0,
    "do",       0,
    "double",   0,
    "else",     0,
    "enum",     0,
    "extern",   0,
    "float",    0,
    "for",      0,
    "goto",     0,
    "if",       0,
    "int",      0,
    "long",     0,
    "register", 0,
    "return",   0,
    "short",    0,
    "signed",   0,
    "sizeof",   0,
    "static",   0,
    "struct",   0,
    "switch",   0,
    "typedef",  0,
    "unsigned", 0,
    "void",     0,
    "volatile", 0,
    "while",    0
};

int main() {
    char word[LIMIT];
    int idx;

    while (getword(word, LIMIT) != EOF)
        if (isalpha(word[0]))
            if ((idx = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[idx].count++;            

    for (idx = 0; NKEYS > idx; idx++)
        if (keytab[idx].count > 0)
            printf("%d %s\n", keytab[idx].count, keytab[idx].word);

    return 0;
}

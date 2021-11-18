#ifndef _MAIN_H_
#define _MAIN_H_


struct filestrings{
    char line[128];
    struct filestrings *next;
};

struct symbols{
    char simbolo[128];
    int value;
    struct symbols *next;
};

#endif // _MAIN_H_
#ifndef _MAIN_H_
#define _MAIN_H_


struct label{
    char name[128];
    struct label *next;
};

struct lineafile{
    char linea[128];
    struct lineafile *next;
};

#endif // _MAIN_H_
#ifndef UNTITLED13_ARBORE_H
#define UNTITLED13_ARBORE_H


#include "Nod.h"
#include "Nod_AVL.h"

class Arbore {
protected:
    int nr_nod;
public:
    Arbore(int nr_nod =0);
    virtual ~Arbore();

    virtual void insert(int info) = 0;
    virtual void deleten(Nod_AVL *n, int info) = 0;
    virtual void * find(int info) = 0;
};

#endif //UNTITLED13_ARBORE_H

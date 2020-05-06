//
// Created by Mini Wof on 5/6/2020.
//

#ifndef UNTITLED13_ABC_H
#define UNTITLED13_ABC_H

#include <iostream>
#include "Arbore.h"
#include "Nod.h"
#include "Nod_AVL.h"

class ABC : public Arbore{
    Nod_AVL *rad;
public:
    ABC(int nr_nod = 0, Nod_AVL *rad = nullptr);
    ABC(int info);
    virtual ~ABC();
    virtual Nod_AVL * get_rad() const;
    virtual void set_rad(Nod_AVL *rad);
    void insert(int info);
    void deleten(Nod_AVL *n, int info) override;
    void * find(int info);
    virtual ABC& operator>>(Nod_AVL *n);
    virtual int height(Nod_AVL *n);
    Nod_AVL * parent(Nod_AVL *n);
    Nod_AVL * parentHelper(Nod_AVL *curr, Nod_AVL *n);
};


#endif //UNTITLED13_ABC_H

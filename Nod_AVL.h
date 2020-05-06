#ifndef UNTITLED13_NOD_AVL_H
#define UNTITLED13_NOD_AVL_H

#include "Nod.h"

class Nod_AVL :public Nod{
public:
    Nod_AVL(int info = 0, Nod_AVL *left = nullptr, Nod_AVL *right = nullptr, int balance_factor=0);
    virtual ~Nod_AVL();
    int get_balance();
    void set_balance(int n_balance);
    Nod_AVL *get_left();
    void set_left(Nod_AVL *n_left);
    Nod_AVL *get_right();
    void set_right(Nod_AVL *n_right);

    int balance_factor;
};


#endif //UNTITLED13_NOD_AVL_H

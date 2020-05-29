#ifndef FINAL_ARBORE_AVL_H
#define FINAL_ARBORE_AVL_H


#include "Nod_AVL.h"
#include "Arbore.h"
#include "ABC.h"

class Arbore_AVL : public ABC{
    Nod_AVL *root;
public:
    explicit Arbore_AVL(Nod_AVL *root = nullptr);
    ~Arbore_AVL() override;
    void clear();
    int balance(Nod_AVL *n);
    void rebalance(Nod_AVL *n);
    void rotate(Nod_AVL* n);
    Nod_AVL * LLR(Nod_AVL* cur);
    Nod_AVL * LRR(Nod_AVL* cur);
    Nod_AVL * RRR(Nod_AVL* cur);
    Nod_AVL * RLR(Nod_AVL* cur);
    void printInOrder(Nod_AVL* n) const;
    void printPostOrder(Nod_AVL* n) const;
    void printPreOrder(Nod_AVL* n) const;
    void print_balance(Nod_AVL *curr, std::ostream &out) const;
    friend std::ostream &operator<< (std::ostream &out, const Arbore_AVL& arb);
};

#endif //FINAL_ARBORE_AVL_H

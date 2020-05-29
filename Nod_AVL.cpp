#include "Nod_AVL.h"

Nod_AVL::Nod_AVL(int info, Nod_AVL *left, Nod_AVL *right, int balance_factor) {
    this->balance_factor = 0;
    this->info = info;
    this->left = left;
    this->right = right;
}

Nod_AVL::~Nod_AVL() = default;

int Nod_AVL::get_balance() { return balance_factor; }

void Nod_AVL::set_balance(int n_balance) { balance_factor = n_balance; };

Nod_AVL *Nod_AVL::get_left() { return static_cast<Nod_AVL*>(this->left); }

void Nod_AVL::set_left(Nod_AVL *n_left) { left = n_left; }

Nod_AVL *Nod_AVL::get_right() { return static_cast<Nod_AVL*>(this->right); };

void Nod_AVL::set_right(Nod_AVL *n_right) { right = n_right; }

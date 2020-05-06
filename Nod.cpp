#include "Nod.h"

Nod::Nod(int info, Nod *left, Nod *right) {
    this->info = info;
    this->left = left;
    this->right = right;
}

Nod::~Nod() = default;

int Nod::get_info() { return info; }

void Nod::set_info(int n_info) { info = n_info; };

Nod *Nod::get_left() { return left; }

void Nod::set_left(Nod *n_left) { left = n_left; };

Nod *Nod::get_right() { return right; };

void Nod::set_right(Nod *n_right) { right = n_right; }

#include "Arbore_AVL.h"
#include "ABC.h"


Arbore_AVL::Arbore_AVL(Nod_AVL *root) {
    this->root = root;
}

Arbore_AVL::~Arbore_AVL() {
    clear();
}

Nod_AVL * Arbore_AVL::LLR(Nod_AVL *cur) {
    Nod_AVL* newN = cur->get_left();
    cur->set_left(newN->get_right());
    newN->set_right(cur);
    newN->set_balance(height(newN->get_left()) - height(newN->get_right())) ;
    newN->set_balance( height(cur->get_left()) - height(cur->get_right()));
    return newN;
}

Nod_AVL * Arbore_AVL::LRR(Nod_AVL *cur) {
    cur->set_left(RRR(cur->get_left())) ;
    return LLR(cur);
}

Nod_AVL * Arbore_AVL::RRR(Nod_AVL *cur) {
    Nod_AVL* newN = cur->get_right();
    cur->set_right(newN->get_left());
    newN->set_left(cur);
    newN->set_balance(height(newN->get_left()) - height(newN->get_right()));
    cur->set_balance(height(cur->get_left()) - height(cur->get_right())) ;
    return newN;
}

Nod_AVL * Arbore_AVL::RLR(Nod_AVL *cur) {
    cur->set_right(LLR(cur->get_right())) ;
    return RRR(cur);
}

int Arbore_AVL::balance(Nod_AVL *n) {
    if (n == nullptr) return 0;
    int leftheight = height(n->get_left());
    int rightheight = height(n->get_right());
    n ->set_balance(rightheight- leftheight) ;
    return n->get_balance();
}

void Arbore_AVL::rebalance(Nod_AVL *n) {
    while (n != nullptr){
        balance(n);
        if(n->get_balance() >=2 || n->get_balance() <= -2)
            rotate(n);
        n = parent(n);
    }
}

void Arbore_AVL::rotate(Nod_AVL *n) {
    Nod_AVL *child;
    if (n->get_balance() < -1){
        child = n->get_left();
        balance(child);
        if (child->get_balance() == 1)
            LRR(n);
        else
            LLR(n);
    }
    else {
        child = n-> get_right();
        balance(child);
        if (child->get_balance() == -1)
            RLR(n);
        else
            RRR(n);
    }
}

void Arbore_AVL::printInOrder(Nod_AVL *n) const {
    if(n == nullptr) return;
    printInOrder(n->get_left());
    std::cout << n->get_info() << " ";
    printInOrder(n->get_right());
}

void Arbore_AVL::printPostOrder(Nod_AVL *n) const {
    if(n == nullptr) return;
    printPostOrder(n->get_left());
    printPostOrder(n->get_right());
    std::cout << n->get_info() <<" ";
}

void Arbore_AVL::printPreOrder(Nod_AVL *n) const {
    if(n == nullptr) return;
    std::cout << n->get_info() << " ";
    printPreOrder(n->get_left());
    printPreOrder(n->get_right());
}

void Arbore_AVL::clear() {
    while(root != nullptr)
        deleten(root, root->get_info());
}

void Arbore_AVL::print_balance(Nod_AVL *curr, std::ostream &out) const {
    if(curr != nullptr){
        print_balance(curr->get_left(), out);
        out << curr ->get_info() << "balance factor" << curr->get_balance() << std::endl;
        print_balance(curr -> get_right(), out);
    }
}

std::ostream &operator<< (std::ostream &out, const Arbore_AVL& arb){
    arb.print_balance(arb.get_rad(), out);
    return out;
}

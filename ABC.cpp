#include "ABC.h"
#include "Arbore.h"
#include "Nod_AVL.h"
#include <algorithm>
ABC::ABC(int info) : Arbore(info) {
    this->rad = new Nod_AVL(info);
}

ABC::ABC(int nr_nod, Nod_AVL *rad) {
    this->nr_nod = nr_nod;
    this->rad= rad;
}

ABC::~ABC() {
    delete rad;
    rad = nullptr;
}

Nod_AVL * ABC::get_rad() const {
    return this->rad;
}

void ABC::set_rad(Nod_AVL *rad) {
    this->rad = rad;
}

void ABC::insert(int info) {
    if(rad == nullptr){
        rad = new Nod_AVL(info);
        return;
    }
    Nod_AVL *cur = rad;
    Nod_AVL *prev = cur;
    while (cur != nullptr){
        prev = cur;
        if (info < cur->get_info())
            cur = cur->get_left();
        else if (info > cur->get_info())
            cur = cur ->get_right();
        else
            return;
    }
    nr_nod++;
    auto *newNode = new Nod_AVL(info, prev);
    if (info < prev->get_info())
        prev->set_left(newNode);
    else
        prev->set_right(newNode);
}

void ABC::deleten(Nod_AVL *n, int info) {
    if (n == nullptr) return;
    if (rad == nullptr) return;
    this->nr_nod --;
    Nod_AVL *cur = rad;
    Nod_AVL *parent = rad;
    int ok =1;
    while (cur->get_info() != info ){
        parent = cur;
        if(cur ->get_info() > info){
            ok = 1;
            cur = cur->get_left();
        }
        else{
            ok = 0;
            cur = cur->get_right();
        }
    }
    if (cur->get_left() == nullptr && cur->get_right() == nullptr){
        if (cur == rad){
            delete rad;
            rad = nullptr;
        }
        else if (ok == 1){
            delete parent->get_left();
            parent->set_left(nullptr);
        }
        else{
            delete parent->get_right();
            parent->set_right(nullptr);
        }
    }
    else if (cur->get_right() == nullptr){
        if (cur == rad)
            rad = cur->get_left();
        else if (ok == 1)
            parent->set_left(cur->get_left());
        else
            parent->set_right(cur->get_left());

        cur->set_left(nullptr);
        delete cur;
    }
    else if (cur->get_left() == nullptr){
        if (cur == rad)
            rad = cur->get_right();
        else if (ok == 1)
            parent->set_left(cur->get_right());
        else
            parent->set_right(cur->get_right());

        cur->set_right(nullptr);
        delete cur;
    }
    else{
        Nod_AVL *newNode = cur;
        Nod_AVL *newNodeParent = cur;
        Nod_AVL *focusReplace = newNode->get_right();

        while (focusReplace != nullptr){
            newNodeParent = newNode;
            newNode = focusReplace;
            focusReplace = focusReplace->get_left();
        }

        if(newNode != cur->get_right()){
            newNodeParent->set_left(newNode->get_right());
            newNode->set_right(cur->get_right());
        }

        if (cur == rad){
            rad = newNode;
        }
        else if (ok == 1){
            parent->set_left(newNode);
        }
        else{
            parent->set_right(newNode);
        }
        newNode->set_left(cur->get_left());

        cur->set_left(nullptr);
        cur->set_right(nullptr);

        delete cur;
    }
}

void * ABC::find(int info) {
    Nod_AVL *temp = rad;
    while (temp != nullptr){
        if (temp->get_info() == info) return temp;
        if (temp->get_info() < info) temp = temp->get_right();
        else temp = temp->get_left();
    }
    return nullptr;
}

ABC &ABC::operator>>(Nod_AVL *n) {
    insert(n->get_info());
    return *this;
}

int ABC::height(Nod_AVL *n) {
    if (n == nullptr) return 0;
    return 1  + std::max(height(n->get_left()), height(n->get_right()));
}

Nod_AVL * ABC::parent(Nod_AVL *n) {
    return parentHelper(rad, n);
}

Nod_AVL * ABC::parentHelper(Nod_AVL *curr, Nod_AVL *n) {
    if(curr == nullptr) return nullptr;
    else{
        if(curr->get_left() == n || curr->get_right() == n)
            return curr;
        else{
            if (curr->get_info() < n->get_info())
                return parentHelper(curr->get_right(), n);
            else
                return parentHelper(curr->get_left(), n);
        }
    }
}

#include <iostream>
#include "Nod.h"
#include "Nod_AVL.h"
#include "Arbore.h"
#include "ABC.h"
#include "Arbore_AVL.h"


int main() {
    Arbore_AVL arb;
    arb.insert(1);
    arb.insert(7);
    arb.insert(14);
    std::cout << arb;
    return 0;
}

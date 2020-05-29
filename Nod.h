#ifndef FINAL_NOD_H
#define FINAL_NOD_H


class Nod {
protected:
    int info;
    Nod *left;
    Nod *right;
public:
    Nod(int info = 0, Nod *left = nullptr, Nod *right = nullptr);
    virtual ~Nod();
    int get_info();
    void set_info(int n_info);

    virtual Nod *get_left();
    void set_left(Nod *n_left);

    virtual Nod *get_right();
    void set_right(Nod *n_right);
};


#endif //FINAL_NOD_H

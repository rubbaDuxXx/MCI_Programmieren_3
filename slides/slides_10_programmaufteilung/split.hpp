#ifndef SPLIT_H
#define SPLIT_H

extern int globalvar;

int rangesum(int start, int stop);

void print_global_var();

class Basis {
public:
    int a = 23;
    void print();
};

class Inherited : public Basis {
public:
    int b = 42;
    void print();
};

#endif /* SPLIT_H */

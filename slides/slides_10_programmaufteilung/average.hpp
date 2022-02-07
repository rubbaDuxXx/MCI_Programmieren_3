#ifndef AVERAGE_H
#define AVERAGE_H

class Average {
private:
    double sum = 0.0;
    int count = 0;

public:
    void add(double val);
    double get_avg();
};

#endif /* AVERAGE_H */


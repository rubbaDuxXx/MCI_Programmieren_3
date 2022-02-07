#include "average.hpp"

void Average::add(double val) {
    sum += val;
    count++;
}

double Average::get_avg() { return sum / count; }

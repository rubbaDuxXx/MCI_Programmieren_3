#include "prime.hpp"

bool is_prime(int number) {
    for (int i = 2; i < number / 2 + 1; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

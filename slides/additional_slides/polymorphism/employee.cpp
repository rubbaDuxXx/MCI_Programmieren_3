#include <iostream>
using namespace std;

class Employee {
public:
  int salary;
  int raise(int amount) {
    salary = salary + amount;
    if (salary > 3200)
      salary = 3200;
  }
}

int main()
{
}

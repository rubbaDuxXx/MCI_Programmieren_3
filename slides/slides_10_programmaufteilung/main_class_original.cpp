#include <iostream>
using namespace std;

class Average {
private:
    double sum = 0.0;
    int count = 0;

public:
    void add(double val) {
        sum += val;
        count++;
    }

    double get_avg() { return sum / count; }
};

int main() {
  Average avg;
  avg.add(12.3);
  avg.add(11.7);
  avg.add(13.7);
  cout << avg.get_avg() << endl;
}

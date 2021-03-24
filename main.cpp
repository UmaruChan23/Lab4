#include <iostream>
#include "Complex.h"
#include "ComplexArithmetic.h"

using namespace std;

int main() {
    Complex num;
    cin >> num;
    const Complex res = y(num);
    cout << res << endl;
    return 0;
}
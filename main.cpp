#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex num;
    cin >> num;
    const Complex res = Complex::y(num);
    cout << res << endl;
    return 0;
}
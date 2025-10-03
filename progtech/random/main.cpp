#include <iostream>
#include <cmath>

using namespace std;

float h (float n) {
    float y = pow(3, -abs(n));
    return y;
}

int main() {
    float x[10];
    float n, y;

    for (n = 0; n < 5; n++) {
        y = h(n+2) + 11*h(n+1) + 11*h(n) +11*h(n-1) + 11*h(n-2) + 10*h(n-3);
        cout << y << endl;
    }


}

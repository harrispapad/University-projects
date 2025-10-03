#include "iostream"
 using namespace std;

int f(int x){
    if(x > 10) return x;
    if(x < 5) throw 7;
    return 3*(x-1);
}

int main() {
    try { cout << f(8); cout << f(1); cout << f(12);}
    catch (bool b) { cout << 17; }
    catch (int n) { cout << n*n+1; }
    try { cout << f(4); }
    catch (int n) { cout << n*n+1; }
    cout << endl;
}

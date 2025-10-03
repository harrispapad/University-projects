#include <iostream>
using namespace std;

int power(int a, int b){
    if (b == 0)
        return 1;
    else if (b == 1)
        return a * a;
    else
        return power(a, b-1);
}

int fact(int a){
    if (a == 0)
        return 1;
    else
        return a * fact(a-1);
}

int main(){

    cout<<power(10, 2)<<endl<<fact(5)<<endl;
}

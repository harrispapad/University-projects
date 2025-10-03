#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int a[100000], N, length, i;

    length = 0;
    i = 0;

    cin>>N;

    while (N>0) {
        a[i] = N%10;
        i++;
        length++;
    }
    cout<<a[length-3];
    return 0;
}

#include <iostream>
using namespace std;

int main(){
    int n, k, *p, counter = 0, distance = 0, max = 0;
    cin>>n>>k;
    p = new int[n];
    for (int i=0; i<n; i++)
        cin>>p[i];

    for (int j=0; j<n; j++){
        counter = 0;
        for (int x=0; x<n; x++){
            distance = j - p[x];
            if (abs(distance) <= k) counter++;
        }
        if (counter > max) max = counter;
    }

    cout<<max<<endl;

    delete []p;
}

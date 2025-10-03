#include <iostream>
using namespace std;

int main(){
    int n, *a, velocity = 0, i, k, l=0, max=0;
    cin>>n;
    a = new int[n];
    for(i=0; i<n; i++)
        cin>>a[i];

    for(l=0; l<n; l++){
        velocity = 0;
        for (k=l; k<n; k++){
            velocity += a[k];
            if (velocity < 0) break;
        }
        if (velocity > max) max = velocity;
    }

    cout<<max<<endl;

    delete []a;
}

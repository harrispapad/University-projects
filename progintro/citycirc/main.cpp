#include <iostream>
using namespace std;

int main (){
    int n, *p, counter = 0, flag = 1, loops = 0, size;
    cin>>n;
    p = new int[n];
    size = n;

    for (int i=0; i<n; i++)
        cin>>p[i];

    do {
        counter = 0;
        flag = 1;
        for (int k = loops; k<n; k++){
            counter += p[k];
            if (counter < 0){
                flag = 0;
                break;
            }
        }
        n++;
        p[n-1] = p[loops];
        loops++;
    }   while (!flag && loops<size);

    if (flag) cout<<loops<<endl;
    else cout<<0<<endl;

    delete []p;
}

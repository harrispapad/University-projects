#include <iostream>

using namespace std;

int main()
{
int n, k, *a, sum=0, max1=0, max2=0, spot=0, spot2;
cin>>n>>k;
a = new int[n];
for (int i=0; i<n; i++)
    cin>>a[i];

for (int j=0; j<n-k+1; j++){
    sum = 0;
    for (int l=j; l<(j+k); l++)
        sum += a[l];
    if (sum >= max1){
        max1 = sum;
        spot = j;
    }
}

for (int q=0; q<n-k+1; q++){
    sum = 0;
    for (int l=q; l<(q+k); l++)
        sum += a[l];
    if (sum >= max2 && q!= spot){
        max2 = sum; spot2=q;}
}

cout<<max1+max2<<endl;

delete []a;

return 0;
}

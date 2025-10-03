#include <iostream>
#include <iomanip>
using namespace std;

int fact(int x){
int fact=1;
for (int i=1; i<=x; i++)
    fact *= i;
return fact;
}

int main(){
long double e=0.0;
int n;
cin>>n;

for (int i=0; i<n; i++){
    e=0.0;
    for (int j=0; j<i+1; j++)
        e += 1.0/fact(j);
    cout<<fixed<<setprecision(20)<<e<<endl;
}
}

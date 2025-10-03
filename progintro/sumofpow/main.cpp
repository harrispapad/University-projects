#include "iostream"
#include "math.h"
using namespace std;

bool sumofpow (int a){
  int flag=0;
  for (int i=0; i<100; i++){
    for (int j=0; j<100; j++) {
      for (int k=0; k<100; k++) {
        if (a == pow(2, i) + pow(3, j) + pow (5, k)) {flag=1; break;}
      }
    }
  }
if (flag)
  return true;
else
  return false;
}

int main() {
  int n, counter=0;
  cin>>n;
  for (int i=0; i<n; i++){
    if (sumofpow(i)) counter++;
  }

  cout<<counter<<endl;

  return 0;
}

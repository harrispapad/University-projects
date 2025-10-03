#include <iostream>
using namespace std;

//αλγόριθμος για ταξινόμηση Ο(2logn)
void merge (int a[], int first, int mid, int last){
 int b[last-first+1];

 int i = first, j = mid+1, k=0;
 while (i <= mid && j <= last) if (a[i] < a[j])  b[k++] = a[i++];
                               else              b[k++] = a[j++];

 while (i <= mid)  b[k++] = a[i++];
 while (j <= last) b[k++] = a[j++];

 for (i=0; i<k; i++) a[first+i] = b[i];
}



void mergesort (int a[], int first, int last) {
 int mid;

 if (first >= last) return;

 mid = (first + last) / 2;
 mergesort (a, first, mid); mergesort(a, mid+1, last);
 merge(a , first, mid, last);
}



int min (int x, int y){
  if (x < y)
    return x;
  else
    return y;
}



int max (int x, int y){
  if (x > y)
    return x;
  else
    return y;
}



int main(){
 int a[100000], b[100000], n, counta=0, countb=0, x, y;

 cin>>n;

 for (int i=0; i<n; i++) {
   cin>>a[i]; counta += a[i];
 }
 mergesort (a, 0, n-1);

 for (int j=0; j<n; j++) {
   cin>>b[j]; countb += b[j];
 }
 mergesort (b, 0, n-1);

 for (int q=0; q<n; q++)
   if (a[q] != b[q]) {x=min(a[q], b[q]); break;}

 for (int w=(n-1); w>0; w--)
   if (a[w] != b[w]) {y=max(a[w], b[w]); break;}

 if (counta == countb) cout<<"yes"<<endl;
 else cout<<"no "<<x<<" "<<y<<endl;


return 0;
}

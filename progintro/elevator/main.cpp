#include <iostream>
using namespace std;

void merge (int a[], int first, int mid, int last){
    int b[last -  first + 1];

    int i = first, j = mid+1, k = 0;
    while (i <= mid && j <= last) if (a[i] < a[j]) b[k++] = a[i++];
                                  else             b[k++] = a[j++];

    while(i <= mid) b[k++] = a[i++];
    while(j <= last) b[k++] = a[j++];

    for(i=0; i<k; i++)  a[first+i] = b[i];
}

void mergesort (int a[], int first, int last){
    int mid;

    if (first >= last) return;

    mid = (first + last) / 2;
    mergesort(a, first, mid);
    mergesort(a, mid+1, last);
    merge(a, first, mid, last);
}

int main(){
    int n, B, *p, min, max, l = 0, counter = 0, k;
    cin>>n>>B;
    k = n - 1;
    p = new int[n];
    for (int i=0; i<n; i++)
        cin>>p[i];
    mergesort(p, 0, n-1);

    while(l < k){
        min = p[l];
        max = p[k];
        if((min + max) < B){
            counter++;
            l++;
            k--;
        }
        else{
            counter++;
            k--;
        }
    }

    cout<<counter<<endl;

    delete []p;
}

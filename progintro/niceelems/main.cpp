#include <iostream>
using namespace std;

int main(){
    int N, M, a[200][200], row = 0, result = 0, i, j, palin = 0;
    cin>>N>>M;

    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
        cin>>a[i][j];
        }
    }

    for(int d=0; d<N; d++){
        palin = 1;
        for(int k=0; k<(M/2 +1); k++)
            if (a[d][k] != a[d][M - k - 1]) {
                palin = 0;
                break;
            }
        if(palin){
            result += M;
            row++;
        }
    }

    for(int x=0; x<M; x++){
        palin = 1;
        for(int y=0; y<(N/2 +1); y++)
            if(a[y][x] != a[N-y-1][x]){
                palin = 0;
                break;
            }
        if(palin)
            result += (N - row);
        }

    cout<<result<<endl;
}


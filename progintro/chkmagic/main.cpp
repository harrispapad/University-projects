#include "iostream"
using namespace std;

int main(){
    int flag=1, i, j, k=0, N, a[150][150], row[150], col[150], diag1=0, diag2=0;
    cin>>N;	//διαστάσεις πίνακα
    for (i=0; i<N; i++){	//διάβασμα πίνακα
        for (j=0; j<N; j++){
            cin>>a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }

    for (i=0; i<N; i++){ 	//διαγώνιοι
        diag1 += a[i][i];
    }

    for (i=0; i<N; i++){
        diag2 += a[i][N-i-1];
    }

    do { 	//έλεγχος για παραλήψεις και επαναλήψεις αριθμών
        flag = 0;
        for (i=0; i<N; i++){
            for (j=0; j<N; j++){
                if (a[i][j] == k) flag = 1;
            }
        }
        k++;
    } while (flag == 1 && k<N*N);

    i = 0;	//έλεγχος για άθροισμα γραμμών, στηλών, διαγωνίων
    while (flag == 1 && i<(N-1)){
        if (row[i] != row[i+1] || col[i] != col[i+1] || diag1 != diag2) flag = 0;
        else i++;
    }

    if (flag == 1)  cout<<"yes"<<endl;
    else cout<<"no"<<endl;

}
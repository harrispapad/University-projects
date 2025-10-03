//missing lines
#include <iostream>
using namespace std;

int main(){
    char text[100][100];
    int c, i, k, j=0, x=0, y=0, d, l, space[60];
    bool twospaces = false;

    c = getchar();
    while (c != EOF) {
        if (!twospaces) x=0;
        for (i=y; i<=60; i++) {
            if (c == '\n') c = 32;
            if (i==0 && c==32) {
                c = getchar();
                y = 0;
                j--;
                break;
            }
        }
        text[j][i] = c;
        c = getchar();
        if (c == EOF) break;
        if (i == 60) {
            y = 0;
            if (text[j][60] != 32) {
                for (k = space[x - 1] + 1; k <= 60; k++)
                    text[j + 1][y++] = text[j][k];
                while (text[j][60] != 32) {
                    for (int z =x-2; z>=0; z--) {
                        for (int a=60-space[z]; a>0; a--)
                            text[j][space[z]+a] = text[j][space[z]+a-1];
                        for (int b=x-1; b>z; b--)
                            space[b] += 1;
                        if (text[j][60] == 32) break;
                    }
                }
            }
        }

        if (!twospaces) {
            for (k=0; k<x; k++) {
                space[k] = 0;
            }
        }
        j++;
    }

    for (l=0; l<j-1; l++) {
        for (k=0; k<60; k++)
            cout<<text[l][k];
        cout<<endl;
    }
    for (d=0; d<i; d++)
        cout<<text[j-1][d];
    cout<<endl;


    return 0;
}

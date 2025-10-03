#include <iostream>
using namespace std;

char tolower (char ch){
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    else
        return ch;
}

char tocapital (char ch) {
    return ch - 'a' + 'A';
}

int main(){
    int ch, flag=0;
    char en[27];
    for (int j=0; j<26; j++){
        cin>>en[j];
    }

    for (int k=0; k<26; k++) {
        for (int i=(k+1); i<26; i++){
            if (en[k] == en [i] || en[k] < 'a' || en[k] > 'z') flag = 1;
        }
        if (flag) {cout<<"error"<<endl; break;}
    }

    if (!flag) {
        ch = getchar();
        while (ch != EOF) {
            ch = getchar();
            if (ch >= 'A' && ch <= 'Z') cout<<tocapital(en[tolower(ch) - 'a']);
            else if (ch >= 'a' && ch <= 'z') cout<<en[tolower(ch) - 'a'];
            else if (ch == EOF) cout<<"";
            else cout<<(char)ch;
        }
    }

    return 0;
}

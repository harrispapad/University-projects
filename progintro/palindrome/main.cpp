#include <iostream>
#include <string.h>
#include <cstring>
#include <limits>
using namespace std;

int main(){
    string str;  //δήλωση basic string
    int i, length, N, count;
    count = 0;
    cin>>N;    //αριθμός επαναλήψεων
    cin.ignore (std::numeric_limits<streamsize>::max(), '\n');   //προσπέραση του enter ως χαρακτήρα


    for (int j=0; j<N; j++){
        int flag = 0;
        getline (cin,str);    //διάβασμα basic string από τον χρήστη
        char* c = const_cast<char*>(str.c_str());   //μετατροπή basic string σε constant char με μεταβλητή c
        length = strlen(c);     //μήκος constant char
        if (str.empty()) cout<<"empty"<<endl;      //έλεγχος για empty string
        else {if (length>20) cout<<"error"<<endl;      //έλεγχος για υπέρβαση 20 χαρακτήρων
              else{
                for(i=0; i<length; i++){    	//έλεγχος παλίνδρομου
                    if (c[i] != c[length-i-1]){
                        flag = 1;
                        break;
                    }
                }

                if (flag) {
                    cout<<"no"<<endl;
                }

                else {
                    count++;
                    cout<<"yes"<<endl;
                }
            }
        }
    }

    printf("%0.3lf", 100.0*count/N);	//ποσοστό παλίνδρομων με 3 δεκαδικά
    return 0;
}

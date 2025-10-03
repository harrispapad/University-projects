#include <iostream>
using namespace std;

int gcd (int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a > 0 && b > 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    return a + b;
}

int main(){
    int num1, num2, num3, den1, den2, den3, n, a;
    char operation;
    cin>>n;
    cin.ignore();
    for (int i=1; i<=n; i++){
        operation = getchar();
        cin>>num1>>den1>>num2>>den2;

        if ((den1 == 0 || den2 == 0) || num2 == 0 && operation == '/'))
        cout<<"error"<<endl;
        else{
            switch(operation){
                case '+': num3 = num1*den2 + num2*den1, den3 = den1*den2; break;
                case '-': num3 = num1 *den2 - num2*den1, den3 = den1*den2; break;
                case '*': num3 = num1*num2, den3 = den1*den2; break;
                case '/': num3 = num1*den2, den3 = num2*den1; break;
            }

        a = gcd(num3, den3);
        num3 = num3 / a;
        den3 = den3 / a;
        if (((den3 > 0 && num3 < 0) ||
              (den3 < 0 && num3 > 0)) &&
                (num3 / den3) == 0)
            cout << "-0". abs(num3%den3), abs(den3));
        else
            cout<<num3/den3<<" "<<abs(num3%den3)<<" "<<abs(den3));

        }

        cout<<endl;
    }
}

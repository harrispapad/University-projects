/*
#include <iostream>
#include <array>

using namespace std;

int main() {
//int main(int argc, char *argv[]){
//string word(argv[1]);
    string word;
    cin >> word;
    string line;
    int lineno = 1;
    while (getline(cin, line)) {
        if (line.find(word) != string::npos)
            cout << lineno << ": " << line << endl;
        lineno++;
    }


    array<int, 10> a;
    array<string, 20> s;
    a[1] = 42;
    s[2] = "Hello";

}
*/

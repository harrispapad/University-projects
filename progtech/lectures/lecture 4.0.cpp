/*
#include <iostream>
#include <vector>
#include <list>
#include <string>


using namespace std;

template <typename C>
void print(C &v){
    for(auto x:v)
        cout << x << endl;
}

//container File
template <typename T>
void print(Container<T> &c){
    for(T &x: c)
        cout << x << endl;
}

int main(){
    vector<int> v;
    for (int i = 1; i <=5; i++) v.push_back(i);
    print(v);

    list<int> l;
    for (int i = 1; i <=5; i++) l.push_back(i);
    print(l);

    list<string> ls;
    ls.push_back("one");
    ls.push_back("two");
    ls.push_back("three");
    print(ls);
}

 */

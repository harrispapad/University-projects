/*
#include <iostream>
#include <list>

using namespace std;

//int main(){
    list<int> l;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) l.push_front(i);
        else l.push_back(i);
    }
    for (int i =0; !l.empty(); i++){
        if ( i % 2 == 0) {
            cout << l.back() << endl;
            l.pop_back();
        } else {
            cout << l.front() << endl;
            l.pop_front();
        }
        }

    //iterators!
    list<int> l;
    for (int i = 1; i <= 5; i++)
        l.push_back(i);

    list<int>::iterator i;
    for (i = l.begin(); i != l.end(); i++)
        cout << *i << endl;

}

     */

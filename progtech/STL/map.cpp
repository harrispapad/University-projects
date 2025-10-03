#include <iostream>
#include <map>

using namespace std;

int fib(int n) {
    return n < 2 ? n : fib(n-1) + fib(n-2);
}

int memo_fib(int n) {
    static map<int, int> cache;
    if(n<2) return n;

    map<int, int>::iterator p = cache.find(n);
    if (p != cache.end()) return p->second;

    int v = memo_fib(n-1) + memo_fib(n-2);
    cache[n] = v;
    return v;
}

int main(){
    map<int, string> m;

    /*m.insert(make_pair(1, "one"));
    m.insert(make_pair(2, "two"));
    m.insert(make_pair(3, "three"));
    */

    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    int x;
    cin >> x;

    //(m[x]) cout << m[x] << endl; creates default string if not found

    map<int, string>::iterator p;
    p = m.find(x);

    if (p != m.end())
        cout << p->second << endl;
    else {
        cout << "Not found!" << endl;
        exit(1);
    }
}

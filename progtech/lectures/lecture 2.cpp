/*
#include <iostream>
#include <list>
#include <string>
using namespace std;

template <typename T>
void bubble_sort(int n, T a[]) {
    for (int i=0; i < n-1; i++)
        for (int j=n-2; j>=1; --j)
            if (a[j] > a[j+1]) {
                T t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

template <typename T>
class secret {
            private:
                string password;
                T data;
            public:
                secret(const string &pwd, const T &d):
                    password(pwd), data(d){}
                T get(const string &pwd);
            };

template <typename T>
T secret<T>::get(const string &pwd) {
    if (pwd == password) return data;
    cout << "Wrong password!" << endl;
    exit(0);
}

class Person {
    public:
        Person(const string &name): myName(name) {}
        string getName() const {
            return myName;
    }
    private:
        string myName;
    };

class Origin {
public:
        explicit Origin(const string &origin);
        string getOrigin() const {
            return myCountry;
        }
private:
    string myCountry;
};

Origin::Origin(const string &origin) : myCountry(origin){}

class Citizen:  public Person,
                public Origin {
public:
    Citizen(const string &name, const string &country)
        : Person(name), Origin(country){}
};

/*class Parent: public Person {
public:
    Parent(const string &name)
        : Person(name), children() {}
    void addChild(const Person &p) {
        children.append(p);
    }
    int countChildren() const {
        return children.size();
    }
private:
    list<Person> children;
};


int main() {
    int a[8] = {42, 17, 4, 3, 8, 2, 1, 9};
    int na = sizeof(a) / sizeof(a[0]);
    bubble_sort(na, a);

    string b[] = {"ba", "abc", "aa", "bab"};
    int nb = sizeof(b) / sizeof(b[0]);
    bubble_sort(nb, b);

    secret<int> y("sagapo", 1971);
    secret<string> n("de sagapo", "rakitzis");
    cout << "Give the password: ";
    string p;
    cin >> p;
    cout << y.get(p) << endl;
    cout << n.get(p) << endl;
    Person  d1("Joe Dalton"),
            d2("William Dalton"),
            d3("Jack Dalton"),
            d4("Averel Dalton");
    Parent m("Ma Dalton");
    m.addChild(d1);
    m.addChild(d2);
    m.addChild(d3);
    m.addChild(d4);
    cout << d1.getName() << "is the son of" << m.getName() << " who has " << m.countChildren() << " children." << endl;

    Citizen c ("Charles Foster Kane", "USA");
    cout << c.getName() << " comes from " << c.getOrigin() <<endl;


};

*/

/*
class complex {
public:
    complex(double r = 0.0, double i = 0.0);
    ~complex();
    friend complex operator+(complex c1, complex c2);
    friend ostream& operator<<(ostream &out, complex c);

private:
    double re, im;
};

complex::complex(double r, double i){
    re = r;
    im = i;
}

complex::~complex() {};

complex operator+(complex c1, complex c2){
    return complex(c1.re + c2.re, c1.im + c2.im);
}

ostream& operator<<(ostream &out, complex c){
    if (c.im > 0)
        out << c.re << "+" << c.im << "i";
    else
        out << c.re << c.im << "i";
    return out;
}

class Person {
public:
    Person(double w);
    ~Person();
    double getWeight();
    static double getTotalWeight();
private:
    double weight;
    static double totalWeight;
};

Person::Person(double w) {
    weight = w;
    totalWeight += weight;
}

Person::~Person(){
    totalWeight -= weight;
};

double Person::totalWeight = 0.0;

double Person::getWeight() {
    return weight;
}

double Person::getTotalWeight() {
    return totalWeight;
}



int main(){
    //complex class
    double r1, i1, r2, i2;
    cin >> r1 >> i1 >> r2 >> i2;
    complex c1(r1, i1), c2(r2, i2);
    complex c = c1 + c2;
    cout << c << endl;

    Person class
    Person x(65), y(100);
    cout<< x.getWeight() << endl << x.getTotalWeight() << endl;
    Person *z = new Person(85);
    cout << Person::getTotalWeight() << endl;
    delete z;
    cout << y.getTotalWeight() << endl;
}

*/

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int num=0;
    for (int i=0; i<10; i++){
        num = srand(time(NULL));
        cout<<num;
    }
}

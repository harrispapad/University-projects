#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    FILE *f;

    f = fopen("C:\Users\harri\Documents\test.txt", "r");

    fclose(f);
}

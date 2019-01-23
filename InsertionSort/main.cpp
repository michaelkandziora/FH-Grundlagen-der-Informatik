#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fill_array(long int *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        a[i] = (rand()<<15)+rand();
    }
}

void insertion_sort(long int *a, int n)
{
    int i, j, help;
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(a[j] < a[i])
            {
                help = a[i];
                a[i] = a[j];
                a[j] = help;
            }
        }
    }
}

void print_array(long int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

int main()
{
    int num = 40000;
    long int* feld;
    feld = new long int[num];



    fill_array(feld, num);

    system_clock::time_point start = system_clock::now();
    insertion_sort(feld, num);
    system_clock::time_point ende = system_clock::now();


    print_array(feld, num);

    cout << (ende - start).count() << "µs" << endl;
    cout << feld[num-1];


    delete feld;
    return 0;
}

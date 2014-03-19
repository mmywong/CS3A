#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define max  1000
#define range 6

int randomnums(int A[]);
void freq(int A[], int freqlist[]);
void init(int freqlist[]);
void display(int freqlist[]);

int main()
{
    int A[max];
    int freqlist[range+1];

    srand(time(NULL));
    init(freqlist);
    randomnums(A);


    freq(A,freqlist);
    return 0;
}

void freq(int A[], int freqlist[])
{
    int j=0;
    for (int i=0; i<max; i++)
    {
            j= A[i];
            freqlist[j]++;
    }
    display(freqlist);
}

int randomnums(int A[])
{
    for (int i=0; i<max; i++)
    {
        A[i] = (rand()%range)+1; //rand()%range gives a random number from 0 to range. this sentence instead gives random number from 1 to range.
    }
}

void display(int freqlist[])
{
    for(int i=1; i<=range; i++)
        cout<<i<<":"<<freqlist[i]<<endl;
}

void init(int freqlist[])
{
    for(int i=0; i<=range; i++)
        freqlist[i]=0;
}

#include <iostream>

using namespace std;

char add(char n1[], char n2[], char r[]);
int strLen(char sub[]);
void reverse(char a[]);

int main()
{
    char n1[]="000015";
    char n2[]="000178";
    char r[]="000000";

    cout<<n1<<"+"<<n2<<"="<<endl;
    add(n1, n2, r);

    cout<<r<<endl;
    return 0;
}

char add(char n1[], char n2[], char r[])
{
    int i=0;
    int carry = 0;
    reverse(n1);
    reverse(n2);

    while((n1[i] != '\0') && (n2[i] != '\0'))
    {
          int temp = carry;
          temp += n1[i] - 48 + n2[i] - 48;
          r[i] = (temp%10)+48;
          carry = temp/10;
          i++;
    }
    r[i]= carry+48;
    r[i+1]='\0';
    reverse(r);
}

void reverse(char a[])
{
    int temp=0;

    for(int i=0; i<(strLen(a)/2); i++)
    {
        temp = a[i];
        a[i]=a[strLen(a)-1-i];
        a[strLen(a)-1-i]=temp;
    }
}

int strLen(char sub[])
{
    int i=0;
    while(sub[i] != '\0')
    {
        i++;
    }
    return i;
}

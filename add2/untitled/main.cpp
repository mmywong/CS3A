#include <iostream>

#define MaxSize 6

using namespace std;

void AddChar(char num1[], char num2[], char result[], int base);

void ShowOutput(char result[]);

void CharToInt(char num[], int IntNum[]);

void Reverse(char array[]);

void StrCpy(char MyString[], char CopyThis[]);

int StrLen(char array[]);

void InitializeInt(int array[]);

void initialize(char array[]);

void GetInput(char ItemOrder[], char array[]);

int main()
{
    //int num1[MaxSize * 5], num2[MaxSize * 5], sum[MaxSize * 5];
    int num1[MaxSize], num2[MaxSize];
    char outcome[MaxSize], ans;

    char n1[] = "321";
    char n2[] = "123";

    do
    {
//        initialize(n1);
//        GetInput("FIRST", n1);

//        initialize(n2);
//        GetInput("SECOND", n2);
        cout << endl << "n1: " << n1 << endl;
        cout << endl << "n2: " << n2 << endl;
        Reverse(n1);
        Reverse(n2);
        cout << endl << "n1: " << n1 << endl;
        cout << endl << "n2: " << n2 << endl;

        AddChar(n1, n2, outcome, 10);

        cout << "\nPerform another addition?  (Y)es or (N)o:\n\n";
        cin >> ans;
        cout << endl << endl;
    } while(ans == 'y' || ans == 'Y');
    return 0;
}

void AddChar(char num1[], char num2[], char result[], int base)
{
    int IntNum1[MaxSize], IntNum2[MaxSize], IntResult[MaxSize], carry = 0;

    InitializeInt(IntNum1);
    InitializeInt(IntNum2);

    CharToInt(num1, IntNum1);
    CharToInt(num2, IntNum2);

//    for(int i=0;i<StrLen(num1);i++)
//    cout<<"\natoi num1: "<<IntNum1[i];




//    for(int i=0;i<StrLen(num2);i++)
//    cout<<"\natoi num2: "<<IntNum2[i];

    int i;
    for(i = 0; i < MaxSize; i++)
    {
        IntResult[i] = IntNum1[i] + IntNum2[i] + carry;
        carry = IntResult[i] / base;
        IntResult[i] = IntResult[i] % base;

        result[i] = IntResult[i] + '0';
    }
    result[i] = '\0';

    Reverse(result);

    cout<<"\nresult: "<<result;
}

void ShowOutput(char result[])
{
//    int ReverseOrder = MaxSize * 5 - 1;
//    while(array[ReverseOrder] == 0)
//        ReverseOrder--;

//    cout << "\nThe result of the addition is:\n\n";
//    for(int i = ReverseOrder; i >= 0; i--)
//        cout << array[i];

//    if(ReverseOrder > (MaxSize - 1)) // Global MAX size is 20.
//        cout << "\n\nInteger Overflow!" << endl << endl;

    cout << endl << endl;
}

void CharToInt(char num[], int IntNum[])
{
    for(int i = 0; i < StrLen(num); i++)
    {
        IntNum[i] = num[i] - '0';
    }
}

void Reverse(char array[])
{
    cout<<"strlen: "<<StrLen(array) << endl;
    int i, j = 0;
    char TempArray[MaxSize];

    for(i = StrLen(array) - 1; i >= 0; i--)
    {
        TempArray[j] = array[i];
        j++;
    }
    TempArray[j] = '\0';

    StrCpy(array, TempArray);
}

//void AddInt(int num1[], int num2[], int result[], int base)
//{
//    int carry = 0;
//    for(int i = 0; i < MaxSize; i++)
//    {
//        result[i] = num1[i] + num2[i] + carry;
//        carry = result[i] / base;
//        result[i] %= base;
//    }
//}

void StrCpy(char MyString[], char CopyThis[])
{
    int i = 0;

    while(CopyThis[i] != '\0')
    {
        MyString[i] = CopyThis[i];
        i++;
    }
    MyString[i] = '\0';
}

int StrLen(char array[])
{
    int i = 0;

    while(array[i] != '\0')
    {
        i++;
    }
    return i;
}

void InitializeInt(int array[]) //Initializes the array to zeros.
{
    for(int i = 0; i < MaxSize; i++)
    {
        array[i] = 0;
    }
}

void initialize(char array[]) //Initializes the array to zeros.
{
    int i;

    for(i = 0; i < MaxSize; i++)
    {
        array[i] = '0';
    }
    array[i] = '\0';
}

void GetInput(char ItemOrder[], char array[])//string ItemOrder is alternative to char ItemOrder[].
{
    cout << "\n\nEnter the " << ItemOrder << " NUMBER (up to " << MaxSize - 1 << " digits):\n\n";
    cin >> array;
}

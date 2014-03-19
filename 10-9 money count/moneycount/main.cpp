#include <iostream>
#include "counter.h"

using namespace std;

int main()
{
    int amount, limit;
    char asdf;
    char repeat = 'Y';

    cout << "/---initial set-up---/" << endl;
    cout << "limit : ";
    cin >> limit;
    counter mom(limit); // constructs the counter and sets limit
    cout << endl << endl;

    while (repeat == 'y' || repeat == 'Y')
    {
        cout << "/---counter---/" << endl;
        cout << "a : ten dollars" << endl;
        cout << "s : dollars" << endl;
        cout << "d : dimes" << endl;
        cout << "f : cents" << endl;
        cout << "o : overflow" << endl;
        cout << "r : reset" << endl;
        cout << "input which key to press followed by the value to increment" << endl;

        cin >> asdf;
        switch (asdf)
        {
            case 'a':
                cin >> amount;
                cout << endl;
                mom.incr1000(amount); //increment by that amount
                mom.setall(); // organize to 0-9
                if(mom.overflow() == true){
                    cout<<"overflow"<<endl;
                }
                else
                {
                cout << "~~mom's counter~~" << "        overflow:" << mom.overflow() <<endl;
                cout << "$  " << mom.getTendollars() << "  "
                     << mom.getDollars() << "  "
                     << mom.getDimes() << "  "
                     << mom.getCents() << endl << endl;
                }
                break;
        case 's':
            cin >> amount;
            cout << endl;
            mom.incr100(amount); //increment by that amount
            mom.setall(); // organize to 0-9
            if(mom.overflow() == true){
                cout<<"overflow"<<endl;
            }
            else
            {
            cout << "~~mom's counter~~" << "        overflow:" << mom.overflow() << endl;
            cout << "$  " << mom.getTendollars() << "  "
                 << mom.getDollars() << "  "
                 << mom.getDimes() << "  "
                 << mom.getCents() << endl << endl;
            }
            break;
        case 'd':
            cin >> amount;
            cout << endl;
            mom.incr10(amount); //increment by that amount
            mom.setall(); // organize to 0-9
            if(mom.overflow() == true){
                cout<<"overflow"<<endl;
            }
            else
            {
            cout << "~~mom's counter~~" << "        overflow:" << mom.overflow() << endl;
            cout << "$  " << mom.getTendollars() << "  "
                 << mom.getDollars() << "  "
                 << mom.getDimes() << "  "
                 << mom.getCents() << endl << endl;
            }
            break;
        case 'f':
            cin >> amount;
            cout << endl;
            mom.incr1(amount); //increment by that amount
            mom.setall(); // organize to 0-9
            if(mom.overflow() == true){
                cout<<"overflow"<<endl;
            }
            else
            {
            cout << "~~mom's counter~~" << "        overflow:" << mom.overflow() << endl;
            cout << "$  " << mom.getTendollars() << "  "
                 << mom.getDollars() << "  "
                 << mom.getDimes() << "  "
                 << mom.getCents() << endl << endl;
            }
            break;
        case 'o':
            cout << endl;
            if(mom.overflow() == true)
                cout<<"overflow"<<endl;
            else
                cout<<"no overflow"<<endl;
            break;
        case 'r':
            cout << endl;
            mom.reset();
            cout << "$  " << mom.getTendollars() << "  "
                 << mom.getDollars() << "  "
                 << mom.getDimes() << "  "
                 << mom.getCents() << endl << endl;
        }
        cout << "repeat? Y:yes" << endl;
        cin >> repeat;
        cout << endl << endl;
    }


    return 0;
}


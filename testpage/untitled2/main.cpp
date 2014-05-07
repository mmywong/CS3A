#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void initialize(string suit[], string faceValue[]);
void shuffle(bool deck[]);
void deal( bool deck[], vector<int> &hand);
void display(string suit[], string faceValue[],vector<int> &hand);

int main(int argc, char *argv[])
{
    int x;
    x = 5;

    string name;
    name = "michelle";

    QCoreApplication a(argc, argv);
    srand(time(NULL));
    string suit[4], faceValue[13];
    bool deck[52];
    vector<int> hand;
    initialize(suit, faceValue);
    for(int i = 0; i < 5; i++)
    {
        if(i%2 == 0)
                shuffle(deck);
        deal(deck, hand);
        display(suit, faceValue,hand);
    }
    return a.exec();
}

void display(string suit[], string faceValue[],vector<int> &hand)
{
    cout<<endl<<"Your hand:"<<endl;
    for(int i = 0; i < 5; i++)
        cout<<faceValue[hand[i]%13]<<" of "<<suit[hand[i]/13]<<endl;
    hand.clear();
}


void shuffle(bool deck[])
{
    cout<<endl<<endl<<"Shuffling....."<<endl<<endl;
    for(int i = 0; i < 52; i++)
        deck[i] = true;
}

void deal( bool deck[], vector<int> &hand)
{
    for(int i = 0; i < 5; i++)
    {
        int card;
        while(!deck[card = rand()%52]);
        deck[card] = false;
        hand.push_back(card);
    }
}

void initialize(string suit[], string faceValue[])
{
    suit[0] = "Hearts";
    suit[1] = "Clubs";
    suit[2] = "Diamonds";
    suit[3] = "Spades";
    faceValue[0] = "Ace";
    faceValue[1] = "Two";
    faceValue[2] = "Three";
    faceValue[3] = "Four";
    faceValue[4] = "Five";
    faceValue[5] = "Six";
    faceValue[6] = "Seven";
    faceValue[7] = "Eight";
    faceValue[8] = "Nine";
    faceValue[9] = "Ten";
    faceValue[10] = "Jack";
    faceValue[11] = "Queen";
    faceValue[12] = "King";
}

#include "error.h"
#include <iostream>

using namespace std;

Error::Error(int tip)
{
    this->tip = tip;
}

Error::~Error()
{
    //dtor
}

void Error::Tratare()
{
    if(tip == 1)
        cout<<"List must exists \n";
    else if(tip == 2)
        cout<<"List must have a name \n";
    else if(tip == 3)
        cout<<"List must have max number of elements bigger than 0 \n";
    else if(tip == 4)
        cout<<"You must create a list first \n";
}

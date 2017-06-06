#include "itemtext.h"
#include <iostream>

using namespace std;

ItemText::ItemText()
{
    //ctor
}

ItemText::~ItemText()
{
    //dtor
}

void ItemText::ShowItem()
{
    if(this->text != "###")
    cout<<this->text<<" "<<this->completed<<endl;
}


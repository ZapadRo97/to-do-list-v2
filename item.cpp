#include "item.h"
#include <iostream>

using namespace std;

Item::Item()
{
    //ctor
    text = "###";
    this->listId = -1;
    completed = 0;
}

Item::~Item()
{
    //dtor
}

void Item::SetList(int listId)
{
    this->listId = listId;
}

/*void Item::ShowItem()
{
    if(this->text != "###")
    cout<<this->text<<" "<<this->completed<<endl;
}*/

void Item::ToggleCompleted()
{
    this->completed = !(this->completed);
}

int Item::CountItems()
{
   if(this->text != "###")
        return 1;
   return 0;
}

void Item::SetItem(string text)
{
    this->text = text;
}

/*ostream& operator<<(ostream& out, Item itemus)
{
    //out<< everything
    out<<itemus.completed<<" "<<itemus.listId<<" "<<itemus.text;
    return out;
}


istream& operator>>(istream & in, Item &itemus)
{
    //in>> everything
    in>>itemus.completed>>itemus.listId;
    in.ignore();
    getline(in, itemus.text);
    return in;
}*/

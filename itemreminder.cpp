#include "itemreminder.h"
#include <iostream>

using namespace std;

ItemReminder::ItemReminder()
{
    //ctor
}

ItemReminder::~ItemReminder()
{
    //dtor
}

void ItemReminder::ShowItem()
{
    if(this->text != "###")
    {
        cout<<this->text<<" "<<this->completed<<" ";
        item_date.ShowDate();
        cout<<endl;
    }

    //to add date here

}

void ItemReminder::SetItem(string text)
{
    this->text = text;
}

void ItemReminder::SetItem(string text, Date reminder_date)
{
    this->text = text;
    this->item_date = reminder_date;
}

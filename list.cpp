#include <string>
#include <iostream>
#include "list.h"

using namespace std;

ItemText text_item;
ItemReminder reminder_item;

Item *item1 = &text_item;
Item *item2 = &reminder_item;

List::List(string name, int noItems)
{
    this->name = name;
    this->noItems = noItems;
    this->items_text = new ItemText[noItems];
    this->items_reminder = new ItemReminder[noItems];
    //for(int i = 0; i < noItems; i++){
        //items[i].SetList(0); //TO change 0 with id
    //}
    //ctor
}

List::List(List &object)
{
    this->items_text = new ItemText[object.noItems]; //if it's not working, replace with this->noItems
    this->items_reminder = new ItemReminder[object.noItems];
    *(this->items_text) = *(object.items_text);
    *(this->items_reminder) = *(object.items_reminder);
    this->name = object.name;
    this->noItems = object.noItems;
    this->id = object.id;
}

List& List::operator=(const List &other)
{
    this->items_text = new ItemText[other.noItems];
    this->items_reminder = new ItemReminder[other.noItems];
    *(this->items_text) = *(other.items_text);
    *(this->items_reminder) = *(other.items_reminder);
    this->name = other.name;
    this->noItems = other.noItems;
    this->id = other.id;
    return *this;
}

List::~List()
{
    delete[] this->items_text;
    delete[] this->items_reminder;
    //dtor
}

void List::showItems()
{
    for(int i = 0; i < noItems; i++){
        items_text[i].ShowItem();
        items_reminder[i].ShowItem();
    }

}

void List::AddListItem(int index, string text)
{
    //hope this will work
    item1 = &(items_text[index]);
    item1->SetItem(text);
    item1->SetList(0);
    //items_text[index].SetItem(text);
    //items_text[index].SetList(0);
}

void List::AddListItem(int index, string text, Date reminder_date)
{
    items_reminder[index].SetItem(text, reminder_date);
    items_reminder[index].SetList(0);
}

void List::DeleteListItem(int index, int typeoff) //0 for text and 1 for reminder
{
    if(!typeoff){
        items_text[index].SetItem("###");
        for(int i = index; i < this->noItems-1; i++){
            items_text[i] = items_text[i+1];
        }
    }
    else{
        items_reminder[index].SetItem("###");
        for(int i = index; i < this->noItems-1; i++){
            items_reminder[i] = items_reminder[i+1];
        }
    }


}

void List::ToggleListItem(int index, int typeoff) //idem
{
    if(!typeoff)
        items_text[index].ToggleCompleted();
    else
        items_reminder[index].ToggleCompleted();
}

void List::DeleteList()
{
    this->name = "###";
    this->noItems = 0;
    for(int i = 0; i < noItems; i++){
        items_text[i].SetItem("###");
        items_reminder[i].SetItem("###");
    }
}

void List::showList()
{
    int ActualNumberOfItems = 0;
    for(int i = 0; i < noItems; i++){
        ActualNumberOfItems += items_text[i].CountItems();
        ActualNumberOfItems += items_reminder[i].CountItems();
    }
    cout<<this->name<<" Items: "<<ActualNumberOfItems;
}

bool List::Exists()
{
    if(name == "###")
        return 0;
    return 1;
}

/*ostream& operator<<(ostream& out, const List &listus)
{
    //out<< everything
    out<<listus.name<<" "<<listus.noItems;
    out<<endl;
    for(int i = 0; i < listus.noItems; i++){
        out<<listus.items_text[i];
        out<<endl;
    }
    return out;
}


istream& operator>>(istream & in, List &listus)
{
    //in>> everything
    in>>listus.name>>listus.noItems;
    List TempList(listus.name, listus.noItems);
    listus = TempList;
    for(int i = 0; i < listus.noItems; i++){
        in>>listus.items_text[i];
    }
    return in;
}
*/

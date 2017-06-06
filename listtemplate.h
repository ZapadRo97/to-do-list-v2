#ifndef LISTTEMPLATE_H
#define LISTTEMPLATE_H

#include <string>
#include <iostream>
#include "date.h"

template <class ListType> class ListTemplate
{
    public:
        ListTemplate(std::string, int);
        ~ListTemplate();
        ListTemplate(ListTemplate&);
        ListTemplate& operator=(const ListTemplate&);
        void showItems();
        void AddListItem(int, std::string);
        void AddListItem(int, std::string, Date);
        void DeleteListItem(int);
        void ToggleListItem(int);
        void DeleteList();
        void showList();
        bool Exists();

    protected:

    private:
        ListType *items;
        std::string name;
        int noItems, id;
};

template <class ListType>
ListTemplate<ListType>::ListTemplate(std::string name, int noItems)
{
    this->name = name;
    this->noItems = noItems;
    this->items = new ListType[noItems];
}

template <class ListType>
ListTemplate<ListType>::ListTemplate(ListTemplate &object)
{
    this->items = new ListType[object.noItems];
    *(this->items) = *(object.items);
    this->name = object.name;
    this->noItems = object.noItems;
    this->id = object.id;
}

template <class ListType>
ListTemplate<ListType>& ListTemplate<ListType>::operator=(const ListTemplate &other)
{
    this->items = new ListType[other.noItems];
    *(this->items) = *(other.items);
    this->name = other.name;
    this->noItems = other.noItems;
    this->id = other.id;
    return *this;
}

template <class ListType>
ListTemplate<ListType>::~ListTemplate()
{
    delete[] this->items;
    //dtor
}

template <class ListType>
void ListTemplate<ListType>::showItems()
{
    for(int i = 0; i < noItems; i++){
        items[i].ShowItem();
    }

}

template <class ListType>
void ListTemplate<ListType>::AddListItem(int index, std::string text)
{
    items[index].SetItem(text);
    items[index].SetList(0);
}

template <class ListType>
void ListTemplate<ListType>::AddListItem(int index, std::string text, Date reminder_date)
{
    //to check in main for validity
    items[index].SetItem(text, reminder_date);
    items[index].SetList(0);
}

template <class ListType>
void ListTemplate<ListType>::DeleteListItem(int index) //0 for text and 1 for reminder
{
        items[index].SetItem("###");
        for(int i = index; i < this->noItems-1; i++){
            items[i] = items[i+1];
        }
}

template <class ListType>
void ListTemplate<ListType>::ToggleListItem(int index) //idem
{
    items[index].ToggleCompleted();
}

template <class ListType>
void ListTemplate<ListType>::DeleteList()
{
    this->name = "###";
    this->noItems = 0;
    for(int i = 0; i < noItems; i++){
        items[i].SetItem("###");
    }
}

template <class ListType>
void ListTemplate<ListType>::showList()
{
    int ActualNumberOfItems = 0;
    for(int i = 0; i < noItems; i++){
        ActualNumberOfItems += items[i].CountItems();
    }
    std::cout<<this->name<<" Items: "<<ActualNumberOfItems;
}

template <class ListType>
bool ListTemplate<ListType>::Exists()
{
    if(name == "###")
        return 0;
    return 1;
}

#endif // LISTTEMPLATE_H

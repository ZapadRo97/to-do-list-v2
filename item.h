#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "date.h"

//this will be an abstract class
//with pure virtual function

class Item
{
    public:
        Item();
        ~Item();
        void SetList(int);
        virtual void ShowItem() = 0; //this is pure
        void SetItem(std::string);
        //virtual void SetItem(std::string, Date); //to be changed with date class
        void ToggleCompleted();
        int CountItems();

        //friend std::ostream& operator<<(std::ostream&, Item); //this will be moved in derivate classes
        //friend std::istream& operator>>(std::istream&, Item&); //this too

    protected:
        std::string text;
        bool completed;
    private:
        int listId, id;
};

#endif // ITEM_H

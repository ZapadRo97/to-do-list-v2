#ifndef LIST_H
#define LIST_H
#include <string>
#include "itemtext.h"
#include "itemreminder.h"
#include "date.h"
class ItemText;
class ItemReminder;

class List
{
    public:
        List(std::string, int);
        ~List();
        List(List&);
        List& operator=(const List&);
        void showItems();
        void AddListItem(int, std::string);
        void AddListItem(int, std::string, Date);
        void DeleteListItem(int, int);
        void ToggleListItem(int, int);
        void DeleteList();
        void showList();
        bool Exists();

        //to be modified
        //friend std::ostream& operator<<(std::ostream&, const List&);
        //friend std::istream& operator>>(std::istream&, List&);

    protected:

    private:
        ItemText *items_text;
        ItemReminder *items_reminder;
        std::string name;
        int noItems, id;
};

#endif // LIST_H

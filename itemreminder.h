#ifndef ITEMREMINDER_H
#define ITEMREMINDER_H

#include <string>
#include "itemtext.h"
#include "date.h"
//this will inherit item text (hope this will work) and date
//make inheritance of date class worth (opt)

class ItemReminder: public ItemText, public Date
{
    public:
        ItemReminder();
        ~ItemReminder();
        void ShowItem();
        void SetItem(std::string);
        void SetItem(std::string, Date);
    protected:

    private:
        Date item_date;
};

#endif // ITEMREMINDER_H

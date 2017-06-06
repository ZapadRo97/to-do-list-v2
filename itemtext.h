#ifndef ITEMTEXT_H
#define ITEMTEXT_H

#include <string>
#include "item.h"

//this will inherit item class

class ItemText: public Item
{
    public:
        ItemText();
        ~ItemText();
        void ShowItem();

    protected:

    private:
};

#endif // ITEMTEXT_H

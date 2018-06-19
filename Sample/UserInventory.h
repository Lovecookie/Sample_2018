#pragma once

#include "SampleDefine.h"

namespace Sample
{
    class UserInventory final
    {
    public:
        UserInventory() = default;
        UserInventory( const UserIndex& userIndex );
        ~UserInventory();

        bool AddItem( Item* const pItem );
        Item* FindItem( const TableIndex itemIndex );
        void Remove( const TableIndex itemIndex );

    private:
        UserIndex _userIndex;
        ItemMap _items;
    };
}

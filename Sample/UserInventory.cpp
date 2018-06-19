#include "UserInventory.h"
#include "Item.h"


namespace Sample
{
    UserInventory::UserInventory( const UserIndex& userIndex )
        : _userIndex(userIndex)
    {   
    }

    UserInventory::~UserInventory()
    {
        for( auto item : _items )
        {
            SafeDelete( item.second );
        }
    }

    bool UserInventory::AddItem( Item* const pItem )
    {   
        const auto iter = _items.find( pItem->GetItemIndex() );
        if( _items.end() != iter )
        {
            return false;
        }

        _items.emplace( std::make_pair( pItem->GetItemIndex(), pItem ) );
        return true;
    }

    Item* UserInventory::FindItem( const TableIndex itemIndex )
    {
        const auto iter = _items.find( itemIndex );
        return _items.end() != iter ? iter->second : nullptr;
    }

    void UserInventory::Remove( const TableIndex itemIndex )
    {
        _items.erase( itemIndex );
    }

}
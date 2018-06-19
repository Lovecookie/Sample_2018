#include "ItemContent.h"
#include "UserInventory.h"
#include "Item.h"
#include "UserContent.h"
#include "UserPlayer.h"


namespace Sample
{
    ItemContent::ItemContent()
        :   _contentType( ContentType::item )
    {
    }

    ItemContent::~ItemContent()
    {
        Finalize();
    }

    bool ItemContent::Initialize()
    {   
        return true;
    }

    void ItemContent::Finalize()
    {   
        for( auto inventory : _userInventorys )
        {
            SafeDelete( inventory.second );
        }
    }

    UserInventory* ItemContent::FindInventory( const UserIndex& userIndex ) const
    {
        const auto iter = _userInventorys.find( userIndex );
        return _userInventorys.end() != iter ? iter->second : nullptr;
    }

    CommonResult ItemContent::AddUserItem( const UserIndex& userIndex, Item* const pItem )
    {
        auto inventory = FindInventory( userIndex );
        if( nullptr == inventory )
        {
            return CommonResult::InvalidUserIndex;
        }

        const auto result = inventory->AddItem( pItem );
        if( !result )
        {
            return CommonResult::InvalidTableIndex;
        }

        return CommonResult::Succeed;
    }

    CommonResult ItemContent::UseUserItem( const UserIndex& userIndex, const TableIndex itemIndex )
    {
        auto pInventory = FindInventory( userIndex );
        if( nullptr == pInventory )
        {
            return CommonResult::InvalidUserIndex;
        }

        const auto pUserPlayer = UserContent::Instance()->FindUserPlayer( userIndex );
        if( nullptr == pUserPlayer )
        {
            return CommonResult::InvalidUserIndex;
        }

        auto pItem = pInventory->FindItem( itemIndex );
        if( nullptr == pItem )
        {
            return CommonResult::InvalidTableIndex;
        }

        pItem->Use( pUserPlayer );

        return CommonResult::Succeed;
    }

    CommonResult ItemContent::RemoveItem( const UserIndex& userIndex, const TableIndex itemIndex )
    {
        auto pInventory = FindInventory( userIndex );
        if( nullptr == pInventory )
        {
            return CommonResult::InvalidUserIndex;
        }
        
        pInventory->Remove( itemIndex );

        return CommonResult::Succeed;
    }


}

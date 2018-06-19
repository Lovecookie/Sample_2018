#pragma once

#include "SimpleSingleton.h"
#include "IContentBase.h"

namespace Sample
{
    class ItemContent final : public IContentBase, public SimpleSingleton<ItemContent>
    {   
    public:
        ItemContent();
        virtual ~ItemContent();

        const ContentType& GetContentType() const
        {
            return _contentType;
        }

        bool Initialize() override;
        void Finalize() override;

        UserInventory* FindInventory( const UserIndex& userIndex ) const;

        CommonResult AddUserItem( const UserIndex& userIndex, Item* const pItem );
        CommonResult RemoveItem( const UserIndex& userIndex, const TableIndex itemIndex );
        CommonResult UseUserItem( const UserIndex& userIndex, const TableIndex itemIndex );

    private:
        ContentType _contentType;
        InventoryMap _userInventorys;
    };
}


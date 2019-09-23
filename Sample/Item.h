#pragma once

#include "SampleDefine.h"
#include "IBaseItem.h"

namespace Sample
{
    class UserPlayer;    

    class Item abstract
    {
    public:
        explicit Item( const TableIndex itemIndex, uint32_t amount );
        virtual ~Item() = default;

        TableIndex GetItemIndex() const
        {
            return _itemIndex;
        }
        uint32_t GetAmount() const
        {
            return _amount;
        }

        void SetAmount( const uint32_t amount )
        {
            _amount = amount;
        }
        
        void Subtract( const uint32_t amount )
        {
            _amount -= amount;
        }

        virtual CommonResult Use( IInfluenceItemActor* const pActor ) = 0;

    private:
        TableIndex _itemIndex;
        uint32_t _amount;
    };


    class ItemCoin final : public Item
    {
    public:
        explicit ItemCoin( const TableIndex itemIndex, uint32_t amount );
        ~ItemCoin() = default;

        CommonResult Use( IInfluenceItemActor* const pActor) override;
    };


    class ItemBuff final : public Item
    {
    public:
        explicit ItemBuff( const TableIndex itemIndex, uint32_t amount );
        ~ItemBuff() = default;

        CommonResult Use( IInfluenceItemActor* const pActor ) override;
    };
}

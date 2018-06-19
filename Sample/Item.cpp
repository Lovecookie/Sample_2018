#include "Item.h"
#include "IInfluenceActor.h"


namespace Sample
{
    
    Item::Item( const TableIndex itemIndex, uint32_t amount )
        :   _itemIndex( itemIndex ),
            _amount( amount )
    {
    }    

    // Item Coin
    ItemCoin::ItemCoin( const TableIndex itemIndex, uint32_t amount )
        :   Item( itemIndex, amount )
    {   
    }

    CommonResult ItemCoin::Use( IInfluenceItemActor* pActor )
    {
        return pActor->CoinInfluence( this );        
    }

    //  Item Buff
    ItemBuff::ItemBuff( const TableIndex itemIndex, uint32_t amount )
        :   Item( itemIndex, amount )
    {   
    }

    CommonResult ItemBuff::Use( IInfluenceItemActor* pActor )
    {
        return pActor->BuffInfluence( this );
    }


}

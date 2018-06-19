#pragma once

#include "SampleDefine.h"

namespace Sample
{
    class Item;
    __interface IInfluenceItemActor
    {
        CommonResult BuffInfluence( const Item* pItem );
        CommonResult CoinInfluence( const Item* pItem );
    };
}

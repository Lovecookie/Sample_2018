#pragma once

#include "SampleDefine.h"

namespace Sample
{
    class Item;
    __interface IInfluenceItemActor
    {
        CommonResult UseBuffItem( const Item* pItem );
        CommonResult UseCoinItem( const Item* pItem );
    };
}

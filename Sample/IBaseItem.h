#pragma once

#include "SampleDefine.h"
#include <functional>

namespace Sample
{
    class Item;
    __interface IInfluenceItemActor;

    using UseFunctor = std::function<CommonResult(IInfluenceItemActor*)>;

    __interface IBaseItem
    {
        CommonResult Use();
        CommonResult Use( const UseFunctor&& );
    };
}

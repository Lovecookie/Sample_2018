#include "UserPlayer.h"
#include "Item.h"

namespace Sample
{
    UserPlayer::UserPlayer( const UserIndex& userIndex )
        : _userIndex( userIndex )
    {   
    }

    CommonResult UserPlayer::BuffInfluence( const Item* pItem )
    {
        // 버프 사용에 대한 영향을 줌..
        return CommonResult::Succeed;
    }

    CommonResult UserPlayer::CoinInfluence( const Item* pItem )
    {
        // 코인 사용에 대한 영향을 줌..
        return CommonResult::Succeed;
    }
}

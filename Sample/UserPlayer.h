#pragma once

#include "IInfluenceActor.h"

namespace Sample
{
    class UserPlayer : public IInfluenceItemActor
    {
    public:
        UserPlayer() = default;
        UserPlayer( const UserIndex& userIndex );
        virtual ~UserPlayer() = default;

        const UserIndex& GetUserIndex() const
        {
            return _userIndex;
        }

        void SetUserIndex( const UserIndex& userIndex )
        {
            _userIndex = userIndex;
        }

        CommonResult BuffInfluence( const Item* pItem ) override;
        CommonResult CoinInfluence( const Item* pItem ) override;

    private:
        UserIndex _userIndex;
    };
}

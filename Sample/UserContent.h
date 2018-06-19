#pragma once

#include "SampleDefine.h"
#include "SimpleSingleton.h"
#include "IContentBase.h"

namespace Sample
{
    class UserContent : public IContentBase, public SimpleSingleton<UserContent>
    {   
    public:
        UserContent();
        virtual ~UserContent();

        const ContentType& GetContentType() const
        {
            return _contentType;
        }

        bool Initialize() override;
        void Finalize() override;

        UserPlayer* FindUserPlayer( const UserIndex& userIndex ) const;
        CommonResult AddUserPlayer( UserPlayer* const pUserPlayer );
        CommonResult RemovePlayer( const UserIndex& userIndex );

    private:
        ContentType _contentType;
        UserPlayerMap _userPlayerMap;
    };
}

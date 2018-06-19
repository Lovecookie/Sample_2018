#include "UserContent.h"
#include "UserPlayer.h"


namespace Sample
{
    UserContent::UserContent()
        :   _contentType( ContentType::user )
    {        
    }

    UserContent::~UserContent()
    {        
    }

    bool UserContent::Initialize()
    {
        return true;
    }

    void UserContent::Finalize()
    {
    }

    UserPlayer* UserContent::FindUserPlayer( const UserIndex& userIndex ) const
    {   
        const auto iter = _userPlayerMap.find( userIndex );
        return _userPlayerMap.end() != iter ? iter->second : nullptr;
    }

    CommonResult UserContent::AddUserPlayer( UserPlayer* const pUserPlayer )
    {
        const auto pTempUser = FindUserPlayer( pUserPlayer->GetUserIndex() );
        if( nullptr != pTempUser )
        {
            return CommonResult::InvalidUserIndex;
        }

        _userPlayerMap.emplace( std::make_pair( pUserPlayer->GetUserIndex(), pUserPlayer ) );

        return CommonResult::Succeed;
    }

    CommonResult UserContent::RemovePlayer( const UserIndex& userIndex )
    {
        _userPlayerMap.erase( userIndex );
        return CommonResult::Succeed;
    }

}

#include "ContentDictionary.h"
#include "IContentBase.h"


namespace Sample
{


    bool ContentDictionary::AddContent( IContentBase* const pContent )
    {   
        if( nullptr == pContent )
        {
            return false;
        }

        if( !pContent->Initialize() )
        {
            // Content is error
            return false;
        }

        return true;
    }

    IContentBase* ContentDictionary::FindContent( const ContentType& contentType ) const
    {
        const auto iter = _contentMap.find( contentType );
        return _contentMap.end() != iter ? iter->second : nullptr;
    }

    void ContentDictionary::FinalizeContent( const ContentType& contentType )
    {
        auto pContent = FindContent( contentType );
        if( nullptr == pContent )
        {
            return;
        }

        pContent->Finalize();
    }

}
#pragma once

#include "SampleDefine.h"
#include "SimpleSingleton.h"

namespace Sample
{
    __interface IContentBase;

    class ContentDictionary final : public SimpleSingleton<ContentDictionary>
    {
    public:
        ContentDictionary() = default;
        ~ContentDictionary() = default;
        
        bool AddContent( IContentBase* const pContent );
        IContentBase* FindContent( const ContentType& contentType ) const;
        void FinalizeContent( const ContentType& contentType );
        
    private:
        ContentMap _contentMap;
    };
}

//Sample::SimpleSingleton<Sample::ContentDictionary>::Instance()
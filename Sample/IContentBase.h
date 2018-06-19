#pragma once

#include "SampleDefine.h"

namespace Sample
{
    __interface IContentBase
    {
        virtual bool Initialize();
        virtual void Finalize();
    };
}
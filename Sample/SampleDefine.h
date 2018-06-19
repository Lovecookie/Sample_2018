#pragma once

#include <stdint.h>
#include <unordered_map>

namespace Sample
{
    class Item;
    class UserInventory;
    class UserPlayer;
    __interface IContentBase;

    //  {{CONSTANT}}
    static const int32_t InvalidUID = 0;

    enum class CommonResult : uint16_t
    {
        Succeed = 0,
        DBError = 100,
        InvalidUserIndex = 200,
        InvalidTableIndex = 300,
    };

    enum class ContentType : uint16_t
    {
        user = 0,
        item = 1,
    };
    //  {{CONSTANT}}


    //  {{TYPE DEFINE}}    
    using UserIndex = uint64_t;
    using TableIndex = uint32_t;


    using ItemMap = std::unordered_map<TableIndex, Item*>;
    using InventoryMap = std::unordered_map<UserIndex, UserInventory*>;
    using UserPlayerMap = std::unordered_map<UserIndex, UserPlayer*>;
    using ContentMap = std::unordered_map<ContentType, IContentBase*>;
    //  {{TYPE DEFINE}}


    //  {{GLOBAL FUNC}}
    template<typename T>
    void SafeDelete( T*& pObject )
    {
        if( nullptr != pObject )
        {
            delete pObject;
            pObject = nullptr;
        }
    }
    //  {{GLOBAL FUNC}}
}
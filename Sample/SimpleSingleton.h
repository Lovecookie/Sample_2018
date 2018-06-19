#pragma once

namespace Sample
{
    template<typename Type>
    class SimpleSingleton
    {
    protected:
        SimpleSingleton() = default;

    public:
        virtual ~SimpleSingleton() = default;
    
        static Type* Instance()
        {
            if( nullptr == _pInstance )
            {
                static Type instance;
                _pInstance = &instance;
            }
            
            return _pInstance;
        }

    private:
        static Type* _pInstance;
    };    

    template <typename  Type>
    Type* SimpleSingleton<Type>::_pInstance = nullptr;
}


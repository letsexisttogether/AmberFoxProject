#pragma once

#include <iostream>
#include <string>

template <class _Collection>
class CollectionPrinter 
{
public:
    static void PrintArray(const _Collection& collection,
        const std::string& message = {}) noexcept;
};

template <class _Collection>
void CollectionPrinter<_Collection>::PrintArray(const _Collection& collection,
    const std::string& message) noexcept
{
    std::cout << message;

    std::cout << '[';
    for (auto iter = collection.begin(), end = collection.end(),
        preEnd = ((iter != end) ? (end - 1) : (iter)); iter != end; ++iter)
    {
        std::cout << *iter;

        if (iter != preEnd)
        {
            std::cout << ", ";
        }
    }
    std::cout << ']' << std::endl;
}

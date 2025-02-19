#pragma once

#include <set>

#include "ArrayTransformer.hpp"

template <class _Type>
class ArrayDistinctor : public ArrayTransformer<_Type>
{
public:
    ATUsings;

public:
    ArrayDistinctor() = delete;
    ArrayDistinctor(const ArrayDistinctor&) = default;
    ArrayDistinctor(ArrayDistinctor&&) = default;

    ArrayDistinctor(const ArrayCollection& collection);

    ~ArrayDistinctor() = default;

    Array ExecuteTransformation() noexcept override;

    ArrayDistinctor& operator = (const ArrayDistinctor&) = default;
    ArrayDistinctor& operator = (ArrayDistinctor&&) = default;

private:
    const ArrayCollection m_ArrayCollection; 
};

template <class _Type>
ArrayDistinctor<_Type>::ArrayDistinctor(const ArrayCollection& collection)
    : m_ArrayCollection{ collection }
{}

template <class _Type>
typename ArrayDistinctor<_Type>::Array 
    ArrayDistinctor<_Type>::ExecuteTransformation()
    noexcept
{
    std::set<_Type> result{};

    for (const Array& array : m_ArrayCollection)
    {
        for (const _Type& value : array)
        {
            result.insert(value);
        }
    }

    return Array{ result.rbegin(), result.rend() };
}

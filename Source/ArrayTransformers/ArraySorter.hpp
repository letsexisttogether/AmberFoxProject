#pragma once 

#include <algorithm>

#include "ArrayTransformer.hpp"

template <class _Type>
class ArraySorter : public ArrayTransformer<_Type>
{
public:
    ATUsings;

public:
    ArraySorter() = delete;
    ArraySorter(const ArraySorter&) = default;
    ArraySorter(ArraySorter&&) = default;

    ArraySorter(const Array& array);

    ~ArraySorter() = default;

    Array ExecuteTransformation() noexcept override;

    ArraySorter& operator = (const ArraySorter&) = default;
    ArraySorter& operator = (ArraySorter&&) = default;

private:
    const Array& m_Array; 
};


template <class _Type>
ArraySorter<_Type>::ArraySorter(const Array& array)
    : m_Array{ array }
{}

template <class _Type>
typename ArraySorter<_Type>::Array ArraySorter<_Type>::ExecuteTransformation()
    noexcept
{
    Array copy{ m_Array };

    std::sort(copy.begin(), copy.end());

    return copy;
}

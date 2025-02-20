#pragma once 

#include "ArrayTransformer.hpp"

template <class _Type>
class ArraySorter : public ArrayTransformer<_Type>
{
public:
    ATUsings;

    using Index = std::size_t;

public:
    ArraySorter() = delete;
    ArraySorter(const ArraySorter&) = default;
    ArraySorter(ArraySorter&&) = default;

    ArraySorter(const Array& array, const bool isAscending = true);

    ~ArraySorter() = default;

    Array ExecuteTransformation() noexcept override;

    ArraySorter& operator = (const ArraySorter&) = default;
    ArraySorter& operator = (ArraySorter&&) = default;

private:
    void Sort(Array& array, const Index left, const Index right)
        const noexcept;

    Index Partition(Array& array, const Index left, const Index right)
        const noexcept;

    void Swap(_Type& first, _Type& second) const noexcept;

private:
    const Array& m_Array; 
    const bool m_IsAscending;
};


template <class _Type>
ArraySorter<_Type>::ArraySorter(const Array& array, const bool isAscending)
    : m_Array{ array }, m_IsAscending{ isAscending }
{}

template <class _Type>
typename ArraySorter<_Type>::Array ArraySorter<_Type>::ExecuteTransformation()
    noexcept
{
    Array copy{ m_Array };

    if (!copy.empty())
    {
        Sort(copy, 0, copy.size() - 1);
    }

    return copy;
}

template <class _Type>
void ArraySorter<_Type>::Sort(Array& array, const Index left,
    const Index right) const noexcept
{
    if (left >= right)
    {
        return;
    }

    const Index pivot = Partition(array, left, right);

    if (pivot > 0)
    {
        Sort(array, left, pivot - 1);
    }

    Sort(array, pivot + 1, right);
}

template <class _Type>
typename ArraySorter<_Type>::Index ArraySorter<_Type>::Partition
    (Array& array, const Index left, const Index right)
    const noexcept
{
    const _Type& pivot = array[right];

    Index i = left - 1;

    for (Index j = left; j < right; ++j)
    {
        const bool isLess = array[j] < pivot;
        
        if ((m_IsAscending && isLess) || (!m_IsAscending && !isLess))
        {
            Swap(array[++i], array[j]);
        }
    }

    Swap(array[++i], array[right]);

    return i;
}


template <class _Type>
void ArraySorter<_Type>::Swap(_Type& first, _Type& second)
    const noexcept
{
    _Type temp{ first };
    first = second;
    second = temp;
}

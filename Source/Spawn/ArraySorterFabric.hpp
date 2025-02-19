#pragma once

#include "ArrayTransformers/Sort/ArraySorter.hpp"
#include <algorithm>
#include <any>

template <class _ArrTransType>
class ArraySorterSpawner : public ArrayTransformerSpawner<_ArrTransType>
{
public:
    ArrayTransformerSpawnerUsings 

public:
    ArraySorterSpawner() = delete;

    ArraySorterSpawner(const ArrayCollection& arrays);

    ~ArraySorterSpawner() = default;

    ArrTrans* GetArrayTransformer() noexcept override;

private:
    std::uint8_t m_Iter{};
};

template <class _ArrTransType>
ArraySorterSpawner<_ArrTransType>::ArraySorterSpawner
    (const ArrayCollection& arrays)
    : Base{ arrays }
{}

template <class _ArrTransType>
typename ArraySorterSpawner<_ArrTransType>::ArrTrans*
    ArraySorterSpawner<_ArrTransType>::GetArrayTransformer() noexcept
{
    ArrTrans* const arraySorter{};

    arraySorter = m_Arrays[m_Iter];

    ++m_Iter;
    if (m_Iter >= m_Arrays.size())
    {
        m_Iter = 0;
    }

    return arraySorter;
}

#undef ArrayTransformerSpawnerUsings

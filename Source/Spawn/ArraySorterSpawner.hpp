#pragma once

#include "ArrayTransformerSpawner.hpp"
#include "Transform/ArraySorter.hpp"

template <class _ArrTransType>
class ArraySorterSpawner : public ArrayTransformerSpawner<_ArrTransType>
{
public:
    ATSUsings;

public:
    ArraySorterSpawner() = delete;
    ArraySorterSpawner(const ArrayCollection& collection);

    ~ArraySorterSpawner() = default;

    ArrTrans* GetArrayTransformer() noexcept override;

private:
    void AdjustIterator() noexcept;

private:
    std::uint8_t m_Iterator{};
};

template <class _ArrTransType>
ArraySorterSpawner<_ArrTransType>::ArraySorterSpawner
    (const ArrayCollection& collection)
    : Base{ collection }
{}

template <class _ArrTransType>
typename ArraySorterSpawner<_ArrTransType>::ArrTrans*
    ArraySorterSpawner<_ArrTransType>::GetArrayTransformer()
    noexcept
{
    if (this->m_ArrayCollection.empty())
    {
        return nullptr;
    }

    ArrTrans* arrayTransformer = new ArraySorter<_ArrTransType> 
    {
        this->m_ArrayCollection[m_Iterator]
    };

    AdjustIterator();

    return arrayTransformer;
}

template <class _ArrTransType>
void ArraySorterSpawner<_ArrTransType>::AdjustIterator()
    noexcept
{
    ++m_Iterator;

    if (m_Iterator == this->m_ArrayCollection.size())
    {
        m_Iterator = 0;
    }
}

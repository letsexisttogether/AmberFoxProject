#pragma once

#include "ArrayTransformerSpawner.hpp"
#include "ArrayTransformers/ArrayIntersector.hpp"
#include <utility>

template <class _ArrTransType>
class ArrayIntersectorSpawner : public ArrayTransformerSpawner<_ArrTransType>
{
public:
    ATSUsings;

public:
    ArrayIntersectorSpawner() = delete;
    ArrayIntersectorSpawner(const ArrayCollection& collection);

    ~ArrayIntersectorSpawner() = default;

    ArrTrans* GetArrayTransformer() noexcept override;

private:
    std::uint8_t FindShortestArrayIndex() const noexcept;

    void FlipState() noexcept;

private:
    bool m_IgnoreShortest{ true };
    std::uint8_t m_ShortestArrayIndex;
};

template <class _ArrTransType>
ArrayIntersectorSpawner<_ArrTransType>::ArrayIntersectorSpawner
    (const ArrayCollection& collection)
    : Base{ collection }, m_ShortestArrayIndex{ FindShortestArrayIndex() }
{}

template <class _ArrTransType>
typename ArrayIntersectorSpawner<_ArrTransType>::ArrTrans*
    ArrayIntersectorSpawner<_ArrTransType>::GetArrayTransformer()
    noexcept
{
    if (m_IgnoreShortest)
    {
    }
    
    ArrTrans* arrayTransformer = new ArrayIntersector<_ArrTransType> 
    {
        this->m_ArrayCollection, m_ShortestArrayIndex
    };

    FlipState();

    return arrayTransformer;
}

template <class _ArrTransType>
std::uint8_t ArrayIntersectorSpawner<_ArrTransType>::FindShortestArrayIndex()
    const noexcept
{
    if (this->m_ArrayCollection.empty())
    {
        return 0;
    }

    using IndexSizePair = std::pair<std::uint8_t, std::size_t>;

    IndexSizePair shortest{ 0, this->m_ArrayCollection[0] };
    bool wasFound = false;

    const std::uint8_t size = this->m_ArrayCollection.size();
    for(std::uint8_t i = 1; i < this->m_ArrayCollection.size(); ++i)
    {
        const std::size_t size = this->m_ArrayCollection[i].size();

        if (shortest.second < size)
        {
            wasFound = true;

            shortest = IndexSizePair{ i, size };
        }
    }

    return ((wasFound) ? (shortest.first) : (size));
}


template <class _ArrTransType>
void ArrayIntersectorSpawner<_ArrTransType>::FlipState()
    noexcept
{
    m_IgnoreShortest = !m_IgnoreShortest;
}



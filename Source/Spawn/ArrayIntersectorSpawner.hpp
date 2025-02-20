#pragma once

#include "ArrayTransformerSpawner.hpp"
#include "Transform/ArrayIntersector.hpp"

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
    using ArrayCollectionConstIterator = typename ArrayCollection::const_iterator;

private:
    ArrayCollectionConstIterator FindShortestArray(const ArrayCollection& collection)
        const noexcept;
    ArrayCollection RemoveShortest() const noexcept;

    void FlipState() noexcept;

private:
    bool m_IgnoreShortest{ true };
};

template <class _ArrTransType>
ArrayIntersectorSpawner<_ArrTransType>::ArrayIntersectorSpawner
    (const ArrayCollection& collection)
    : Base{ collection }
{}

template <class _ArrTransType>
typename ArrayIntersectorSpawner<_ArrTransType>::ArrTrans*
    ArrayIntersectorSpawner<_ArrTransType>::GetArrayTransformer()
    noexcept
{
    const ArrayCollection collection = ((m_IgnoreShortest) ? 
        (RemoveShortest()) : (this->m_ArrayCollection));
    
    ArrTrans* arrayTransformer = new ArrayIntersector<_ArrTransType> 
    {
        collection
    };

    FlipState();

    return arrayTransformer;
}

template <class _ArrTransType>
typename ArrayIntersectorSpawner<_ArrTransType>::ArrayCollectionConstIterator
    ArrayIntersectorSpawner<_ArrTransType>::FindShortestArray
    (const ArrayCollection& collection) const noexcept
{
    if (collection.empty())
    {
        return collection.end();
    }

    ArrayCollectionConstIterator shortest{ collection.begin() };
    bool wasChanged = false;

    for (ArrayCollectionConstIterator iter{ collection.begin() + 1 };
        iter != collection.end(); ++iter)
    {
        if (shortest->get().size() < iter->get().size())
        {
            shortest = iter;
            wasChanged = true;
        }
    }

    if (!wasChanged)
    {
        return collection.end();
    }

    return shortest;
}

template <class _ArrTransType>
typename ArrayIntersectorSpawner<_ArrTransType>::ArrayCollection
    ArrayIntersectorSpawner<_ArrTransType>::RemoveShortest() const noexcept
{
    ArrayCollection result{ this->m_ArrayCollection };

    ArrayCollectionConstIterator iter{ FindShortestArray(result) };

    if (iter != result.end())
    {
        result.erase(iter);
    }
    
    return result;
}

template <class _ArrTransType>
void ArrayIntersectorSpawner<_ArrTransType>::FlipState()
    noexcept
{
    m_IgnoreShortest = !m_IgnoreShortest;
}

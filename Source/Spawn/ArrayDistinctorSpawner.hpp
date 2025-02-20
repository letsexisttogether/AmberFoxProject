#pragma once

#include "ArrayTransformerSpawner.hpp"
#include "Transform/ArrayDistinctor.hpp"

template <class _ArrTransType>
class ArrayDistinctorSpawner : public ArrayTransformerSpawner<_ArrTransType>
{
public:
    ATSUsings;

public:
    ArrayDistinctorSpawner() = delete;
    ArrayDistinctorSpawner(const ArrayCollection& collection);

    ~ArrayDistinctorSpawner() = default;

    ArrTrans* GetArrayTransformer() noexcept override;
};

template <class _ArrTransType>
ArrayDistinctorSpawner<_ArrTransType>::ArrayDistinctorSpawner
    (const ArrayCollection& collection)
    : Base{ collection }
{}

template <class _ArrTransType>
typename ArrayDistinctorSpawner<_ArrTransType>::ArrTrans*
    ArrayDistinctorSpawner<_ArrTransType>::GetArrayTransformer()
    noexcept
{
    ArrTrans* arrayTransformer = new ArrayDistinctor<_ArrTransType> 
    {
        this->m_ArrayCollection
    };

    return arrayTransformer;
}


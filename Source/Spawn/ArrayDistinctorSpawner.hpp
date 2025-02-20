#pragma once

#include "ArrayTransformerSpawner.hpp"
#include "Transform/ArrayDistinctor.hpp"

template <class _ArrTransType>
class ArryDistinctorSpawner : public ArrayTransformerSpawner<_ArrTransType>
{
public:
    ATSUsings;

public:
    ArryDistinctorSpawner() = delete;
    ArryDistinctorSpawner(const ArrayCollection& collection);

    ~ArryDistinctorSpawner() = default;

    ArrTrans* GetArrayTransformer() noexcept override;
};

template <class _ArrTransType>
ArryDistinctorSpawner<_ArrTransType>::ArryDistinctorSpawner
    (const ArrayCollection& collection)
    : Base{ collection }
{}

template <class _ArrTransType>
typename ArryDistinctorSpawner<_ArrTransType>::ArrTrans*
    ArryDistinctorSpawner<_ArrTransType>::GetArrayTransformer()
    noexcept
{
    ArrTrans* arrayTransformer = new ArrayDistinctor<_ArrTransType> 
    {
        this->m_ArrayCollection
    };

    return arrayTransformer;
}


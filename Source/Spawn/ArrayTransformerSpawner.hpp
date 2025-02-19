#pragma once

#include <memory>
#include <vector>

#include "ArrayTransformers/ArrayTransformer.hpp"

template <class _ArrTransType>
class ArrayTransformerSpawner
{
public:
    using ArrTrans = ArrayTransformer<_ArrTransType>;
    using Array = typename ArrTrans::Array;
    using ArrayCollection = typename ArrTrans::ArrayCollection;

public:
    ArrayTransformerSpawner() = delete;

    ArrayTransformerSpawner(const ArrayCollection& collection);
    
    virtual ~ArrayTransformerSpawner() = default;

    virtual ArrTrans* GetArrayTransformer() noexcept = 0;

protected:
    const ArrayCollection& m_ArrayCollection;
};


template <class _ArrTransType>
ArrayTransformerSpawner<_ArrTransType>::ArrayTransformerSpawner
    (const ArrayCollection& collection)
    : m_ArrayCollection{ collection }
{}

#define ATSUsings \
    using Base = ArrayTransformerSpawner<_ArrTransType>; \
    using ArrTrans = typename Base::ArrTrans; \
    using Array = typename Base::Array; \
    using ArrayCollection = typename Base::ArrayCollection;

#pragma once

#include <memory>
#include <vector>

#include "ArrayTransformers/ArrayTransformer.hpp"

template <class _ArrTransType>
class ArrayTransformerSpawner
{
public:
    using ArrTrans = ArrayTransformer<_ArrTransType>;
    using ArrayPointer = typename ArrTrans::Array*;
    using ArrayCollection = std::vector<ArrayPointer>;

public:
    ArrayTransformerSpawner() = delete;

    ArrayTransformerSpawner(const ArrayCollection& arrays);
    
    virtual ~ArrayTransformerSpawner() = default;

    virtual ArrTrans* GetArrayTransformer() noexcept = 0;

protected:
    ArrayCollection m_Arrays;
};


template <class _ArrTransType>
ArrayTransformerSpawner<_ArrTransType>::ArrayTransformerSpawner
    (const ArrayCollection& arrays)
    : m_Arrays{ arrays }
{}

#define ATSUsings \
    using Base = ArrayTransformerSpawner<_ArrTransType>; \
    using ArrTrans = typename Base::ArrTrans; \
    using ArrayPointer = typename Base::ArrayPointer; \
    using ArrayCollection = typename Base::ArrayCollection;

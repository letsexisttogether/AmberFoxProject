#pragma once

#include <type_traits>
#include <vector>
#include <memory>

template <class _Type>
class ArrayTransformer
{
    static_assert(std::is_arithmetic_v<_Type>, 
        "The array should be of an arithmetic type");

public:
    using Array = std::vector<_Type>;
    using ArrayPointer = std::shared_ptr<Array>;
    using ArrayCollection = std::vector<ArrayPointer>;

public:
    ArrayTransformer() = default;

    virtual ~ArrayTransformer() = default;

    virtual Array ExecuteTransformation() noexcept = 0;
};

#define ATUsings \
    using Base = ArrayTransformer<_Type>; \
    using Array = typename Base::Array; \
    using ArrayPointer = typename Base::ArrayPointer; \
    using ArrayCollection = typename Base::ArrayCollection;

#pragma once

#include <type_traits>
#include <vector>

template <class _Type>
class ArrayTransformer
{
    static_assert(std::is_arithmetic_v<_Type>, 
        "The array must be of an arithmetic type");

public:
    using Array = std::vector<_Type>;
    using ArrayCollection = std::vector<std::reference_wrapper<const Array>>;

public:
    ArrayTransformer() = default;

    virtual ~ArrayTransformer() = default;

    virtual Array ExecuteTransformation() noexcept = 0;
};

#define ATUsings \
    using Base = ArrayTransformer<_Type>; \
    using Array = typename Base::Array; \
    using ArrayCollection = typename Base::ArrayCollection;

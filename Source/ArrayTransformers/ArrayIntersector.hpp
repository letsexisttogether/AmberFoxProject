#pragma once

#include <unordered_map>
#include <unordered_set>

#include "ArrayTransformer.hpp"

template <class _Type>
class ArrayIntersector : public ArrayTransformer<_Type>
{
public:
    ATUsings;

public:
    ArrayIntersector() = delete;
    ArrayIntersector(const ArrayIntersector&) = default;
    ArrayIntersector(ArrayIntersector&&) = default;

    ArrayIntersector(const ArrayCollection& collection);

    ~ArrayIntersector() = default;

    Array ExecuteTransformation() noexcept override;

    ArrayIntersector& operator = (const ArrayIntersector&) = default;
    ArrayIntersector& operator = (ArrayIntersector&&) = default;

private:
    const ArrayCollection& m_ArrayCollection; 
};

template <class _Type>
ArrayIntersector<_Type>::ArrayIntersector(const ArrayCollection& collection)
    : m_ArrayCollection{ collection }
{}

template <class _Type>
typename ArrayIntersector<_Type>::Array 
    ArrayIntersector<_Type>::ExecuteTransformation()
    noexcept
{
    Array result{};

    std::unordered_map<_Type, std::uint32_t> frequencies{}; 

    for (const Array& array : m_ArrayCollection)
    {
        std::unordered_set<_Type> usedValues{};

        for (const _Type& value : array)
        {
            if (usedValues.find(value) == usedValues.end())
            {
                usedValues.insert(value);
                ++frequencies[value]; 
            }
        }
    }

    // Miss decomposition from C++17 here
    for (const auto& iter : frequencies)
    {
        const _Type& value = iter.first;
        const std::uint32_t suitableFrequency = iter.second;

        if (suitableFrequency == m_ArrayCollection.size())
        {
            result.push_back(value);
        }
    }

    return result;
}

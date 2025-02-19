#pragma once

#include <iostream>
#include <type_traits>

#include "ArrayTransformers/ArrayTransformer.hpp"
#include "Spawn/ArrayTransformerSpawner.hpp"

template <class _ArrTransType, class _ArrayTransformer>
class ConsecutiveATS : public ArrayTransformerSpawner<_ArrTransType>
{
static_assert(std::is_base_of_v<ArrayTransformer<_ArrTransType>,
    _ArrayTransformer>, "The class should be inherited from AT");

public:
    ATSUsings;

public:
    ConsecutiveATS() = delete;
    ConsecutiveATS(const ArrayCollection& arrays);

    ~ConsecutiveATS() = default;

    ArrTrans* GetArrayTransformer() noexcept override;

private:
    std::uint8_t m_Iterator{};
};

template <class _ArrTransType, class _ArrayTransformer>
ConsecutiveATS<_ArrTransType, _ArrayTransformer>::ConsecutiveATS
    (const ArrayCollection& arrays)
    : Base{ arrays }
{}

template <class _ArrTransType, class _ArrayTransformer>
typename ConsecutiveATS<_ArrTransType, _ArrayTransformer>::ArrTrans*
    ConsecutiveATS<_ArrTransType, _ArrayTransformer>::GetArrayTransformer()
    noexcept
{
    std::cout << this->m_Arrays.size();

    if (this->m_Arrays.empty())
    {
        return nullptr;
    }

    ArrTrans* arrayTransformer = new _ArrayTransformer
    {
        this->m_Arrays[m_Iterator]
    };

    ++m_Iterator;

    if (m_Iterator == this->m_Arrays.size())
    {
        m_Iterator = 0;
    }

    return arrayTransformer;
}

/*
template <class _ArrTransType>
using ArraySorterSpawner = ConsecutiveATS<_ArrTransType, 
*/

#undef ATSUsings

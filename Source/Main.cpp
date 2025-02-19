#include <iostream>

#include "ArrayTransformers/ArraySorter.hpp"
#include "Spawn/Consecutive/ConsecutiveATS.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    std::cout << "Hello, AmberFoxStudio" << std::endl;

    using Type = std::int32_t;
    using Array = std::vector<Type>;

    const Array small 
    {
        5, 1, 3, 2, 6, 1, 4
    };
    const Array mid 
    {
        10, 3, 150, 308, 11
    };
    const Array big 
    {
        600, 300, 5, 1500, 1, 17, 2000, 2, 17000
    };

    ArrayTransformerSpawner<Type>::ArrayCollection collection
    {
        std::move(small),
        std::move(mid),
        std::move(big),
    };

    std::unique_ptr<ArrayTransformerSpawner<Type>> sorterSpawner
    {
        new ArraySorterSpawner<Type>{ collection }
    };

    std::unique_ptr<ArrayTransformer<Type>> sorter1
    { 
        sorterSpawner->GetArrayTransformer() 
    };
    std::unique_ptr<ArrayTransformer<Type>> sorter2
    { 
        sorterSpawner->GetArrayTransformer() 
    };
    std::unique_ptr<ArrayTransformer<Type>> sorter3
    { 
        sorterSpawner->GetArrayTransformer() 
    };

    const Array array = sorter3->ExecuteTransformation();

    for (const Type& item : array)
    {
        std::cout << item << ' ';
    }

    return EXIT_SUCCESS;
}

#include <iostream>

#include "ArrayTransformers/ArraySorter.hpp"
#include "Spawn/Consecutive/ConsecutiveATS.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    std::cout << "Hello, AmberFoxStudio" << std::endl;

    using Type = std::int32_t;

    std::vector<Type> array
    {
        5, 1, 3, 2, 6, 1, 4
    };

    std::cout << "Breakes here #1" << std::endl;
    ArrayTransformerSpawner<Type>::ArrayCollection collection
    {
        ArrayTransformerSpawner<Type>::ArrayPointer{ &array }
    };

    std::cout << "Breakes here #2" << std::endl;
    std::unique_ptr<ArrayTransformerSpawner<Type>> sorterSpawner
    {
        new ConsecutiveATS<Type, ArraySorter<Type>>{ collection }
    };

    std::cout << "Breakes here #3" << std::endl;
    std::unique_ptr<ArrayTransformer<Type>> sorter
    { 
        sorterSpawner->GetArrayTransformer() 
    };

    std::cout << "Breakes here #4" << std::endl;
    array = std::move(sorter->ExecuteTransformation());

    for (const Type& item : array)
    {
        std::cout << item << ' ';
    }

    std::cout << "\nThe end " << std::endl;

    return EXIT_SUCCESS;
}

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

    std::cerr << "Breakes here #1" << std::endl;
    ArrayTransformerSpawner<Type>::ArrayCollection collection
    {
        ArrayTransformerSpawner<Type>::ArrayPointer{ &array }
    };

    std::cerr << "Breakes here #2" << std::endl;
    std::unique_ptr<ArrayTransformerSpawner<Type>> sorterSpawner
    {
        new ConsecutiveATS<Type, ArraySorter<Type>>{ collection }
    };

    std::cerr << "Breakes here #3" << std::endl;
    std::unique_ptr<ArrayTransformer<Type>> sorter
    { 
        sorterSpawner->GetArrayTransformer() 
    };

    std::cerr << "Breakes here #4" << std::endl;
    array = std::move(sorter->ExecuteTransformation());

    for (const Type& item : array)
    {
        std::cout << item << ' ';
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}

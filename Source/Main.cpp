#include <functional>
#include <iostream>

#include "ArrayTransformers/ArraySorter.hpp"
#include "ArrayTransformers/ArrayIntersector.hpp"
#include "Spawn/ArrayIntersectorSpawner.hpp"
#include "ArrayTransformers/ArrayDistinctor.hpp"
#include "Spawn/ConsecutiveATS.hpp"

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
        10, 3, 150, 308, 11, 1
    };
    const Array big 
    {
        600, 300, 5, 1500, 1, 17, 2000, 3, 17000
    };

    ArrayTransformerSpawner<Type>::ArrayCollection collection
    {
        small, mid, big
    };

    std::unique_ptr<ArrayTransformerSpawner<Type>> spawner
    {
        new ArrayIntersectorSpawner<Type>{ collection }
    };

    std::unique_ptr<ArrayTransformer<Type>> intersector
    {
        spawner->GetArrayTransformer()
    };

    const auto array{ intersector->ExecuteTransformation() };

    for (const Type& value : array)
    {
        std::cout << value << ' ';
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}

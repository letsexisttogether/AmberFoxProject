#include "Application.hpp"

#include <iostream>

#include "Spawn/ArraySorterSpawner.hpp"
#include "Spawn/ArrayIntersectorSpawner.hpp"
#include "Spawn/ArrayDistinctorSpawner.hpp"

Application::Application(FileReader&& reader)
    : m_FileReader{ std::move(reader) }
{}

std::int32_t Application::Application::Run() noexcept
{
    if (!ReadTask())
    {
        return EXIT_FAILURE;
    }

    SortTask();
    IntersectTask();
    DistinctTask();

    return EXIT_SUCCESS;
}

bool Application::ReadTask() noexcept
{ 
    if (!m_FileReader.DoesFileExist())
    {
        std::cerr << "Specified file does not exist" << std::endl;

        return false;
    }

    m_RawCollection = m_FileReader.ReadFile();
    m_Collection.reserve(m_RawCollection.size());
    
    std::cout << "\nThe next arrays were found:\n";
    for (const Array& array : m_RawCollection)
    {
        m_Collection.push_back(array);
        CollectionPrinter::PrintArray(array);
    }
    std::cout << std::endl;

    return true;
}

void Application::SortTask() const noexcept
{
    std::cout << "\nTask #1. Sorting the arrays\n";

    std::unique_ptr<ArrayTransformerSpawner> sorterSpawner 
    {
        new ArraySorterSpawner<Type>{ m_Collection }
    };

    for (std::uint8_t i = 0; i < m_Collection.size(); ++i)
    {
        std::unique_ptr<ArrayTransformer> sorter 
        {
            sorterSpawner->GetArrayTransformer()
        };

        const Array array{ sorter->ExecuteTransformation() };

        CollectionPrinter::PrintArray(array);
    }
    std::cout << std::endl;
}

void Application::IntersectTask() const noexcept
{
    std::cout << "\nTask #2. Finding the intersection of the arrays\n";

    std::unique_ptr<ArrayTransformerSpawner> intersectorSpawner 
    {
        new ArrayIntersectorSpawner<Type>{ m_Collection }
    };

    for (std::uint8_t i = 0; i < 2; ++i)
    {
        std::unique_ptr<ArrayTransformer> intersector 
        {
            intersectorSpawner->GetArrayTransformer()
        };

        const Array array{ intersector->ExecuteTransformation() };
        CollectionPrinter::PrintArray(array);
    }
    std::cout << std::endl;
}

void Application::DistinctTask() const noexcept
{
    std::cout << "\nTask #3. Combining disctint values of the arrays\n";

    std::unique_ptr<ArrayTransformerSpawner> distinctorSpawner 
    {
        new ArrayDistinctorSpawner<Type>{ m_Collection }
    };

    std::unique_ptr<ArrayTransformer> distinctor 
    {
       distinctorSpawner->GetArrayTransformer()
    };

    const Array array{ distinctor->ExecuteTransformation() };
    CollectionPrinter::PrintArray(array);

    std::cout << std::endl;
}

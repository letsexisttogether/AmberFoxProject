#pragma once

#include "Print/CollectionPrinter.hpp"
#include "Read/FileReader.hpp"
#include "Transform/ArrayTransformer.hpp"
#include "Spawn/ArrayTransformerSpawner.hpp"

class Application
{
public:
    Application() = delete;
    Application(const Application&) = delete;
    Application(Application&&) = delete;

    Application(FileReader&& reader);

    ~Application() = default;

    std::int32_t Run() noexcept;

    Application& operator = (const Application&) = delete;
    Application& operator = (Application&&) = delete;

private:
    using Type = std::int32_t;

    using ArrayTransformer = ArrayTransformer<Type>;
    using ArrayTransformerSpawner = ArrayTransformerSpawner<Type>;

    using Array = ArrayTransformer::Array;
    using ArrayCollection = ArrayTransformer::ArrayCollection;
    using RawArrayCollection = FileReader::ArrayCollection;
    
    using CollectionPrinter = CollectionPrinter<Array>;

private:
    bool ReadTask() noexcept;
    void SortTask() const noexcept;
    void IntersectTask() const noexcept;
    void DistinctTask() const noexcept;

private:
    FileReader m_FileReader;

    RawArrayCollection m_RawCollection{};
    ArrayCollection m_Collection{};
};

#pragma once

#include <string>

#include "Transform/ArrayTransformer.hpp"

class FileReader
{
public:
    using FileName = std::string;

    using Array = ArrayTransformer<std::int32_t>::Array;
    using ArrayCollection = std::vector<Array>;

public:
    FileReader() = delete;
    FileReader(const FileReader&) = default;
    FileReader(FileReader&&) = default;

    // Make this explicit as well as the other constructors
    FileReader(const FileName& fileName);

    ~FileReader() = default;

    ArrayCollection ReadFile() noexcept;

    bool DoesFileExist() const noexcept;

    const FileName& GetFileName() const noexcept;

    FileReader& operator = (const FileReader&) = default;
    FileReader& operator = (FileReader&&) = default;

private:
    Array ParseLine(const std::string& line);

private:
    FileName m_FileName;
};

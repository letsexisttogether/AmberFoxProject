#include "FileReader.hpp"

#include <iostream>
#include <fstream>
#include <regex>

FileReader::FileReader(const FileName& fileName)
    : m_FileName{ fileName }
{}

bool FileReader::DoesFileExist() const noexcept
{
    std::ifstream file{ m_FileName };

    return file.good();
}

FileReader::ArrayCollection FileReader::ReadFile() noexcept
{
    std::ifstream file{ m_FileName };
    if (!file.is_open())
    {
        return {};
    }

    ArrayCollection arrayCollection{};

    for (std::string line{}; std::getline(file, line); )
    {
        if (!line.empty())
        {
            const Array array{ ParseLine(line) };

            if (!array.empty())
            {
                arrayCollection.push_back(std::move(array));
            }
        }
    }

    return arrayCollection;
}


const FileReader::FileName& FileReader::GetFileName() const noexcept
{
    return m_FileName;
}

FileReader::Array FileReader::ParseLine(const std::string& line)
{
    Array array{};

    std::regex delimiter{ R"([,\s]+)" };

    std::sregex_token_iterator iter{ line.begin(), line.end(), delimiter, -1 };
    std::sregex_token_iterator end{};

    for (; iter != end; ++iter)
    {
        const std::string possibleNumber{ iter->str() };

        try
        {
            const Type value = std::stoi(possibleNumber);
            array.push_back(std::stoi(iter->str()));
        }
        catch(...)
        {
            std::cerr << "[Error] One of the arrays "
                "contained non-integer values" << std::endl;
            return {};
        }
    }

    return array;
}

#include "FileReader.hpp"

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
            arrayCollection.push_back(ParseLine(line));        
        }
    }

    return arrayCollection;
}

FileReader::Array FileReader::ParseLine(const std::string& line)
{
    Array array{};

    std::regex delimiter{ R"([,\s]+)" };

    std::sregex_token_iterator iter{ line.begin(), line.end(), delimiter, -1 };
    std::sregex_token_iterator end{};

    for (; iter != end; ++iter)
    {
        array.push_back(std::stoi(iter->str()));
    }

    return array;
}

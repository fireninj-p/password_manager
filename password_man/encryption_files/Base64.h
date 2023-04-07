#ifndef BASE64_H
#define BASE64_H
#include <string>
#include <vector>

class Base64
{
    static std::string encode(const std::vector<char>& data);
    static std::vector<char> decode(const std::string& data);
    static std::string encodeFromFile(const std::string& inFileName);
    static void decodeToFile(
        const std::string& outFileName, const std::string& encodedString
    );

};
#endif

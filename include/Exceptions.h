#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

#include<exception>
#include<string>

class ResourceNotFound: public std::exception
{
    std::string path;
    public:
    ResourceNotFound(const std::string& resource_path);
    const char* what() const noexcept override;
};

#endif
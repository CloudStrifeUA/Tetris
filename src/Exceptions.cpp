#include"Exceptions.h"
#include<sstream>

ResourceNotFound::ResourceNotFound(const std::string& resource_path)
{
    std::stringstream ss;
    ss << "Resource " << resource_path << " not found" << std::endl;
    path = ss.str();
}

const char* ResourceNotFound::what() const noexcept
{
    return path.c_str();
}
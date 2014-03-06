#pragma once

#include <string>
#include <vector>

namespace StringUtils
{

  std::vector<std::string> split(const std::string & str, const std::string & delimiter);

  void split(std::vector<std::string>& tokens, const std::string & str,
    const std::string & delimiter);

  std::string rtrim(const std::string &str);
  std::string ltrim(const std::string &str);
  std::string trim(const std::string &str);
}


#pragma once

#include <string>
#include <vector>

namespace StringUtils {
  void split(std::vector<std::string>& tokens, const std::string & str, 
    const std::string & delimiter);
}


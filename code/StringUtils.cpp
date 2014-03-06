#include "StringUtils.h"

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

std::vector<std::string> StringUtils::split(const std::string & str,
  const std::string & delimiter) {

  std::vector<std::string> tokens;

  split(tokens, str, delimiter);

  return tokens;
}

void StringUtils::split(std::vector<std::string>& tokens, const std::string & str, 
  const std::string & delimiter) {

  if (str.empty()) {
    return;
  }

  auto delimiterPosition = str.find(delimiter);

  if (delimiterPosition == std::string::npos) {
    tokens.push_back(str);
    return;
  }

  tokens.push_back(str.substr(0, delimiterPosition));

  split(tokens, str.substr(delimiterPosition + 1), delimiter);
}

std::string StringUtils::ltrim(const std::string & str) {
  auto s = std::string(str);
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

std::string StringUtils::rtrim(const std::string & str) {
  auto s = std::string(str);
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

std::string StringUtils::trim(const std::string & str) {
  return ltrim(rtrim(std::string(str)));
}

#include "StringUtils.h"

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

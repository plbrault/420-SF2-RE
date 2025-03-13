#include <string>
#include <vector>
#include "Element.h"

std::vector<std::string> split(const std::string& str, char delimiter);

std::vector<Element> parseElements(const std::string& filename);

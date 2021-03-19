
#pragma conce
#include <rapidjson/document.h>

class FileUtility{
public:
  // Loads a JSON file into a RapidJSON document
  static bool LoadJSON(const std::string& fileName, rapidjson::Document& outDoc);
};
#include "TextResource.h"
#include "FileUtility.h"

TextResource::TextResource() {}

TextResource::~TextResource() {}

void TextResource::LoadText(const std::string &fileName) {
  // Clear the existing map, if already loaded
  mText.clear();

  rapidjson::Document doc;
  if (!FileUtility::LoadJSON(fileName, doc)) {
    printf("Failed to load text resource file %s", fileName.c_str());
    return;
  }

  // Parse the text map
  const rapidjson::Value &actions = doc["TextMap"];
  for (rapidjson::Value::ConstMemberIterator itr = actions.MemberBegin();
       itr != actions.MemberEnd(); ++itr) {
    if (itr->name.IsString() && itr->value.IsString()) {
      mText.emplace(itr->name.GetString(), itr->value.GetString());
    }
  }
}

const std::string &TextResource::GetText(const std::string &key) {
  static std::string errorMsg("**KEY NOT FOUND**");
  // Find this text in the map, if it exists
  auto iter = mText.find(key);
  if (iter != mText.end()) {
    return iter->second;
  } else {
    return errorMsg;
  }
}
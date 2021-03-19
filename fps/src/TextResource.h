#pragma conce

#include <string>
#include <unordered_map>

class TextResource {
public:
  TextResource();
  ~TextResource();

  void LoadText(const std::string& fileName);
	const std::string& GetText(const std::string& key);

private:
  std::string mFileName;
  	// Map for text localization
	std::unordered_map<std::string, std::string> mText;
};

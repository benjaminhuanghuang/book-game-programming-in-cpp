#include "FileUtility.h"
#include <vector>
#include <fstream>

bool FileUtility::LoadJSON(const std::string& fileName, rapidjson::Document& outDoc)
{
	// Load the file from disk into an ifstream in binary mode,
	// loaded with stream buffer at the end (ate)
	std::ifstream file(fileName, std::ios::in | std::ios::binary | std::ios::ate);
	if (!file.is_open())
	{
		return false;
	}

	// Get the current position in stream buffer, which is size of file
	std::ifstream::pos_type fileSize = file.tellg();
	// Seek back to start of file
	file.seekg(0, std::ios::beg);

	// Create a vector of size + 1 (for null terminator)
	std::vector<char> bytes(static_cast<size_t>(fileSize) + 1);
	// Read in bytes into vector
	file.read(bytes.data(), static_cast<size_t>(fileSize));

	// Load raw data into RapidJSON document
	outDoc.Parse(bytes.data());

	if (!outDoc.IsObject())
	{
		return false;
	}

	return true;
}
#include "string_utils.h"

static std::string	readFileIntoString(std::ifstream &file)
{
	std::string	nextLine;
	std::string	ret;

	while (std::getline(file, nextLine))
	{
		ret += nextLine + "\n";
	}
	ret.pop_back();
	return (ret);
}
	
std::string	fileToString(std::string &fileName)
{
	std::ifstream	file(fileName.c_str(), std::ifstream::in);
	std::string	ret;
	
	if (!file.is_open())
	{
		std::cerr << "Couldn't open " << fileName << "." << std::endl;
		return ("");
	}
	ret = readFileIntoString(file);
	file.close();
	return  (ret);
}

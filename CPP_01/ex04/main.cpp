#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[])
{
	size_t				pos = 0;
	std::stringstream	buffer;
	std::string			text;
	std::string 		filename_replace;
	if (argc != 4){
		std::cout << "Rules: <filename> <str1> <str2>" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string filename = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];

	std::ifstream in_file(filename.c_str());
	if (!in_file.is_open()){
		std::cerr << "File not found" << std::endl;
		return (EXIT_FAILURE);
	}
	buffer << in_file.rdbuf();
	in_file.close();
	text = buffer.str();
	pos = text.find(str1, pos);
	if (pos == std::string::npos){
		std::cout << "No matches of <str1> founded in the file" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream out_file((filename + ".replace").c_str());
	if (!out_file.is_open()){
		std::cerr << "Error opening new file" << std::endl;
		return (EXIT_FAILURE);
	}
	while(pos != std::string::npos){
		text.erase(pos, str1.length());
		text.insert(pos, str2);
		pos = text.find(str1, pos + 1);
	}
	out_file << text;
	out_file.close();

	return (EXIT_SUCCESS);
}

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
	std::string line;

	if (argc != 4)
	{
		std::cout << "[Err] Need 3 Argument" << std::endl;
		return (0);
	}
	for (int i = 1; i < 4; i++)
	{
		if (argv[i] == NULL)
		{
			std::cout << "[Err] empty Argument" << std::endl;
			return (0);
		}
	}
	std::string file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string replace_name = file_name + ".replace";
	std::ifstream fin(file_name);
	if (fin.fail())
	{
		std::cout << "[Err] fail open" << std::endl;
		return (1);
	}
	std::ofstream fout(replace_name);
	if (fout.fail())
	{
		std::cout << "[Err] fail create" << std::endl;
		return (1);
	}
	while (getline(fin, line))
	{
		int	index;
		while (line.find(s1) != std::string::npos)
		{
			index = line.find(s1);
			line.erase(index, s1.length());
			line.insert(index, s2);
		}
		fout << line << '\n';

	}
	fin.close();
	fout.close();
	return (0);
}
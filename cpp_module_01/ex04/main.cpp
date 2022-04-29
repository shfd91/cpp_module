#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
	std::string line;

	if (argc != 4)
	{
		std::cout << "[Err] Need 3 Argument" << std::endl;
		std::cout << "./main [ file name ] [ sentence ] [ sentence to change ]" << std::endl;
		return (0);
	}
	std::string file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (file_name.empty() || s1.empty())
	{
		std::cout << "[Err] empty Argument" << std::endl;
		return (0);
	}
	if (!(s1.compare(s2)))
	{
		std::cout << "[Err] s1 and s2 are the same." << std::endl;
		return (0);
	}
	std::ifstream fin(file_name, std::ios_base::in);
	if (!fin.is_open())
	{
		std::cout << "[Err] open readfile " << std::endl;
		return (-1);
	}
	std::string replace_name = file_name.append(".replace");
	std::ofstream fout(replace_name, std::ios_base::out);
	if (!fout.is_open())
	{
		std::cout << "[Err] open writefile" << std::endl;
		return (-1);
	}
	while (getline(fin, line))
	{
		int	index = 0;
		int	i = 0;
		while (index != -1)
		{
			index = line.find(s1, i);
			if (index == -1)
				break ;
			line.erase(index, s1.length());
			line.insert(index, s2);
			i += (index + s2.length());
		}
		fout << line + '\n';
	}
	fin.close();
	fout.close();
	return (0);
}
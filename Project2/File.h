#include <iostream>

using namespace std;


class File
{
public:
	int get_size()
	{
		return Size;
	}
	int set_size(int size)
	{
		Size = size;
		return size;
	}
	string get_name()
	{
		return Name;
	}
	string set_name(string name)
	{
		Name = name;
		return name;
	}
	File();
	~File();

private:
	int Size;
	string Name;
};

File::File()
{
}

File::~File()
{
}

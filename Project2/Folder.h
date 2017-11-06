#include <iostream>


using namespace std;

class Folder
{
public:
	int get_size()
	{
		//this calculate all the tree contents below current folder node.
		return Size;
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

	Folder();
	~Folder();

private:
	string Name;
	int Size;
};

Folder::Folder()
{
}

Folder::~Folder()
{
}

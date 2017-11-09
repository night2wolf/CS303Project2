#include <iostream>
// #include "File.h"

using namespace std;
list<File> File_list;
class Folder
{
public:
	int get_size()
	{
		int folder_size = Size;
		// If there are no files, the folder is empty and has a size of 0
		if (file_list.size() == 0)
		{
			folder_size = 0;
		}
		else
		{
			list<File>::iterator itr;
			for (itr = file_list.begin(); itr != file_list.end(); itr++)
			{
				File current_file = *itr;
				folder_size += current_file.get_size();
			}
		}
		return folder_size;
	}
	void set_size(int size)
	{
		Size = size;
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
	void add_file(string name, int size)
	{
		
		File new_file;
		new_file.set_name(name);
		new_file.set_size(size);
		file_list.push_back(new_file);
		
	}
	list<File> get_file_list()
	{
		return file_list;
	}
	File find_file(string file_name)
	{
		File target_file;
		target_file.set_name(" ");
		list<File>::iterator itr;
		for (itr = file_list.begin(); itr != file_list.end(); itr++)
		{
			if( itr->get_name() == file_name)
			{
				target_file = *itr;
				break;
			}			
		}
		if(target_file.get_name() == " ")
		{
			// Should throw some kind of not found exception here.
			return target_file;
		}
		return target_file;
	}
	void delete_file(string file_name)
	{
		list<File>::iterator itr;
		for (itr = file_list.begin(); itr != file_list.end(); itr++)
		{
			if (itr->get_name() == file_name)
			{
				file_list.erase((itr));				
			}
		}
	}

	Folder();
	 ~Folder();

private:
	string Name;
	int Size;
	list<File> file_list;
};

Folder::Folder()
{
}

Folder::~Folder()
{
}


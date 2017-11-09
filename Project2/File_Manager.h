
#include "File.h"
#include <iostream>
#include <list>
#include "String_Tokenizer.h"
#include "Binary_Search_Tree.h"
// This class is probably unnecessary but now i am too scared to remove it.
#include "Binary_Tree.h"
#include "Folder.h"
using namespace std;
// Binary_Tree<Folder> folder_tree;
Binary_Search_Tree<string> folder_search_tree;
list<Folder> folder_list;

// TODO: Searching tree logic Create Seperate function for parsing and finding the folder in the tree.. will have to pass in the tree...
class File_manager
{
public:

	bool Search_tree(Binary_Search_Tree<string> tree, string path)
	{

		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			if (tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path";
				return false;
			}

		}
		// Fall here if entire path found
		return true;

	}


	void add_folder(string path, string folder_name)
	{
		Folder folder;
		folder.set_name(folder_name);
		folder.set_size(folder.get_size());
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.		
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path";
				return;
			}
		}
		// If we find the path. insert		
		folder_search_tree.insert(folder_name);
		folder_list.push_back(folder);
		return;
	}

	// This wasn't a requested function but a requested output. putting it here.
	void get_folder_size(string path, string folder_name)
	{

		int total_size;
		Folder folder;
		folder.set_name(folder_name);
		// folder.get_size();
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path";
				return;
			}
			//find each folder in path and add size.
			list<Folder>::iterator itr;
			for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
			{
				Folder current_folder = *itr;
				total_size += current_folder.get_size();
			}
		}
		//once we have all the folders we can set total size
		folder.set_size(total_size);
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			Folder current_folder = *itr;
			if (current_folder.get_name() == folder_name)
			{
				folder_list.erase((itr));
			}
		}
		folder_list.push_back(folder);

	}
	void delete_folder(string path, string folder_name)
	{

		Folder folder;
		folder.set_name(folder_name);
		// folder.get_size();
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path";
				return;
			}
			//find each folder and remove them.
			list<Folder>::iterator itr;
			for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
			{
				if (itr->get_name() == current_path)
				{
					folder_list.erase((itr));
				}

			}
		}
		//once we have removed all folders we can remove the folder from list as well.	
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			if (itr->get_name() == folder_name)
			{
				folder_list.erase((itr));
			}
		}
		//Remove folder from tree.
		folder_search_tree.erase(folder_name);

		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		//Folder destination_folder;
		//folder_search_tree.find(destination_folder.get_name());
		//folder_search_tree.erase(destination_folder.get_name());

	}
	void add_file(string path, string file_name, int size)
	{
		string last_path;
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			last_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path";
				return;
			}
			//find each folder and remove them.


		}
		// Last token in path will be the folder we are looking to add a file in.
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			if (itr->get_name() == last_path)
			{
				itr->add_file(file_name, size);
			}

		}
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		//Folder destination_folder;
		//folder_search_tree.find(destination_folder.get_name());
		//destination_folder.add_file(file_name, size);

	}
	void delete_file(string path, string file_name)
	{
		string last_path;
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			last_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path";
				return;
			}
		}
		// Last token in path will be the folder we are looking to add a file in.
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			if (itr->get_name() == last_path)
			{
				itr->delete_file(file_name);
			}
		}
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		//Folder destination_folder;
		//folder_search_tree.find(destination_folder.get_name());
	}

	File get_file(string path, string file_name)
	{
		File file_target;
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;
		//folder_search_tree.find(destination_folder.get_name());
		//file_target = destination_folder.find_file(file_name);
		return file_target;
	}

	list<File> get_files(string path, string file_name)
	{
		string last_path;
		list<File> file_list;
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			last_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path";
				return file_list;
			}
		}
		// Last token in path will be the folder we are looking to add a file in.
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			if (itr->get_name() == last_path)
			{

				file_list.push_back(itr->find_file(file_name));

			}
		}
		return file_list;
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.

	}







	File_manager();
	~File_manager();


private:

};

File_manager ::File_manager ()
{
}

File_manager ::~File_manager ()
{
}


#include "File.h"
#include <list>
#include "String_Tokenizer.h"
#include "Binary_Search_Tree.h"
#include "Folder.h"
using namespace std;
// Binary_Tree<Folder> folder_tree;
Binary_Search_Tree<string> folder_search_tree;
list<Folder> folder_list;


class File_manager
{
public:
	// Print entire tree to a string
	void print_tree()
	{
		folder_search_tree.to_string();
	}
	// Returns true if path is found false if not
	bool Search_tree(Binary_Search_Tree<string> tree, string path)
	{

		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			if (tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path"<<endl;
				return false;
			}

		}
		// Fall here if entire path found
		return true;
	}
	// Add a Folder to the Folder tree
	void add_folder(string path, string folder_name)
	{
		Folder folder;
		folder.set_name(folder_name);
		folder.set_size(folder.get_size());
		// If empty tree, just add the folder.	
		if(folder_search_tree.is_null())
		{
			folder_search_tree.insert(folder_name);
			folder_list.push_back(folder);
			return;
		}
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path" << endl;
				return;
			}
		}
		// If we find the path. insert		
		folder_search_tree.insert(folder_name);
		folder_list.push_back(folder);
		return;
	}

	// Calculate a folder's entire size
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
				cout << "Cannot find with given path" << endl;
				return;
			}
			//find each folder in path and add size.
			list<Folder>::iterator itr;
			for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
			{
				total_size += itr->get_size();
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
				folder.set_size(total_size + itr->get_size());
				folder_list.erase((itr));
				folder_list.push_back(folder);
				return;
			}
		}
		
	}

	//Delete Folder from tree and list
	void delete_folder(string path, string folder_name)
	{
		// Come back to this. might be removing the wrong folders...
		Folder folder;
		folder.set_name(folder_name);		
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path"<<endl;
				return;
			}
			//find each folder and remove them from the folder list.
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
		// Once we get here we have removed all lower folders from list.Remove folder from tree.
		folder_search_tree.erase(folder_name);

	}
	//Find a destination folder and add a file inside it using a list.
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
				cout << "Cannot find with given path"<<endl;
				return;
			}
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
	}
	// Find a desired file in a folder path and delete it
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
				cout << "Cannot find with given path"<<endl;
				return;
			}
		}
		// Last token in path will be the folder we are looking to delete a file from.
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			if (itr->get_name() == last_path)
			{
				itr->delete_file(file_name);
			}
		}
	}
	// Find a desired file and return it
	File get_file(string path, string file_name)
	{
		string last_path;
		File file;
		string_tokenizer tokenizer(path, "/");
		while (tokenizer.has_more_tokens())
		{
			string current_path = tokenizer.next_token();
			last_path = tokenizer.next_token();
			if (folder_search_tree.find(current_path) == NULL)
			{
				cout << "Cannot find with given path"<<endl;
				return file;
			}
		}
		// Last token in path will be the folder we are looking for the file in.
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			if (itr->get_name() == last_path)
			{
				file = (itr->find_file(file_name));
			}
		}
		return file;
	}
	// Find all files with a file name in a desired path
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
				cout << "Cannot find with given path"<<endl;
				return file_list;
			}
		}
		// Last token in path will be the folder we are looking for all files in.
		list<Folder>::iterator itr;
		for (itr = folder_list.begin(); itr != folder_list.end(); itr++)
		{
			if (itr->get_name() == last_path)
			{
				file_list.push_back(itr->find_file(file_name));
			}
		}
		return file_list;
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

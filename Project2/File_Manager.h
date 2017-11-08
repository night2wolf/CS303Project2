
#include "File.h"
#include <iostream>
#include <list>
#include "String_Tokenizer.h"
#include "Binary_Search_Tree.h"
#include "Binary_Tree.h"
#include "Folder.h"
using namespace std;
// Binary_Tree<Folder> folder_tree;
Binary_Search_Tree<string> folder_search_tree;
// string_tokenizer tokenizer = "/";
// TODO: Searching tree logic
class File_manager 
{
public:
	void add_folder(string path, string folder_name)
	{
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;		
		folder_search_tree.find(destination_folder.get_name());
		folder_search_tree.insert(destination_folder.get_name());
	}
	// This wasn't a requested function but a requested output. putting it here.
	void get_folder_size(string path, string folder_name)
	{
		int total_folder_size;
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;
		folder_search_tree.find(destination_folder.get_name());
		// TODO: parse every tree node underneath destination folder and get size and add to total.
		total_folder_size += destination_folder.get_size();

	}
	void delete_folder(string path, string folder_name)
	{		
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;
		folder_search_tree.find(destination_folder.get_name());
		folder_search_tree.erase(destination_folder.get_name());

	}
	void add_file(string path, string file_name, int size)
	{
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;
		folder_search_tree.find(destination_folder.get_name());
		destination_folder.add_file(file_name, size);

	}
	void delete_file(string path, string file_name)
	{
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;
		folder_search_tree.find(destination_folder.get_name());
	}
	File get_file(string path, string file_name)
	{
		File file_target;
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;
		folder_search_tree.find(destination_folder.get_name());
		return file_target;
	}
	list<File> get_files(string path, string file_name)
	{
		// TODO: Tokenize Path and pass it as the destination folder name. Parse tree and search for folder.
		Folder destination_folder;
		list<File> file_list =  destination_folder.get_file_list();
		return file_list;
	}

	File_manager ();
	~File_manager ();

private:

};

File_manager ::File_manager ()
{
}

File_manager ::~File_manager ()
{
}

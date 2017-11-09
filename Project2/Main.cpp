#include <iostream>
#include "File_Manager.h"
using namespace std;




int main()
{
	File_manager files;
	files.add_folder("path1", "folder1");
	files.print_tree();
	files.add_file("folder1", "file1", 5);
	files.get_files("folder1", "file1");
	files.get_file("folder1", "file1");
	files.delete_file("folder1", "file1");
	files.delete_folder("folder1", "folder1");


	return 0;
}
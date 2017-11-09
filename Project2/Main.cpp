#include <iostream>
#include "File_Manager.h"
using namespace std;




int main()
{
	File_manager files;
	files.add_folder("path1", "folder1");
	files.add_file("path1", "file1", 5);
	files.delete_file("path1", "file1");
	files.delete_folder("path1", "folder1");
	files.get_files("path1", "file1");	
	files.get_file("string", "str");

	return 0;
}
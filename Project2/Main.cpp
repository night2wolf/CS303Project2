#include <iostream>
#include "File_Manager.h"
using namespace std;




int main()
{
	File_manager system_files;

	// Test Functions \/
	system_files.add_file("blah/blh", "bleh", 5);
	system_files.delete_file("blah/blh", "bleh");
	system_files.add_folder("blah", "blh");
	system_files.delete_folder("blah", "blh");
	system_files.get_file("blah","bleh");
	system_files.get_files("blah","bleh");
	return 0;
}
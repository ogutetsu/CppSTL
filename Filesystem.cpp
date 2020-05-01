#include <filesystem>
#include <iostream>
#include <fstream>
#include <functional>

using std::cout;
using std::endl;

 
#if _MSC_VER >= 1910 && _MSC_VER < 1920
//VisualStudio2017

namespace fs = std::filesystem;



void FilesystemLibSample()
{
	cout << "Current path: " << fs::current_path() << endl;

	std::string dir = "sandbox/a/b";
	fs::create_directories(dir);

	std::ofstream("sandbox/file.txt");


	cout << "fs::is_directory(dir): " << fs::is_directory(dir) << endl;

	for (auto& p : fs::recursive_directory_iterator("sandbox"))
	{
		cout << p.path() << endl;
	}


	fs::remove_all("sandbox");
}

void FilesystemPermission()
{
	std::function<void(fs::perms)> printPerms = [](fs::perms perm)
	{
		cout << ((perm & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
			<< ((perm & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
			<< ((perm & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
			<< ((perm & fs::perms::group_read) != fs::perms::none ? "r" : "-")
			<< ((perm & fs::perms::group_write) != fs::perms::none ? "w" : "-")
			<< ((perm & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
			<< ((perm & fs::perms::others_read) != fs::perms::none ? "r" : "-")
			<< ((perm & fs::perms::others_write) != fs::perms::none ? "w" : "-")
			<< ((perm & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
			<< endl;
	};

	std::ofstream("file.txt");

	cout << "permission: ";
	printPerms(fs::status("file.txt").permissions());


	fs::permissions("file.txt",
		fs::perms::owner_write | fs::perms::group_write,
		fs::perm_options::remove);
	cout << "Remove to owner_write | group_write : ";
	printPerms(fs::status("file.txt").permissions());



	fs::permissions("file.txt",
		fs::perms::owner_all | fs::perms::group_all);
	cout << "Adding to owner_all | group_all : ";
	printPerms(fs::status("file.txt").permissions());

	fs::remove("file.txt");
}


void FilesystemMain()
{

	FilesystemLibSample();

	FilesystemPermission();
	

}

#else

void FilesystemMain()
{
	cout << "Build FilesystemMain with VisualStudio2017" << endl;

}

#endif


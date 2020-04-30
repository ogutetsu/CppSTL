#include <filesystem>
#include <iostream>
#include <fstream>


using std::cout;
using std::endl;

 
#if _MSC_VER >= 1910 && _MSC_VER < 1920
//VisualStudio2017

namespace fs = std::filesystem;

void FilesystemMain()
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

#else

void FilesystemMain()
{
	cout << "Build FilesystemMain with VisualStudio2017" << endl;

}

#endif


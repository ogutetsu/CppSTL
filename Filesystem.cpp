#include <filesystem>
#include <iostream>


using std::cout;
using std::endl;

 
#if _MSC_VER >= 1910 && _MSC_VER < 1920
//VisualStudio2017

namespace fs = std::filesystem;

void FilesystemMain()
{
	cout << "Current path: " << fs::current_path() << endl;


	
}

#else

void FilesystemMain()
{
	cout << "Build FilesystemMain with VisualStudio2017" << endl;

}

#endif


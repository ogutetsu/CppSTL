#include <filesystem>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>

using std::cout;
using std::endl;

 
#if _MSC_VER >= 1910 && _MSC_VER < 1920
//VisualStudio2017

namespace fs = std::filesystem;

using namespace std::chrono_literals;


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

void FilesystemNonMemberSample()
{

	fs::path path = fs::current_path() / "file.txt";
	std::ofstream(path.c_str());
	auto t = fs::last_write_time(path);
	auto st = std::chrono::time_point_cast<std::chrono::system_clock::duration>(t - fs::file_time_type::clock::now() + std::chrono::system_clock::now());

	std::time_t cftime = std::chrono::system_clock::to_time_t(st);


	std::function<std::string(tm*)> Asctime = [](tm* t)
	{
		char timebuf[32];
		asctime_s(timebuf, _countof(timebuf), t);
		std::string s(timebuf);
		return s;
	};


	tm ltiume;
	localtime_s(&ltiume, &cftime);

	cout << "Write time on Server " << Asctime(&ltiume) << endl;


	gmtime_s(&ltiume, &cftime);

	cout << "Write time on Server " << Asctime(&ltiume) << endl;

	fs::last_write_time(path, t + 2h);
	t = fs::last_write_time(path);
	st = std::chrono::time_point_cast<std::chrono::system_clock::duration>(t - fs::file_time_type::clock::now() + std::chrono::system_clock::now());

	cftime = std::chrono::system_clock::to_time_t(st);
	localtime_s(&ltiume, &cftime);
	cout << "Local time on client " << Asctime(&ltiume) << endl;


	fs::space_info root = fs::space("/");
	cout << ".        Capacity         Free          Acailable" << endl
		<< "/     " << root.capacity << "   " << root.free << "    " << root.available << endl;


}


void FilesystemStatusSample()
{

	std::function<void(const fs::path&)> printStatus = [](const fs::path& path)
	{
		cout << path;
		if (!fs::exists(path)) cout << " does not exist" << endl;
		else
		{
			if (fs::is_block_file(path)) cout << " is a block file" << endl;
			if (fs::is_character_file(path)) cout << " is a character device" << endl;
			if (fs::is_directory(path)) cout << " is a directory" << endl;
			if (fs::is_fifo(path)) cout << " is a named pipe" << endl;
			if (fs::is_regular_file(path)) cout << " is a regular file" << endl;
			if (fs::is_socket(path)) cout << " is a socket" << endl;
			if (fs::is_symlink(path)) cout << " is a symlink" << endl;
		}
	};

	fs::create_directory("sandbox");
	printStatus("sandbox");

	std::ofstream("sandbox/regular.txt");
	printStatus("sandbox/regular.txt");

	//mkfifo("sandbox/namedPipe", 0644);
	//printStatus("sandbox/namedPipe");

	//fs::create_symlink("sandbox/regular.txt", "symlink");
	//printStatus("sandbox/regular.txt");

	printStatus("dummy.txt");

	fs::remove_all("sandbox");


}



void FilesystemMain()
{

	FilesystemLibSample();

	FilesystemPermission();

	FilesystemNonMemberSample();

	FilesystemStatusSample();
	
}

#else

void FilesystemMain()
{
	cout << "Build FilesystemMain with VisualStudio2017" << endl;

}

#endif


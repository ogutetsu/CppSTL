#include <iomanip>
#include <iostream>
#include <string>


using std::cout;
using std::endl;


void IOStreamInputSample()
{
	std::string line;
	cout << "Write a line: " << endl;

	std::getline(std::cin, line);
	cout << line << endl;

	cout << "Write numbers, separated by;" << endl;
	while(std::getline(std::cin, line, ';'))
	{
		cout << line << " ";
	}
}

void IOStreamFormatSample()
{
	int num{ 2020 };
	cout.setf(std::ios::hex, std::ios::basefield);
	cout << num << endl;
	cout.setf(std::ios::dec, std::ios::basefield);
	cout << num << endl;

	cout << std::hex << num << endl;
	cout << std::dec << num << endl;
	
	cout.fill('#');
	cout << -12345;
	cout << std::setw(10) << -12345 << endl;
	cout << std::setw(10) << std::left << -12345 << endl;
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;

	cout << "2020 -> std::oct : " << std::oct << 2020 << endl;
	cout << "2020 -> std::hex : " << std::hex << 2020 << endl;


	cout << "cout 123.456789 : " << 123.456789 << endl;

	cout << std::fixed;
	cout << " === std::fixed ===" << endl;
	cout << "std::setprecision(3) : " << std::setprecision(3) << 123.456789 << endl;
	cout << "std::setprecision(6) : " << std::setprecision(6) << 123.456789 << endl;
	cout << "std::setprecision(9) : " << std::setprecision(9) << 123.456789 << endl;

	cout << std::scientific;
	cout << " === std::scientific ===" << endl;
	cout << "std::setprecision(3) : " << std::setprecision(3) << 123.456789 << endl;
	cout << "std::setprecision(6) : " << std::setprecision(6) << 123.456789 << endl;
	cout << "std::setprecision(9) : " << std::setprecision(9) << 123.456789 << endl;

	cout << std::hexfloat;
	cout << " === std::hexfloat ===" << endl;
	cout << "std::setprecision(3) : " << std::setprecision(3) << 123.456789 << endl;
	cout << "std::setprecision(6) : " << std::setprecision(6) << 123.456789 << endl;
	cout << "std::setprecision(9) : " << std::setprecision(9) << 123.456789 << endl;
}

void IOStreamMain()
{
	//IOStreamInputSample();

	IOStreamFormatSample();
}


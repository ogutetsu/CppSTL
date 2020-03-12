#include <iostream>
#include <type_traits>


using std::cout;
using std::endl;


void PrimaryTypeSample()
{
	cout << "is_void<void> : " << std::is_void<void>::value << endl;
	cout << "is_integral<int> : " << std::is_integral<int>::value << endl;
	cout << "is_array<int []> : " << std::is_array<int[]>::value << endl;

	struct MemberObject
	{
		int val;
		int func(int) { return 2020; }
	};

	cout << "is_member_object_pointer<int MemberObject::*> : " << std::is_member_object_pointer<int MemberObject::*>::value << endl;
	cout << "is_member_function_pointer<int (MemberObject::*)(int)> : " << std::is_member_function_pointer<int (MemberObject::*)(int)>::value << endl;

	cout << "is_class<std::string> : " << std::is_class<std::string>::value << endl;
}

void ConstTypeSample()
{
	cout << "is_const<int> : " << std::is_const<int>::value << endl;
	cout << "is_const<const int> : " << std::is_const<const int>::value << endl;
	cout << "is_const<std::add_const<int>::type> : " << std::is_const<std::add_const<int>::type>::value << endl;

	typedef std::add_const<int>::type AddConstInt;
	cout << "is_const<std::remove_const<AddConstInt>::type> : " << std::is_const<std::remove_const<AddConstInt>::type>::value << endl;
}

void TypeMain()
{
	PrimaryTypeSample();


	ConstTypeSample();
	
	
}


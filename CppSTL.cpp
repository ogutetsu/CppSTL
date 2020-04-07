// CppSTL.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>


extern void UtilityMain();
extern void FunctionMain();
extern void TupleMain();
extern void SmartPtrMain();
extern void TypeMain();
extern void ContainerMain();
extern void VectorMain();
extern void DequeMain();
extern void ListMain();
extern void AssciativeContainerMain();
extern void StackMain();
extern void QueueMain();
extern void IteratorMain();
extern void FunctionObjectMain();
extern void ForEachMain();
extern void NonModifyMain();
extern void ModifyMain();
extern void PartitionMain();
extern void SortMain();
extern void BinarySearchMain();

int main()
{
	std::cout << " ==== Utility === " << std::endl;
	
    UtilityMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== Function === " << std::endl;

	FunctionMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== Tuple === " << std::endl;

	TupleMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== SmartPtr === " << std::endl;

	SmartPtrMain();
	std::cout << " ================ " << std::endl;



	std::cout << " ==== Type === " << std::endl;

	TypeMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== Container === " << std::endl;

	ContainerMain();

	std::cout << " ================ " << std::endl;



	std::cout << " ==== Vector === " << std::endl;

	VectorMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== Deque === " << std::endl;

	DequeMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== List === " << std::endl;

	ListMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== Associative Container === " << std::endl;

	AssciativeContainerMain();

	std::cout << " ================ " << std::endl;



	std::cout << " ==== Stack === " << std::endl;

	StackMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== Queue === " << std::endl;

	QueueMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== Iterator === " << std::endl;

	IteratorMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== FunctionObject === " << std::endl;

	FunctionObjectMain();

	std::cout << " ================ " << std::endl;


	std::cout << " ==== ForEach === " << std::endl;

	ForEachMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== NonModify === " << std::endl;

	NonModifyMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== Modify === " << std::endl;

	ModifyMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== Pertition === " << std::endl;

	PartitionMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== Sort === " << std::endl;

	SortMain();

	std::cout << " ================ " << std::endl;

	std::cout << " ==== BinarySearch === " << std::endl;

	BinarySearchMain();

	std::cout << " ================ " << std::endl;

	
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

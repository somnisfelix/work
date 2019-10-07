#pragma once
using namespace std;
class CAlgorithm
{
public: 
	void Main();
private:
	int GetGenerator(int number);
	int GetTargetNumCount(int number, int targetNum);
	float GetDiagonal(float fBase, float fHeight);
	void PrintSpiralArray1(int low, int line);
	void PrintSpiralArray2(int low, int line);
	int PowCount(int num);
	void Dojang1();
	void Dojang2();
	void Dojang3();
	void Dojang4();
	void Dojang5();
	void Dojang6();
	void StringCompress(string s);
	void Dojang3N_1(int num1, int num2);
	void SameNumber(int cnt);
	bool IsSameNumber(int num);
	void UglyNumbers(int cnt);
	bool IsUglyNumber(int num);
};
// PAT.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<list>
#include <iomanip> 
using namespace std;

class Polynomial {
public:
	Polynomial(int ordernumber=0, float number=0) {
		this->ordernumber = ordernumber;
		this->number = number;
	}  

	int ordernumber;
	float number;
};
int main()
{
	int a = 0;
	while (cin >> a)
	{

		Polynomial num1[10000];
		for (int num = 0; num < a; num++)
		{
			bool find = false;
			int k = 0;
			float n = 0;
			cin >> k;
			cin >> n;
			for (int num2 = 0; num2 < a; num2++)
			{
				if (num1[num2].ordernumber == k) {
					num1[num2].number += n;
					find = true;
				}//注意重复
			}
			if(!find)
			num1[num] = Polynomial(k, n);
		}
		int b = 0;
		cin >> b;
		for (int num = 0; num < b; num++)
		{
			bool find = false;
			int k = 0;
			float n = 0;
			cin >> k;
			cin >> n;
			for (int num2 = 0; num2 < a; num2++)
			{
				if (num1[num2].ordernumber == k) {
					num1[num2].number += n;
					find = true;
				}
			}
			if (!find)
				num1[a++] = Polynomial(k, n);


		}
		for (int num2 = 0; num2 < a; num2++)
			for (int num3 = num2; num3 < a; num3++) {
				if (num1[num2].ordernumber < num1[num3].ordernumber) {
					float k;
					int n;
					k = num1[num2].number;
					n = num1[num2].ordernumber;
					num1[num2].number = num1[num3].number;
					num1[num2].ordernumber = num1[num3].ordernumber;
					num1[num3].number = k;
					num1[num3].ordernumber = n;
				}
			}
		bool iszero = false;
		int minus = 0;
		for (int num2 = 0; num2 < a; num2++) {
			num1[num2 - minus] = num1[num2];
			if (num1[num2].number == 0)
				minus++;
		}//注意清楚为0的项数
		a -= minus;
		if (a == 0)
			cout << a<<endl;
		else
		cout << a << " ";
		for (int num2 = 0; num2 < a; num2++) {
			
			if (num2 != a - 1)
				cout << num1[num2].ordernumber << " " << fixed << setprecision(1) << num1[num2].number << " ";
			else
				cout << num1[num2].ordernumber << " " << fixed << setprecision(1) << num1[num2].number<<endl;
			//注意保留一位小数
		}
	}


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

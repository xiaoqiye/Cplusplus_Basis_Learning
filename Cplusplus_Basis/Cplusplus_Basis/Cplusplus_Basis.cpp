// Cplusplus_Basis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MySharedPtr.h"
#include "Sort.h"

int main()
{
    std::cout << "Hello World!\n";
    //可以检查编译系统对标准C库的支持情况
    std::cout << "Standard Clib: " << __STDC_HOSTED__ << std::endl;//Standard Clib: 1(指定编译器目标系统是否包含完整的C库)
    
    /*int N1 = 10;
    int* Nptr1 = &N1;
    CSharedPtr<int> SN1(Nptr1);
    std::cout << SN1.getRefCount() << std::endl;

    int N2 = 10;
    int* Nptr2 = &N2;
    CSharedPtr<int> SN2(Nptr2);
    std::cout << SN2.getRefCount() << std::endl;

    SN1 = SN2;
    std::cout << SN2.getRefCount() << std::endl;*/

    std::vector<int> Test = { 3,8,1,4,6,5,9,4 };
    CSortAlgorithm* Sort = new CSortAlgorithm();
    Sort->insertSortBasis(Test, 0);
    Sort->printEachElement(Test);

    Sort->insertSortBasis(Test, 1);
    Sort->printEachElement(Test);

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

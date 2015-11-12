#include <algorithm>
#include <numeric>

void readOnlyAlgorithm()
{
	// accumulate(第三个参数是和的初值)
	int sum = accumulate(vec.cbegin(), vec.cend(), 0);
}

int main()
{
	// find操作的是迭代器，因此find可以在任何容器中查找值
	// list<string> lst = ...
	string val = "a Value";
	auto result = find(lst.cbegin(), lst.cend(), val);

	// 用find在数组中查找值（指针就像内置数组的迭代器）
	int ia[] = {27, 210, 12, 47, 109, 83};
	int val2 = 83;
	// 使用标准库begin和end来获得指向ia的首元素和尾元素之后位置的指针
	int *result2 = find(begin(ia), end(ia), val);

	// 在序列的子范围查找
	auto result3 = find(ia + 1, ia + 4, val);
}
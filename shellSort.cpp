#include <iostream>
#include <vector>
using namespace std;
/*希尔排序*/
class shellSort {
private:
	vector<int> array;
	int length;

public:
	shellSort(vector<int> nums) :array(nums), length(nums.size()) {};
	void makeRoom(int i, int j, int s);
	void sort();
	void show();
};

void shellSort::sort()
{
	//将原始数组分成sp份
	int sp = length / 2;
	for (int s = sp; s >= 1; s /= 2)
	{
		cout <<"s: " << s << endl;
		//首先要跳过每份的第1个元素
		for (int i = s; i < length; i++)
		{
			//此处需要注意的是每次比较的步长为s
			for (int j = i - s; j >= 0; j-=s)
			{
				if (array[i] >= array[j])
				{
					//将索引i的元素填充到索引j+s,即元素j所属份的下一步的索引处
					makeRoom(j+s, i, s);
					break;//【注意：别忘了这个break】
				}
				else if(j==0)
					makeRoom(0, i ,s);
			}
		}
		show();
	}
}

//将索引为num的元素插入到索引index处
//记住，位移的步长为s
void shellSort::makeRoom(int index, int num, int s)
{
	int temp = array[num];
	if (num > index)
	{
		for (int i = num; i >= (index + s); i -= s)
		{
			array[i] = array[i - s];
		}
		array[index] = temp;
	}
}
//打印排序后的数组
void shellSort::show()
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}
//int main()
//{
//	vector<int> nums = { 0, 14, 9, 6, 13, 21, 7, 16,  33, 4, 5, 6, 10 };
//
//	shellSort temp(nums);
//	temp.show();
//	temp.sort();
//	temp.show();
//	cin.get();
//	return 0;
//}
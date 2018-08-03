#include<iostream>
#include<time.h>
#include<vector>
#include<random>
#include<algorithm>
#include<windows.h>
#include<stack>
using namespace std;
const int INF = 99999999;
//hash_map<int, int> mymap;
int mymap[100000000];
vector<int> number,number2;

void CreateRandom(int Rlength,int MAXsize)
{
	number2.resize(Rlength);
	int temp;
	random_device rd;
	default_random_engine el(rd());
	uniform_int_distribution<int>Rnum(1, MAXsize);
	for (int i = 0; i < Rlength; i++)
	{
		do {
			temp = Rnum(el);
		} while (mymap[temp] != 0);		
		mymap[temp] = INF;
		number.push_back(temp);	
	}
}
void QuickSort(vector<int> &number,int left,int right)  //快速排序 递归算法
{
	int i, j, temp;
	if (left > right)
	{
		return;
	}
	temp = number[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (number[j] >= temp&&i < j)
			j--;
		while (number[i] <= temp&&i < j)
			i++;
		if (i < j)
		{
			swap(number[i], number[j]);
		}
	}
	number[left] = number[i];
	number[i] = temp;
	QuickSort(number,left, i - 1);
	QuickSort(number,i + 1, right);
}
int partition(vector<int> &vec, int low, int high) {
	int pivot = vec[low];  //任选元素作为轴，这里选首元素
	while (low<high) {
		while (low<high && vec[high] >= pivot)
			high--;
		vec[low] = vec[high];
		while (low<high && vec[low] <= pivot)
			low++;
		vec[high] = vec[low];
	}
	//此时low==high
	vec[low] = pivot;
	return low;
}
int partition2(vector<int>&vec, int left, int right)
{
	int i, j, temp;
	temp = vec[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (vec[j] >= temp&&i < j)
			j--;
		while (vec[i] <= temp&&i < j)
			i++;
		if (i < j)
		{
			swap(vec[i], vec[j]);
		}
	}
	swap(vec[left], vec[i]);
	return i;

}

void quicksort2(vector<int> &vec, int low, int high) {
	stack<int> st;
	if (low<high) {
		int mid = partition(vec, low, high);
		if (low<mid - 1) {
			st.push(low);
			st.push(mid - 1);
		}
		if (mid + 1<high) {
			st.push(mid + 1);
			st.push(high);
		}
		//其实就是用栈保存每一个待排序子串的首尾元素下标，下一次while循环时取出这个范围，对这段子序列进行partition操作
		while (!st.empty()) {
			int q = st.top();
			st.pop();
			int p = st.top();
			st.pop();
			mid = partition(vec, p, q);
			if (p<mid - 1) {
				st.push(p);
				st.push(mid - 1);
			}
			if (mid + 1<q) {
				st.push(mid + 1);
				st.push(q);
			}
		}
	}
}
void MyquickSort(vector<int> &vec, int left, int right)
{
	if (left < right)
	{
		int mid = partition2(vec, left, right);
		MyquickSort(vec, left, mid - 1);
		MyquickSort(vec, mid + 1, right);
	}
}

void QuickNoR(vector<int>&vec, int left, int right)
{
	if (left >= right)
		return;
	stack<int>s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();
		if (left < right)
		{
			int mid = partition(vec, left, right);
			s.push(left);
			s.push(mid);
			s.push(mid + 1);
			s.push(right);
		}
	}
}


void BubbleSort(vector<int>&vec)
{
	for (int i = 0; i <vec.size()-1; i++)
	{
		for (int j = 0; j <vec.size()-1-i; j++)
		{
			if (vec[j] > vec[j+1])
			{
				swap(vec[j], vec[j + 1]);
			}
		}
	}

}
void InsertSort(vector<int>&vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; j--)
		{
			swap(vec[j], vec[j + 1]);
		}
	}
}

void ShellSort(vector<int>&vec)
{
	int len = vec.size();
	for (int gap = len / 2; gap >= 1; gap = gap / 2) {                    //拆分整个序列，元素间距为gap(也就是增量)
																		  //对子序列进行直接插入排序
		for (int i = gap; i < len; i++) {
			for (int j = i - gap; j >= 0 && vec[j] > vec[j + gap]; j = j - gap) {
				swap(vec[j], vec[j + gap]);
			}
		}

	}
}

void Merge1(vector<int>& r,vector<int> r1,int s,int m,int t)
{
	int i = s;
	int j = m + 1;
	int k = s;
	while (i <= m&&j <= t)
	{
		if (r[i] <= r[j])
			r1[k++] = r[i++];
		else
			r1[k++] = r[j++];			
	}
	if(i<=m)
		while (i <= m)
		{
			r1[k++] = r[i++];
		}
	else
		while (j <= t)
		{
			r1[k++] = r[j++];
		}
}

void Merge(vector<int>&arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	//int L[n1], R[n2];
	vector<int> L(n1), R(n2);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void Merge2(vector<int>&arr, int l, int m, int r)
{
	int lenL = m - l + 1;
	int lenR = r - m;
	vector<int> L(lenL), R(lenR);
	for (int i = 0; i < lenL; i++)
		L[i] = arr[i + l];
	for (int i = 0; i < lenR; i++)
		R[i] = arr[m + 1 + i];
	int i = 0, j = 0, k = 0;
	while (i<lenL&&j<lenR)
	{
		if (i < j&&L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < lenL)
	{
		arr[k++] = L[i++];
	}
	while (j < lenR)
	{
		arr[k++] = L[j++];
	}
}

void mergeSort(vector<int>&arr, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;
		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		Merge2(arr, l, m, r);
	}
}

//大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
//小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]  

int BinarySearch(vector<int>&vec, int value, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (vec[mid] == value)
			return mid;
		else if (vec[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}






int main()
{
	clock_t start,start2,process,process2;
	CreateRandom(100000,100000000);
	vector<int> temp(number);
	/*
	start = clock();
	sort(number.begin(), number.end());
	process = clock() - start;
	
	cout << (double)process / CLOCKS_PER_SEC << endl;
	*/
	//QuickNoR(temp, 0,99999);
	//quicksort2(temp, 0, 99999);
	//MyquickSort(temp, 0, 999999);
	//BubbleSort(temp);
	//InsertSort(temp);
	//ShellSort(temp);
	start2 = clock();
	//mergeSort(temp,0,99999);
	sort(temp.begin(), temp.end());
	process2 = clock() - start2;
	for (int i = 0; i < 1000; i++)cout << temp[i] << " ";
	int findnumber;
	cin >> findnumber;
	
	cout << BinarySearch(temp,findnumber, 9999);
	cout << endl;
	cout << (double)process2 / CLOCKS_PER_SEC << endl;
}

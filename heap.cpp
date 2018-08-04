#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class heap
{
	private: 
		vector<int> arr;
	public:
	int parent(int i)
	{
		return (i-1)/2;
	}
	
	int left(int i)
	{
		return 2*i+1;
	}
	
	int right(int i)
	{
		return 2*i+2;
	}
	
	void MinHeapify(int idx)
	{
		int l = left(idx);
		int r = right(idx);
		
		int smallest = idx;

		if(l < arr.size() && arr[l] < arr[idx])
		{
			smallest = l;
		}
		if(r < arr.size() && arr[r] < arr[smallest])
		{
			smallest = r;
		}
		if(smallest != idx)
		{
			swap(&arr[idx],&arr[smallest]);
			MinHeapify(smallest);
		}
	}

	
	int extractMin()
	{
		if(arr.size() == 0) return INT_MAX;
		int val = arr[0];
		arr[0] = arr[arr.size()-1];
		arr.pop_back();
		MinHeapify(0);
		return val;
	}
	void decreaseKey(int i, int new_val)
	{
		arr[i] = new_val;
		while(i != 0 && arr[parent(i)] > arr[i])
		{
			swap(&arr[parent(i)],&arr[i]);
			i = parent(i);
		}
	}
	int getMin()
	{
		if(arr.size() == 0) return INT_MAX;
		return arr[0]; 
	}

	void insert(int k)
	{
		int i=arr.size();
		arr.push_back(k);
		while(i!=0 && arr[parent(i)] > arr[i])
		{
			swap(&arr[i],&arr[parent(i)]);
			i = parent(i);
		}
	}
};

int main()
{
	heap h;
	int nops;
	cin>>nops;
	while(nops--)
	{	
		cout << "\n\nChoose the operation (1/2/3/4):\n";
		cout <<"1. Insert\n";
		cout <<"2. Get Min\n";
		cout <<"3. Decrease Key\n";
		cout <<"4. Delete Min\n\n";
		
		int c;
		cin >> c;
		int val = 0;
		int i, newval;
		switch(c)
		{
			case 1: cout <<"\nEnter the value: "; cin >> val; h.insert(val); break;
			case 2: cout <<"\nThe minimum in heap is : "<<h.getMin()<<"\n"; break;
			case 3: cout <<"\nEnter index and new value: "; cin>>i>>newval; h.decreaseKey(i,newval); break;
			case 4: cout <<"\nThe Deleted value is: "<<h.extractMin()<<"\n"; break;	
			default : cout <<"\nInvalid option, choose again!";	
		}
	}
}

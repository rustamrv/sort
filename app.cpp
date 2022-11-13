#include <iostream>
#include <cstdlib>

const int size = 100;

int *generateArray();
int binarySearch(int *arr, int item);
int findSmallest(int *arr);
void selectionSort(int *arr);
void printArray(int *arr);

int main()
{ 
	int *arr = generateArray();

	int item = arr[rand() % 10];

	std::cout << "Init array" << '\n';

	printArray(arr);

	selectionSort(arr); 

	std::cout << "Selection sort" << '\n';

	printArray(arr);

	int findItem = binarySearch(arr, item);

	if (findItem == -1) {
		std::cout << "Not found " << item << " in array " << '\n';
	}
	else {
		std::cout << "Item " << item << " found: " << findItem << '\n';
	}

	delete[] arr;
}

int *generateArray()
{ 
	srand(time(0));

    int *array = new int[size];

	for (int i = 0; i < size; i++)
	{ 
		array[i] = rand() % 100;
	} 

	return array;
}

int findSmallest(int* arr)
{
	int smallest = arr[0];
	int smallestIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			smallestIndex = i;
		}
	}
	return smallestIndex;
}

void selectionSort(int *arr)
{ 
	for (int i = 0; i < size; i++)
	{  
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) { 
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	} 
}

int binarySearch(int *arr, int item)
{
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		int mid = low + high;
		int guess = arr[mid];
		if (guess == item)
		{
			return mid;
		}
		else if (guess > item)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;

}

void printArray(int *arr)
{ 
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

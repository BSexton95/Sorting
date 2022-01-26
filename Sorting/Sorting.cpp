#include <iostream>
#include "DynamicArray.h"

template <typename T>
void bubbleSort(T array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//instead do j = i + 1
		for (int j = 0; j < size; j++)
		{
			T tempslot = array[i];

			if (array[i] < array[j])
			{
				array[i] = array[j];
				array[j] = tempslot;
			}
		}
	}

	/*for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << std::endl;
	}*/
}

/// <summary>
/// Prints out array to console
/// </summary>
template <typename T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

/// <summary>
/// Collection = []
/// j = 0
/// key = 0
/// for each index in collection
/// set key to be the value at the current index
/// set j to be the previous index
/// start while loop
/// while j is greater than or equal to 0 and the value at j is greater than key
/// set collection at the index of j + 1 to be the value at index of j
/// decrement
/// end while loop
/// set collection at the index of j + 1 to be the key
/// </summary>
/// <param name="array"></param>
/// <param name="size"></param>
void insertionSort(int array[], int size)
{
	int j = 0;
	int key = 0;

	//Iterate through the array
	for (int i = 1; i < size; i++)
	{
		//Store the current value of the current index
		key = array[i];

		//Set j to be the previous index
		j = i - 1;

		//While j hasn't reached the end of the list
		//and the value at the index of j is greater than the key...
		while (j >= 0 && array[j] > key)
		{
			//...move each element in the array over by 1
			array[j + 1] = array[j];
			--j;
		}

		//Set the index after j to be the key
		array[j + 1] = key;
	}

	////Print out array to console
	//for (int i = 0; i < size; i++)
	//{
	//	std::cout << array[i] << std::endl;
	//}
}

void printDynamicArray(DynamicArray<int> arr)
{
	for (int i = 0; i < arr.getLength(); i++)
		std::cout << arr.getItem(i) << std::endl;
}

void main()
{
	//int array[] = { 10, 2, 3, 5, 4 };
	//float arrFloat[] = { 1.2f, .4f, 8.6f, -12.9f };
	//// bubbleSort(array, 5);
	//bubbleSort(arrFloat, 4);
	//printArray(arrFloat, 4);
	//insertionSort(array, 5);
	//printArray(array, 5);

	DynamicArray<int> arr = DynamicArray<int>();
	arr.addItem(10);
	arr.addItem(3);
	arr.addItem(5);
	arr.addItem(4);
	arr.addItem(7);
	arr.addItem(9);
	arr.addItem(2);

	arr.sortItems();
	printDynamicArray(arr);

	arr.removeItem(3);
	std::cout << std::endl;
	printDynamicArray(arr);
}

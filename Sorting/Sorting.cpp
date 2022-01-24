#include <iostream>

void bubbleSort(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		//instead do j = i + 1
		for (int j = 0; j < size; j++)
		{
			int tempslot = array[i];

			if (array[i] < array[j])
			{
				array[i] = array[j];
				array[j] = tempslot;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << std::endl;
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

	//Print out array to console
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << std::endl;
	}
}

void main()
{

	int array[] = { 10, 2, 3, 5, 4 };
	// bubbleSort(array, 5);

	insertionSort(array, 5);

}

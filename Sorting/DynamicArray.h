#pragma once
template <typename T>
class DynamicArray
{
public:
	DynamicArray() {};
	~DynamicArray() {};

	/// <summary>
	/// Adds an item to the end of the array
	/// </summary>
	/// <param name="item">The new item to add to the array</param>
	void addItem(T* item);

	/// <summary>
	/// Removes an item from the array
	/// </summary>
	/// <param name="item">The item to be removed from the array</param>
	/// <returns>False if the item is not in the array</returns>
	bool removeItem(T* item);

	/// <summary>
	/// Sorts the items in the array using insertion sort
	/// </summary>
	void sortItems();

	/// <summary>
	/// Gets an item from the array
	/// </summary>
	/// <param name="index">The index of the disired item</param>
	/// <returns>The actor found at the index or nullptr if the index was out of bounds</returns>
	T* getItem(int index);

	/// <summary>
	/// Gets the length of the array
	/// </summary>
	int getLength() { return m_length };
	
private:
	T** m_items;
	int m_length;
};

template<typename T>
void DynamicArray<T>::addItem(T* item)
{
	//Create a new array with a size one greater than our old arry
	T** appendedArray = new T * [m_length + 1];

	//Copy the values from the old array to the new array
	for (int i = 0; i < m_length; i++)
	{
		appendedArray[i] = m_items[i];
	}

	//Set the last value in the new array to be the actor we want to add
	appendedArray[m_length] = item;

	//Set old array to hold the values of the new array
	m_items = appendedArray;
	m_length++;
}

template<typename T>
bool DynamicArray<T>::removeItem(T* item)
{
	//Check to see if the actor was null
	if (!item || m_length <= 0)
		return false;

	bool itemRemoved = false;

	//Create a new array with a size one less than our old array
	T** newArray = new T * [m_length - 1];

	//Create variable to access tempArray index
	int j = 0;

	//Copy values from the old array to the new array
	for (int i = 0; i < m_length; i++)
	{
		if (item != m_items[i])
		{
			newArray[j] = m_items[i];
			j++
		}
		else
		{
			itemRemoved = true;
		}
	}

	//Set the old array to the new arry
	if (itemRemoved)
	{
		m_items = newArray;
		m_length--;
	}

	//Return whether or not the removal was successful
	return itemRemoved;
}

template<typename T>
void DynamicArray<T>::sortItems()
{
	int j = 0;
	int key = 0;

	//Iterate through the array
	for (int i = 1; i < m_length; i++)
	{
		//Store the current value of the current index
		key = m_items[i];

		//Set j to be the previous index
		j = i - 1;

		//While j hasn't reached the end of the list
		//and the value at the index of j is greater than the key...
		while (j >= 0 && m_items[j] > key)
		{
			//...move each element in the array over by 1
			m_items[j + 1] = m_items[j];
			--j;
		}

		//Set the index after j to be the key
		m_items[j + 1] = key;
	}

	////Print out array to console
	//for (int i = 0; i < m_length; i++)
	//{
	//	std::cout << m_items[i] << std::endl;
	//}
}

template<typename T>
inline T* DynamicArray<T>::getItem(int index)
{
	//Return false if the index is out of bounds
	if (index < 0 || index >= m_length)
		return nullptr;

	return m_items[index];
}

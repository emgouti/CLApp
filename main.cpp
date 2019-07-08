#include <iostream>
using namespace std;

void initalize(int from, const int &n, int *arr);
void printElement(int* arr, const int &numElem);
void addElement(int el, int *&arr, int &numElem, int &cap);
void expand(int *&arr, int &cap, const int &numElem);
void showSelection(int &choice, int *&arr, int &numElem, int &cap);
void rearrange(int *&arr, const int &numElem);
void shrink(int *&arr, int &numElem, int &cap);
void delElem(int el, int *&arr, int &numElem, int &cap);

int main()
{
	//array
	int cap = 2;
	int numElem = 0;
	int *arr = new int[cap];

	//menu
	int choice;
	initalize(0, cap, arr);
	showSelection(choice, arr, numElem, cap);

	while (choice != 5)
	{
		showSelection(choice, arr, numElem, cap);
	}

	delete[] arr;

	system("pause");
	return 0;
}


void showSelection(int &choice, int *&arr, int &numElem, int &cap)
{
	cout << endl;
	cout << "=========MENU=========" << endl;
	cout << "To select an item, enter: " << endl;
	cout << "1 to PRINT items in array" << endl;
	cout << "2 to ADD a number to array" << endl;
	cout << "3 to DELETE a number from array" << endl;
	cout << "4 to see current SIZE of array" << endl;
	cout << "5 to EXIT" << endl;
	cout << endl;

	cin >> choice;
	cout << "-------------------------------" << endl;
	cout << "You selected: " << choice << endl;

	int x;
	int y;

	switch (choice)
	{
	case 1:
		printElement(arr, numElem);
		break;

	case 2:
		cout << "Type a number, then press enter: " << endl;
		cin >> x;
		addElement(x, arr, numElem, cap);
		showSelection(choice, arr, numElem, cap);
		break;

	case 3:
		cout << endl;
		cout << "Type a number to delete, then press enter: " << endl;
		cin >> y;
		delElem(y, arr, numElem, cap);
		showSelection(choice, arr, numElem, cap);
		break;

	case 4:
		cout << "Current size of array is " << cap << endl;
		break;

	case 5:
		cout << "Quitting Program" << endl;
		break;

	default:
		cout << "Invalid selection." << endl;
		break;
	}

}


void rearrange(int *&arr, const int &numElem)
{
	int i, j, temp;
	for (i = 0; i < numElem; ++i)
	{
		for (j = 0; j < numElem - i -1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}
		}
	}
}


void expand(int *&arr, int &cap, const int &numElem)
{
	cap *= 2; // increases array
	int *tempArr = new int[cap]; // creates temp array
	for (int i = 0; i < numElem; ++i)
	{
		tempArr[i] = arr[i]; // copies 

	}
	delete[] arr; // deleted old array memory
	arr = tempArr; // point old arry pointer to new array location

	initalize(numElem, cap, arr);

	cout << "Size = " << cap << endl;

}



void addElement(int el, int *&arr, int &numElem, int &cap)
{

	if (numElem >= cap)
		expand(arr, cap, numElem);

	arr[numElem++] = el;

	cout << "Element Added: " << el << endl;


}

void printElement(int* arr, const int &numElem)
{
	rearrange(arr, numElem);
	cout << "Current array values: ";

	for (int i = 0; i < numElem; ++i)
		cout << arr[i] << " ";

	cout << endl;
}

void initalize(int from, const int &cap, int *arr)
{
	for (int i = from; i < cap; ++i)
	{
		arr[i] = 0;
	}
}

void shrink(int *&arr, int &numElem, int &cap)
{

	bool shrunk = false;

	int *tempPtr = nullptr;

	while (numElem < (cap / 2))
	{
		tempPtr = new int[cap / 2];

		for (int i = 0; i < numElem; i++)
		{
			tempPtr[i] = arr[i];
		}

		delete[] arr;
		arr = nullptr;

		arr = tempPtr;
		cap = cap / 2;
		shrunk = true;

		tempPtr = nullptr;
	}

	if (shrunk == true)
	{
		cout << "Array size Shrunk to: " << cap << endl << endl;
	}
}

void delElem(int el, int *&arr, int &numElem, int &cap)
{

	bool Found = false;

	if (numElem != 0)
	{
		for (int i = 0; i < numElem; i++)
		{
			if (arr[i] == el)
			{
				Found = true;

				for (int j = i; j < numElem; j++)
				{
					arr[j] = arr[j + 1];
				}

				i = -1;
				numElem--;
			}
		}

		if (Found == false)
		{
			cout << "Error: " << el << " was not found in the array." << endl << endl;
		}
	}
	else
	{
		cout << "ERROR: There are no elements in the array to delete. " << endl << endl;
	}

	shrink(arr, numElem, cap);




}
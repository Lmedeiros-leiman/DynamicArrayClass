#include <iostream>
#include <string>

using namespace std;

void print(string OutputText) {
	std::cout << (OutputText) << endl;
}

class DynamicArray {
private:
	int capacity = 1;
	int contents = 0;
	int* array;

public:
	DynamicArray(int InitialCapacity = 0) 
	{
		capacity = InitialCapacity;
		array = new int[InitialCapacity];
		std::fill(array, array + InitialCapacity, 0);
	}
	~DynamicArray(){
		delete[] array;
	}

	int& operator[](int index) {
		if (index < 0 || index >= contents) {
			throw std::out_of_range("Index out of bounds");
		}
		return array[index];
	}

	DynamicArray& operator=(const DynamicArray& other) {
		print("aceitado.");
	}

	void grow(void) {
		capacity++;
		int* auxArray = new int[capacity];

		for (int i = 0; i < capacity; i++) {
			auxArray[i] = array[i];
		}

		for (int i = contents; i < capacity; i++) {
			auxArray[i] = 0;
		}

		delete[] array;
		array = auxArray;
		
		return;
	}

	//
	// add data
	//
	int append(int data) // adiciona um valor no final do array, retorna o tamanho do array.
	{
		
		if (contents >= capacity) {
			grow();
		}
		array[contents] = data;
		
		contents++;
		return contents;
	}

	int unshift(int data) // adiciona um valor no inicio do array, retorna o tamanho do array.
	{
		
		if (contents >= capacity) {
			grow();
		}

		int* auxArray = new int[capacity];
		auxArray[0] = data;
		for (int i = 0; i < contents; i++) {
			auxArray[i + 1] = array[i];
		}

		delete[] array;
		array = auxArray;

		contents++;
		return contents;
	}

	int insert(int data, int index) {
		if (index > capacity || index < 0) 
		{ 
			return -1; // invalid index 
		}

		if (contents >= capacity) {
			grow();
		}

		for (int i = contents; i > index; i--)
		{
			array[i] = array[i - 1];
		}
		array[index] = data;
		contents++;

		return contents;
	}
	//
	// remove data
	
	int clear_array() // clears the array, seting all entries to 0. 
	{ clearArray(); }
	int clearArray() // clear the array/ set all of its content to 0.
	{
		for (int i = 0; i < capacity; i++) {
			array[i] = 0;
		}
		contents = 0;

		return 0;
	}

	int resize_array() // resizes the array, making so that it only ocupies the ammount of data stored inside of it.
	{ return resizeArray(); }
	int resizeArray() // resizes the array, making so that it only ocupies the ammount of data stored inside of it.
	{
		if (contents < capacity) {
			capacity = contents;
			int* auxArray = new int[capacity];
			for (int i = 0; i < capacity; i++) {
				auxArray[i] = array[i];
			}
		
			delete[] array;
			array = auxArray;
		}
		return 0;
	}

	int shift() // removes the first element on the array, returns the removed element.
	{
		if (contents == 0) {
			return -1;
		}

		int* auxArray = new int[capacity];
		int deletedData = array[0];

		for (int i = 1; i < capacity; i++ )
		{
			auxArray[i - 1] = array[i];
		}
		auxArray[capacity - 1] = 0;
		delete[] array;
		array = auxArray;
		contents--;

		return deletedData;
	}

	int pop() {
		contents--;
		int deletedData = array[contents];
		array[contents] = 0;
		return deletedData;
	}

	int remove(int index) {
		int deletedData = array[index];
		
		// começa pelo index, move todos os itens para o inicio.

		for (int i = index; i < contents ; i++) {
			array[i] = array[i + 1];
		}
		array[contents - 1] = 0;
		contents--;
		return deletedData;
	}

	//
	// select data
	//

	//
	// retrieve data
	//
	string to_string(bool showNull = false) { return toString(showNull); } // retorna uma mascara em formato de string do array.
	string toString(bool showNull = false) // retorna uma mascara em formato de string do array.
	{
		string string = "";
		int limit = showNull ? capacity : contents;
		
		for (int i = 0; i < limit; i++) {
			if (i < contents) {
				string += std::to_string(array[i]) + ", ";
			}
			else {
				string += " NULL, ";
			}	
		}
		
		if (string != "") {
			string = "[" + string.substr(0, string.length() - 2) + "]";
		}
		else {
			string = "[]";
		}

		return string;
	}

	bool isEmpty() { return is_empty(); }
	bool is_empty() {
		return contents == 0;
	}
	
	int* clone() // cria um array novo e retorna o indicador de memória.
	{
		int* auxArray = new int[contents - 1];

		for (int i = 0; i < contents; i++) 
		{
			auxArray[i] = array[i];
		}

		return auxArray;
	}

	int parse(DynamicArray newArray) // recebe um array de outro array dinamico.
	{
		int sizeNewArray = newArray.size();



		return 0;
	}

	int parse(int* newArray[] = {}, int newArraySize = 0) // recebe um array e o torna o array do objeto.
	{
		return 0; // ainda não funciona e eu to com sono...
		if (array != nullptr) 
		{
			delete[] array;
		}

		array = newArray;

		for (int i = 0; i < newArraySize; i++)
		{
			array[i] = newArray[i];
		}

		capacity = newArraySize;
		contents = newArraySize;
		
		return 0;
	}

	int size(void) { return contents; }
	int length(void) { return contents; }
	
};


int main(void) {
	DynamicArray myArray(1);
	myArray[1] = 20;

	myArray.append(1);
	myArray.append(2);
	myArray.unshift(3);
	myArray.insert(4, 2);

	//int testArray[] = {1,2,3,4,5,6,7,8,9,10};
	//myArray.parse(testArray, 10);

	print(myArray.toString());
	print(myArray.toString(true));

	return 0;
}

//
// Lista para adicionar:
// //////////////////////
// 
//	- cortar a lista em 2;
//		- criar uma lista nova a partir de um index;
//		- somar duas listas em uma só
//		- método join do javascript, básicamente append em loop.
//
//		
//

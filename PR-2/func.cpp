#include "module.h"
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <windows.h>

using namespace std;
//-------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------Одномерный массив----------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------

//													   ___ _   _ _____ 
//													  |_ _| \ | |_   _|
//													   | ||  \| | | |  
//													   | || |\  | | |  
//													  |___|_| \_| |_|  

void RandValues(int* ARR, int size)
{

	random_device seed;
	mt19937 generator(seed());
	uniform_int_distribution<int> distribution(-100, 100);

	for (int i = 0; i < size; i++)
		ARR[i] = distribution(generator);

}

bool Range(int index, int start, int end)
{
	return (index >= start) && (index <= end);
}
int SumArr(int* arr, int size,int start, int end, bool(&pred)(int, int, int))
{
	int summ{ 0 };
	for (int i = 0; i < size; i++) 
		if ((*pred)(i, start, end)) summ += arr[i];
	return summ;
}
int MultArr(int* arr, int size, int start, int end, bool(&pred)(int, int, int)) 
{
	int mult{ 1 };
	for (int i = start; i < size; i++)
		if ((*pred)(i, start, end)) mult *= arr[i];
	return mult;
}

int PasteArr(int*& arr, int& size, int index, int value)
{
	size++;
	if (index < 0 || index > size) 
	{
		return -1; 
	}
	int* secArr = new int[size];
	int j{ 0 };
	for (int i = 0; i < index; i++)
	{
		secArr[i] = arr[j];
		j++;
	}
	secArr[index] = value;
	for (int i = index+1; i < size; i++)
	{
		secArr[i] = arr[j];
		j++;
	}
	delete[] arr;
	arr = secArr;
	return size; 
}
int DeleteArr(int*& arr, int& size, int index)
{
	if (index < 0 || index > size) 
	{
		return -1;
	}
	int* secArr = new int[size];
	int j = 0;

	for (int i = 0; i < size+1; i++) 
		if (i != index) 
		{
			secArr[j] = arr[i];
			j++;
		}
	delete[] arr;
	arr = secArr;
	size--;
	return size;
}

void BubbleSort(int*& arr, int size) 
{
	while (size--)
	{
		bool swapped = false;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}
void ChoiceSort(int*& arr, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		int smallPos = MinValArr(arr, i, size);
		swap(arr[i], arr[smallPos]);
	}
}
void PasteSort(int*& arr, int size) 
{
	for (int i = 1; i < size; i++) 
	{
		int j{ i - 1 };

		while (j >= 0 && arr[j] > arr[j + 1]) 
		{
			swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}

int MinValArr(int*& arr, int start, int size) 
{
	int smallPos = start;

	for (int i = start + 1; i < size; i++) 
	{
		if (arr[i] < arr[smallPos]) smallPos = i;
	}
	return smallPos;
}
int MaxValArr(int*& arr, int start, int size)
{
	int largePos = start;
	for (int i = start; i < size; i++) 
		if (arr[i] > arr[largePos]) largePos = i;
	return largePos;
}

int BinSerchArr(int*& arr, int size ,int value) 
{
	bool complete{ false };
	int left{ 0 };
	int right{ size - 1 };
	int mid;
	while ((left <= right) && (complete != true))
	{
		mid = (left + right) / 2;
		if (arr[mid] == value) complete = true;
		if (arr[mid] > value) right = mid - 1;
		if (arr[mid] < value) left = mid + 1;
	}
	if (complete == true) return mid;
	else return -1;
}

bool Positive(int value) 
{
	return value >= 0;
}
bool NIGGAtive(int value)
{
	return value < 0;
}
bool Zero(int value) 
{
	return value == 0;
}
bool MultF(int value, int factor) 
{

	return (value % factor) == 0;
}

int Count(int*& arr, int size, bool(*pred)(int))
{
	int count{ 0 };
	for (int i = 0; i < size; i++) 
		if ((*pred)(arr[i]))count++;
	return count;
}
int CountF(int*& arr, int size, int factor, bool(*pred)(int, int))
{
	int count{ 0 };
	for (int i = 0; i < size; i++) 
	{
		if ((*pred)(arr[i], factor))count++;
		return count;
	} 
	return 0;
}

void InputArr(int*& arr, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		cout << endl << i + 1 << "-й элемент массива: "; 
		cin >> arr[i];
	}
}
void InputFileArr(int*& arr, int size) 
{

	string line;
	int i{ 0 };
	ifstream file("input.txt");
	if (!file) cerr << "Не удалось открыть файл\n\n";

	while (getline(file, line, ';') && i < size)
	{
		if (i > size - 1) break;

		istringstream iss(line);
		int num;
		if (iss >> num) 
		{
			num = stoi(line);
			arr[i] = num;
			i++;
		}
	}
	file.close();
}

void ArrOut(int* arr, int size) 
{
	for (int i = 0; i < size; i++) cout << setw(12) << arr[i];
	cout << endl;
}
void ArrOutFile(int*& arr, int size)
{
	ofstream out_file("ching-chong.txt");
	if (out_file.is_open()) 
	{
		for (int i = 0; i < size; i++) 
			out_file << setw(10) <<arr[i];
		out_file.close();
		cout << "Массив записан в ching-chong.txt" << endl;
	}
	else cerr << "Неудалось открыть файл!!!";
}

void RegenARR(int*& arr, int size)
{
	RandValues(arr, size);
	cout << endl;
	ArrOut(arr, size);
}


//                                               _____ _     ___    _  _____ 
//                                              |  ___| |   / _ \  / \|_   _|
//                                              | |_  | |  | | | |/ _ \ | |  
//                                              |  _| | |__| |_| / ___ \| |  
//                                              |_|   |_____\___/_/   \_\_|  


void RandValues(float*& arr, int size)
{

	default_random_engine generator(time(0));
	uniform_real_distribution<float> distribution(-100.0, 100.0);

	for (int i = 0; i < size; i++) 
		arr[i] = distribution(generator);
	RoundArrValues(arr,size);
}
void RoundArrValues(float*& ARR, int size)
{
	for (int i = 0; i < size; i++) 
		ARR[i] = round(ARR[i] * 10000) / 10000;
}

float SumArr(int start, int end, float*& ARR, int size, bool (*pred)(int, int, int))
{
	float summ{ 0.0 };
	for (int i = start; i < size; i++)
		if ((*pred)(i, start, end)) summ += ARR[i];
	return summ;
}
float MultArr(int start, int end, float*& ARR, int size, bool(*pred)(int, int, int))
{
	float mult{ 1.0 };
	for (int i = start; i < size; i++)
		if ((*pred)(i, start, end))
			mult *= ARR[i];
	return mult;
}

int PasteArr(int& size, float*& arr, int index, float value)
{
	size++;
	if (index < 0 || index > size) 
	{
		return -1;
	}
	float* secArr = new float[size + 1];
	int j{ 0 };
	for (int i = 0; i < index; i++)
	{
		secArr[i] = arr[j];
		j++;
	}
	secArr[index] = value;
	for (int i = index + 1; i < size + 1; i++)
	{
		secArr[i] = arr[j];
		j++;
	}
	delete[] arr;
	arr = secArr;
	return 0;
}
int DeleteArr(int& size, float*& arr, int index) 
{
	float* secArr = new float[size - 1];
	int j = 0;

	for (int i = 0; i < size; i++) 
		if (i != index) 
		{
			secArr[j] = arr[i];
			j++;
		}
	size--;
	delete[] arr;
	arr = secArr;
	return 0;
}

void BubbleSort(float*& arr, int size) 
{
	while (size--)
	{
		bool swapped = false;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}
void ChoiceSort(float*& arr, int size){
	for (int i = 0; i < size; i++) 
	{
		int smallPos = MinValArr(i, arr, size);
		for (int j = i + 1; j < size; j++) 
			if (arr[j] < arr[smallPos])
				smallPos = j;
		swap(arr[i], arr[smallPos]);
	}
}
void PasteSort(float*& arr, int size)
{
	for (int i = 1; i < size; i++) 
	{
		int j{ i - 1 };
		while (j >= 0 && arr[j] > arr[j + 1]) 
		{
			swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}

int MaxValArr(int start, float*& arr, int lengthARR)
{
	int largePos = start;
	for (int i = start; i < lengthARR; i++) 
		if (arr[i] > arr[largePos]) largePos = i;
	return largePos;
}
int MinValArr(int start, float*& arr, int size)
{
	int smallPos = start;

	for (int i = start; i < size; i++)
		if (arr[i] < arr[smallPos]) smallPos = i;
	
	return smallPos;
}

int BinSerchArr(float*& arr,int size, float value)
{
	bool complete{ false };
	int left{ 0 };
	int right{ size - 1 };
	int mid;
	while ((left <= right) && (complete != true))
	{
		mid = (left + right) / 2;
		if (arr[mid] == value) complete = true;
		if (arr[mid] > value) right = mid - 1;
		if (arr[mid] < value) left = mid + 1;
	}
	if (complete == true) return mid;
	else return -1;
}

bool Positive(float value)
{
	return value >= 0;
}
bool NIGGAtive(float value)
{
	return value < 0;
}
bool Zero(float value)
{
	return value == 0;
}
bool MultF(float value, float factor)
{
	return fmod(value,factor) == 0;
}

int Count(bool(*pred)(float), float*& arr, int size)
{
	int count{ 0 };
	for (int i = 0; i < size; i++)
	{
		if ((*pred)(arr[i]))count++;
	}
	return count;
}
int CountF(float*& arr, int size, bool(*pred)(float, float), float factor) 
{
	int count{ 0 };
	for (int i = 0; i < size; i++) 
	{
		if ((*pred)(arr[i], factor))count++;
	}
	return count;
}

void InputArr(int size, float*& arr) 
{
	for (int i = 0; i < size; i++) 
	{
		cout << endl << i + 1 << "-й элемент массива: ";
		cin >> arr[i];
	}
}
void InputFileArr(int size, float*& arr) 
{
	string line;
	int i{ 0 };
	ifstream file("inputFLOAT.txt");
	if (!file) cerr << "Не удалось открыть файл\n\n";

	while (getline(file, line, ';') && i < size) 
	{
		if (i > size - 1)
			break;
		istringstream iss(line);
		float num;
		if (iss >> num) 
		{
			arr[i] = num;
			i++;
		}
	}
	file.close();
}
void ArrOut(float*& arr, int size)
{
	for (int i = 0; i < size; i++) cout << setw(12) << arr[i];
	cout << endl;
}
void ArrOutFile(float*& arr, int size)
{
	ofstream out_file("ching-chong.txt");
	if (out_file.is_open()) {
		for (int i = 0; i < size; i++) {
			out_file << setw(10) << arr[i];
		}
		out_file.close();
		cout << "Массив записан в ching-chong.txt" << endl;
	}
	else cerr << "Неудалось открыть файл!!!";
}

void RegenArr(float*& arr, int size) 
{
	RandValues(arr, size);
	cout << endl;
	ArrOut(arr,size);
}


//                                              ____   ___  _   _ _   _ ____  
//                                             | __ ) / _ \| \ | | | | / ___| 
//                                             |  _ \| | | |  \| | | | \___ \ 
//                                             | |_) | |_| | |\  | |_| |___) |
//                                             |____/ \___/|_| \_|\___/|____/ 
int MultEvenARR(int*& arr, int size) {
	int answ{ 1 };
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			answ *= arr[i];
		}
	}
	return answ;
}
int SumZero2Zero(int*& arr,int size) 
{
	int answ{ 0 };
	int indexFirstZero{ -1 };
	int indexLastZero{ -1 };
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] == 0) 
		{
			indexFirstZero = i;
			break;
		}
	}

	for (int i = 0; i < size; i++) 
		if (arr[i] == 0) indexLastZero = i;
	for (int i = indexFirstZero; i <= indexLastZero; i++) answ += arr[i];
	return answ;
}
void ConverARR(int*& arr, int size) {
	int* temp = new int[size];
	int indexPositive{ 0 };
	int indexNIGGAtive{ size };

	for (int i = 0; i < size; i++) {
		if (arr[i] >= 0) {
			temp[indexPositive] = arr[i];
			indexPositive++;
		}
		else {
			temp[indexNIGGAtive] = arr[i];
			indexNIGGAtive--;
		}
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}

}


//------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------Двумерный массив----------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
int** InputKeyboard(int** matrix, int countLines, int countColumns)
{
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			cout << "[" << line << "] " << "[" << column << "] ";
			cin >> matrix[line][column];
			cout << endl;
		}
	}
	return matrix;
}
int** InputRand(int** matrix, int countLines, int countColumns)
{
	random_device seed;
	mt19937 generator(seed());
	uniform_int_distribution<int> distribution(-100, 100);

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			matrix[line][column] = distribution(generator);
		}
	}
	return matrix;
}
int* InputRandVector(int* vector, int vectorLength)
{
	random_device seed;
	mt19937 generator(seed());
	uniform_int_distribution<int> distribution(-100, 100);

	for (int i = 0; i < vectorLength; i++)
	{
		vector[i] = distribution(generator);
	}
	return vector;
}


void OutputScreen(int** matrix, int countLines, int countColumns)
{
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			cout << setw(12) << matrix[line][column];
		}
		cout << endl;
	}
}
void OutVectorScreen(int* vector, int vectorSize) {
	for (int i = 0; i < vectorSize; i++)
		cout << setw(12) << vector[i];
	cout << endl;
}

int* Matrix2Vector(int** matrix, int newCountLines, int newCountCloums)
{
	int index{ 0 };
	int size{ newCountLines * newCountCloums };
	int* oneDimArr = new int[size];


	for (int line = 0; line < newCountLines; line++)
	{
		for (int column = 0; column < newCountCloums; column++)
		{
			oneDimArr[index] = matrix[line][column];
			index++;
		}
	}

	return oneDimArr;
}
int** Vector2Matrix(int* vector, int countLines, int countColumns, int vectorSize)
{
	int size(countLines * countColumns);
	int index(0);
	int line{ 0 };
	int column{ 0 };
	int** matrix{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		matrix[i] = new int[countColumns];
		memset(matrix[i], 0, sizeof(int) * countColumns);
	}
	for (int line = 0; line < countLines; line++) {
		for (int column = 0; column < countColumns; column++) {
			if (index >= vectorSize) {
				break;
			}
			matrix[line][column] = vector[index];
			index++;
		}
	}
	return matrix;
}


void SumMulLineMatrix(int** matrix, int line, int countColumns, int& sum, int& mult)
{
	sum = 0;
	mult = 1;
	for (int i = 0; i < countColumns; i++)
	{
		if (matrix[line][i] == 0)
		{
			continue;
		}
		sum += matrix[line][i];
		mult *= matrix[line][i];
	}
}
void SumMulColumnMatrix(int** matrix, int column, int countLines, int& sum, int& mult)
{
	sum = 0;
	mult = 1;
	for (int i = 0; i < countLines; i++)
	{
		if (matrix[i][column] == 0)
		{
			continue;
		}
		sum += matrix[i][column];
		mult *= matrix[i][column];
	}
}
void SumMulMainDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult)
{
	sum = 0;
	mult = 1;
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (line == column)
			{
				if (matrix[line][column] == 0)
				{
					continue;
				}
				sum += matrix[line][column];
				mult *= matrix[line][column];
			}
		}
	}

}
void SumMulSaidDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult)
{
	sum = 0;
	mult = 1;
	int line{ countLines - 1 };

	for (int column = 0; column < countColumns; column++)
	{
		if (line < 0)
		{
			break;
		}
		if (matrix[line][column] == 0)
		{
			continue;
		}
		sum += matrix[line][column];
		mult *= matrix[line][column];
		line--;
	}
}


string SearchLineMatrix(int** matrix, int line, int countColumns)
{
	int min{ matrix[0][0] };
	int max{ matrix[0][0] };
	int minC{ 0 };
	int maxC{ 0 };
	for (int i = 0; i < countColumns; i++)
	{
		if (matrix[line][i] == 0)
		{
			continue;
		}
		if (matrix[line][i] < min)
		{
			minC = i;
		}
		if (matrix[line][i] > max)
		{
			maxC = i;
		}
	}
	stringstream message;
	message << "Индекс минимального : [" << line << "][" << minC << "].\n";
	message << "Индекс максимального: [" << line << "][" << maxC << "]." << endl;
	return message.str();
}
string SearchColumnMatrix(int** matrix, int column, int countLines)
{
	int min{ matrix[0][0] };
	int max{ matrix[0][0] };
	int minL{ 0 };
	int maxL{ 0 };
	for (int i = 0; i < countLines; i++)
	{
		if (matrix[i][column] == 0)
		{
			continue;
		}
		if (matrix[i][column] < min)
		{
			minL = i;
		}

		if (matrix[i][column] > max)
		{
			maxL = i;
		}
	}
	stringstream message;
	message << "Индекс минимального :[" << minL << "][" << column << "].\n";
	message << "Индекс максимального : [" << maxL << "][" << column << "]." << endl;
	return message.str();
}
string SearchMainDiag(int** matrix, int countLines, int countColumns)
{
	int min = matrix[0][0];
	int max = matrix[0][0];
	int minC{ 0 };
	int minL{ 0 };
	int maxL{ 0 };
	int maxC{ 0 };
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (line == column)
			{
				if (matrix[line][column] == 0)
				{
					continue;
				}
				if (matrix[line][column] < min)
				{
					minL = line;
					minC = column;
				}

				if (matrix[line][column > max])
				{
					maxL = line;
					maxC = column;
				}
			}
		}
	}
	stringstream message;
	message << "Индекс минимального :[" << minL << "][" << minC << "].\n";
	message << "Индекс максимального : [" << maxL << "][" << maxC << "]." << endl;
	return message.str();
}
string SearchSaidDiag(int** matrix, int countLines, int countColumns)
{
	int min = matrix[0][0];
	int max = matrix[0][0];
	int minC{ 0 };
	int minL{ 0 };
	int maxL{ 0 };
	int maxC{ 0 };
	int line{ countLines - 1 };
	for (int column = 0; column < countColumns; column++)
	{
		if (matrix[line][column] == 0)
		{
			continue;
		}
		if (matrix[line][column] < min)
		{
			minL = line;
			minC = column;
		}

		if (matrix[line][column > max])
		{
			maxL = line;
			maxC = column;
		}
		line--;
	}
	stringstream message;
	message << "Индекс минимального :[" << minL << "][" << minC << "].\n";
	message << "Индекс максимального : [" << maxL << "][" << maxC << "]." << endl;
	return message.str();
}


bool MoreN(int value, int factor)
{
	return value >= factor;
}
bool LessN(int value, int factor)
{
	return value < factor;
}
bool MultN(int value, int factor)
{
	return (value % factor) == 0;
}
bool EquallyN(int value, int factor) 
{
	return value == factor;
}
string	FindCountQuan(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if ((*pred)(matrix[line][column], N))
			{
				quan++;
				message << "[" << line << "] [" << column << "]\n";
			}
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}

string FindCountQuanLine(int** matrix, int countLines, int countColumns, int line, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int column = 0; column < countColumns; column++)
	{
		if ((*pred)(matrix[line][column], N))
		{
			quan++;
			message << "[" << line << "] [" << column << "]\n";
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanColumn(int** matrix, int countLines, int countColumns, int column, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countLines; line++)
	{
		if ((*pred)(matrix[line][column], N))
		{
			quan++;
			message << "[" << line << "] [" << column << "]\n";
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanMainDiag(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (line == column)
			{
				if ((*pred)(matrix[line][column], N))
				{
					quan++;
					message << "[" << line << "] [" << column << "]\n";
				}
			}
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanSaidDiag(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	int line{ countLines - 1 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int column = 0; column < countColumns; column++)
	{
		if (line < 0)
		{
			break;
		}
		if ((*pred)(matrix[line][column], N))
		{
			quan++;
			message << "[" << line << "] [" << column << "]\n";
		}
		line--;
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanUp3(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	int saidCoeff{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countLines; line++)
	{
		for (int column = saidCoeff; column < countColumns; column++)
		{
			if ((*pred)(matrix[line][column], N))
			{
				quan++;
				message << "[" << line << "] [" << column << "]\n";
			}
		}
		saidCoeff++;
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanUnder3(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	int saidCoeff{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < saidCoeff; column++)
		{
			if ((*pred)(matrix[line][column], N))
			{
				quan++;
				message << "[" << line << "] [" << column << "]\n";
			}
		}
		saidCoeff++;
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}

int** DeleteStrMatrix(int** matrix, int& countLines, int countColumns, int deathLine)
{
	int newLine{ 0 };
	int** newArr{ new int* [countLines - 1] };
	for (int i = 0; i < countLines - 1; i++)
	{
		newArr[i] = new int[countColumns];
	}

	for (int i = 0; i < countLines; i++)
	{
		if (i == deathLine)
		{
			continue;
		}

		for (int j = 0; j < countColumns; j++)
		{

			newArr[newLine][j] = matrix[i][j];
		}
		newLine++;
	}
	countLines--;
	return newArr;
}
int** DeleteColMatrix(int** matrix, int countLines, int& countColumns, int deathColumn)
{
	int newColumn{ 0 };
	int** newArr{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		newArr[i] = new int[countColumns - 1];
	}
	for (int i = 0; i < countLines; i++)
	{
		newColumn = 0;
		for (int j = 0; j < countColumns; j++)
		{
			if (j != deathColumn)
			{
				newArr[i][newColumn] = matrix[i][j];
				newColumn++;
			}
		}
	}


	for (int i = 0; i < countLines; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	countColumns--;
	return newArr;
}

void PasteSortVector(int* vector, int vectorLenght)
{
	for (int i = 1; i < vectorLenght; i++)
	{
		int j{ i - 1 };
		while (j >= 0 && vector[j] > vector[j + 1])
		{
			swap(vector[j], vector[j + 1]);
			j--;
		}
	}
}

void PasteSortMatrix(int** matrix, int countLines, int countColumns, int& sortLine, int& sortColumn)
{
	if (sortLine > -1)
	{
		int* vector = new int[countColumns];

		for (int columnI = 0; columnI < countColumns; columnI++)
		{
			vector[columnI] = matrix[sortLine][columnI];
		}
		PasteSortVector(vector, countColumns);
		for (int column = 0; column < countColumns; column++)
		{
			matrix[sortLine][column] = vector[column];
		}
		delete[] vector;
	}
	if (sortColumn > -1)
	{
		int* vector = new int[countLines];

		for (int lineI = 0; lineI < countLines; lineI++)
		{
			vector[lineI] = matrix[lineI][sortColumn];
		}
		PasteSortVector(vector, countColumns);
		for (int line = 0; line < countLines; line++)
		{
			matrix[line][sortColumn] = vector[line];
		}
		delete[] vector;
	}
	if (sortLine == INT_MIN && sortColumn == INT_MIN)
	{
		int* vector = new int[countLines * countColumns];
		int vectorIndex{ 0 };
		vector = Matrix2Vector(matrix, countLines, countColumns);
		PasteSortVector(vector, countLines * countColumns);
		for (int line = 0; line < countLines; line++)
		{
			for (int column = 0; column < countColumns; column++)
			{
				matrix[line][column] = vector[vectorIndex];
				vectorIndex++;
			}
		}
		delete[] vector;
	}
	sortLine = INT_MIN;
	sortColumn = INT_MIN;
}

int** multMtrix2Vector(int** matrix, int* vector, int countLines, int& countColumns)
{
	int** multVector{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		multVector[i] = new int[1];
	}

	for (int i = 0; i < countLines; i++)
	{
		multVector[i][0] = 0;
	}

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			multVector[line][0] += matrix[line][column] * vector[column];
		}
	}
	countColumns = 1;
	return multVector;
}

int** multMatrix2Matrix(int** matrix1, int** matrix2, int& countLines1, int& countColumns1, int countColumns1AndLines2, int countColumns2)
{
	int** multMatrix{ new int* [countLines1] };
	for (int i = 0; i < countLines1; i++)
	{
		multMatrix[i] = new int[countColumns2];
		for (int j = 0; j < countColumns2; j++)
		{
			multMatrix[i][j] = 0;
			for (int k = 0; k < countColumns1AndLines2; k++)
			{
				multMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	countColumns1 = countColumns2;
	return multMatrix;
}

void matrixTransformation(int** matrix, int countColumns, int transformationLine, int faactor, bool condition)
{
	if (condition == false)
	{
		for (int column = 0; column < countColumns; column++)
		{
			matrix[transformationLine][column] *= faactor;
		}
	}
	else
	{
		for (int column = 0; column < countColumns; column++)
		{
			matrix[transformationLine][column] /= faactor;
		}
	}
}

void Transportation(int** matrix, int countLines, int countColumns)
{
	int** tempMatrix{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		tempMatrix[i] = new int[countColumns];
	}

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			tempMatrix[column][line] = matrix[line][column];
		}
	}

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			int value = tempMatrix[line][column];
			matrix[line][column] = value;
		}
	}
	for (int i = 0; i < countLines; i++) 
	{
		delete[] tempMatrix[i];
	}
	delete[] tempMatrix;

}
int Bonus1(int** matrix, int countLines, int countColumns)
{
	int count{ 0 };

	for (int i = 0; i < countColumns; i++)
	{
		for (int j = 0; j < countLines; j++)
		{
			if (matrix[j][i] == 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}

int Bonus2(int** matrix, int countLines, int countColumns)
{
	int biggerStrik{ 0 };
	int currentStrik{ 1 };
	int maxStrikLine{ -1 };
	for (int i = 0; i < countLines; i++)
	{
		for (int j = 1; j < countColumns; j++)
		{
			if (matrix[i][j - 1] == matrix[i][j])
			{
				currentStrik++;
			}
			if (currentStrik > biggerStrik)
			{
				biggerStrik = currentStrik;
				maxStrikLine = i;
			}
			currentStrik = 1;
		}
	}
	return maxStrikLine;
}

#pragma once
#include <string>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

//----------------------------------------------------Одномерный массив----------------------------------------------------
//													   ___ _   _ _____ 
//													  |_ _| \ | |_   _|
//													   | ||  \| | | |  
//													   | || |\  | | |  
//													  |___|_| \_| |_|   

void RandValues(int* ARR, int size);

bool Range(int index, int start, int end);
int SumArr(int* arr, int size, int start, int end, bool(&pred)(int, int, int));
int MultArr(int* arr, int size, int start, int end, bool(&pred)(int, int, int));

int PasteArr(int*& arr, int& size, int index, int value);
int DeleteArr(int*& arr, int& size, int index);

void BubbleSort(int*& arr, int size);
void ChoiceSort(int*& arr, int size);
void PasteSort(int*& arr, int size);

int MinValArr(int*& arr, int start, int size);
int MaxValArr(int*& arr, int start, int size);

int BinSerchArr(int*& arr, int size, int value);

bool Positive(int value);
bool NIGGAtive(int value);
bool Zero(int value);
bool MultF(int value, int factor);

int Count(int*& arr, int size, bool(*pred)(int));
int CountF(int*& arr, int size, int factor, bool(*pred)(int, int));

void InputArr(int*& arr, int size);
void InputFileArr(int*& arr, int size);

void ArrOut(int* ARR, int size);
void ArrOutFile(int*& arr, int size);

void RegenARR(int*& arr, int size);


//                                               _____ _     ___    _  _____ 
//                                              |  ___| |   / _ \  / \|_   _|
//                                              | |_  | |  | | | |/ _ \ | |  
//                                              |  _| | |__| |_| / ___ \| |  
//                                              |_|   |_____\___/_/   \_\_|  

void RandValues(float*& arr, int size);
void RoundArrValues(float*& ARR, int size);

float SumArr(int start, int end, float*& ARR, int size, bool (*pred)(int, int, int));
float MultArr(int start, int end, float*& ARR, int size, bool(*pred)(int, int, int));

int PasteArr(int& size, float*& arr, int index, float value);
int DeleteArr(int& size, float*& arr, int index);

void BubbleSort(float*& arr, int size);
void ChoiceSort(float*& arr, int size);
void PasteSort(float*& arr, int size);

int MaxValArr(int start, float*& arr, int lengthARR);
int MinValArr(int start, float*& arr, int size);

int BinSerchArr(float*& arr, int size, float value);

bool Positive(float value);
bool NIGGAtive(float value);
bool Zero(float value);
bool MultF(float value, float factor);

int Count(bool(*pred)(float), float*& arr, int size);
int CountF(float*& arr, int size, bool(*pred)(float, float), float factor);

void InputArr(int size, float*& arr);
void InputFileArr(int size, float*& arr);
void ArrOut(float*& arr, int size);
void ArrOutFile(float*& arr, int size);

void RegenArr(float*& arr, int size);


//                                              ____   ___  _   _ _   _ ____  
//                                             | __ ) / _ \| \ | | | | / ___| 
//                                             |  _ \| | | |  \| | | | \___ \ 
//                                             | |_) | |_| | |\  | |_| |___) |
//                                             |____/ \___/|_| \_|\___/|____/ 

int MultEvenARR(int*& arr, int size);
int SumZero2Zero(int*& arr, int size);
void ConverARR(int*& arr, int size);

//----------------------------------------------------Двумерный массив----------------------------------------------------

int** InputKeyboard(int** matrix, int countLines, int countColumns);
int** InputRand(int** matrix, int countLines, int countColumns);
int* InputRandVector(int* vector, int vectorLength);

void OutputScreen(int** matrix, int countLines, int countColumns);
void OutVectorScreen(int* vector, int vectorSize);

int* Matrix2Vector(int** matrix, int newCountLines, int newCountCloums);
int** Vector2Matrix(int* vector, int countLines, int countColumns, int vectorSize);

void SumMulLineMatrix(int** matrix, int line, int countColumns, int& sum, int& mult);
void SumMulColumnMatrix(int** matrix, int column, int countLines, int& sum, int& mult);
void SumMulMainDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);
void SumMulSaidDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);

string SearchLineMatrix(int** matrix, int line, int countColumns);
string SearchColumnMatrix(int** matrix, int column, int countLines);
string SearchMainDiag(int** matrix, int countLines, int countColumns);
string SearchSaidDiag(int** matrix, int countLines, int countColumns);

bool MoreN(int value, int factor);
bool LessN(int value, int factor);
bool MultN(int value, int factor);
bool EquallyN(int value, int factor);
string	FindCountQuan(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N);

string FindCountQuanLine(int** matrix, int countLines, int countColumns, int line, bool (*pred)(int, int), int N);
string FindCountQuanColumn(int** matrix, int countLines, int countColumns, int column, bool (*pred)(int, int), int N);
string FindCountQuanMainDiag(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N);
string FindCountQuanSaidDiag(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N);
string FindCountQuanUp3(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N);
string FindCountQuanUnder3(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N);


int** DeleteStrMatrix(int** matrix, int& countLines, int countColumns, int deathLine);
int** DeleteColMatrix(int** matrix, int countLines, int& countColumns, int deathColumn);

void PasteSortVector(int* vector, int vectorLenght);
void PasteSortMatrix(int** matrix, int countLines, int countColumns, int& sortLine, int& sortColumn);



void matrixTransformation(int** matrix, int countColumns, int transformationLine, int faactor, bool condition = 0);

int** multMtrix2Vector(int** matrix, int* vector, int countLines, int& countColumns);
int** multMatrix2Matrix(int** matrix1, int** matrix2, int& countLines1, int& countColumns1, int countColumns1AndLines2, int countColumns2);

void Transportation(int** matrix, int countLines, int countColumns);


//                                           ____      ____     _   _    _    _     _____ 
//                                          |  _ \    / __ \   | \ | |  | |  | |   / ____|
//                                          | |_) |  | |  | |  |  \| |  | |  | |  | (___  
//                                          |  _ <   | |  | |  | . ` |  | |  | |   \___ \ 
//                                          | |_) |  | |__| |  | |\  |  | |__| |   ____) |
//                                          |____/    \____/   |_| \_|   \____/   |_____/  



int Bonus1(int** matrix, int countLines, int countColumns);
int Bonus2(int** matrix, int countLines, int countColumns);


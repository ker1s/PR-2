#include "module.h"
#include <iostream>


int main()
{
	int task{ 0 };
	int enter{ 1 };
	//cin
	while (enter == 1)
	{
		cout << "1 - одномерные массивы;\n"
			<< "2 - двумерные массивы." << endl;
		
		cin >> task;
		switch (task)
		{
		case 1:
        {

            while (enter == 1)
            {
				int taskC1;
				cout << "INT - 1 \nFLOAT - 2 \nBONUS - 3"<< endl; cin >> taskC1;
                switch (taskC1) {
                case 1: {
                    int size;
                    int start;
                    int end;
                    int quan;
                    int searchVal;
                    int factor;

                    cout << "Введите размер массива ";
                    cin >> size;
                    int* X = new int [size];

                    //Заполенение случайными значениями
                    RandValues(X, size);
                    //Вывод на экран
                    ArrOut(X,size);


                    //Сумма и умножение
                    cout << "\nВведите диапазон (через пробел, или enter)\n";
                    cin >> start >> end;
                    while (start > end) {
                        cout << "Ошибка!!! Попробуйте ещё раз.\n";
                        cin >> start >> end;
                    }

                    cout << "\nСумма элементов из заданного диапазона равна " << SumArr(X,size ,start , end , Range) << endl;
                    cout << "\nПроизведение элементов из заданного диапазона равно " << MultArr(X, size,start , end , Range) << endl;

                    //Вставка
                    cout << "\nСколько элементов хотите вставить? \n";
                    cin >> quan;
                    for (int i = 0; i < quan; i++) {
                        int tempValue;
                        int tempIndex;
                        cout << i + 1 << " значение равно "; cin >> tempValue;
                        cout << "\nНа какое место хотите его поставить? \n"; cin >> tempIndex;
                        PasteArr(X,size ,tempIndex , tempValue);
						cout << "\n\n" << size << endl;
                    }
                    ArrOut(X,size);

                    //Удаление
                    cout << "\nСколько элементов хотите удалить? \n";
                    cin >> quan;
                    for (int i = 0; i < quan; i++) {
                        int tempIndex;
                        cout << "\nКакой элемент хотите удалить? \n"; cin >> tempIndex;
                        DeleteArr(X,size,tempIndex);
                    }
                    ArrOut(X,size);

                    //Метод ПУЗЫРЬКОВОЙ сортировки
                    cout << "\n\nМетод ПУЗЫРЬКОВОЙ сортировки \n";
                    BubbleSort(X,size);
                    ArrOut(X,size);

                    RegenARR(X, size);

                    //Метод сортировки ВЫБОРОМ
                    cout << "\n\nМетод сортировки ВЫБОРОМ \n";
                    ChoiceSort(X, size);
                    ArrOut(X,size);

                    RegenARR(X, size);

                    //Метод сортировки ВСТАВКАМИ
                    cout << "\n\nМетод сортировки ВСТАВКАМИ \n";
                    PasteSort(X, size);
                    ArrOut(X,size);

                    //Бинарный поиск
                    cout << "\nВведите искомое значение "; cin >> searchVal;
                    if (BinSerchArr(X, size, searchVal) == -1) cout << "Нет такого" << endl;
                    else cout << "Значение имеет индекс " << BinSerchArr(X, size, searchVal) << endl;

                    //Ввод массива с клавиатуры
                    InputArr(X, size);
                    ArrOut(X,size);
                    //Вывод в файл
                    ArrOutFile(X,size);


                    //Ввод массива из файла
                    InputFileArr(X, size);
                    ArrOut(X,size);

                    cout << endl << endl;
                    system("pause");
                    //Линейный поиск
                    cout << "\n\nМинимальное значение данного массива равно " << X[MinValArr(X, 0, size)] << endl;
                    cout << "\n\nМаксимальное значение данного массива равно " << X[MaxValArr(X, 0, size)];

                    //Подсчет количества элементов с указанной  характеристикой
                    //Положительных
                    cout << "Колличество положительных числе в данном массиве равно " << Count(X, size, Positive) << endl;

                    //Отрицательных
                    cout << "Колличество положительных числе в данном массиве равно " << Count(X, size, NIGGAtive) << endl;

                    //Нулевые
                    cout << "Колличество нулевых числе в данном массиве равно " << Count(X, size, Zero) << endl;

                    //Кратные произвольному числу
                    cout << "\nКратных какому числу нужно найти? \n"; cin >> factor;
                    cout << "Колличество положительных числе в данном массиве равно " << CountF(X, size, factor, MultF) << endl;



                }
                      break;

				case 2: {
					int size;
					int start;
					int end;
					int quan;
					float searchVal;
					float factor;

					cout << "Введите размер массива ";
					cin >> size;
					float* X = new float[size];

					//Заполенение случайными значениями
					RandValues(X, size);
					//Вывод на экран
					ArrOut(X, size);

					//Сумма и умножение
					cout << "\nВведите диапазон (через пробел, или enter)\n";
					cin >> start >> end;
					while (start > end) {
						cout << "Ошибка!!! Попробуйте ещё раз.\n";
						cin >> start >> end;
					}

					cout << "\nСумма элементов из заданного диапазона равна " << SumArr(start, end, X, size, Range) << endl;
					cout << "\nПроизведение элементов из заданного диапазона равно " << MultArr(start, end, X, size, Range) << endl;

					// Вставка
					cout << "\nСколько элементов хотите вставить? \n";
					cin >> quan;
					for (int i = 0; i < quan; i++) {
						float tempValue;
						int tempIndex;
						cout << i + 1 << " значение равно "; cin >> tempValue;
						cout << "\nНа какое место хотите его поставить? \n"; cin >> tempIndex;
						PasteArr(size, X, tempIndex , tempValue);
					}
					ArrOut(X, size);

					//Удаление
					cout << "\nСколько элементов хотите удалить? \n";
					cin >> quan;
					for (int i = 0; i < quan; i++) {
						int tempIndex;
						cout << "\nКакой элемент хотите удалить? \n"; cin >> tempIndex;
						DeleteArr(size, X, tempIndex );
					}
					ArrOut(X, size);

					//Метод ПУЗЫРЬКОВОЙ сортировки
					cout << "\n\nМетод ПУЗЫРЬКОВОЙ сортировки \n";
					BubbleSort(X, size);
					ArrOut(X, size);

					RandValues(X, size);
					cout << endl;

					ArrOut(X, size);

					//Метод сортировки ВЫБОРОМ
					cout << "\n\nМетод сортировки ВЫБОРОМ \n";
					ChoiceSort(X, size);
					ArrOut(X, size);

					RegenArr(X, size);

					//Метод сортировки ВСТАВКАМИ
					cout << "\n\nМетод сортировки ВСТАВКАМИ \n";
					PasteSort(X, size);
					ArrOut(X, size);


					//Бинарный поиск
					cout << "Введите искомое значение "; cin >> searchVal;
					if (BinSerchArr(X, size, searchVal) == -1) cout << "Нет такого" << endl;
					else cout << "Значение имеет индекс " << BinSerchArr(X, size, searchVal) << endl;


					//Ввод массива с клавиатуры
					InputArr(size, X);
					ArrOut(X, size);
					//Вывод в файл
					ArrOutFile(X, size);

					//Ввод массива из файла
					InputFileArr(size, X);
					ArrOut(X, size);



					//Линейный поиск
					cout << "\n\nМинимальное значение данного массива равно " << X[MinValArr(0, X, size)] <<endl ;
					cout << "\n\nМаксимальное значение данного массива равно " << X[MaxValArr(0, X, size)] << endl;

                    //Подсчет количества элементов с указанной  характеристикой
                    //Положительных
                    cout << "Колличество положительных числе в данном массиве равно " << Count(Positive, X, size) << endl;

                    //Отрицательных
                    cout << "Колличество положительных числе в данном массиве равно " << Count(NIGGAtive, X,size) << endl;

                    //Нулевые
					cout << "Колличество положительных числе в данном массиве равно " << Count(Zero, X, size) << endl;

                    //Кратные произвольному числу
                    cout << "\nКратных какому числу нужно найти? \n"; cin >> factor;
                    cout << "Колличество чисел кратных введёному числу в данном массиве равно " << CountF(X,size, MultF, factor) << endl;


                }
                      break;

                case 3: {
                    int size;

                    cout << "Введите размер массива ";
                    cin >> size;
					int* X = new int[size];

                    //Заполенение 
                    InputArr(X, size);
                    //Вывод на экран
                    ArrOut(X,size);

                    cout << "Произведение элементов массива с четными номерами: " << MultEvenARR(X,size) << endl;
                    cout << "Сумма элементов массива, расположенных между первым и последним нулевыми элементами: " << SumZero2Zero(X,size) << endl;
                    ConverARR(X,size);
                    cout << endl << "Преобразованный массив:" << endl;
                    ArrOut(X,size);




                }
                      break;

                default: {
                    system("cls");
                    cout << "Нет такого!!!";
                    system("pause");
                }
                       break;
                }


                system("pause");
                system("cls");
                cout << "Для продолжения нажмите 1.";
                cin >> enter;
            }
        }
			break;


		case 2:
		{
			SetConsoleOutputCP(CP_UTF8);
			//	setlocale(0, "rus");

			int countLines;
			int countColumns;
			int countLines2;
			int countColumns2;
			int vectorSeize;
			int line;
			int column;
			int sum;
			int mult;
			int iteration;
			int factor;
			cout << "Колличество срок: "; cin >> countLines;
			cout << endl << "Колличество столбцов: "; cin >> countColumns;
			int* vector = new int[countLines * countColumns];

			int** matrix{ new int* [countLines] };
			for (int i = 0; i < countLines; i++)
			{
				matrix[i] = new int[countColumns];
			}

			//заполнение и вывод
			cout << "\n\n---------------------заполнение и вывод---------------------\n\n";
			matrix = InputRand(matrix, countLines, countColumns);
			OutputScreen(matrix, countLines, countColumns);
			cout << endl;


			//Двумерный массив в одномерный
			cout << "\n\n---------------------Двумерный массив в одномерный---------------------\n\n";
			vector = Matrix2Vector(matrix, countLines, countColumns);
			vectorSeize = countLines * countColumns;
			OutVectorScreen(vector, vectorSeize);
			cout << endl;

			//Одномерный массив в двумерный
			cout << "\n\n---------------------Одномерный массив в двумерный---------------------\n\n";
			cout << "Новое колличество срок: "; cin >> countLines;
			cout << endl << "Новое колличество столбцов: "; cin >> countColumns;
			matrix = Vector2Matrix(vector, countLines, countColumns, vectorSeize);
			OutputScreen(matrix, countLines, countColumns);


			//Вычисление суммы, произведения
			cout << "\n\n---------------------Вычисление суммы, произведения---------------------\n\n";
			cout << endl << "Строка: "; cin >> line;
			cout << endl << "Столбец: "; cin >> column;
			SumMulLineMatrix(matrix, line, countColumns, sum, mult);
			cout << endl << "Сумма по заданной строке " << sum << endl << "Произведение по заданной строке " << mult << endl;

			SumMulColumnMatrix(matrix, column, countLines, sum, mult);
			cout << endl << "Сумма по заданному столбцу " << sum << endl << "Произведение по заданному столбцу " << mult << endl;

			SumMulMainDiag(matrix, countLines, countColumns, sum, mult);
			cout << endl << "Сумма по главной диагонали " << sum << endl << "Произведение по главной диагонали " << mult << endl;

			SumMulSaidDiag(matrix, countLines, countColumns, sum, mult);
			cout << endl << "Сумма по побочной диагонали " << sum << endl << "Произведение по побочной диагонали " << mult << endl;

			//Поиск минимального и максимального
			cout << "\n\n---------------------Поиск минимального и максимального---------------------\n\n";
			cout << endl << "Строка: "; cin >> line;
			cout << endl << "Столбец: "; cin >> column;

			cout << SearchLineMatrix(matrix, line, countColumns) << endl;
			cout << SearchColumnMatrix(matrix, column, countLines) << endl;
			cout << SearchMainDiag(matrix, countLines, countColumns) << endl;
			cout << SearchSaidDiag(matrix, countLines, countColumns) << endl;


			//поиск и подсчет количества
			cout << "\n\n---------------------Поиск и подсчет количества в строке---------------------\n\n";
			cout << "Искать числа в строке "; cin >> line;
			cout << "Искомы числа больше чем - "; cin >> factor;
			cout << "Числа большие чем " << factor << FindCountQuanLine(matrix, countLines, countColumns, line, MoreN, factor) << endl;

			cout << "Искомы числа меньше чем - "; cin >> factor;
			cout << "Числа меньше чем " << factor << FindCountQuanLine(matrix, countLines, countColumns, line, LessN, factor) << endl;

			cout << "Искомы числа кратны - "; cin >> factor;
			cout << "Числа кртные " << factor << FindCountQuanLine(matrix, countLines, countColumns, line, MultN, factor) << endl;

			cout << "Искомы числа равны- "; cin >> factor;
			cout << "Числа равные " << factor << FindCountQuanLine(matrix, countLines, countColumns, line, EquallyN, factor) << endl;




			cout << "\n\n---------------------Поиск и подсчет количества в столбце---------------------\n\n";
			cout << "Искать числа в столбце "; cin >> column;
			cout << "Искомы числа больше чем - "; cin >> factor;
			cout << "Числа большие чем " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, MoreN, factor) << endl;

			cout << "Искомы числа меньше чем - "; cin >> factor;
			cout << "Числа меньше чем " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, LessN, factor) << endl;

			cout << "Искомы числа кратны - "; cin >> factor;
			cout << "Числа кртные " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, MultN, factor) << endl;

			cout << "Искомы числа равны- "; cin >> factor;
			cout << "Числа равные " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, EquallyN, factor) << endl;




			cout << "\n\n---------------------Поиск и подсчет количества в главной диагонали---------------------\n\n";
			cout << "Искомы числа больше чем - "; cin >> factor;
			cout << "Числа большие чем " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, MoreN, factor) << endl;

			cout << "Искомы числа меньше чем - "; cin >> factor;
			cout << "Числа меньше чем " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, LessN, factor) << endl;

			cout << "Искомы числа кратны - "; cin >> factor;
			cout << "Числа кртные " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, MultN, factor) << endl;

			cout << "Искомы числа равны- "; cin >> factor;
			cout << "Числа равные " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, EquallyN, factor) << endl;




			cout << "\n\n---------------------Поиск и подсчет количества в побочной диагонали---------------------\n\n";
			cout << "Искомы числа больше чем - "; cin >> factor;
			cout << "Числа большие чем " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, MoreN, factor) << endl;

			cout << "Искомы числа меньше чем - "; cin >> factor;
			cout << "Числа меньше чем " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, LessN, factor) << endl;

			cout << "Искомы числа кратны - "; cin >> factor;
			cout << "Числа кртные " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, MultN, factor) << endl;

			cout << "Искомы числа равны- "; cin >> factor;
			cout << "Числа равные " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, EquallyN, factor) << endl;




			cout << "\n\n---------------------Поиск и подсчет количества в верхнем треугольнике---------------------\n\n";
			cout << "Искомы числа больше чем - "; cin >> factor;
			cout << "Числа большие чем " << factor << FindCountQuanUp3(matrix, countLines, countColumns, MoreN, factor) << endl;

			cout << "Искомы числа меньше чем - "; cin >> factor;
			cout << "Числа меньше чем " << factor << FindCountQuanUp3(matrix, countLines, countColumns, LessN, factor) << endl;

			cout << "Искомы числа кратны - "; cin >> factor;
			cout << "Числа кртные " << factor << FindCountQuanUp3(matrix, countLines, countColumns, MultN, factor) << endl;

			cout << "Искомы числа равны- "; cin >> factor;
			cout << "Числа равные " << factor << FindCountQuanUp3(matrix, countLines, countColumns, EquallyN, factor) << endl;




			cout << "\n\n---------------------Поиск и подсчет количества в нижнем треугольнике---------------------\n\n";
			cout << "Искомы числа больше чем - "; cin >> factor;
			cout << "Числа большие чем " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, MoreN, factor) << endl;

			cout << "Искомы числа меньше чем - "; cin >> factor;
			cout << "Числа меньше чем " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, LessN, factor) << endl;

			cout << "Искомы числа кратны - "; cin >> factor;
			cout << "Числа кртные " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, MultN, factor) << endl;

			cout << "Искомы числа равны- "; cin >> factor;
			cout << "Числа равные " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, EquallyN, factor) << endl;

			//Удление строки в динамическом массиве
			cout << "\n\n---------------------Удление строки в динамическом массиве---------------------\n\n";
			cout << "Сколько строк удалить?"; cin >> iteration;
			for (int i = 0; i < iteration; i++)
			{
				line = 0;
				cout << "Удаляема строка : "; cin >> line;
				matrix = DeleteStrMatrix(matrix, countLines, countColumns, line);
				OutputScreen(matrix, countLines, countColumns);
				cout << endl;
			}

			//Удление столбца в динамическом массиве

			cout << "\n\n---------------------Удление столбца в динамическом массиве---------------------\n\n";
			cout << "Сколько столбцов удалить? "; cin >> iteration;
			for (int i = 0; i < iteration; i++)
			{
				cout << "Удаляемый столбец : "; cin >> column;
				matrix = DeleteColMatrix(matrix, countLines, countColumns, column);
				OutputScreen(matrix, countLines - i, countColumns);
				cout << endl;
			}

			//Сортировка

			cout << "\n\n---------------------Сортировка строки---------------------\n\n";
			cout << "Сортируемая строка: "; cin >> line;
			PasteSortMatrix(matrix, countLines, countColumns, line, column);
			OutputScreen(matrix, countLines, countColumns);

			cout << "\n\n---------------------Сортировка столбца---------------------\n\n";
			cout << "Сортируемый столбец: "; cin >> column;
			PasteSortMatrix(matrix, countLines, countColumns, line, column);
			OutputScreen(matrix, countLines, countColumns);

			cout << "\n\n---------------------Сортировка всего массива---------------------\n\n";
			PasteSortMatrix(matrix, countLines, countColumns, line, column);
			OutputScreen(matrix, countLines, countColumns);


			//Умножение матрицы на вектор
			cout << "\n\n---------------------Умножение матрицы на вектор---------------------\n\n";
			int* vector2{ new int[countLines] };
			vector2 = InputRandVector(vector2, countLines);
			OutVectorScreen(vector2, countLines);
			matrix = multMtrix2Vector(matrix, vector2, countLines, countColumns);
			OutputScreen(matrix, countLines, countColumns);

			cout << "\n\n---------------------Умножение матрицы на матрицу---------------------\n\n";


			cout << "Колличество срок: "; cin >> countLines2;
			cout << endl << "Колличество столбцов: "; cin >> countColumns2;
			int** matrix2{ new int* [countLines2] };
			for (int i = 0; i < countLines2; i++)
			{
				matrix2[i] = new int[countColumns2];
			}
			matrix2 = InputRand(matrix2, countLines2, countColumns2);
			OutputScreen(matrix2, countLines2, countColumns2);
			cout << endl;
			matrix = multMatrix2Matrix(matrix, matrix2, countLines, countColumns, countLines2, countColumns2);
			OutputScreen(matrix, countLines, countColumns);


			//Преобразование матрицы 
			cout << "\n\n---------------------Преобразование матрицы---------------------\n\n";
			cout << "Номер строки: "; cin >> line;
			cout << "Умнжить на: "; cin >> factor;
			matrixTransformation(matrix, countColumns, line, factor, 0);
			OutputScreen(matrix, countLines, countColumns);

			cout << "Номер строки: "; cin >> line;
			cout << "Поделить на: "; cin >> factor;
			matrixTransformation(matrix, countColumns, line, factor, 1);
			OutputScreen(matrix, countLines, countColumns);

			//Транспорирование

			cout << "\n\n---------------------транспорирование---------------------\n\n";
			matrix = InputRand(matrix, countLines, countColumns);
			OutputScreen(matrix, countLines, countColumns);
			cout << endl;
			Transportation(matrix, countLines, countColumns);
			OutputScreen(matrix, countLines, countColumns);
			cout << endl;
			system("pause");

			//Бонус
			InputKeyboard(matrix, countLines, countColumns);
			cout << endl << endl;
			OutputScreen(matrix, countLines, countColumns);
			cout << "Количество столбцов, содержащих хотя бы один нулевой элемент: " << Bonus1(matrix, countLines, countColumns) << endl;
			cout << "номер строки, в которой находится самая длинная серия одинаковых элементов: " << Bonus2(matrix, countLines, countColumns) << endl;
			system("pause");



		}
			break;


		default:
			break;
		}
		system("pause");
		system("cls");
		cout << "Для продолжения нажмите 1.";
		cin >> enter;
	}
}

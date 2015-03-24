#include <iostream>
#include <fstream>

using namespace std;
void print(int** matrix, int rows, int cols);
void menu();
void add(int** matrix1, int** matrix2, int rows, int cols);
void subtract(int** matrix1, int** matrix2, int rows, int cols);
void multiply(int** matrix1, int** matrix2, int rows, int cols);
void transpose(int** matrix, int rows, int cols);
bool validate(int rows1, int cols1, int rows2, int cols2, int op);

int main()
{

	menu();
	return(0);

}

void menu()
{
	fstream input;
	input.open("Text.txt", ios::in);
	int **matrixA, **matrixB;
	int rows1, cols1, rows2, cols2, value;
	int response = 0;
	cout << "1. File input\n2. User input\n3. Quit";
	cin >> response;
	switch (response)
	{
	case 1:
		input >> rows1;
		input >> cols1;
		matrixA = new int*[rows1];
		for (int i = 0; i < cols1; i++)
			matrixA[i] = new int[cols1];

		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols1; j++)
			{
				input >> value;
				*(*(matrixA + i) + j) = value;
			}
		}
		//________________________________________________
		input >> rows2;
		input >> cols2;
		matrixB = new int*[rows2];
		for (int i = 0; i < cols2; i++)
			matrixB[i] = new int[cols2];
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < cols2; j++)
			{
				input >> value;
				*(*(matrixB + i) + j) = value;
			}
		}
		cout << "matrix1: " << endl << endl;
		print(matrixA, rows1, cols1);
		cout << "Matrix2: \n";
		print(matrixB, rows2, cols2);
		break;
	case 2:
		//int rows1, cols1, rows2, cols2, value;
		cout << "\nEnter row 1 size: ";
		cin >> rows1;
		cout << "\nEnter column 1 size: ";
		cin >> cols1;
		matrixA = new int*[rows1];
		for (int i = 0; i < cols1; i++)
			matrixA[i] = new int[cols1];

		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols1; j++)
			{
				cout << "[" << i << "][" << j << "]: ";
				cin >> value;
				*(*(matrixA + i) + j) = value;
			}
		}
		cout << "matrix: " << endl;
		print(matrixA, rows1, cols1);
		//_______________________________--
		cout << "\nEnter row 2 size: ";
		cin >> rows2;
		cout << "\nEnter column 2 size: ";
		cin >> cols2;

		matrixB = new int*[rows2];
		for (int i = 0; i < cols2; i++)
			matrixB[i] = new int[cols2];

		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < cols2; j++)
			{
				cout << "[" << i << "][" << j << "]: ";
				cin >> value;
				*(*(matrixB + i) + j) = value;
			}
		}
		cout << "Matrix: \n";
		print(matrixB, rows2, cols2);
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "Incorrect input. Try again";
		menu();
		break;
	}
//_______________________________________________________________
	cout << "Choose an operation." <<endl;
	cout << "1. Add\n";
	cout << "2. Subtract\n";
	cout << "3. Multiply\n";
	cout << "4. Find the transpose.\n";
	cin >> response;

	//Matrices Acquired. Now determine which op will be performed on them.
	switch (response)
	{
	case 1:
		if (validate(rows1, cols1, rows2, cols2, 1))
			add(matrixA, matrixB, rows1, cols1);
		else
		{
			cout << "unable to perform this operation on the given Matrix." << endl;
			system("pause");
			system("cls");
			menu();
		}
		break;
	case 2:
		if (validate(rows1, cols1, rows2, cols2, 2))
			subtract(matrixA, matrixB, rows1, cols1);
		else
		{
			cout << "unable to perform this operation on the given Matrix." << endl;
			system("pause");
			system("cls");
			menu();
		}
		break;

	case 3:
		if (validate(rows1, cols1, rows2, cols2, 3))
			multiply(matrixA, matrixB, rows2, cols1);
		else
		{
			cout << "unable to perform this operation on the given Matrix." << endl;
			system("pause");
			system("cls");
			menu();
		}
		break;
		//determining which matrix to perform transpose op
	case 4:
		cout << "1. Matrix A\n2. Matrix B:";
		cin >> response;
		if (response == 1)
			transpose(matrixA, rows1, cols1);
		else if (response == 2)
			transpose(matrixB, rows2, cols2);
		else
			cout << "You're making life difficult. Shame on you";
		system("pause");
		system("cls");
		menu();
		break;
	}
	system("pause");
	system("cls");
	menu();
}

void print(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << "\n";
	}
}

void add(int** matrix1, int** matrix2, int rows, int cols)
{
	int **new_matrix = nullptr;
	new_matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
		*(new_matrix + i) = new int[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <cols; j++)
		{
			(*(*(new_matrix + i) + j)) = (*(*(matrix1 + i) + j)) + (*(*(matrix2 + i) + j));
		}
	}

	print(new_matrix, rows, cols);
}

void subtract(int** matrix1, int** matrix2, int rows, int cols)
{
	int **new_matrix = nullptr;
	new_matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
		*(new_matrix + i) = new int[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			(*(*(new_matrix + i) + j)) = (*(*(matrix1 + i) + j)) - (*(*(matrix2 + i) + j));
		}
	}
	print(new_matrix, rows, cols);
}

void multiply(int** matrix1, int** matrix2, int rows, int cols)
{
	int **new_matrix = nullptr;
	new_matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		*(new_matrix + i) = new int[cols];
		for (int j = 0; j < cols; j++)
			*(*(new_matrix + i) + j) = 0;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < rows; k++)
			{
				(*(*(new_matrix + i) + j)) += (*(*(matrix1 + i) + k)) * (*(*(matrix2 + k) + j));

			}
		}
	}
	print(new_matrix, rows, cols);

}
void transpose(int** matrix, int rows, int cols)
{
	int **new_matrix = nullptr;
	new_matrix = new int *[cols];
	for (int i = 0; i < cols; i++)
		*(new_matrix + i) = new int[rows];

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			(*(*(new_matrix + i) + j)) = (*(*(matrix + j) + i));
		}
	}
	print(new_matrix, rows, cols);
}
bool validate(int rows1, int cols1, int rows2, int cols2, int op)
{
	switch (op)
	{
	case 1:
		if ((rows1 != rows2) && (cols1 != cols2))
			return false;
		return true;
		break;
	case 2:
		if ((rows1 != rows2) && (cols1 != cols2))
			return false;
		return true;
		break;
	case 3:
		if (cols1 != rows2)
			return false;
		return true;
		break;
	default:
		cout << "How did you manage to mess this up?";
		system("pause");
			exit(0);
		break;
	}

}
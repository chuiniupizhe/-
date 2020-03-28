#include "stdio.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "relation.h"
using namespace std;

//---------------------------------------------------------------------------------------------------

Relation::Relation(int d)
{
	//Construct an empty relation of dimension d

	dimension = d;
	Matrix = new int[dimension * dimension];
	memset(Matrix, 0, sizeof(int) * dimension * dimension);
}

Relation::Relation(int d, const int* M)
{
	//Construct a relation from the dimension of its relational matrix and the array of the relational matrix

	dimension = d;
	Matrix = new int[dimension * dimension];
	memcpy(Matrix, M, sizeof(int) * dimension * dimension);
}

Relation::Relation(const char* filename)
{
	//Read the matrix of a relation from a file

	ifstream readfile(filename);
	if (!readfile)
	{
		printf("Fail to open.\n");
		exit(1);
	}
	else
	{
		int row, column;
		readfile >> dimension;
		Matrix = new int[dimension * dimension];
		for (row = 0; row < dimension; row++)
			for (column = 0; column < dimension; column++)
				readfile >> Matrix[row * dimension + column];
	}
	readfile.close();
}

Relation::~Relation()
{
	//Destructor

	delete[]Matrix;
}

Relation::Relation(const Relation& r)
{
	dimension = r.dimension;
	Matrix = new int[dimension * dimension];
	memcpy(Matrix, r.Matrix, sizeof(int) * dimension * dimension);
}

Relation& Relation::operator =(const Relation& r)
{
	dimension = r.dimension;
	Matrix = new int[dimension * dimension];
	memcpy(Matrix, r.Matrix, sizeof(int) * dimension * dimension);
	return *this;
}

//---------------------------------------------------------------------------------------------------

int Relation::GetDimension() const
{
	//Get the dimension of relational matrix

	return dimension;
}

int Relation::GetatPosition(int row, int column) const
{
	//Gets the value at the cross position in column-th column and row-th row of the relational matrix, and this function returns -1 if it is over the boundary.

	if (row >= 0 && row < dimension && column >= 0 && column < dimension)
		return Matrix[row * dimension + column];
	else
		return -1;
}

int Relation::operator()(int row, int column) const
{
	//You can use R (i, j) to get the value at the cross position in column-th column and row-th row of the relational matrix, and this function returns - 1 if it is over the boundary.

	if (row >= 0 && row < dimension && column >= 0 && column < dimension)
		return Matrix[row * dimension + column];
	else
		return -1;
}

bool Relation::GetMatrix(int* result) const
{
	//Get the relational matrix
	if (result != NULL)
	{
		memcpy(result, Matrix, sizeof(int) * dimension * dimension);
		return true;
	}
	return false;
}

void Relation::Output() const
{
	//Display the matrix of the relation on the screen
	int row, column;
	cout << dimension << endl;
	for (row = 0; row < dimension; row++)
	{
		for (column = 0; column < dimension; column++)
		{
			cout << (*this)(row, column);
		}
		cout << "\n";
	}
}

bool Relation::OutputtoFile(const char* filename) const
{
	//Write the relation matrix to a file in the same format as the read file

	ofstream writefile(filename);
	if (!writefile)
	{
		cout << "Fail to open.\n";
		return false;
	}
	else
	{
		int row, column;
		writefile << dimension << endl;
		for (row = 0; row < dimension; row++)
		{
			for (column = 0; column < dimension; column++)
				writefile << Matrix[row * dimension + column] << ' ';
			writefile << endl;
		}
	}
	writefile.flush();
	writefile.close();
	return true;
}
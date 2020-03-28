#pragma once
#include<iostream>
using namespace std;

class Relation
{
protected:
	int dimension;
	int* Matrix;

public:
	//====================================================================================================
	Relation(int d = 1);									//Construct an empty relation of dimension d.(If not specified, default is d = 1)
	Relation(int d, const int* M);							//Construct a relation from the dimension of its relational matrix and the array of the relational matrix
	Relation(const char* filename);							//Read the matrix of a relation from a file
	Relation(const Relation& r);							//Copy constructor
	Relation& operator =(const Relation& r);				//Overloaded of assignment operator
	~Relation();											//Destructor
	//====================================================================================================
	int GetDimension() const;								//Get the dimension of relational matrix
	int GetatPosition(int row, int column) const;			//Gets the value at the cross position in column-th column and row-th row of the relational matrix,
															//and this function returns -1 if it is over the boundary
	int operator() (int row, int column) const;				//You can use R (i, j) to get the value at the cross position in column-th column and row-th row of the relational matrix,
															//and this function returns - 1 if it is over the boundary
	bool GetMatrix(int* result) const;						//Get the relational matrix
	//====================================================================================================
	void Output() const;									//Display the matrix of the relation on the screen
	bool OutputtoFile(const char* filename) const;			//Output to a file
	//====================================================================================================
	bool IsReflexive() const;								//ToDo: determine whether this relation has this property or not
	bool IsIrreflexive() const;								//ToDo: determine whether this relation has this property or not
	bool IsSymmetric() const;								//ToDo: determine whether this relation has this property or not
	bool IsAsymmetric() const;								//ToDo: determine whether this relation has this property or not
	bool IsAntisymmetric() const;							//ToDo: determine whether this relation has this property or not
	bool IsTransitive() const;								//ToDo: determine whether this relation has this property or not
	//====================================================================================================
	Relation ReflexiveClosure() const;						//ToDo: get the relational matrix of its reflexive closure
	Relation SymmetricClosure() const;						//ToDo: get the relational matrix of its symmetric closure
	Relation TransitiveClosure() const;						//ToDo: get the relational matrix of its transitive closure
	//====================================================================================================
	bool IsEquivalence() const;								//ToDo: determine whether this relation is an equalence relation or not
	//====================================================================================================
	bool EquiClasses(int* result) const;					//Todo:
															//result is an array of the dimension in size.
															//If this relation is an equivalence relation, then stores the number of the equivalent class
															//of the elements of the current relation (the number is started from 0) in the array result,
															//and returnes true.
															//Otherwise, the value of any item in the array result is set as -1 and returnes false.
															//Example:
															//3
															//1 1 0
															//1 1 0
															//0 0 1
															//the array result should be {0, 0, 1}, and should return true.
};

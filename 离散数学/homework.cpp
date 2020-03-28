#include "stdio.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "relation.h"
using namespace std;

bool Relation::IsReflexive() const
{
	//ToDo£ºdetermine whether this relation has this property or not
	return true;
}

bool Relation::IsIrreflexive() const
{
	//ToDo£ºdetermine whether this relation has this property or not
	return true;
}

bool Relation::IsSymmetric() const
{
	//ToDo£ºdetermine whether this relation has this property or not
	return true;
}

bool Relation::IsAsymmetric() const
{
	//ToDo£ºdetermine whether this relation has this property or not
	return true;
}

bool Relation::IsAntisymmetric() const
{
	//ToDo£ºdetermine whether this relation has this property or not
	return true;
}

bool Relation::IsTransitive() const
{
	//ToDo£ºdetermine whether this relation has this property or not
	return true;
}

bool Relation::IsEquivalence() const
{
	//ToDo£ºdetermine whether this relation is an equivalence relation or not
	return true;
}

Relation Relation::ReflexiveClosure() const
{
	int* m = new int[dimension * dimension];
	GetMatrix(m);

	/*
	ToDo: Modify *m to get the relational matrix of its reflexive closure, from which the object r is constructed and returned
	*/

	Relation r(dimension, m);
	return r;
}

Relation Relation::SymmetricClosure() const
{
	int* m = new int[dimension * dimension];
	GetMatrix(m);

	/*
	ToDo: Modify *m to get the relational matrix of its symmetric closure , from which the object r is constructed and returned
	*/

	Relation r(dimension, m);
	return r;
}

Relation Relation::TransitiveClosure() const
{
	int* m = new int[dimension * dimension];
	GetMatrix(m);

	/*
	ToDo: Modify *m to get the relational matrix of its transitive closure , from which the object r is constructed and returned
	*/

	Relation r(dimension, m);
	return r;
}

bool Relation::EquiClasses(int* result) const
{
	/*
	ToDo: result is an array of the dimension in size.
	If this relation is an equivalence relation, then stores the number of the equivalent class
	of the elements of the current relation (the number is started from 0) in the array result,
	and returnes true.
	Otherwise, the value of any item in the array result is set as -1 and returnes false.
	For an example, see the comment at the function declaration.
	*/
	memset(result, 255, sizeof(int) * dimension);
	return false;
}
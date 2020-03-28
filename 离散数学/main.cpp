#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include "relation.h"
using namespace std;

void benchmark(const char* filename)
{
	int i;
	Relation r;
	Relation rr;

	r = Relation(filename);

	cout << "================================" << endl;
	cout << "The relation represented by" << filename << ":" << endl;
	cout << "      is reflexive: " << (r.IsReflexive() ? "YES" : "NO") << endl;
	cout << "    is irreflexive: " << (r.IsIrreflexive() ? "YES" : "NO") << endl;
	cout << "      is symmetric: " << (r.IsSymmetric() ? "YES" : "NO") << endl;
	cout << "     is asymmetric: " << (r.IsAsymmetric() ? "YES" : "NO") << endl;
	cout << "  is antisymmetric: " << (r.IsAntisymmetric() ? "YES" : "NO") << endl;
	cout << "     is transitive: " << (r.IsTransitive() ? "YES" : "NO") << endl;

	rr = r.ReflexiveClosure();
	cout << "  Its reflexive closure is:" << endl;
	rr.Output();
	rr = r.SymmetricClosure();
	cout << "  Its symmetric closure is:" << endl;
	rr.Output();
	rr = r.TransitiveClosure();
	cout << "  Its transitive closure is:" << endl;
	rr.Output();

	int* EClass = new int[r.GetDimension()];
	r.EquiClasses(EClass);

	cout << filename << " represens an equivalence relation: " << (r.IsEquivalence() ? "YES" : "NO") << endl;
	cout << "The Equivalent classes are:" << endl;
	for (i = 0; i < r.GetDimension(); i++)
	{
		cout << setw(3) << i;
	}
	cout << endl;
	for (i = 0; i < r.GetDimension(); i++)
	{
		cout << setw(3) << EClass[i];
	}
	cout << endl;

	cout << "================================" << endl;
}

void test1()
{
	Relation r("test1.txt");
	r.Output();
	r.OutputtoFile("result1.txt");
	r = Relation("result1.txt");
	r.Output();
}

int main()
{
	test1();

	benchmark("test1.txt");
	return 0;
}
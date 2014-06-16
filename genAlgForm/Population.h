#pragma once
#include "windows.h"
#include "math.h"
#include <iostream>
using namespace std;

const int L = 6;
int n = 2;
const int rand_max = 1000;
class Individ{
public:
	int* chromosome;
	int chrCount;
	double fitnessValue;
public:
	void randomInit()
	{
		for(int k=0; k<chrCount; k++)
			chromosome[k] = rand()%(1<<L);
	}
	Individ()
	{
		chrCount = n;
		chromosome = new int[chrCount];
		randomInit();
	}
	/*void crossover(Individ& ind1)
	{
		for(int k=0; k<chrCount; k++)
		{
			int crossPoint1 = rand()%(L+1);
			//int crossPoint2 = rand()%(L+1);
			int crossPoint2 = crossPoint1;
			//cout << "cross point " << crossPoint1 << endl;
			if(crossPoint1 == crossPoint2) // случай слияния точек кроссовера
			{
				// меняем часть своих генов на часть генов другого
				int myNewChr = 0;
				for(int i=0; i<crossPoint1; i++)
					myNewChr |= ind1.chromosome[k] & (1<<i);
				for(int i=crossPoint1; i<L; i++)
					myNewChr |= chromosome[k] & (1<<i);
				// меняем часть генов другого на часть своих
				int heNewChr = 0;
				for(int i=0; i<crossPoint1; i++)
					heNewChr |= chromosome[k] & (1<<i);
				for(int i=crossPoint1; i<L; i++)
					heNewChr |= ind1.chromosome[k] & (1<<i);
				chromosome[k] = myNewChr;
				ind1.chromosome[k] = heNewChr;
			} else {

			}
		}

	}*/

	void crossover(Individ& ind1)
	{
		for(int k=0; k<chrCount; k++)
		{
			int crossPoint1 = rand()%(L+1);
			int crossPoint2 = rand()%(L+1);
			if(crossPoint1 == crossPoint2) // случай слияния точек кроссовера
			{
				// меняем часть своих генов на часть генов другого
				int myNewChr = 0;
				for(int i=0; i<crossPoint1; i++)
					myNewChr |= ind1.chromosome[k] & (1<<i);
				for(int i=crossPoint1; i<L; i++)
					myNewChr |= chromosome[k] & (1<<i);
				// меняем часть генов другого на часть своих
				int heNewChr = 0;
				for(int i=0; i<crossPoint1; i++)
					heNewChr |= chromosome[k] & (1<<i);
				for(int i=crossPoint1; i<L; i++)
					heNewChr |= ind1.chromosome[k] & (1<<i);
				chromosome[k] = myNewChr;
				ind1.chromosome[k] = heNewChr;
			} else {
				int myNewChr = 0;
				for(int i=crossPoint1; i<crossPoint2; i++)
					myNewChr |= ind1.chromosome[k] & (1<<i);
				for(int i=0; i<crossPoint1; i++)
					myNewChr |= chromosome[k] & (1<<i);
				for(int i=crossPoint2; i<L; i++)
					myNewChr |= chromosome[k] & (1<<i);

				int heNewChr = 0;
				for(int i=crossPoint1; i<crossPoint2; i++)
					heNewChr |= chromosome[k] & (1<<i);
				for(int i=0; i<crossPoint1; i++)
					heNewChr |= ind1.chromosome[k] & (1<<i);
				for(int i=crossPoint2; i<L; i++)
					heNewChr |= ind1.chromosome[k] & (1<<i);
				chromosome[k] = myNewChr;
				ind1.chromosome[k] = heNewChr;
			}
		}

	}

	void randMutation(double probabitily)
	{
		for(int k=0; k<chrCount; k++)
		{
			for(int i=0; i<L; i++)
				if(rand()%rand_max <= probabitily*rand_max)
				{
					if(chromosome[k] & (1 << i))
						chromosome[k] &= ~(1 << i);
					else
						chromosome[k] |= (1 << i);
				}
		}
	}
	Individ& operator=(Individ& ind)
	{
		for(int i=0; i<chrCount; i++)
			chromosome[i] = ind.chromosome[i];
		fitnessValue = ind.fitnessValue;
		return ind;
	}
	void print()
	{
		for(int k=0; k<chrCount; k++)
		{
			cout << " | chr " << k << ": ";
			for(int i=0; i<L; i++)
				if(chromosome[k] & (1<<i))
					cout << '1';
				else
					cout << '0';
			cout << " (" << chromosome[k] << ") ";
		}
		cout << endl;
	}
	~Individ()
	{
		delete [] chromosome;
	}
};

class Population
{
public:
	Individ** inds;
	Individ** indsBuff;
	int indsCount;
	
	double probCross; // вероятность кроссовера
	double probMutation; // вер. мутации

	void init()
	{
		inds = new Individ*[indsCount];
		for(int i=0; i<indsCount; i++)
			inds[i] = new Individ();

		indsBuff = new Individ*[indsCount];
		for(int i=0; i<indsCount; i++)
			indsBuff[i] = new Individ();
	}

	int a, b;

	double fitnessFunc(Individ* ind)
	{
		double sum = 0;
		double x;
		for(int i=0; i<n; i++)
		{
			x = a + ind->chromosome[i]/(double)(1<<L)*(b-a);
			//sum += x*sin(abs(x));
			sum += x*sin(sqrt(abs(x)));
		}
		return sum;
	}

public:

	Population(void)
	{
		inds = NULL;
	}

	Population(int size, int a_, int b_)
	{
		probCross = 1; // вероятность кроссовера
		probMutation = 0.01; // вер. мутации

		a = a_;
		b = b_;
		indsCount = size;
		init();
	}

	

	void tournamentSelection()
	{
		int n1, n2;
		for(int i=0; i<indsCount; i++)
		{
			n1 = rand()%indsCount;
			n2 = rand()%indsCount;

			if(inds[n1]->fitnessValue < inds[n2]->fitnessValue)
				indsBuff[i] = inds[n1];
			else
				indsBuff[i] = inds[n2];
		}
	}

	void computeFitness()
	{
		for(int i=0; i<indsCount; i++)
			inds[i]->fitnessValue = fitnessFunc(inds[i]);
	}

	double* getResult()
	{
		computeFitness();
		int nmin = 0;
		double min = 100000;
		for(int i=0; i<indsCount; i++)
			if(inds[i]->fitnessValue < min)
			{
				nmin = i;
				min = inds[i]->fitnessValue;
			}
			double* res = new double[n+1];
			for(int i=0; i<n; i++)
				res[i] = a + inds[nmin]->chromosome[i]/(double)(1<<L)*(b-a);
			res[n] = inds[nmin]->fitnessValue;
			return res;
	}

	void crossing()
	{
		int n1, n2;
		for(int i=0; i<indsCount; i++)
		{
			n1 = rand()%indsCount;
			n2 = rand()%indsCount;
			if(rand()%rand_max <= rand_max*probCross)
			{
				indsBuff[n1]->crossover(*indsBuff[n2]);
			}
			if(rand()%rand_max <= rand_max*probMutation)
			{
				indsBuff[n1]->randMutation(1);
				indsBuff[n2]->randMutation(1);
			}
		}
	}

	void buffToMain()
	{
		for(int i=0; i<indsCount; i++)
			*inds[i] = *indsBuff[i];
	}

	void nextStep()
	{
		computeFitness();
		tournamentSelection();
		crossing();
		buffToMain();
	}

	void print()
	{
		for(int i=0; i<indsCount; i++)
		{
			//inds[i]->print();
			for(int j=0; j<n; j++)
				cout << a + inds[i]->chromosome[j]/64.0*18 << " | ";
			cout << endl;
		}
	}

	~Population(void)
	{
		/*for(int i=0; i<indsCount; i++)
			if(inds[i] != NULL)
				delete inds[i];
		delete [] inds;

		for(int i=0; i<indsCount; i++)
			if(indsBuff[i] != NULL)
				delete indsBuff[i];
		delete [] indsBuff;*/
	}
};


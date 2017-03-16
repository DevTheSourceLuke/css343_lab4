//#include "stdafx.h"
#include <iostream>
#include "dvdfactory.h"

void DVDFactory::createDVDs(ifstream & infile, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC)
{
	//DVD* temp = NULL;
	while (!infile.eof())
	{
		char genre;

		infile >> genre;

		Comedy* tempF = new Comedy();
		Drama* tempD = new Drama();
		Classic* tempC = new Classic();

		switch (genre)
		{
		case 'F':

			if (tempF->setData(infile))
			{
				if (!inventoryF->insert(tempF))
				{
					delete tempF;
					tempF = NULL;
				}
				tempF = NULL;
			}
			else
			{
				delete tempF;
				tempF = NULL;
			}
			break;

		case 'D':

			if (tempD->setData(infile))
			{
				if (!inventoryD->insert(tempD))
				{
					delete tempD;
					tempD = NULL;
				}
				tempD = NULL;
			}
			else
			{
				delete tempD;
				tempD = NULL;
			}
			break;

		case 'C':

			if (tempC->setData(infile))
			{
				if (!inventoryC->insert(tempC))
				{
					delete tempC;
					tempC = NULL;
				}
				tempC = NULL;
			}
			else
			{
				delete tempC;
				tempC = NULL;
			}
			break;

		default:
			cout << "Invalid Movie Genre: " << genre << endl;
			infile.ignore(1000000, '\n');
			break;
		}
	}
}

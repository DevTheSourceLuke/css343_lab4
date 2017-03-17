//#include "stdafx.h"
#include <iostream>
#include "dvdfactory.h"

void DVDFactory::createDVDs(ifstream & infile, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC)
{
	vector<Classic*> sameMovie;

	Comedy* returnedF = NULL;
	Drama* returnedD = NULL;
	Classic* returnedC = NULL;
	while (!infile.eof())
	{
		char genre = '#';

		infile >> genre;
		if (genre == '#')
		{
			break;
		}

		Comedy* tempF = NULL;
		Drama* tempD = NULL;
		Classic* tempC = NULL;

		switch (genre)
		{
		case 'F':
			tempF = new Comedy();
			if (tempF->setData(infile))
			{
				if (!inventoryF->insert(tempF))
				{
					inventoryF->retrieve(*(tempF), returnedF);
					if (returnedF != NULL)
					{
						returnedF->adjustInventory(tempF->getInventory());
						returnedF = NULL;
					}
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
			tempD = new Drama();
			if (tempD->setData(infile))
			{
				if (!inventoryD->insert(tempD))
				{
					inventoryD->retrieve(*(tempD), returnedD);
					if (returnedD != NULL)
					{
						returnedD->adjustInventory(tempD->getInventory());
						returnedD = NULL;
					}
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
			tempC = new Classic();
			if (tempC->setData(infile))
			{
				if (!inventoryC->insert(tempC))
				{
					inventoryC->retrieve(*(tempC), returnedC);
					if (returnedC != NULL)
					{
						returnedC->adjustInventory(tempC->getInventory());
						returnedC = NULL;
					}
					delete tempC;
					tempC = NULL;
				}
				else
				{
					bool found = false;
					for (int i = 0; i < sameMovie.size(); i++)
					{
						
						if (sameMovie[i]->getTitle().compare(tempC->getTitle()) == 0 && sameMovie[i]->getMonth() == tempC->getMonth() && sameMovie[i]->getYear() == tempC->getYear())
						{
							found = true;
							tempC->setOtherStock(sameMovie[i]->getOtherStock());
							sameMovie[i]->setOtherStock(tempC);
						}
					}
					if (found == false)
					{
						sameMovie.push_back(tempC);
					}
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
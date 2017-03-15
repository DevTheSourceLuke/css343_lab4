#include "stdafx.h"
#include <iostream>
#include "dvdfactory.h"

void DVDFactory::createDVDs(ifstream & infile, vector<BinarySearchTree<DVD>*> inventory)
{
	DVD* temp = NULL;
	while (!infile.eof())
	{
		char genre;

		infile >> genre;

		switch (genre)
		{
		case 'F':
			temp = new Comedy();
			if (temp->setData(infile))
			{
				if (!inventory[0]->insert(temp))
				{
					delete temp;
					temp = NULL;
				}
				temp = NULL;
			}
			else
			{
				delete temp;
				temp = NULL;
			}
			break;

		case 'D':
			temp = new Drama();
			if (temp->setData(infile))
			{
				if (!inventory[1]->insert(temp))
				{
					delete temp;
					temp = NULL;
				}
				temp = NULL;
			}
			else
			{
				delete temp;
				temp = NULL;
			}
			break;

		case 'C':
			temp = new Classic();
			if (temp->setData(infile))
			{
				if (!inventory[2]->insert(temp))
				{
					delete temp;
					temp = NULL;
				}
				temp = NULL;
			}
			else
			{
				delete temp;
				temp = NULL;
			}
			break;

		default:
			cout << "Invalid Movie Genre: " << genre << endl;
			infile.ignore(1000000, '\n');
			break;
		}
	}
}
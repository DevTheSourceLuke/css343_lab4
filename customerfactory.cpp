//#include "stdafx.h"
#include <iostream>
#include "customerfactory.h"

void CustomerFactory::createCustomer(ifstream & infile, HashTable& customers)
{
	Customer* temp = NULL;
	while (!infile.eof())
	{
		temp = new Customer();
		if (temp->setData(infile))
		{

			if (!customers.insertCustomer(temp))
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
	}
}

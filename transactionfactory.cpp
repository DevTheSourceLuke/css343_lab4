#include "stdafx.h"
#include <iostream>
#include "transactionfactory.h"

void TransactionFactory::createTransaction(ifstream & infile, queue<Transaction*> pending, HashTable& customers, vector<BinarySearchTree<DVD>*>& inventory)
{	
	cout << "Make transactions." << endl;
	Transaction* temp = NULL;

	
		while (!infile.eof())
		{
			char transactionType;

			infile >> transactionType;

			switch (transactionType) 
			{
			case 'I':
				temp = new transactionInventory();
				if(temp->setData(infile))
				{
					pending.push(temp);					
				}	
			}
		


	}



}

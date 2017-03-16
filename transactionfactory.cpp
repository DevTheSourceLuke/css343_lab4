#include "stdafx.h"
#include <iostream>
#include "transactionfactory.h"

void TransactionFactory::createTransaction(ifstream & infile, queue<Transaction*>& pending)
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
			if (temp->setData(infile))
			{
				pending.push(temp);
			}
			temp = NULL;
			break;

		case 'H':
			temp = new transactionHistory();
			if (temp->setData(infile))
			{
				pending.push(temp);
			}
			temp = NULL;
			break;

		case 'B':
			temp = new transactionBorrow();
			if (temp->setData(infile))
			{
				pending.push(temp);
			}
			temp = NULL;
			break;

		case 'R':
			temp = new transactionReturn();
			if (temp->setData(infile))
			{
				pending.push(temp);
			}
			temp = NULL;
			break;

		default:
			cout << "Invalid Transaction: " << transactionType << endl;
			infile.ignore(1000000, '\n');
			break;
		}
	}
}

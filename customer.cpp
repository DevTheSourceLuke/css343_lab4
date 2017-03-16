#include "stdafx.h"
#include "customer.h"

Customer::Customer(void)
{
}

Customer::~Customer(void)
{
	holding.clear();
	history.clear();
}

bool Customer::setData(ifstream & infile)
{
	int ID = -1;
	string first, last = "";
	infile >> ID >> last >> first;
	if (setID(ID) != true || setFirstName(first) != true || setLastName(last) != true)
	{
		cout << "Customer not created." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

void Customer::displayHistory(void) const
{
	for (int i = 0; i < history.size(); i++)
	{
		cout << history[i];
	}
}

void Customer::displayCustomer(void) const
{
	cout << "Customer: " << getID() << " " << getFirstName() << " " << getLastName() << endl;
}

void Customer::borrowMedia(DVD * movie, string transaction)
{
	int i = 0;
	bool done = false;
	while (i < holding.size() && done == false)
	{
		if (holding[i] == NULL)
		{
			holding[i] = movie;
			done = true;
		}
		i++;
	}
	if (done == false)
	{
		holding.push_back(movie);
	}
	addTransaction(transaction);
}

void Customer::addTransaction(string toAdd)
{
	history.push_back(toAdd);
}

void Customer::returnMedia(DVD * movie, string transaction)
{
	int i = 0;
	bool done = false;
	while (i < holding.size() && done == false)
	{
		if (holding[i] == movie)
		{
			delete holding[i];
			holding[i] = NULL;
			addTransaction(transaction);
			done = true;
		}
		i++;
	}
	if (done == false)
	{
		cout << "Movie: was not borrowed. Transaction : " << transaction << endl;
		
	}
}

int Customer::getID(void) const
{
	return ID;
}

string Customer::getFirstName(void) const
{
	return firstName;
}

string Customer::getLastName(void) const
{
	return lastName;
}

bool Customer::setID(int input)
{
	if (input > 999 && input < 10000)
	{
		ID = input;
		return true;
	}
	else
	{
		cout << "Invalid ID: " << input << endl;
		return false;
	}
}

bool Customer::setFirstName(string input)
{
	if (input.length() > 0)
	{
		firstName = input;
		return true;
	}
	else
	{
		cout << "Empty First Name" << endl;
		return false;
	}
}

bool Customer::setLastName(string input)
{
	if (input.length() > 0)
	{
		lastName = input;
		return true;
	}
	else
	{
		cout << "Empty Last Name" << endl;
		return false;
	}
}

Customer & Customer::operator=(const Customer & toCopy)
{
	ID = toCopy.getID();
	firstName = toCopy.getFirstName();
	lastName = toCopy.getLastName();
	return *this;
}

//#include "stdafx.h"
#include "transactionReturn.h"

transactionReturn::transactionReturn(void)
{
	inventory = NULL;
	customers = NULL;
	setTransactionType('R');
	customerID = 0;
	year = 0;
	month = 0;
	mediaType = ' ';
	genre = ' ';
	director = "";
	title = "";
	actor = "";
}

transactionReturn::~transactionReturn(void)
{
	inventory = NULL;
	customers = NULL;
}

bool transactionReturn::setData(ifstream & infile)
{
	string item1, item2;
	int id, num1, num2;
	char media, type;

	infile >> id >> media >> type;

	if (setGenre(type) && setMediaType(media) && setCustomerID(id))
	{
		switch (type)
		{
		case 'F':
			getline(infile, item1, ',');
			infile >> num1;

			if (setTitle(item1) && setYear(num1))
			{
				return true;
			}
			else
			{
				return false;
			}

		case 'D':
			getline(infile, item1, ',');
			getline(infile, item2, ',');

			if (setDirector(item1) && setTitle(item2))
			{
				return true;
			}
			else
			{
				return false;
			}

			break;

		case 'C':
			infile >> num1 >> num2 >> item1 >> item2;

			if (setDate(num2, num1) && setActor(item1 + " " + item2))
			{
				return true;
			}
			else
			{
				return false;
			}

			break;

		default:
			infile.ignore(1000000, '\n');
			return false;
		}
	}
	else
	{
		infile.ignore(1000000, '\n');
		return false;
	}
}

void transactionReturn::displayTransaction(void) const
{
	cout << toString() << endl;
}

string transactionReturn::toString(void) const
{
	string transaction = "R ";
	transaction += to_string(getCustomerID()) + " ";
	transaction += getGenre();
	transaction += " ";

	switch (genre)
	{
	case 'F':
		transaction += getTitle() + ", ";
		transaction += to_string(getYear());
		break;

	case 'D':
		transaction += getDirector() + ", ";
		transaction += getTitle() + ",";
		break;
	case 'C':
		transaction += to_string(getMonth()) + " ";
		transaction += to_string(getYear()) + " ";
		transaction += getActor();
		break;
	}

	return transaction;
}

void transactionReturn::processTransaction(HashTable& customers, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC)
{
	Customer* temp = NULL;
	temp = customers.getCustomer(getCustomerID());
	if (temp == NULL)
	{
		cout << "No Customer with this id exists: " << getCustomerID() << endl;
		delete temp;
		temp = NULL;
		return;
	}

	//DVD target;
	//DVD* returned = NULL;
	Classic targetC = Classic();
	Classic* returnedC = NULL;
	Drama targetD = Drama();
	Drama* returnedD = NULL;
	Comedy targetF = Comedy();
	Comedy* returnedF = NULL;

	switch (getGenre())
	{
	case 'C':

		targetC.setMonth(getMonth());
		targetC.setYear(getYear());
		targetC.setActor(getActor());
		inventoryC->retrieve(targetC, returnedC);
		if (returnedC == NULL)
		{
			cout << "This movie could not be found: " << getMonth() << " " << getYear() << " " << getActor() << endl;
		}
		else
		{
			temp->borrowMedia(returnedC, toString());
		}
		break;

	case 'D':

		targetD.setDirector(getDirector());
		targetD.setTitle(getTitle());
		inventoryD->retrieve(targetD, returnedD);
		if (returnedD == NULL)
		{
			cout << "This movie could not be found: " << getTitle() << " " << getDirector() << endl;
		}
		else
		{
			temp->borrowMedia(returnedD, toString());
		}
		break;

	case 'F':

		targetF.setTitle(getTitle());
		targetF.setYear(getYear());
		inventoryF->retrieve(targetF, returnedF);
		if (returnedF == NULL)
		{
			cout << "This movie could not be found: " << getTitle() << " " << getYear() << endl;
		}
		else
		{
			temp->borrowMedia(returnedF, toString());
		}
		break;

	default:
		cout << "No such genre available." << endl;
		break;
	}
}

int transactionReturn::getMonth(void) const
{
	return month;
}

int transactionReturn::getYear(void) const
{
	return year;
}

int transactionReturn::getCustomerID(void) const
{
	return customerID;
}

char transactionReturn::getMediaType(void) const
{
	return mediaType;
}

char transactionReturn::getGenre(void) const
{
	return genre;
}

string transactionReturn::getDirector(void) const
{
	return director;
}

string transactionReturn::getTitle(void) const
{
	return title;
}

string transactionReturn::getActor(void) const
{
	return actor;
}

bool transactionReturn::setCustomerID(int input)
{
	if (input > 999 && input < 10000)
	{
		customerID = input;
		return true;
	}
	else
	{
		cout << "Invalid ID: " << input << endl;
		return false;
	}
}

bool transactionReturn::setMediaType(char input)
{
	if (input == 'D')
	{
		mediaType = input;
	}
	else
	{
		cout << "Invalid Media Type: " << input << endl;
		return false;
	}
	return true;
}

bool transactionReturn::setGenre(char input)
{
	if (input == 'C' || input == 'D' || input == 'F')
	{
		genre = input;
	}
	else
	{
		cout << "Invalid Movie Type: " << input << endl;
		return false;
	}
	return true;
}

bool transactionReturn::setDirector(string input)
{
	if (input.length() != 0)
	{
		director = input;
		return true;
	}
	else
	{
		cout << "Empty Director Name" << endl;
		return false;
	}
}

bool transactionReturn::setTitle(string input)
{
	if (input.length() != 0)
	{
		title = input;
		return true;
	}
	else
	{
		cout << "Empty Title" << endl;
		return false;
	}
}

bool transactionReturn::setActor(string input)
{
	if (input.length() != 0)
	{
		actor = input;
		return true;
	}
	else
	{
		cout << "Empty Actor Name" << endl;
		return false;
	}
}

bool transactionReturn::setYear(int input)
{
	if (input >= 1927 && input < CURRENTYEAR + 1)
	{
		year = input;
		return true;
	}
	else
	{
		cout << "Invalic Year: " << input << endl;
		return false;
	}
}

bool transactionReturn::setDate(int inputY, int inputM)
{
	if (inputY >= 1927 && inputY < CURRENTYEAR + 1)
	{
		year = inputY;
		if (inputM > 0 && inputM <= 12)
		{
			month = inputM;
			return true;
		}
		else
		{
			cout << "Invalic Month: " << inputM << endl;
			return false;
		}
	}
	else
	{
		cout << "Invalic Year: " << inputY << endl;
		return false;
	}
}
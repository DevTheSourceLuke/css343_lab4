#include "stdafx.h"
#include "dvd.h"

DVD::DVD(void)
{

}

DVD::~DVD(void)
{

}

bool DVD::setData(ifstream & inFile)
{
	return false;
}

void DVD::display(void) const
{
	cout << "Movie : " << getTitle() << ", " << getDirector() << ", " << getYear() << ", " << getInventory() << endl;
}

string DVD::getTitle(void) const
{
	return title;
}

string DVD::getDirector(void) const
{
	return director;
}

string DVD::getActor(void) const
{
	return "";
}

int DVD::getInventory(void) const
{
	return inventory;
}

int DVD::getYear(void) const
{
	return year;
}

char DVD::getGenre(void) const
{
	return genre;
}

int DVD::getMonth(void) const
{
	return -1;
}

bool DVD::setTitle(string input)
{
	if (input.length() > 0)
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

bool DVD::setDirector(string input)
{
	if (input.length() > 0)
	{
		director = input;
		return true;
	}
	else
	{
		cout << "Empty Director" << endl;
		return false;
	}
}

bool DVD::setYear(int input)
{
	if (input >= 1927 && input < CURRENTYEAR + 1)
	{
		year = input;
		return true;
	}
	else
	{
		cout << "Invalid Year: " << input << endl;
		return false;
	}
}

bool DVD::setMonth(int input)
{
	if (input > 0 && input <= 12)
	{
		year = input;
		return true;
	}
	else
	{
		return false;
	}
}

bool DVD::adjustInventory(int input)
{
	if (inventory + input >= 0)
	{
		inventory += input;
		return true;
	}
	else
	{
		cout << "Inventory for " << getTitle() << " would be " << inventory + input << endl;
		return false;
	}
}

bool DVD::setGenre(char input)
{
	if (input == ' ')
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool DVD::setActor(string input)
{
	if (input == " ")
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool DVD::operator==(const DVD & toCompare) const
{
	return (getTitle().compare(toCompare.getTitle()) != 0 && getDirector().compare(toCompare.getDirector()) != 0);
	/*
	switch (getGenre())
	{
	case 'F':
		return (getTitle().compare(toCompare.getTitle()) != 0 && getDirector().compare(toCompare.getDirector()) != 0);
	case 'C':
		return (getActor().compare(toCompare.getActor()) != 0 && getMonth() == toCompare.getMonth() && getYear() == toCompare.getYear());
	case 'D':
		return (getTitle().compare(toCompare.getTitle()) != 0 && getDirector().compare(toCompare.getDirector()) != 0);
	default:
		cout << "False" << endl;
		return false;
	}*/
}

bool DVD::operator!=(const DVD & toCompare) const
{
	return false;
}

bool DVD::operator<(const DVD & toCompare) const
{
	return false;
}

bool DVD::operator>(const DVD & toCompare) const
{
	return false;
}

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
	return 0;
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
		cout << "Invalic Year: " << input << endl;
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

bool DVD::operator==(const DVD & toCompare) const
{
	return false;
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

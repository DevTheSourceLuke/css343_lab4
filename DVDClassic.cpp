#include "stdafx.h"
#include "DVDClassic.h"

Classic::Classic(void)
{
	setGenre('C');
	majorActor = "";
	releaseMonth = 0;
}

Classic::~Classic(void)
{
}

bool Classic::setData(ifstream & infile)
{
	int stock, year, month;
	string director, first, last, title;

	infile.ignore(1);
	infile >> stock;
	infile.ignore(1);
	getline(infile, director, ',');
	getline(infile, title, ',');
	infile >> first >> last >> month >> year;

	if (setActor(first + " " + last) == true && setDirector(director) == true && setMonth(month) == true && setYear(year) == true && setTitle(title) == true && adjustInventory(stock) == true)
	{	
		setOtherStock(this);
		return true;
	}
	else
	{
		cout << "Classic DVD not created." << endl;
		return false;
	}
}

void Classic::display(void) const
{
	cout << "Movie : " << getTitle() << ", " << getDirector() << ", " << getActor() << ", " << getYear() << ", " << getMonth() << ", " << getInventory() << endl;
}

string Classic::getActor(void) const
{
	return majorActor;
}

int Classic::getMonth(void) const
{
	return releaseMonth;
}

bool Classic::operator==(const DVD & toCompare) const
{
	return (getActor().compare(toCompare.getActor()) != 0 && getMonth() == toCompare.getMonth() && getYear() == toCompare.getYear());
}

bool Classic::operator!=(const DVD & toCompare) const
{
	return !(*this == toCompare);
}

bool Classic::operator<(const DVD & toCompare) const
{
	if (getYear() < toCompare.getYear())
	{
		return true;
	}
	else if (getYear() == toCompare.getYear())
	{
		if (getMonth() < toCompare.getMonth())
		{
			return true;
		}
		else if (getMonth() == toCompare.getMonth())
		{
			if (getActor().compare(toCompare.getActor()) < 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Classic::operator>(const DVD & toCompare) const
{
	if (getYear() > toCompare.getYear())
	{
		return true;
	}
	else if (getYear() == toCompare.getYear())
	{
		if (getMonth() > toCompare.getMonth())
		{
			return true;
		}
		else if (getMonth() == toCompare.getMonth())
		{
			if (getActor().compare(toCompare.getActor()) < 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Classic::setOtherStock(Classic* dupe)
{
	if (otherStock == NULL)
	{
		return false;
	}
	otherStock = dupe;
	return true;
}

Classic* Classic::getOtherStock(void)
{
	return otherStock;
}

bool Classic::setActor(string input)
{
	if (input.length() > 0)
	{
		majorActor = input;
		return true;
	}
	else
	{
		cout << "Empty Actor" << endl;
		return false;
	}
}

bool Classic::setMonth(int input)
{
	if (input > 0 && input < 13)
	{
		releaseMonth = input;
		return true;
	}
	else
	{
		cout << "Invalid Month: " << input << endl;
		return false;
	}
}

#include "stdafx.h"
#include "DVDDrama.h"

Drama::Drama(void)
{
	setGenre('D');
}

Drama::~Drama(void)
{
}

bool Drama::setData(ifstream & infile)
{
	int stock, year;
	string director, title;

	infile.ignore(1);
	infile >> stock;
	infile.ignore(1);
	getline(infile, director, ',');
	getline(infile, title, ',');
	infile >> year;

	if (true && setDirector(director) == true && setYear(year) == true && setTitle(title) == true && adjustInventory(stock) == true)
	{
		return true;
	}
	else
	{
		cout << "Drama DVD not created." << endl;
		return false;
	}
}

bool Drama::operator==(const DVD & toCompare) const
{
	return (getTitle().compare(toCompare.getTitle()) != 0 && getDirector().compare(toCompare.getDirector()) != 0 && getYear() == toCompare.getYear());
}

bool Drama::operator!=(const DVD & toCompare) const
{
	return !(*this == toCompare);
}

bool Drama::operator<(const DVD & toCompare) const
{
	if (getDirector().compare(toCompare.getDirector()) < 0)
	{
		return true;
	}
	else if (getDirector().compare(toCompare.getDirector()) == 0)
	{
		if (getTitle().compare(toCompare.getTitle()) < 0)
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

bool Drama::operator>(const DVD & toCompare) const
{
	if (getDirector().compare(toCompare.getDirector()) > 0)
	{
		return true;
	}
	else if (getDirector().compare(toCompare.getDirector()) == 0)
	{
		if (getTitle().compare(toCompare.getTitle()) > 0)
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

#include "stdafx.h"
#include "DVDComedy.h"

Comedy::Comedy(void)
{
	setGenre('F');
}

Comedy::~Comedy(void)
{
}

bool Comedy::setData(ifstream & infile)
{
	int stock, year;
	string director, title;

	infile.ignore(1);
	infile >> stock;
	infile.ignore(1);
	getline(infile, director, ',');
	getline(infile, title, ',');
	infile >> year;

	if (setDirector(director) == true && setYear(year) == true && setTitle(title) == true && adjustInventory(stock) == true)
	{
		return true;
	}
	else
	{
		cout << "Comedy DVD not created." << endl;
		return false;
	}
}

bool Comedy::operator==(const DVD & toCompare) const
{
	if (toCompare.getTitle().front() == ' ')
	{
		string title = toCompare.getTitle();
		title = title.substr(1, title.length());
		return (getTitle().compare(title) != 0 && getYear() == toCompare.getYear());
	}
	return (getTitle().compare(toCompare.getTitle()) != 0 && getYear() == toCompare.getYear());
}

bool Comedy::operator!=(const DVD & toCompare) const
{
	return !(*this == toCompare);
}

bool Comedy::operator<(const DVD & toCompare) const
{
	if (getTitle().compare(toCompare.getTitle()) < 0)
	{
		return true;
	}
	else if (getTitle().compare(toCompare.getTitle()) == 0)
	{
		if (getYear() < toCompare.getYear())
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

bool Comedy::operator>(const DVD & toCompare) const
{
	if (getTitle().compare(toCompare.getTitle()) > 0)
	{
		return true;
	}
	else if (getTitle().compare(toCompare.getTitle()) == 0)
	{
		if (getYear() > toCompare.getYear())
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

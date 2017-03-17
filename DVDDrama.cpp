//#include "stdafx.h"
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
	infile.ignore(2);
	getline(infile, director, ',');
	infile.ignore(1);
	getline(infile, title, ',');
	infile >> year;

	if (setDirector(director) == true && setYear(year) == true && setTitle(title) == true && adjustInventory(stock) == true)
	{
		return true;
	}
	else
	{
		cout << "Drama DVD not created." << endl;
		return false;
	}
}

void Drama::display(void) const
{
	cout << "Movie : D, " << getInventory() << ", " << getDirector() << ", " << getTitle() << ", " << getYear() << endl;
}

bool Drama::operator==(const DVD & toCompare) const
{
	if (toCompare.getTitle().front() == ' ')
	{
		if (toCompare.getDirector().front() == ' ')
		{
			string title = toCompare.getTitle();
			title = title.substr(1, title.length());
			string director = toCompare.getDirector();
			director = director.substr(1, director.length());
			return (getTitle().compare(title) == 0 && getDirector().compare(director) == 0);
		}
		else
		{
			string title = toCompare.getTitle();
			title = title.substr(1, title.length());
			return (getTitle().compare(title) == 0 && getDirector().compare(toCompare.getDirector()) == 0);
		}
	}
	return (getTitle().compare(toCompare.getTitle()) == 0 && getDirector().compare(toCompare.getDirector()) == 0);
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
#include "stdafx.h"
#include "DVDComedy.h"

Comedy::Comedy(void)
{
}

Comedy::~Comedy(void)
{
}

bool Comedy::operator==(const DVD & toCompare) const
{
	return (getTitle().compare(toCompare.getTitle()) != 0 && getDirector().compare(toCompare.getDirector()) != 0 && getYear() == toCompare.getYear());
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

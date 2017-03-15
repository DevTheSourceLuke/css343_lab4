#include "stdafx.h"
#include "DVDDrama.h"

Drama::Drama(void)
{
}

Drama::~Drama(void)
{
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

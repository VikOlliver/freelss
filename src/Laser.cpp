/*
 ****************************************************************************
 *  Copyright (c) 2014 Uriah Liggett <hairu526@gmail.com>                   *
 *	This file is part of FreeLSS.                                           *
 *                                                                          *
 *  FreeLSS is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by    *
 *  the Free Software Foundation, either version 3 of the License, or       *
 *  (at your option) any later version.                                     *
 *                                                                          *
 *  FreeLSS is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *  GNU General Public License for more details.                            *
 *                                                                          *
 *   You should have received a copy of the GNU General Public License      *
 *   along with FreeLSS.  If not, see <http://www.gnu.org/licenses/>.       *
 ****************************************************************************
*/

#include "Main.h"
#include "Laser.h"
#include "RelayLaser.h"
#include "ArduinoLaser.h"

namespace scanner
{

Laser * Laser::m_instance = NULL;

Laser::Laser()
{
	// Do nothing
}

Laser::~Laser()
{
	// Do nothing
}

Laser * Laser::getInstance()
{
	if (m_instance == NULL)
	{
        #ifdef USE_LINUX_HARDWARE
    		m_instance = new ArduinoLaser();
        #else
            m_instance = new RelayLaser();
        #endif
	}

	return m_instance;
}

void Laser::release()
{
	delete m_instance;
	m_instance = NULL;
}

std::string Laser::toString(Laser::LaserSide side)
{
	std::string str = "";

	if (side == RIGHT_LASER)
	{
		str = "RIGHT_LASER";
	}
	else if (side == LEFT_LASER)
	{
		str = "LEFT_LASER";
	}
	else if (side == ALL_LASERS)
	{
		str = "ALL_LASERS";
	}

	return str;
}

} // ns scanner

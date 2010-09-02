//----------------------------------------------------
//
// GPL code license:
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//----------------------------------------------------------
//
// VC:MP Multiplayer Modification For GTA:VC
// Copyright 2004-2005 SA:MP team
//
// File Author(s): kyeman
//                 jenksta
//
//----------------------------------------------------------

#pragma once

#include "common.h"

#define ENTITY_TYPE_UNKNOWN		0
#define ENTITY_TYPE_PED			1
#define ENTITY_TYPE_VEHICLE		2

class CEntity
{
private:
	ENTITY_TYPE	* m_pEntity;

public:
	ENTITY_TYPE * GetEntity();
	void		  SetEntity(ENTITY_TYPE * pEntity);

	void		  GetMatrix(MATRIX4X4 * matMatrix);
	void		  SetMatrix(MATRIX4X4 matMatrix);
	void          GetPosition(Vector3 * vecPosition);
	void          SetPosition(Vector3 vecPosition);
	void          SetHeading(float fHeading);

	WORD		  GetModelIndex();

	BOOL          IsOnScreen();
};
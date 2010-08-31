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
//---------------------------------------------------
//
// VC:MP Multiplayer Modification For GTA:VC
// Copyright 2004-2005 SA:MP team
//
// File Author: kyeman
//
//---------------------------------------------------

#pragma once

typedef struct _VEHICLE_SPAWN_INFO
{
	BYTE byteVehicleType;
	Vector3 vecPos;
	float fRotation;
	int iColor1;
	int iColor2;
} VEHICLE_SPAWN_INFO;

//----------------------------------------------------

class CVehiclePool
{
private:	
	BOOL				m_bVehicleSlotState[MAX_VEHICLES];
	CVehicle			*m_pVehicles[MAX_VEHICLES];
	VEHICLE_SPAWN_INFO	m_SpawnInfo[MAX_VEHICLES];
	BOOL				m_bIsActive[MAX_VEHICLES];
	BOOL				m_bIsWasted[MAX_VEHICLES];

public:
	
	CVehiclePool();
	~CVehiclePool();

	BOOL New(EntityId vehicleID, BYTE byteVehicleType,
			 Vector3 * vecPos, float fRotation,
			 int iColor1, int iColor2,
			 Vector3 * vecSpawnPos, float fSpawnRotation);

	BOOL Delete(EntityId vehicleID);	

	CVehicle* GetAt(EntityId vehicleID) {
		if(vehicleID > MAX_VEHICLES) { return NULL; }
		return m_pVehicles[vehicleID];
	};

	BOOL GetSlotState(EntityId vehicleID) {
		if(vehicleID > MAX_VEHICLES) { return FALSE; }
		return m_bVehicleSlotState[vehicleID];
	};

	BOOL Spawn( EntityId vehicleID, BYTE byteVehicleType,
				Vector3 * vecPos, float fRotation,
				int iColor1, int iColor2 );

	int FindIDFromGtaPtr(VEHICLE_TYPE * pGtaVehicle);
	int FindGtaIDFromID(int iID);

	void SendVehicleDeath(EntityId vehicleID);

	void Process();
};

//----------------------------------------------------
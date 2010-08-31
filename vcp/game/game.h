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
// File Author: kyeman
//
//----------------------------------------------------------

#pragma once

#include "address.h"
#include "common.h"
#include "vehicle.h"
#include "playerped.h"
#include "camera.h"
#include "scripting.h"

//-----------------------------------------------------------

#define FUNC_RequestModel 0x40E310
#define FUNC_LoadRequestedModels 0x40B5F0
#define VAR_ModelInfo 0x94DDD8
#define CClock__SetTime 0x487160
#define ADDR_Set_Cash	0x94ADC8

//-----------------------------------------------------------

enum eGameState
{
	GS_START,
	GS_SHOWLOGO,
	GS_LOGOPROCESS,
	GS_SHOWTITLES,
	GS_TITLESPROCESS,
	GS_PREINITGAME,
	GS_SELVIDEOMODE,
	GS_MENUPROCESS,
	GS_LOADGAME,
	GS_SHUTDOWN,
};

//-----------------------------------------------------------


class CGame
{
public:
	

	CPlayerPed *NewPlayer(int iSystemAddress, int iModel,float fPosX,float fPosY,float fPosZ,float fRotation);
	CVehicle *NewVehicle(int iType,float fPosX,float fPosY,float fPosZ,float fRotation);
		
	int		GetWeaponModelFromWeapon(int iWeaponID);
	void	ToggleKeyInputsDisabled(BOOL bDisable);
	void	StartGame();
	BOOL	IsMenuActive();
	void	RequestModel(int iModelID);
	void	LoadRequestedModels();
	BOOL	IsModelLoaded(int iModelID);
	void	DisplayHud(BOOL bSwitch);
	void	ToggleHud(bool bToggle);
	void	HideRadar(bool bToggle);
	void	ToggleFrameLimiterState(BOOL bState);
	BOOL    GetFrameLimiterState();
	void    SetDrawDistance(DWORD dwDrawDistance);
	DWORD   GetDrawDistance();
	void    SetBrightness(DWORD dwBrightness);
	DWORD   GetBrightness();
	void    SetWidescreen(BOOL bWidescreen);
	BOOL    GetWidescreen();
	void	DisplayTextMessage(PCHAR szText);
	void    PlaySound(int iSoundId, Vector3 vPosition);
	void    FadeScreen(int iType, int iTime);
	void	SetGameTime(BYTE hours, BYTE minutes);
	void	SetCash(int Cash);

	DWORD	GetD3DDevice() { return *(DWORD *)ADDR_ID3D8DEVICE; };
	void	SetD3DDevice(DWORD pD3DDevice) { *(DWORD *)ADDR_ID3D8DEVICE = pD3DDevice; };
	DWORD	GetD3D() { return *(DWORD *)ADDR_ID3D8DEVICE; };
	void	SetD3D(DWORD pD3D) {	*(DWORD *)ADDR_ID3D8 = pD3D; };
	HWND	GetMainWindowHwnd() { return *(HWND *)ADDR_HWND; };

	//-----------------------------------------------------------

	CPlayerPed  *FindPlayerPed() {
		if(m_pInternalPlayer==NULL)	m_pInternalPlayer = new CPlayerPed();
		return m_pInternalPlayer;
	};
	
	CCamera     *GetCamera() {	return m_pInternalCamera; };

	//-----------------------------------------------------------

	void EnablePassengerEngineAudio() {
		*(BYTE *)0x5F2175 = 0x3B;
		*(BYTE *)0x5F2176 = 0xC2;
	};

	void DisablePassengerEngineAudio() {
		*(BYTE *)0x5F2175 = 0x39;
		*(BYTE *)0x5F2176 = 0xF0;
	};

	//-----------------------------------------------------------

	eGameState GetGameState() {
		return *(eGameState *)VAR_GameState;
	}

	void SetGameState(eGameState state) {
		*(eGameState *)VAR_GameState = state;
	}

	//-----------------------------------------------------------

	CGame();
	~CGame() {};

private:

	CCamera			*m_pInternalCamera;
	CPlayerPed		*m_pInternalPlayer;
};

//-----------------------------------------------------------

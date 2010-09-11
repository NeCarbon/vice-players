//-----------------------------------------------------
//
// VC:Players Multiplayer Modification For GTA:VC
// Copyright 2010 GTA:Online team
//
// File Author(s): adamix
// License: See LICENSE in root directory
//
//-----------------------------------------------------

#include "../main.h"

extern IDirect3DDevice8 *pD3DDevice;
extern CChatWindow * pChatWindow;

CText::CText(EntityId TextID, DWORD color, char * szFontName, int iSize, float posX, float posY, char * szText)
{
	m_iID = TextID;

	m_dwColor = color;
	m_szText = new char[strlen(szText)+1];
	memcpy(m_szText, szText, strlen(szText)+1);
	m_fPosX = posX;
	m_fPosY = posY;
	
	m_bShow = false;

	m_pFont = new CD3DFont(szFontName, iSize, 0);
	if(m_pFont)
	{
		m_pFont->InitDeviceObjects(pD3DDevice);
		m_pFont->RestoreDeviceObjects();
	}

}

CText::~CText()
{

}

void CText::Process()
{
	if(m_bShow)
	{
		if(!m_pFont) return;
		
		D3DDISPLAYMODE DisplayMode;
		pD3DDevice->GetDisplayMode(&DisplayMode);

		float posX, posY;
		posX = ((DisplayMode.Width / 100) * m_fPosX);
		posY = ((DisplayMode.Height / 100) * m_fPosY);

		m_pFont->DrawText(posX, posY, m_dwColor, m_szText);
	}
}
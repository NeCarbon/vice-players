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
//-----------------------------------------------------
//
// VC:Players Multiplayer Modification For GTA:VC
// Copyright 2010 GTA:Online team
//
//-----------------------------------------------------

#include "sq_timer_natives.h"
#include "scripts.h"
#include "../main.h"

extern CNetGame *pNetGame;
extern CScripts *pScripts;

using namespace RakNet;

SQInteger sq_setScriptAuthor(SQVM * pVM)
{
	for(int i = 0; i < MAX_SCRIPTS; i++)
	{
		if(pScripts->GetScript(i))
		{
			if(pScripts->GetScript(i)->GetVM() == pVM)
			{
				CScript * pScript = pScripts->GetScript(i);
				const SQChar * szAuthor;
				sq_getstring(pVM, -1, &szAuthor);
				pScript->SetScriptAuthor(szAuthor);
				sq_pushbool(pVM, true);
				return 1;
			}
		}
	}
	sq_pushbool(pVM, false);
	return 1;
}

SQInteger sq_setScriptVersion(SQVM * pVM)
{
	for(int i = 0; i < MAX_SCRIPTS; i++)
	{
		if(pScripts->GetScript(i))
		{
			if(pScripts->GetScript(i)->GetVM() == pVM)
			{
				CScript * pScript = pScripts->GetScript(i);
				const SQChar * szVersion;
				sq_getstring(pVM, -1, &szVersion);
				pScript->SetScriptVersion(szVersion);
				sq_pushbool(pVM, true);
				return 1;
			}
		}
	}
	sq_pushbool(pVM, false);
	return 1;
}
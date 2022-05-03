/*
	░█████╗░██╗░░██╗███████╗██████╗░░█████╗░░░░██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░
	██╔══██╗╚██╗██╔╝██╔════╝██╔══██╗██╔══██╗░░░██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░
	███████║░╚███╔╝░█████╗░░██████╔╝███████║░░░██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░
	██╔══██║░██╔██╗░██╔══╝░░██╔══██╗██╔══██║░░░██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░
	██║░░██║██╔╝╚██╗███████╗██║░░██║██║░░██║██╗██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗
	╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝

	-- Axera.Digital Vision GUI ( Open Source )

	-- Coded by noodle@axera.digital && sonic@axera.digital

	-- Visit Us @https://axera.digital && https://discord.gg/axera
*/

#pragma once

namespace GlobalVars
{
	int iTab = 0;
	bool bExit = false;
};

namespace ESPVars
{
	bool b2DBox = false;
	bool b2DBrackets = false;
	bool bSnaplines = false;
	bool bSkeleton = false;
	bool bCrosshair = false;
};

namespace AimVars
{
	bool bAimLock = false;
	bool bAimHead = false;
	bool bAimNeck = false;
	bool bAimChest = false;
	bool bAimButton = false;
};

namespace MiscVars
{
	bool bMisc1 = false;
	bool bMisc2 = false;
	bool bMisc3 = false;
	bool bMisc4 = false;
	bool bMisc5 = false;
	bool bMisc6 = false;
	bool bMisc7 = false;
	bool bMisc8 = false;
	bool bMisc9 = false;
	bool bMisc10 = false;
};

namespace SettingVars
{
	float exampleColor1[4] = { 1, 1, 1, 1 };
	float exampleColor2[4] = { 1, 1, 1, 1 };
	float exampleColor3[4] = { 1, 1, 1, 1 };
	float exampleColor4[4] = { 1, 1, 1, 1 };
	float exampleColor5[4] = { 1, 1, 1, 1 };
	float exampleColor6[4] = { 1, 1, 1, 1 };
	float exampleColor7[4] = { 1, 1, 1, 1 };
	float exampleColor8[4] = { 1, 1, 1, 1 };
	float exampleColor9[4] = { 1, 1, 1, 1 };
	float exampleColor10[4] = { 1, 1, 1, 1 };
	ImColor exampleImColor1 = ImColor(exampleColor1[0], exampleColor1[1], exampleColor1[2]);
	ImColor exampleImColor2 = ImColor(exampleColor2[0], exampleColor2[1], exampleColor2[2]);
	ImColor exampleImColor3 = ImColor(exampleColor3[0], exampleColor3[1], exampleColor3[2]);
	ImColor exampleImColor4 = ImColor(exampleColor4[0], exampleColor4[1], exampleColor4[2]);
	ImColor exampleImColor5 = ImColor(exampleColor5[0], exampleColor5[1], exampleColor5[2]);
	ImColor exampleImColor6 = ImColor(exampleColor6[0], exampleColor6[1], exampleColor6[2]);
	ImColor exampleImColor7 = ImColor(exampleColor7[0], exampleColor7[1], exampleColor7[2]);
	ImColor exampleImColor8 = ImColor(exampleColor8[0], exampleColor8[1], exampleColor8[2]);
	ImColor exampleImColor9 = ImColor(exampleColor9[0], exampleColor9[1], exampleColor9[2]);
	ImColor exampleImColor10 = ImColor(exampleColor10[0], exampleColor10[1], exampleColor10[2]);
};
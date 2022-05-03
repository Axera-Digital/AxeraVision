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
#include "../imgui/imgui_internal.h"
#include <string>
#include <vector>
#include <functional>
#include "../Global_Vars/Global_Vars.h"

#define MAX_RGB 255.0
#define HELPMARKERDESC(str) ImGui::SameLine(); ImGui::TextColored(ImColor(0, 130, 15, 255), "[ ? ]"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#define HELPMARKERDISC(str) ImGui::SameLine(); ImGui::TextColored(ImColor(0, 130, 15, 255), "[ * ]"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#pragma warning(disable: 26812 26815)

namespace ImGui
{
	void Line(int newId)
	{
		std::string id = ("ImGui_Sauce_line_" + std::to_string(newId));
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		{
			ImGui::BeginChild(id.c_str(), ImVec2(ImGui::GetContentRegionAvail().x, 1), false);
			ImGui::Separator();
			ImGui::EndChild();
		}
		ImGui::PopStyleColor();
	}

	void Linevertical()
	{
		ImGui::SameLine();
		ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
		ImGui::SameLine();
	}

	void CenterText(const char* text, int lineId, bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			Line(lineId);
	}

	void CenterTextEx(const char* text, float width, int lineId, bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((width / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			Line(lineId);
	}

	float GetX()
	{
		return ImGui::GetContentRegionAvail().x;
	}

	float GetY()
	{
		return ImGui::GetContentRegionAvail().y;
	} 

	void UITheme()
	{
		ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_PickerHueWheel);
		ImGuiStyle* Style = &ImGui::GetStyle();
		Style->WindowBorderSize = 4;
		Style->FrameBorderSize = 0;
		Style->WindowRounding = 4;
		Style->ChildRounding = 4;
		Style->ChildBorderSize = 4;
		Style->FrameRounding = 4;
		Style->ScrollbarSize = 0;
		Style->WindowPadding = ImVec2(0, 0);
		Style->FramePadding = ImVec2(0, 0);
		Style->ItemSpacing = ImVec2(0, 0);
		Style->ItemInnerSpacing = ImVec2(0, 0);
		Style->IndentSpacing = 0;
		Style->DisplayWindowPadding = ImVec2(0, 0);
		Style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
		Style->Colors[ImGuiCol_Border] = ImColor(40, 40, 40, 155);
		Style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
		Style->Colors[ImGuiCol_FrameBg] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_FrameBgActive] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_SliderGrab] = ImColor(255, 255, 255);
		Style->Colors[ImGuiCol_SliderGrabActive] = ImColor(255, 255, 255);
	}

	void DisplayESPFeatures()
	{
		if (GlobalVars::iTab == 0)
		{
			ImGui::NewLine();
			ImGui::CenterText("-- ESP Features --", 0, false);
			ImGui::NewLine();
			// Left Side Features
			ImGui::Indent(75);
			ImGui::Checkbox("  2D Box", &ESPVars::b2DBox);
			ImGui::NewLine();
			ImGui::Checkbox("  2D Brackets", &ESPVars::b2DBrackets);
			ImGui::NewLine();
			ImGui::Checkbox("  Snaplines", &ESPVars::bSnaplines);
			ImGui::NewLine();
			ImGui::Checkbox("  Skeleton", &ESPVars::bSkeleton);
			ImGui::NewLine();
			ImGui::Checkbox("  Crosshair", &ESPVars::bCrosshair);
			ImGui::Unindent(75);
			// Right Side Features
			ImGui::SetCursorPos(ImVec2(300, 121));
			ImGui::Checkbox("  2D Box", &ESPVars::b2DBox);
			ImGui::NewLine();
			ImGui::Indent(300);
			ImGui::Checkbox("  2D Brackets", &ESPVars::b2DBrackets);
			ImGui::NewLine();
			ImGui::Checkbox("  Snaplines", &ESPVars::bSnaplines);
			ImGui::NewLine();
			ImGui::Checkbox("  Skeleton", &ESPVars::bSkeleton);
			ImGui::NewLine();
			ImGui::Checkbox("  Crosshair", &ESPVars::bCrosshair);
			ImGui::Unindent(300);
		}
	}

	void DisplayAimFeatures()
	{
		if (GlobalVars::iTab == 1)
		{
			ImGui::NewLine();
			ImGui::CenterText("-- Aim Features --", 0, false);
			ImGui::NewLine();
			// Left Side Features
			ImGui::Indent(75);
			ImGui::Checkbox("  Aim Lock", &AimVars::bAimLock);
			ImGui::NewLine();
			ImGui::Checkbox("  Aim -> Head", &AimVars::bAimHead);
			ImGui::NewLine();
			ImGui::Checkbox("  Aim -> Neck", &AimVars::bAimNeck);
			ImGui::NewLine();
			ImGui::Checkbox("  Aim - > Chest", &AimVars::bAimChest);
			ImGui::NewLine();
			ImGui::Checkbox("  Aim Button", &AimVars::bAimButton);
			ImGui::Unindent(75);
			// Right Side Features
			ImGui::SetCursorPos(ImVec2(300, 121));
			ImGui::Checkbox("  Aim Lock", &AimVars::bAimLock);
			ImGui::NewLine();
			ImGui::Indent(300);
			ImGui::Checkbox("  Aim -> Head", &AimVars::bAimHead);
			ImGui::NewLine();
			ImGui::Checkbox("  Aim -> Neck", &AimVars::bAimNeck);
			ImGui::NewLine();
			ImGui::Checkbox("  Aim - > Chest", &AimVars::bAimChest);
			ImGui::NewLine();
			ImGui::Checkbox("  Aim Button", &AimVars::bAimButton);
			ImGui::Unindent(300);
		}
	}

	void DisplayMiscFeatures()
	{
		if (GlobalVars::iTab == 2)
		{
			ImGui::NewLine();
			ImGui::CenterText("-- Misc Features --", 0, false);
			ImGui::NewLine();
			// Left Side Features
			ImGui::Indent(75);
			ImGui::Checkbox("  Feature 1", &MiscVars::bMisc1);
			ImGui::NewLine();
			ImGui::Checkbox("  Feature 2", &MiscVars::bMisc2);
			ImGui::NewLine();
			ImGui::Checkbox("  Feature 3", &MiscVars::bMisc3);
			ImGui::NewLine();
			ImGui::Checkbox("  Feature 4", &MiscVars::bMisc4);
			ImGui::NewLine();
			ImGui::Checkbox("  Feature 5", &MiscVars::bMisc5);
			ImGui::Unindent(75);
			// Right Side Features
			ImGui::SetCursorPos(ImVec2(300, 121));
			ImGui::Checkbox("  Feature 6", &MiscVars::bMisc6);
			ImGui::NewLine();
			ImGui::Indent(300);
			ImGui::Checkbox("  Feature 7", &MiscVars::bMisc7);
			ImGui::NewLine();
			ImGui::Checkbox("  Feature 8", &MiscVars::bMisc8);
			ImGui::NewLine();
			ImGui::Checkbox("  Feature 9", &MiscVars::bMisc9);
			ImGui::NewLine();
			ImGui::Checkbox("  Feature 10", &MiscVars::bMisc10);
			ImGui::Unindent(300);
		}
	}

	void DisplaySettings()
	{
		if (GlobalVars::iTab == 3)
		{
			ImGui::NewLine();
			ImGui::CenterText("-- Settings --", 0, false);
			ImGui::NewLine();
			// Left Side Features
			ImGui::Indent(75);
			ImGui::ColorEdit3("##ColorEdit1", (float*)&SettingVars::exampleImColor1, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 1");
			ImGui::NewLine();
			ImGui::ColorEdit3("##ColorEdit2", (float*)&SettingVars::exampleImColor2, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 2");
			ImGui::NewLine();
			ImGui::ColorEdit3("##ColorEdit3", (float*)&SettingVars::exampleImColor3, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 3");
			ImGui::NewLine();
			ImGui::ColorEdit3("##ColorEdit4", (float*)&SettingVars::exampleImColor4, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 4");
			ImGui::NewLine();
			ImGui::ColorEdit3("##ColorEdit5", (float*)&SettingVars::exampleImColor5, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 5");
			ImGui::Unindent(75);
			// Right Side Features
			ImGui::SetCursorPos(ImVec2(300, 121));
			ImGui::ColorEdit3("##ColorEdit6", (float*)&SettingVars::exampleImColor6, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 6");
			ImGui::NewLine();
			ImGui::Indent(300);
			ImGui::ColorEdit3("##ColorEdit7", (float*)&SettingVars::exampleImColor7, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 7");
			ImGui::NewLine();
			ImGui::ColorEdit3("##ColorEdit8", (float*)&SettingVars::exampleImColor8, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 8");
			ImGui::NewLine();
			ImGui::ColorEdit3("##ColorEdit9", (float*)&SettingVars::exampleImColor9, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 9");
			ImGui::NewLine();
			ImGui::ColorEdit3("##ColorEdit10", (float*)&SettingVars::exampleImColor10, ImGuiColorEditFlags_NoInputs);
			ImGui::SameLine();
			ImGui::Text("  Color 10");
			ImGui::Unindent(300);
		}
	}
}
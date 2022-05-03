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

#pragma comment (lib, "dwmapi.lib")
#pragma comment (lib, "winmm.lib")
#define IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
#include "UI.h"
#include "UI_Sauce.h"
#include "../Fonts/Roboto-Bold.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include <dwmapi.h>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <random>
#pragma comment(lib,"d3d9.lib")

LPDIRECT3DDEVICE9        g_pd3dDevice;
D3DPRESENT_PARAMETERS    g_d3dpp;
LPDIRECT3D9              g_pD3D;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hwnd = nullptr;

bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;
    return true;
}

void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

std::string chars{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?" };
std::random_device rd;
std::mt19937 generator(rd());
// Randomize String.
std::string RandStr(size_t length)
{
    const size_t char_size = chars.size();
    std::uniform_int_distribution<> random_int(0, char_size - 1);
    std::string output;
    for (size_t i = 0; i < length; ++i)
        output.push_back(chars[random_int(generator)]);
    return output;
}
std::string sRandWin = RandStr(12);
std::string sRandBegin = RandStr(12);
std::string sRandChild1 = RandStr(12);
std::string sRandChild2 = RandStr(12);
std::string sRandChild3 = RandStr(12);
std::string sRandChild4 = RandStr(12);
std::string sRandChild5 = RandStr(12);

void Overlay::Loop()
{
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, sRandWin.c_str(), NULL};
    RegisterClassEx(&wc);
    hwnd = CreateWindow(wc.lpszClassName, sRandWin.c_str(), WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    if (CreateDeviceD3D(hwnd) < 0)
    {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return;
    }

    ShowWindow(hwnd, FALSE);
    UpdateWindow(hwnd);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = NULL;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows

    ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(Roboto_compressed_data, Roboto_compressed_size, 17.f, nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());

    ImGui::StyleColorsDark();
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);
    
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            Render::UI();
            if (GetAsyncKeyState(VK_HOME))
            {
                exit(0);
            }
        }
        ImGui::EndFrame();
        ImGui::Render();
    
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
    
        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }
    
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
    
        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
    }
    
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    
    CleanupDeviceD3D();
    DestroyWindow(hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);
    
    return;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

ImVec2 screen_Size = ImVec2(WND_SIZEX, WND_SIZEY);

void Render::UI()
{
    ImGui::UITheme();

    ImGui::SetNextWindowPos(ImVec2(screen_Size.x / 2.75, screen_Size.y / 2.75), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Always);

    if (ImGui::Begin(sRandBegin.c_str(), 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar)) 
    {
        // Display Main Child Window that stores all other Child Windows
        ImGui::SetCursorPos(ImVec2(10, 10));
        if (ImGui::BeginChild(sRandChild1.c_str(), ImVec2(480, 380), true, ImGuiWindowFlags_NoDecoration))
        {
            // Display Child Window that shows Header
            ImGui::SetCursorPos(ImVec2(10, 10));
            if (ImGui::BeginChild(sRandChild2.c_str(), ImVec2(460, 60), true, ImGuiWindowFlags_NoDecoration))
            {
                ImGui::NewLine();
                ImGui::CenterText("- AxeraVision -", 0, false);
            } ImGui::EndChild();

            // Display ESP Features
            ImGui::DisplayESPFeatures();

            // Display Aim Features
            ImGui::DisplayAimFeatures();

            // Display Misc Features
            ImGui::DisplayMiscFeatures();

            // Display Settings
            ImGui::DisplaySettings();

            // Left Side Child Window ( Empty )
            ImGui::SetCursorPos(ImVec2(10, 80));
            if (ImGui::BeginChild(sRandChild3.c_str(), ImVec2(30, 220), true, ImGuiWindowFlags_NoDecoration))
            {
                // Just for Design ( Add Text here to make it more unique? )
                ImGui::SetCursorPosY(30);
                ImGui::CenterText("A", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("X", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("E", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("R", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("A", 0, false);
            } ImGui::EndChild();

            // Right Side Child Window ( Empty )
            ImGui::SetCursorPos(ImVec2(440, 80));
            if (ImGui::BeginChild(sRandChild4.c_str(), ImVec2(30, 220), true, ImGuiWindowFlags_NoDecoration))
            {
                // Just for Design ( Add Text here to make it more unique? )
                ImGui::SetCursorPosY(30);
                ImGui::CenterText("A", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("X", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("E", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("R", 0, false);
                ImGui::NewLine();
                ImGui::CenterText("A", 0, false);
            } ImGui::EndChild();

            // Display Bottom Menu Bar ( Basic Tab System )
            ImGui::SetCursorPos(ImVec2(10, 310));
            if (ImGui::BeginChild(sRandChild5.c_str(), ImVec2(460, 60), true, ImGuiWindowFlags_NoDecoration))
            {
                // Display ESP Tab Button
                ImGui::SetCursorPos(ImVec2(10, 15));
                if (ImGui::Button("ESP Features", ImVec2(100, 30)))
                {
                    GlobalVars::iTab = 0;
                }
                // Display Aim Tab Button
                ImGui::SetCursorPos(ImVec2(123, 15));
                if (ImGui::Button("Aim Features", ImVec2(100, 30)))
                {
                    GlobalVars::iTab = 1;
                }
                // Display Misc Tab Button
                ImGui::SetCursorPos(ImVec2(238, 15));
                if (ImGui::Button("Misc Features", ImVec2(100, 30)))
                {
                    GlobalVars::iTab = 2;
                }
                // Display Settings Tab Button
                ImGui::SetCursorPos(ImVec2(350, 15));
                if (ImGui::Button("Settings", ImVec2(100, 30)))
                {
                    GlobalVars::iTab = 3;
                }
            } ImGui::EndChild();

        } ImGui::EndChild();

    } ImGui::End();
}
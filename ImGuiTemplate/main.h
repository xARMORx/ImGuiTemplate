#ifndef _MAIN_H_
#define _MAIN_H_

#include <d3d9.h>
#include <Windows.h>
#include <memory>
#include <kthook/kthook.hpp>
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

using CTimer__UpdateSignature = void(__cdecl*)();
using PresentSignature = HRESULT(__stdcall*)(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
using ResetSignature = HRESULT(__stdcall*)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
using WndProcSignature = HRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM);

kthook::kthook_simple<CTimer__UpdateSignature> CTimerHook{};
kthook::kthook_signal<PresentSignature> PresentHook{};
kthook::kthook_signal<ResetSignature> ResetHook{};
kthook::kthook_simple<WndProcSignature> WndProcHook{};

bool ImGuiEnable{};
char ImGuiInputBuffer[256];

#endif // !_MAIN_H_
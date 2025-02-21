#include "pch.h"

#include "WindowInputManager.h"
#include "../Graphics/DX11.h"

LRESULT MadWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	static bool isMouseCaptured = false;

	switch (Msg)
	{
		case WM_CLOSE:
			[[fallthrough]];
		case WM_DESTROY:
			PostQuitMessage(WM_QUIT);
			return 0;

		case WM_KEYDOWN:
			[[fallthrough]];
		case WM_SYSKEYDOWN:
			if( !(lParam & (1 << 30)) ) //Autorepeat
				WindowInputManager::KeyPressed(static_cast<unsigned char>(wParam));
			break;

		case WM_KEYUP:
			[[fallthrough]];
		case WM_SYSKEYUP:
			WindowInputManager::KeyReleased(static_cast<unsigned char>(wParam));
			break;

		case WM_CHAR:
			WindowInputManager::OnCharEvent(static_cast<wchar_t>(wParam));
			break;

		case WM_MOUSEMOVE:
			WindowInputManager::OnMouseMoveEvent(MAKEPOINTS(lParam));

			if (WindowInputManager::bCaptureMouse)
				WindowInputManager::ClampMousePosition();
			break;

		case WM_RBUTTONDOWN:
			if (WindowInputManager::bCaptureMouse && !isMouseCaptured)
			{
				SetCapture(hWnd);
				isMouseCaptured = true;
			}
			WindowInputManager::OnMouseRButtonDown();
			break;

		case WM_LBUTTONDOWN:
			if(WindowInputManager::bCaptureMouse && !isMouseCaptured)
			{
				SetCapture(hWnd);
				isMouseCaptured = true;
			}
			WindowInputManager::OnMouseLButtonDown();
			break;

		case WM_RBUTTONUP:
			if (WindowInputManager::bCaptureMouse && isMouseCaptured)
			{
				ReleaseCapture();
				isMouseCaptured = false;
			}
			WindowInputManager::OnMouseRButtonRelease();
			break;

		case WM_LBUTTONUP:
			if (WindowInputManager::bCaptureMouse && isMouseCaptured)
			{
				ReleaseCapture();
				isMouseCaptured = false;
			}
			WindowInputManager::OnMouseLButtonRelease();
			break;
			
		case WM_MOUSEWHEEL:
			WindowInputManager::OnMouseWheelEvent(GET_WHEEL_DELTA_WPARAM(wParam));
			break;

		case WM_KILLFOCUS:
			WindowInputManager::FlushKeyboardInputState();
			break;

		default:
			break;
	}

	return DefWindowProcW(hWnd, Msg, wParam, lParam);
}
#include <windows.h> // ���������� �������� � ��������� API
#include "winforms1.h"
#include "Resource.h"

// �������� ����:
HINSTANCE hInst; 	//���������� ��������	
LPCTSTR szWindowClass = "Stasik Pisarenko Aleksandr Ignatiev Katerina Soroka";
LPCTSTR szTitle = "����� ��������";

// ��������� ���� �������

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
BOOL CALLBACK AboutDlgProc(HWND, UINT, WPARAM, LPARAM);//��������� �������� ������� ��������� ����������� ���� 
BOOL CALLBACK AboutDlgProc1(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc2(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AboutDlgProc3(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// ������� �������� 
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nCmdShow)
{
	MSG msg;

	// ��������� ����� ���� 
	MyRegisterClass(hInstance);

	// ��������� ���� ��������
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	// ���� ������� ����������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_DBLCLKS | CS_NOCLOSE; 		//����� ���� redraw/doubleclick/non close winow
	wcex.lpfnWndProc = (WNDPROC)WndProc; 		//������ ���������
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; 			//���������� ��������
	wcex.hIcon = LoadIcon(NULL, IDI_INFORMATION); 		//���������� ������
	wcex.hCursor = LoadCursor(NULL, IDC_WAIT); 	//���������� �������
	wcex.hbrBackground = GetSysColorBrush(COLOR_WINDOW + 1); //��������� ����
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); 				//���������� ����
	
	wcex.lpszClassName = szWindowClass; 		//��� �����
	wcex.hIconSm = NULL;
	
	return RegisterClassEx(&wcex); 			//��������� ����� ����
}

// FUNCTION: InitInstance (HANDLE, int)
// ������� ���� �������� � ������ ���������� �������� � ����� hInst

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; //������ ���������� ������� � ����� hInst
	hWnd = CreateWindow(szWindowClass, 	// ��� ����� ����
		szTitle, 				// ����� ��������
		WS_MINIMIZEBOX | WS_VSCROLL| WS_SYSMENU,  //- ������� ���� � ������� ����������� ����� ����!!!!1/system menu
		750, // ��������� �� �
		400, // ��������� �� Y
		400, // ����� �� �
		250, // ����� �� Y
		NULL, 					// ���������� ������������ ����	
		NULL, 					// ���������� ���� ����
		hInstance, 				// ���������� ��������
		NULL); 				// ��������� ���������.

	if (!hWnd) 	//���� ���� �� ���������, ������� ������� FALSE
	{
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow); 		//�������� ����
	UpdateWindow(hWnd); 				//������� ����
	return TRUE;
}

// FUNCTION: WndProc (HWND, unsigned, WORD, LONG)
// ³����� ���������. ������ � �������� �� �����������, �� ��������� � �������

BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // 1 �������� ����
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, 0);
			return TRUE;
		case IDCANCEL2:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG2), 0, (AboutDlgProc1), 0);
			break;
		case IDCANCEL:
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG3), 0, (AboutDlgProc2), 0);
			break;
		}
	}
	return FALSE;
}//���������� ����������� ����


BOOL CALLBACK AboutDlgProc1(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  // ���������
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, 0);
			return TRUE;
			break;
		}

	}
	return FALSE;
}
BOOL CALLBACK AboutDlgProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)  //�����
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			PostQuitMessage(0);
			break;
		case IDCANCEL3:
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return FALSE;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;

	switch (message)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_CHANGE_:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR1)));
			break;
		case ID_CHANGE_CURSOR2:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR2)));
			break;
		case ID_CHANGE_CURSOR3:
			SetClassLong(hWnd, GCLP_HCURSOR, (LONG)LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR3)));
			break;
		case ID_ABOUTUS_ABOUTSTUDENTS:
				DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, (AboutDlgProc), 0);//������� ��������� ����, ����� �������� �� ���������
				break;
	    }
	
	
	case WM_CREATE: 				//����������� ��������� ��� �������� ����
		break;

	case WM_PAINT: 				//������������ ����
		hdc = BeginPaint(hWnd, &ps); 	//������ ��������� ����	
		GetClientRect(hWnd, &rt); 		//������� ���� ��� ���������
		DrawText(hdc, "�����, ���!", -1, &rt, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hWnd, &ps); 		//�������� ��������� ����	
		break;

	case WM_DESTROY: 				//���������� ������
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDBLCLK:
		MessageBox(hWnd, "�����)", "HNURE", MB_OK);
		break;
	default:
		//������� ����������, �� �� �������� ������������
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

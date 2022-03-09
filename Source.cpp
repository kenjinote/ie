#include <windows.h>
#import <shdocvw.dll>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPWSTR pCmdLine, int nCmdShow)
{
	HRESULT hr = CoInitialize(NULL);
	if (SUCCEEDED(hr)) {
		SHDocVw::IWebBrowser2Ptr pIE;
		hr = pIE.CreateInstance(__uuidof(SHDocVw::InternetExplorer));
		if (SUCCEEDED(hr)) {
			pIE->PutVisible(VARIANT_TRUE);
			SetForegroundWindow((HWND)pIE->GetHWND());
		}
	}
	CoUninitialize();
	return 0;
}

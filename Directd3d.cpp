#include <xtl.h>

LPDIRECT3D8 g_pD3D = NULL;
LPDIRECT3DDEVICE8 g_pD3DDevice = NULL;

extern void InitializeD3D();
extern void cleanup();

void InitializeD3D()
{
  g_pD3D = Direct3DCreate8(D3D_SDK_VERSION);
  D3DPRESENT_PARAMETERS d3dpp;

  ZeroMemory(&d3dpp, sizeof(d3dpp));

  d3dpp.BackBufferWidth = 640;
  d3dpp.BackBufferHeight = 448;
  d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
  d3dpp.BackBufferCount = 1;
  d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  
  g_pD3D->CreateDevice(0, D3DDEVTYPE_HAL, NULL, 
  D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pD3DDevice);
}

void cleanup()
{
	g_pD3DDevice->Release();
	g_pD3D->Release();
}

void main()
{
	InitializeD3D();
	bool running = true;
	while(running)
	{
		g_pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
		g_pD3DDevice->BeginScene();
		g_pD3DDevice->EndScene();
		g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
	}
	cleanup();
}
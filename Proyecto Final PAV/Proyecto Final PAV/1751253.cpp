// Librerías
#include <windows.h>

// Prototipos
LRESULT CALLBACK WindowProcedure(
	HWND, UINT, WPARAM, LPARAM);

// Punto de entrada
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	// Declaración
	HWND hwnd;        // Manejador de la ventana principal
	MSG mensaje;      // Variable para manipular mensajes
	WNDCLASSEX wincl;

	// Inicialización
	// Manejador de la instancia de esta clase
	wincl.hInstance = hInstance;
	// Nombre de la clase
	wincl.lpszClassName = "EJEMPLO";
	// Puntero al procesador de los mensajes
	wincl.lpfnWndProc = WindowProcedure;
	// Entero que especifica la apariencia de la ventana
	wincl.style = CS_DBLCLKS;
	// Asigna y reserva el tamaño en bytes
	wincl.cbSize = sizeof(WNDCLASSEX);
	// Usar icono y puntero por defecto 
	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;
	wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	// Creación de la ventana
	// Registrar la clase de ventana
	if (!RegisterClassEx(&wincl)) return 0;

	hwnd = CreateWindowEx(
		0,                   // Estilos de ventana opcionales
		"EJEMPLO",           // Nombre de la clase de la ventana
		"1751253",            // Nombre de la ventana
		WS_OVERLAPPEDWINDOW, // Estilo de la ventana
		CW_USEDEFAULT,       // Posición horizontal
		CW_USEDEFAULT,       // y vertical de la ventana
		640,                 // Ancho
		480,                 // y alto de la ventana
		HWND_DESKTOP,        // Manejador de la ventana padre
		NULL,                // Manejador del menú o ventana hija
		hInstance,           // Manejador de la instancia
		NULL                 // Puntero a los parámetros CMD
	);

	// Mostrar la ventana
	ShowWindow(hwnd, SW_SHOWDEFAULT);

	// Bucle de mensajes
	while (TRUE == GetMessage(&mensaje, 0, 0, 0)) {
		TranslateMessage(&mensaje);
		DispatchMessage(&mensaje);
	}

	return mensaje.wParam;
}

// Definición de funciones
LRESULT CALLBACK WindowProcedure(HWND hwnd,
	UINT mensaje,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (mensaje) {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, mensaje, wParam, lParam);
	}
	return 0;
}
#include <Windows.h>
#include <memory>
#include <iostream>

BOOL HandleProcessAttach( void );
BOOL HandleProcessDetach( void );

// standard windows entry point
BOOL __stdcall DllMain( HINSTANCE dll, DWORD reason, LPVOID reserved ) {

	switch ( reason ) {

	case DLL_PROCESS_ATTACH: return HandleProcessAttach( ); 
	case DLL_PROCESS_DETACH: return HandleProcessDetach( );
	default:
		return TRUE;

	}

}

BOOL HandleProcessAttach( void ) {

	// fuck client.dll all my homies hate clientdll
	if ( GetModuleHandleW( L"client.dll" ) != INVALID_HANDLE_VALUE )
	{

		MessageBoxW( NULL, L"Error", L"fuck off kid who gives a fuck abt legacy", MB_OK );
		return FALSE;

	}


	return TRUE;


}

BOOL HandleProcessDetach( void ) {

	return TRUE;

}
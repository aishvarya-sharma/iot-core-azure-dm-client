// This is the main DLL file.

#include "stdafx.h"

#include "ManagedServiceProxyClient.h"

using namespace ManagedServiceProxyClient;

__MIDL_DECLSPEC_DLLIMPORT
DWORD Initialize();

__MIDL_DECLSPEC_DLLIMPORT
DWORD SendCommand(BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType);


DWORD ManagedServiceProxy::SendRequest(BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType)
{
	return SendCommand(request, requestType, pResponse, pResponseType);
}

__int64 ManagedServiceProxy::InitializeProxy()
{
	return Initialize();
}


// ManagedServiceProxyClient.h

#pragma once

#include <Windows.h>

using namespace System;

namespace ManagedServiceProxyClient {

	public ref class ManagedServiceProxy
	{
	public:
		DWORD SendRequest(BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType);

		__int64 InitializeProxy();
	};
}

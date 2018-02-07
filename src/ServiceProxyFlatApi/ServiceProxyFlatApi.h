// ServiceConfiguratorProxyLib.h

#pragma once

#define RPC_STATIC_ENDPOINT L"IotDmRpcEndpoint"
#define RPC_PROTOCOL L"ncalrpc"

#include "SystemConfiguratorProxy_h.h"

//using namespace System;

namespace ServiceProxyFlatApi {

	class SCProxyClient sealed
	{
	public:
		SCProxyClient();
		virtual ~SCProxyClient();

		DWORD SendCommand(BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType);

		__int64 Initialize();

		bool IsInitialized() { return fInitialized; }

	private:
		RPC_BINDING_HANDLE hRpcBinding;
		bool		fInitialized;
	};
}

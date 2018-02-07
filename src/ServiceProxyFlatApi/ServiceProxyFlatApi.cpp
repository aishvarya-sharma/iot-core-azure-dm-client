// This is the main DLL file.

#include "stdafx.h"

#include "ServiceProxyFlatApi.h"

using namespace ServiceProxyFlatApi;

SCProxyClient *g_client = nullptr;

__MIDL_DECLSPEC_DLLEXPORT
DWORD Initialize()
{
	DWORD status = ERROR_ALREADY_EXISTS;
	if (g_client == nullptr)
	{
		// I know this is bad and doesn't handle many cases, but it's late, I am cranky and eager to just get this to work.
		g_client = new SCProxyClient();

		status = g_client->Initialize();
	}

	return status;
}

__MIDL_DECLSPEC_DLLEXPORT
DWORD SendCommand(BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType)
{
	if (g_client == nullptr)
	{
		return ERROR_NOT_READY;
	}

	if (!g_client->IsInitialized())
	{
		return ERROR_NOT_READY;				// TODO: we should send a different error code.
	}
	

	return g_client->SendCommand(request, requestType, pResponse, pResponseType);
}

DWORD DoSendCommand(handle_t binding, BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType)
{
	if (binding == NULL)
	{
		return RPC_S_INVALID_BINDING;
	}

	RpcTryExcept
	{
		return ::SendRequest(
			/* [in] */ binding,
			/* [in] */ requestType,
			/* [in] */ request,
			/* [out] */ pResponseType,
			/* [out] */ pResponse);
	}
		RpcExcept(1)
	{
		// Ignoring the result of RemoteClose as nothing can be
		// done on the client side with this return code
		return RpcExceptionCode();
	}
	RpcEndExcept
}

SCProxyClient::SCProxyClient()
{
	fInitialized = false;
	hRpcBinding = 0;
}


DWORD SCProxyClient::SendCommand(BSTR requestJson, UINT requestType, BSTR *pResponseJson, UINT* pResponseType)
{
	/*auto blob = command->Serialize();
	auto json = blob->PayloadAsString;
*/

	UINT responseType = 0;

	auto status = DoSendCommand(this->hRpcBinding, requestJson, requestType, pResponseJson, &responseType);
	*pResponseType = responseType;
#if 0
	IResponse^ response = nullptr;
	if (RPC_S_OK != status /*implied: || S_OK != status || ERROR_SUCCESS != status*/)
	{
		// Ignoring the result of RemoteClose as nothing can be
		// done on the client side with this return code
		response = ref new ErrorResponse(ErrorSubSystem::DeviceManagement, status, L"Failure in SystemConfigurator SendRequest RPC");
	}
	else
	{
		auto responseJsonString = ref new Platform::String(responseJson);
		response = Blob::CreateFromJson(responseType, responseJsonString)->MakeIResponse();
	}


	return response;
#endif

	return status;
}


__int64 SCProxyClient::Initialize()
{
	RPC_STATUS status;
	RPC_WSTR pszStringBinding = nullptr;

	status = RpcStringBindingCompose(
		NULL,
		reinterpret_cast<RPC_WSTR>(RPC_PROTOCOL),
		NULL,
		reinterpret_cast<RPC_WSTR>(RPC_STATIC_ENDPOINT),
		NULL,
		&pszStringBinding);

	if (status)
	{
		goto error_status;
	}

	RPC_BINDING_HANDLE handle;
	status = RpcBindingFromStringBinding(
		pszStringBinding,
		&handle);

	hRpcBinding = handle;

	if (status)
	{
		goto error_status;
	}

error_status:

	if (pszStringBinding != nullptr)
	{
		RpcStringFree(&pszStringBinding);
	}


	return status;
}


SCProxyClient::~SCProxyClient()
{
	RPC_STATUS status;

	if (hRpcBinding != NULL)
	{
		RPC_BINDING_HANDLE handle = hRpcBinding;
		status = RpcBindingFree(&handle);
		hRpcBinding = NULL;
	}
}

///******************************************************/
///*         MIDL allocate and free                     */
///******************************************************/

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
	return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
	free(ptr);
}
// This is the main DLL file.

#include "stdafx.h"

#include "ManagedServiceProxyClient.h"




using namespace ManagedServiceProxyClient;

__MIDL_DECLSPEC_DLLIMPORT
DWORD Initialize();

__MIDL_DECLSPEC_DLLIMPORT
DWORD SendCommand(BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType);

CComBSTR ConvertStringToBSTR(String ^ str);

// DWORD ManagedServiceProxy::SendRequest(BSTR request, UINT requestType, BSTR *pResponse, UINT* pResponseType)
DWORD ManagedServiceProxy::SendRequest(String ^request, unsigned int  requestType, String ^%Response, unsigned int %ResponseType)
{
	CComBSTR bstrRequest = ConvertStringToBSTR(request);

	CComBSTR bstrResponse = ConvertStringToBSTR(Response);

	UINT responseCode = 0;
	DWORD dwReturnCode = SendCommand(bstrRequest, requestType, &bstrResponse, &responseCode);
	ResponseType = responseCode;

	return dwReturnCode;
}

__int64 ManagedServiceProxy::InitializeProxy()
{
	return Initialize();
}

CComBSTR ConvertStringToBSTR(String ^ str)
{
	IntPtr ptr = Runtime::InteropServices::Marshal::StringToBSTR(str);
	CComBSTR bstrRequest;
	bstrRequest.Attach(static_cast<BSTR>(ptr.ToPointer()));

	return bstrRequest;
}


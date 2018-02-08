/*
Copyright 2017 Microsoft
Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once
#include "IRequestIResponse.h"
#include "SerializationHelper.h"
#include "DMMessageKind.h"
#include "StatusCodeResponse.h"
#include "Blob.h"

using namespace Platform;
using namespace Platform::Metadata;
using namespace Windows::Data::Json;

namespace Microsoft { namespace Devices { namespace Management { namespace Message
{
    public ref class GetCertificateDetailsRequest sealed : public IRequest
    {
    public:
        GetCertificateDetailsRequest() {}

        property String^ path;
        property String^ hash;

        virtual Blob^ Serialize() {

            JsonObject^ jsonObject = ref new JsonObject();
            jsonObject->Insert("path", JsonValue::CreateStringValue(path));
            jsonObject->Insert("hash", JsonValue::CreateStringValue(hash));
            return SerializationHelper::CreateBlobFromJson((uint32_t)Tag, jsonObject);
        }

        static IDataPayload^ Deserialize(Blob^ blob) {
            assert(blob->Tag == DMMessageKind::GetCertificateDetails);

            String^ str = SerializationHelper::GetStringFromBlob(blob);

            JsonObject^ jsonObject = JsonObject::Parse(str);
            GetCertificateDetailsRequest^ getCertificateDetailsRequest = ref new GetCertificateDetailsRequest();
            getCertificateDetailsRequest->path = jsonObject->Lookup("path")->GetString();
            getCertificateDetailsRequest->hash = jsonObject->Lookup("hash")->GetString();

            return getCertificateDetailsRequest;
        }

        virtual property DMMessageKind Tag {
            DMMessageKind get();
        }
    };

    public ref class GetCertificateDetailsResponse sealed : public IResponse
    {
        StatusCodeResponse statusCodeResponse;
    public:
        property String^ base64Encoding;
        property String^ templateName;
        property String^ issuedBy;
        property String^ issuedTo;
        property String^ validFrom;
        property String^ validTo;

        GetCertificateDetailsResponse(ResponseStatus status) : statusCodeResponse(status, this->Tag) {}

        virtual Blob^ Serialize() {

            JsonObject^ jsonObject = ref new JsonObject();
            jsonObject->Insert("Base64Encoding", JsonValue::CreateStringValue(base64Encoding));
            jsonObject->Insert("TemplateName", JsonValue::CreateStringValue(templateName));
            jsonObject->Insert("IssuedBy", JsonValue::CreateStringValue(issuedBy));
            jsonObject->Insert("IssuedTo", JsonValue::CreateStringValue(issuedTo));
            jsonObject->Insert("ValidFrom", JsonValue::CreateStringValue(validFrom));
            jsonObject->Insert("ValidTo", JsonValue::CreateStringValue(validTo));

            return SerializationHelper::CreateBlobFromJson((uint32_t)Tag, jsonObject);
        }

        static IDataPayload^ Deserialize(Blob^ blob) {

            String^ str = SerializationHelper::GetStringFromBlob(blob);

            JsonObject^ jsonObject = JsonObject::Parse(str);
            auto getCertificateDetailsResponse = ref new GetCertificateDetailsResponse(ResponseStatus::Success);
            getCertificateDetailsResponse->base64Encoding = jsonObject->Lookup("Base64Encoding")->GetString();
            getCertificateDetailsResponse->templateName = jsonObject->Lookup("TemplateName")->GetString();
            getCertificateDetailsResponse->issuedBy = jsonObject->Lookup("IssuedBy")->GetString();
            getCertificateDetailsResponse->issuedTo = jsonObject->Lookup("IssuedTo")->GetString();
            getCertificateDetailsResponse->validFrom = jsonObject->Lookup("ValidFrom")->GetString();
            getCertificateDetailsResponse->validTo = jsonObject->Lookup("ValidTo")->GetString();

            return getCertificateDetailsResponse;
        }

        virtual property ResponseStatus Status {
            ResponseStatus get() { return statusCodeResponse.Status; }
        }

        virtual property DMMessageKind Tag {
            DMMessageKind get();
        }
    };
}
}}}

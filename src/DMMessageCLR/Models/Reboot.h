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
    public ref class ImmediateRebootRequest sealed : public IRequest
    {
    public:

        property String^ lastRebootCmdTime;

        virtual Blob^ Serialize() {
            JsonObject^ jsonObject = ref new JsonObject();
            jsonObject->Insert("lastRebootCmdTime", JsonValue::CreateStringValue(lastRebootCmdTime));
            return SerializationHelper::CreateBlobFromJson((uint32_t)Tag, jsonObject);
        }

        static IDataPayload^ Deserialize(Blob^ blob) {
            assert(blob->Tag == DMMessageKind::ImmediateReboot);
            String^ str = SerializationHelper::GetStringFromBlob(blob);
            JsonObject^ jsonObject = JsonObject::Parse(str);
            auto request = ref new ImmediateRebootRequest();
            request->lastRebootCmdTime = jsonObject->Lookup("lastRebootCmdTime")->GetString();
            return request;
        }

        virtual property DMMessageKind Tag {
            DMMessageKind get();
        }
    };

    public ref class SetRebootInfoRequest sealed : public IRequest
    {
    public:
        property String^ singleRebootTime;
        property String^ dailyRebootTime;

        virtual Blob^ Serialize() {
            JsonObject^ jsonObject = ref new JsonObject();
            jsonObject->Insert("singleRebootTime", JsonValue::CreateStringValue(singleRebootTime));
            jsonObject->Insert("dailyRebootTime", JsonValue::CreateStringValue(dailyRebootTime));
            return SerializationHelper::CreateBlobFromJson((uint32_t)Tag, jsonObject);
        }

        static IDataPayload^ Deserialize(Blob^ blob) {
            String^ str = SerializationHelper::GetStringFromBlob(blob);

            JsonObject^ jsonObject = JsonObject::Parse(str);
            auto result = ref new SetRebootInfoRequest();
            result->singleRebootTime = jsonObject->Lookup("singleRebootTime")->GetString();
            result->dailyRebootTime = jsonObject->Lookup("dailyRebootTime")->GetString();
            return result;
        }

        virtual property DMMessageKind Tag {
            DMMessageKind get();
        }
    };

    public ref class GetRebootInfoRequest sealed : public IRequest
    {
    public:
        virtual Blob^ Serialize() {
            return SerializationHelper::CreateEmptyBlob((uint32_t)Tag);
        }

        static IDataPayload^ Deserialize(Blob^ bytes) {
            auto result = ref new GetRebootInfoRequest();
            return result;
        }

        virtual property DMMessageKind Tag {
            DMMessageKind get();
        }
    };

    public ref class GetRebootInfoResponse sealed : public IResponse
    {
        StatusCodeResponse statusCodeResponse;
    public:
        property String^ lastBootTime;
        property String^ lastRebootCmdTime;
        property String^ singleRebootTime;
        property String^ dailyRebootTime;

        GetRebootInfoResponse(ResponseStatus status) : statusCodeResponse(status, this->Tag) {}

        virtual Blob^ Serialize() {
            JsonObject^ jsonObject = ref new JsonObject();
            jsonObject->Insert("lastBootTime", JsonValue::CreateStringValue(lastBootTime));
            jsonObject->Insert("lastRebootCmdTime", JsonValue::CreateStringValue(lastRebootCmdTime));
            jsonObject->Insert("singleRebootTime", JsonValue::CreateStringValue(singleRebootTime));
            jsonObject->Insert("dailyRebootTime", JsonValue::CreateStringValue(dailyRebootTime));
            return SerializationHelper::CreateBlobFromJson((uint32_t)Tag, jsonObject);
        }

        static IDataPayload^ Deserialize(Blob^ blob) {
            String^ str = SerializationHelper::GetStringFromBlob(blob);
            JsonObject^ jsonObject = JsonObject::Parse(str);
            auto result = ref new GetRebootInfoResponse(ResponseStatus::Success);
            result->lastBootTime = jsonObject->Lookup("lastBootTime")->GetString();
            result->lastRebootCmdTime = jsonObject->Lookup("lastRebootCmdTime")->GetString();
            result->singleRebootTime = jsonObject->Lookup("singleRebootTime")->GetString();
            result->dailyRebootTime = jsonObject->Lookup("dailyRebootTime")->GetString();
            return result;
        }

        virtual property ResponseStatus Status {
            ResponseStatus get() { return statusCodeResponse.Status; }
        }

        virtual property DMMessageKind Tag {
            DMMessageKind get();
        }
    };


}}}}

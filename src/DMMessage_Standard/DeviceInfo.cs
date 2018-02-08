using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{
    public class GetDeviceInfoRequest : IRequest
    {
    }

    public class GetDeviceInfoResponse : IResponse
    {
        public string batteryRuntime;
        public string batteryRemaining;
        public string batteryStatus;
        public string osEdition;
        public string secureBootState;
        public string totalMemory;
        public string totalStorage;
        public string name;
        public string processorArchitecture;
        public string commercializationOperator;
        public string displayResolution;
        public string radioSwVer;
        public string processorType;
        public string platform;
        public string osVer;
        public string fwVer;
        public string hwVer;
        public string oem;
        public string type;
        public string lang;
        public string dmVer;
        public string model;
        public string manufacturer;
        public string id;
    }
}

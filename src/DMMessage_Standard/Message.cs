using Microsoft.Devices.Management.DMDataContract;
using System;
using System.Collections.Generic;

namespace Microsoft.Devices.Management.Message
{

    public enum ErrorSubSystem
    {
        Unknown,
    }
    public enum MessageKind
    {
        WindowsUpdate, 
        TimeService,
        Blah,
        Blah2,
        blah3
    }

    public class GetWindowsUpdatesRequest : IRequest
    {
        
    }

    public class GetWindowsUpdatesResponse : IResponse
    {
        public WindowsUpdatesDataContract.ReportedProperties configuration;
    }

    public class FactoryResetRequest : IRequest
    {
        public bool clearTPM;
        public string recoveryPartitionGUID;
    }

    public class ImmediateRebootRequest : IRequest
    {
        public string lastRebootCmdTime;
    }

    public class SetRebootInfoRequest : IRequest
    {
        public string singleRebootTime;
        public string dailyRebootTime;
    }

    public class GetRebootInfoRequest : IRequest
    {
    }

    public class GetRebootInfoResponse : IResponse
    {
        public string lastBootTime;
        public string singleRebootTime;
        public string dailyRebootTime;
    }


    public class StringListResponse : IResponse
    {
        public List<string> List;
    }


    public class GetDMFoldersRequest : IRequest
    {

    }


    public class GetDMFilesRequest : IRequest
    {
        public string DMFolderName;
    }

    public class DeleteDMFileRequest : IRequest
    {
        public string DMFolderName;
        public string DMFileName;
    }


    public class StatusCodeResponse : IResponse
    {
        public uint Status;
    }


    public class GetWindowsTelemetryRequest : IRequest
    { }


    public class GetWindowsTelemetryResponse : IResponse
    {
        public WindowsTelemetryDataContract.ReportedProperties data;
    }

    public class WindowsTelemetryData
    {
        public string level;
    }

    public class SetWindowsTelemetryRequest : IRequest
    {
        WindowsTelemetryData _data;
        public SetWindowsTelemetryRequest (WindowsTelemetryData data)
        {
            _data = data;
        }
    }

}

using Microsoft.Devices.Management.DMDataContract;
using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{
    public class SetWindowsUpdatePolicyRequest : IRequest
    {
        public string ApplyFromDeviceTwin;
        public string ReportToDeviceTwin;
        public WindowsUpdatePolicyConfiguration data;
    }


    public class WindowsUpdatePolicyConfiguration
    {
        public Policy policy;
        public uint activeFields;

        // Optional fields.
        public uint activeHoursStart;
        public uint activeHoursEnd;
        public uint allowAutoUpdate;
        public uint allowUpdateService;
        public uint branchReadinessLevel;

        public uint deferFeatureUpdatesPeriod;    // in days
        public uint deferQualityUpdatesPeriod;    // in days
        public uint pauseFeatureUpdates;
        public uint pauseQualityUpdates;
        public uint scheduledInstallDay;

        public uint scheduledInstallTime;

        public string ring;

        public WindowsUpdatePolicyConfiguration()
        {
            activeFields = 0;

            activeHoursStart = 0;
            activeHoursEnd = 0;
            allowAutoUpdate = 0;
            allowUpdateService = 0;
            branchReadinessLevel = 0;

            deferFeatureUpdatesPeriod = 0;    // in days
            deferQualityUpdatesPeriod = 0;    // in days
            pauseFeatureUpdates = 0;
            pauseQualityUpdates = 0;
            scheduledInstallDay = 0;

            scheduledInstallTime = 0;

            ring = "";
        }
    }

    [Flags]
    public enum ActiveFields
    {
        ActiveHoursStart = 0x0001,
        ActiveHoursEnd = 0x0002,
        AllowAutoUpdate = 0x0004,
        AllowUpdateService = 0x0008,
        BranchReadinessLevel = 0x0010,
        DeferFeatureUpdatesPeriod = 0x0020,
        DeferQualityUpdatesPeriod = 0x0040,
        PauseFeatureUpdates = 0x0080,
        PauseQualityUpdates = 0x0100,
        ScheduledInstallDay = 0x0200,
        ScheduledInstallTime = 0x0400,
        Ring = 0x0800,
    };

    public class GetWindowsUpdatePolicyResponse : IResponse
    {
        public WindowsUpdatePolicyConfiguration data;
        public string ReportToDeviceTwin;
    }

    public class GetWindowsUpdatePolicyRequest : IRequest
    {

    }


    public class SetWindowsUpdatesConfiguration
    {
        public string approved { get; set; }
    }


    public class SetWindowsUpdatesRequest : IRequest
    {
        SetWindowsUpdatesConfiguration _config;
        public SetWindowsUpdatesRequest (SetWindowsUpdatesConfiguration config)
        {
            _config = config;
        }
    }

}
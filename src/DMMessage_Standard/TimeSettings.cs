using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{
    public class SetTimeInfoRequestData
    {
        public string ntpServer;
        public int timeZoneBias;
        public int timeZoneStandardBias;
        public string timeZoneStandardDate;
        public string timeZoneStandardName;
        public int timeZoneStandardDayOfWeek;
        public int timeZoneDaylightBias;
        public string timeZoneDaylightDate;
        public string timeZoneDaylightName;
        public int timeZoneDaylightDayOfWeek;
        public string timeZoneKeyName;
        public bool dynamicDaylightTimeDisabled;

        public string localTime;
    }

    public class SetTimeInfoRequest : IRequest
    {
        SetTimeInfoRequestData _data;
        public SetTimeInfoRequest (SetTimeInfoRequestData data)
        {
            _data = data;
        }
    }

    public class GetTimeInfoRequest : IRequest
    {

    }

    public class GetTimeInfoResponse : IResponse
    {
        public SetTimeInfoRequestData data;
    }

}

using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{
    public enum PolicySource
    {
        Local = 0,
        Remote = 1,
        Unknown = 2
    }

    public sealed class Policy
    {
        //public void Serialize(JsonObject targetObj);
        //public static Policy Deserialize(JsonObject sourceObj);

        public Policy()
        {

        }

        public IList<PolicySource> sourcePriorities { get; set; }
        public PolicySource source { get; set; }
    }

    public class TimeServiceData
    {
        public string enabled;
        public string startup;
        public string started;
        public Policy policy;

    }


    public class SetTimeServiceRequest : IRequest
    {
        TimeServiceData _data;
        public SetTimeServiceRequest(TimeServiceData data)
        {
            _data = data;
        }
    }

    public class GetTimeServiceRequest : IRequest
    {

    }

    public class GetTimeServiceResponse  : IResponse
    {
        public TimeServiceData data;
    }




}

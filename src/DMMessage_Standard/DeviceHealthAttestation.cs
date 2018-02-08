using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{


    public class DeviceHealthAttestationVerifyHealthRequest : IRequest
    {
        public string HealthAttestationServerEndpoint;
    }
    public class DeviceHealthAttestationGetReportRequest : IRequest
    {
        public string Nonce;
    }


    public class DeviceHealthAttestationGetReportResponse : IResponse
    {
        public string CorrelationId;
        public string HealthCertificate;
    }
}

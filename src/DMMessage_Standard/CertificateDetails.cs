using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{
    public class GetCertificateDetailsRequest : IRequest
    {

        public string path;
        public string hash;
    }

    public class GetCertificateDetailsResponse : IResponse
    {

    }


    public class CertificateConfiguration
    {
        public string certificateStore_CA_System;
        public string certificateStore_My_System;
        public string certificateStore_My_User;
        public string certificateStore_Root_System;
        public string rootCATrustedCertificates_CA;
        public string rootCATrustedCertificates_Root;
        public string rootCATrustedCertificates_TrustedPeople;
        public string rootCATrustedCertificates_TrustedPublisher;

    }


    public class SetCertificateConfigurationRequest : IRequest
    {
        CertificateConfiguration _data;
        public SetCertificateConfigurationRequest (CertificateConfiguration config)
        {
            _data = config;
        }
    }

    public class GetCertificateConfigurationRequest : IRequest
    {

    }

    public class GetCertificateConfigurationResponse : IResponse
    {
        public CertificateConfiguration configuration;
    }

}

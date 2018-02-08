using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{
    public class AzureFileTransferRequest : IRequest
    {
        AzureFileTransferInfo _info;
        public AzureFileTransferRequest (AzureFileTransferInfo info)
        {
            _info = info;
        }
    }
}

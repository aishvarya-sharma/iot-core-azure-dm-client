using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Devices.Management.Message
{
    public sealed class AzureFileTransferInfo
    {
        public AzureFileTransferInfo(string relativeLocalPath, string appLocalDataPath, string connectionString, string containerName, string blobName, bool upload)
        {
            RelativeLocalPath = relativeLocalPath;
            AppLocalDataPath = appLocalDataPath;
            ConnectionString = connectionString;
            ContainerName = containerName;
            BlobName = blobName;
            Upload = upload;
        }

        public AzureFileTransferInfo()
        { }

        public bool Upload { get; set; }
        public string BlobName { get; set; }
        public string ContainerName { get; set; }
        public string ConnectionString { get; set; }
        public string AppLocalDataPath { get; set; }
        public string RelativeLocalPath { get; set; }
    }
}

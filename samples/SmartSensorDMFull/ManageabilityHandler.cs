using Microsoft.Azure.Devices.Client;
using Microsoft.Azure.Devices.Shared;
using Microsoft.Devices.Management;
using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace SmartSensorDM
{
    class ManageabilityHandler : IDeviceManagementRequestHandler
    {
        string connectionString;
        DeviceManagementClient deviceManagementClient;


        public ManageabilityHandler(string connectionString)
        {
            this.connectionString = connectionString;
        }

        public Task<bool> IsSystemRebootAllowed()
        {
            throw new NotImplementedException();
        }

        public async Task ResetConnectionAsync(DeviceClient existingConnection)
        {
            Microsoft.Devices.Management.Logger.Log("ResetConnectionAsync start", LoggingLevel.Verbose);
            // Attempt to close any existing connections before
            // creating a new one
            if (existingConnection != null)
            {
                await existingConnection.CloseAsync().ContinueWith((t) =>
                {
                    var e = t.Exception;
                    if (e != null)
                    {
                        var msg = "existingClient.CloseAsync exception: " + e.Message + "\n" + e.StackTrace;
                        System.Diagnostics.Debug.WriteLine(msg);
                        Microsoft.Devices.Management.Logger.Log(msg, LoggingLevel.Verbose);
                    }
                });
            }

            // Get new SAS Token
            var deviceConnectionString = connectionString;

            // Create DeviceClient. Application uses DeviceClient for telemetry messages, device twin
            // as well as device management
            var newDeviceClient = DeviceClient.CreateFromConnectionString(deviceConnectionString, TransportType.Mqtt);

            // IDeviceTwin abstracts away communication with the back-end.
            // AzureIoTHubDeviceTwinProxy is an implementation of Azure IoT Hub
            IDeviceTwin deviceTwin = new AzureIoTHubDeviceTwinProxy(newDeviceClient, ResetConnectionAsync, Microsoft.Devices.Management.Logger.Log);

            // IDeviceManagementRequestHandler handles device management-specific requests to the app,
            // such as whether it is OK to perform a reboot at any givem moment, according the app business logic
            // ToasterDeviceManagementRequestHandler is the Toaster app implementation of the interface
            IDeviceManagementRequestHandler appRequestHandler = this;

            // Create the DeviceManagementClient, the main entry point into device management
            this.deviceManagementClient = await DeviceManagementClient.CreateAsync(deviceTwin, appRequestHandler);

            // Set the callback for desired properties update. The callback will be invoked
            // for all desired properties -- including those specific to device management
            await newDeviceClient.SetDesiredPropertyUpdateCallbackAsync(OnDesiredPropertyUpdated, null);

            // Tell the deviceManagementClient to sync the device with the current desired state.
            await this.deviceManagementClient.ApplyDesiredStateAsync();

            Microsoft.Devices.Management.Logger.Log("ResetConnectionAsync end", LoggingLevel.Verbose);
        }

        private Task OnDesiredPropertyUpdated(TwinCollection desiredProperties, object userContext)
        {
            throw new NotImplementedException();
        }
    }
}

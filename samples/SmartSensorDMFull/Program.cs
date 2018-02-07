using Microsoft.AmbientIntelligence;
using Microsoft.Azure.Devices.Client;
using Microsoft.Azure.Devices.Shared;
using Microsoft.Devices.Management;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace SmartSensorDM
{
    class Program
    {
#if true   // Use aish's IoT hub
        static string connectionString = "HostName=RFSensorHub.azure-devices.net;SharedAccessKeyName=iothubowner;SharedAccessKey=+3f5KPobPuflFnkGe520TEQ4+j8W0a2X3pIrVHGnUN4=";
        static string deviceName = "myFirstDevice";
#else
            string connectionString = "HostName=rwiIoT01.azure-devices.net;SharedAccessKeyName=iothubowner;SharedAccessKey=DjuF5fUi7SqU6uF2XE8fOC79vDVANzUDswraF1ABjpI=";
            string deviceName = "rfsensor-001-0001";
#endif

     //   DeviceManagementClient deviceManagementClient;

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            IoTDevice dmDevice = new IoTDevice(connectionString, deviceName);
            DeviceClient device = dmDevice.DeviceClient;
            ManageabilityHandler handler = new ManageabilityHandler(connectionString);

            IDeviceTwin deviceTwin = new AzureIoTHubDeviceTwinProxy(device, handler.ResetConnectionAsync);

            var dmClient = DeviceManagementClient.CreateAsync(deviceTwin, handler).Result;

            var timestuff = dmClient.GetTimeServiceStateAsync().Result;




            Task<Dictionary<string, object>> getpropTask = Task.Run(async () =>
            {
                return await deviceTwin.GetDesiredPropertiesAsync();

            });

            var properties = getpropTask.Result;

            foreach (var prop in properties)
            {
                Console.WriteLine($"property name {prop.Key} : Value {prop.Value}");
            }


            Console.WriteLine("press a key to exit...");
            Console.ReadKey();

        }

    }
}

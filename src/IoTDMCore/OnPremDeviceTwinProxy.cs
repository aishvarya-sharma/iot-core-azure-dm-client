/*
Copyright 2017 Microsoft
Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace Microsoft.Devices.Management
{
    public class OnPremDeviceTwinProxy : IDeviceTwin
    {
        public OnPremDeviceTwinProxy(/* something */)
        {
        }

        async Task<Dictionary<string, object>> IDeviceTwin.GetDesiredPropertiesAsync()
        {
            return await new Task<Dictionary<string, object>>(() => { return null; });
        }

        async Task<string> IDeviceTwin.GetAllPropertiesAsync()
        {
            return await new Task<string>(() => { return "{}"; });
        }

        async Task IDeviceTwin.ReportProperties(Dictionary<string, object> collection)
        {
            // Somehow send the property to the DT
            await new Task(() => { return; });
        }

        Task IDeviceTwin.RefreshConnectionAsync()
        {
            // Reconnect if needed
#if false //Aish
            return Task.CompletedTask;
#endif
            return new Task(() => { });
        }

        Task IDeviceTwin.SetMethodHandlerAsync(string methodName, Func<string, Task<string>> methodHandler)
        {
            throw new NotImplementedException();
        }

        Task IDeviceTwin.SendMessageAsync(string message, IDictionary<string, string> properties)
        {
            throw new NotImplementedException();
        }

        void IDeviceTwin.SignalOperationComplete()
        {
            throw new NotImplementedException();
        }
    }
}
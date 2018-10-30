/*
 * AUTO-GENERATED _componentMain.c for the sct013Component component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _sct013Component_le_adc_ServiceInstanceName;
const char** le_adc_ServiceInstanceNamePtr = &_sct013Component_le_adc_ServiceInstanceName;
void le_adc_ConnectService(void);
// Component log session variables.
le_log_SessionRef_t sct013Component_LogSession;
le_log_Level_t* sct013Component_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _sct013Component_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _sct013Component_Init(void)
{
    LE_DEBUG("Initializing sct013Component component library.");

    // Connect client-side IPC interfaces.
    le_adc_ConnectService();

    // Register the component with the Log Daemon.
    sct013Component_LogSession = log_RegComponent("sct013Component", &sct013Component_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_sct013Component_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif

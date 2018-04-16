#ifndef SPECIALMODESERVICESMANAGER_H
#define SPECIALMODESERVICESMANAGER_H

#include <binder/BinderService.h>


#include <services/ConfigurationManagerService/IConfigurationManagerService.h>
#include <services/ConfigurationManagerService/IConfigurationManagerServiceType.h>

#include <services/ApplicationManagerService/IApplicationManagerService.h>
#include <services/ApplicationManagerService/IApplicationManagerServiceType.h>

#include <services/NGTPManagerService/INGTPManagerService.h>
#include <services/NGTPManagerService/INGTPManagerServiceType.h>

#include <services/SystemManagerService/ISystemManagerService.h>
#include <services/SystemManagerService/ISystemManagerServiceType.h>

class SpecialModeServicesManager : public RefBase
{
public:
    SpecialModeServicesManager();
    virtual ~SpecialModeServicesManager();

    sp<IConfigurationManagerService>    getConfigurationManager();
    sp<IApplicationManagerService>      getApplicationManager();
    sp<ISystemManagerService>           getSystemManager();
    sp<INGTPManagerService>             getNGTPManager();

#ifdef G_TEST
public:
#else
private:
#endif
    sp<IConfigurationManagerService>    m_ConfigurationMgr;
    sp<IApplicationManagerService>      m_ApplicationMgr;
    sp<ISystemManagerService>           m_SystemMgr;
    sp<INGTPManagerService>             m_NGTPMgr;
};


#endif // SPECIALMODESERVICESMANAGER_H

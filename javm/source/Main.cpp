
#include <switch.h>
#include <javm/core/core_Machine.hpp>
using namespace javm;

// Special standard classes
#include <nx_Java.hpp>

void LogMessage(std::string msg) {
    // Log using error applet, depending on the applet type
    switch(appletGetAppletType()) {
        case AppletType_Application:
        case AppletType_SystemApplication: {
            ErrorApplicationConfig cfg;
            errorApplicationCreate(&cfg, msg.c_str(), nullptr);
            errorApplicationShow(&cfg);
            break;
        }
        case AppletType_SystemApplet:
        case AppletType_LibraryApplet:
        case AppletType_OverlayApplet: {
            ErrorSystemConfig cfg;
            errorSystemCreate(&cfg, msg.c_str(), nullptr);
            errorSystemShow(&cfg);
            break;
        }
        default:
            break;
    }
}

int main(int argc, char **argv) {
    
    if(argc < 2) {
        return 0;
    }
    
    std::string jar = argv[1];

    core::Machine machine;
    machine.LoadBuiltinNativeClasses();

    // Load native classes for our libraries
    nx::LoadClasses(machine);

    auto &jar_ref = machine.LoadJavaArchive(jar);

    if(jar_ref->CanBeExecuted()) {
        auto args_array_value = core::CreateArray<java::lang::String>(argc - 2);
        auto args_array_ref = args_array_value->GetReference<core::Array>();
        for(int i = 2; i < argc; i++) {
            auto str_arg = core::CreateNewClassWith<true>(machine, "java.lang.String", [&](auto *ref) {
                reinterpret_cast<java::lang::String*>(ref)->SetNativeString(argv[i]);
            });
            args_array_ref->SetAt(i - 2, str_arg);
        }

        machine.CallFunction(jar_ref->GetMainClass(), "main", args_array_value);

        if(machine.WasExceptionThrown()) {
            auto info = machine.GetExceptionInfo();
            LogMessage("Exception in main thread " + info.class_type + ":\n" + info.message);
        }
    }
    else {
        LogMessage("Critical error:\nUnable to execute the JAR file.");
    }

    return 0;
}
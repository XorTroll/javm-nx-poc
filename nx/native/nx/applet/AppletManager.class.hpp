
#pragma once
#include <nx_Include.hpp>

namespace nx::applet {

    class AppletManager : public native::Class {

        public:
            JAVM_NATIVE_CLASS_CTOR(AppletManager) {

                JAVM_NATIVE_CLASS_NAME("nx.applet.AppletManager")

                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(mainLoop)
            }
            
            core::Value mainLoop(core::Frame &frame, std::vector<core::FunctionParameter> parameters) {
                return core::CreateNewValue<bool>(appletMainLoop());
            }
    };

}
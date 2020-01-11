
#pragma once
#include <nx_Include.hpp>

namespace nx::hid {

    class Input : public native::Class {

        public:
            JAVM_NATIVE_CLASS_CTOR(Input) {

                JAVM_NATIVE_CLASS_NAME("nx.hid.Input")

                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(getDownInput)
                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(getUpInput)
                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(getHeldInput)
            }
            
            #define _JAVM_NX_INPUT_FN(ipt) \
            core::Value get##ipt##Input(core::Frame &frame, std::vector<core::FunctionParameter> parameters) { \
                if(parameters.size() > 0) { \
                    auto controller = parameters[0].value->Get<long>(); \
                    hidScanInput(); \
                    long keys = hidKeys##ipt((HidControllerID)controller); \
                    return core::CreateNewValue<long>(keys); \
                } \
                JAVM_NATIVE_CLASS_NO_RETURN \
            }

            _JAVM_NX_INPUT_FN(Down)
            _JAVM_NX_INPUT_FN(Up)
            _JAVM_NX_INPUT_FN(Held)
    };

}
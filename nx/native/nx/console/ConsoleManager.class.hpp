
#pragma once
#include <nx_Include.hpp>

#include <iostream>

namespace nx::console {

    class ConsoleManager : public native::Class {

        public:
            JAVM_NATIVE_CLASS_CTOR(ConsoleManager) {

                JAVM_NATIVE_CLASS_NAME("nx.console.ConsoleManager")

                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(init)
                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(exit)
                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(update)
                JAVM_NATIVE_CLASS_REGISTER_STATIC_FN(clear)
            }
            
            core::Value init(core::Frame &frame, std::vector<core::FunctionParameter> parameters) {

                consoleInit(nullptr);

                JAVM_NATIVE_CLASS_NO_RETURN
            }

            core::Value exit(core::Frame &frame, std::vector<core::FunctionParameter> parameters) {

                consoleExit(nullptr);

                JAVM_NATIVE_CLASS_NO_RETURN
            }

            core::Value update(core::Frame &frame, std::vector<core::FunctionParameter> parameters) {

                consoleUpdate(nullptr);

                JAVM_NATIVE_CLASS_NO_RETURN
            }

            core::Value clear(core::Frame &frame, std::vector<core::FunctionParameter> parameters) {

                consoleClear();

                JAVM_NATIVE_CLASS_NO_RETURN
            }
    };

}
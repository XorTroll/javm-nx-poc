
#pragma once
#include <nx/console/ConsoleManager.class.hpp>
#include <nx/hid/Input.class.hpp>
#include <nx/applet/AppletManager.class.hpp>

namespace nx {

    inline void LoadClasses(core::Machine &machine) {

        machine.LoadNativeClass<console::ConsoleManager>();
        machine.LoadNativeClass<hid::Input>();
        machine.LoadNativeClass<applet::AppletManager>();

    }

}
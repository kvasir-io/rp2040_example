#pragma once
#include "HWConfig.hpp"
///

#include <cmake_git_version/version.hpp>
#include <kvasir/Util/FaultHandler.hpp>
#include <kvasir/Util/StackProtector.hpp>

using Clock          = HW::SystickClock;
using StackProtector = Kvasir::StackProtector<>;
using FaultHandler   = Kvasir::Fault::Handler<HW::Fault_CleanUpAction>;

using Startup = Kvasir::Startup::
  Startup<HW::ClockSettings, Clock, HW::ComBackend, FaultHandler, StackProtector, HW::PinConfig>;

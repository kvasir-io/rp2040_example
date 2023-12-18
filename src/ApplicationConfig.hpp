#pragma once
#include "HWConfig.hpp"
///

#include <cmake_git_version/version.hpp>
#include <kvasir/Util/FaultHandler.hpp>
#include <kvasir/Util/StackProtector.hpp>

using Clock          = HW::SystickClock;
using StackProtector = Kvasir::StackProtector<>;
using FaultHandler   = Kvasir::Fault::Handler<HW::Fault_CleanUpAction>;

struct DmaConfig {
    static constexpr auto numberOfChannels     = 1;
    static constexpr auto callbackFunctionSize = 8;
};

using Dma = Kvasir::DMA::DmaBase<DmaConfig>;

using Uart
  = Kvasir::UART::UartBehavior<HW::UartConfig, Dma, Dma::Channel::ch0, Dma::Priority::low, 512>;

using Startup = Kvasir::Startup::Startup<
  HW::ClockSettings,
  Clock,
  HW::ComBackend,
  FaultHandler,
  StackProtector,
  HW::PinConfig,
  Dma,
  Uart>;

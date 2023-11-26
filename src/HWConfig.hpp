#pragma once
#include "HWConfigCommon.hpp"
namespace HW {
namespace Pin {
    using led = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin25));
}   // namespace Pin

struct Fault_CleanUpAction {
    void operator()() {}
};

struct PinConfig {
    static constexpr auto powerClockEnable = list(
      clear(Kvasir::Peripheral::RESETS::Registers<>::RESET::io_bank0),
      clear(Kvasir::Peripheral::RESETS::Registers<>::RESET::pads_bank0));

    static constexpr auto initStepPinConfig = list(makeOutput(HW::Pin::led{}));
};

}   // namespace HW

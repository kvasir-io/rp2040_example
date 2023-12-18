#pragma once
#include "HWConfigCommon.hpp"
namespace HW {
namespace Pin {

    using uart_tx = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin0));
    using uart_rx = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin1));
    using led = decltype(makePinLocation(Kvasir::Io::port0, Kvasir::Io::pin2));
}   // namespace Pin

struct Fault_CleanUpAction {
    void operator()() {}
};

struct UartConfig {
    static constexpr auto clockSpeed = ClockSpeed;

    static constexpr auto instance      = 0;
    static constexpr auto rxPinLocation = Pin::uart_rx{};
    static constexpr auto txPinLocation = Pin::uart_tx{};
    static constexpr auto baudRate      = 115200;
    static constexpr auto dataBits      = Kvasir::UART::DataBits::_8;
    static constexpr auto parity        = Kvasir::UART::Parity::none;
    static constexpr auto stopBits      = Kvasir::UART::StopBits::_1;
    static constexpr auto isrPriority   = 3;
};

struct PinConfig {
    static constexpr auto powerClockEnable = list(
      clear(Kvasir::Peripheral::RESETS::Registers<>::RESET::io_bank0),
      clear(Kvasir::Peripheral::RESETS::Registers<>::RESET::pads_bank0));

    static constexpr auto initStepPinConfig = list(makeOutput(HW::Pin::led{}));
};

}   // namespace HW

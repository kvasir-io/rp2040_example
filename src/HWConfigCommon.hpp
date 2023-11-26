#pragma once

struct DbgPres {
    bool operator()() { return true; }
};

#include "uc_log/DefaultRttComBackend.hpp"

namespace uc_log {
template<>
struct ComBackend<uc_log::Tag::User>
  : public uc_log::DefaultRttComBackend<DbgPres, 16384, 16384, rtt::BufferMode::skip> {};
}   // namespace uc_log
// need to be included first

#include "chip/Interrupt.hpp"
#include "core/core.hpp"
#include "uc_log/uc_log.hpp"

namespace HW {
static constexpr auto ClockSpeed   = 200'000'000;
static constexpr auto CrystalSpeed = 12'000'000;

struct SystickClockConfig {
    static constexpr auto clockBase = Kvasir::Systick::useProcessorClock;

    static constexpr auto clockSpeed     = ClockSpeed;
    static constexpr auto minOverrunTime = std::chrono::years(32);
};

using SystickClock = Kvasir::Systick::SystickClockBase<SystickClockConfig>;
}   // namespace HW

namespace uc_log {
template<>
struct LogClock<uc_log::Tag::User> : public HW::SystickClock {};
}   // namespace uc_log

#include "chip/chip.hpp"

namespace HW {
using ComBackend = uc_log::ComBackend<uc_log::Tag::User>;

struct ClockSettings {
    static void coreClockInit() {
        Kvasir::DefaultClockSettings::coreClockInit<ClockSpeed, CrystalSpeed>();
    }

    static void peripheryClockInit() {
        Kvasir::DefaultClockSettings::peripheryClockInit<ClockSpeed, CrystalSpeed>();
    }
};
}   // namespace HW

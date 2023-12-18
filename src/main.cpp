#include "ApplicationConfig.hpp"
//

#include <cmake_git_version/version.hpp>
#include <kvasir/Util/StaticVector.hpp>

template<typename Buffer>
static void print(Buffer& buffer, std::string_view s) {
    buffer.resize(s.size());
    std::transform(s.begin(), s.end(), buffer.begin(), [](auto x) {
        return static_cast<std::byte>(x);
    });
    UC_LOG_D("{}",s);
    Uart::send_nocopy(buffer);
}

int main() {
    UC_LOG_D("{}", CMakeGitVersion::FullVersion);
    Kvasir::StaticVector<std::byte, 128> buffer;
    auto                                 next = Clock::now();
    bool                                 on   = false;
    while(true) {
        auto const now = Clock::now();
        if(now > next) {
            next += 250ms;
            if(on) {
                print(buffer, "LED off\n");
                apply(clear(HW::Pin::led{}));
            } else {
                print(buffer, "LED on\n");
                apply(set(HW::Pin::led{}));

            }
            on = !on;
        }

        StackProtector::handler();
    }
}

KVASIR_START(Startup)

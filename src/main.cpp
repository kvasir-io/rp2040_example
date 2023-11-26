#include "ApplicationConfig.hpp"
//

#include <cmake_git_version/version.hpp>

int main() {
    UC_LOG_D("{}", CMakeGitVersion::FullVersion);
    auto next = Clock::now();
    while(true) {
        auto const now = Clock::now();
        if(now > next) {
            UC_LOG_D("foo");
            next += 1s;
            apply(toggle(HW::Pin::led{}));
        }

        StackProtector::handler();
    }
}

KVASIR_START(Startup)

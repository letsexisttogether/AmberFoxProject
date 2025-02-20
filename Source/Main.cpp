#include <iostream>
#include <cstdlib>
#include <functional>

#include "Application/Application.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    const std::string fileName{ ((argc > 1) ? (argv[1]) : ("Arrays.txt")) };

    Application application{ FileReader{ fileName } };

    return application.Run();
}

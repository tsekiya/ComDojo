#pragma once

#include "MainPage.g.h"

namespace winrt::WinrtHelloWorld::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage() = default;

    };
}

namespace winrt::WinrtHelloWorld::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}

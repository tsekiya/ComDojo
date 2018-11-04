﻿//
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace winrt::WinrtHelloWorld::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WinrtHelloWorld::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}

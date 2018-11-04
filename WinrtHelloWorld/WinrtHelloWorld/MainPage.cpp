#include "pch.h"
#include "MainPage.h"
#include "../UniversalGreeting/UniversalGreeting.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::WinrtHelloWorld::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
		HSTRING str;
		hstring message;
		com_ptr<IGreeting> greeting;

		winrt::check_hresult(CreateGreetingInstance(greeting.put()));
		winrt::check_hresult(greeting->SayHello(&str));
		message = ::WindowsGetStringRawBuffer(str, nullptr);
		winrt::check_hresult(::WindowsDeleteString(str));
		this->myTextBlock().Text(message);

        myButton().Content(box_value(L"Clicked"));
    }
}

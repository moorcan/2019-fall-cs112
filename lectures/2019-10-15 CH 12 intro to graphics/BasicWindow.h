#pragma once

#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Export.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Button.H"
#include "FL/fl_ask.H"
#include "FL/Fl_Widget.H"
#include <string>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
using namespace std;
class BasicWindow
{
private:
	Fl_Window* window = nullptr;
	Fl_Input* name_input = nullptr;
	Fl_Box* result_box = nullptr;
	Fl_Button* b1 = nullptr;

	//TODO: figure out how to call private member functions 
	//as callbacks
	void sayHello(Fl_Widget*, void*) {
		string text = name_input->value();
		text = "Hello, " + text;
		char* cstr = new char[text.length() + 1];
		std::strcpy(cstr, text.c_str());
		result_box->label(cstr);
	}

public:
	BasicWindow()
	{
		window = new Fl_Window{ 500, 500, "Window title" };
		name_input = new Fl_Input{ 200, 0, 200, 30, "Name:" };;
		b1 = new Fl_Button{ 20, 20, 80, 25, "&Beep" };

		//TODO: figure out how to call 
		//b1->callback(sayHello, 0);
		result_box = new Fl_Box{ 200, 200, 200, 200, "test" };
		window->show();
	}
};
#include "Window.h"

int main()
{
    Window* window = Window::get();
    window->run();

    return 0;
}
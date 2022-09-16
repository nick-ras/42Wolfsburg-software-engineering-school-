#include "../so_long.h"
 
int main(void)
{
    Display *display;
    Window window;
    XEvent event;
    // char *msg = "Hello, Worlds!!!";
    int screen;
 
    // open connection to the server
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        ft_printf("Cannot open display\n %s\n", stderr);
        exit(1);
    }
 
    screen = DefaultScreen(display);
 
    // create window
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 100, 100, 500, 300, 1,
                                 WhitePixel(display, screen), WhitePixel(display, screen));
 
    // select kind of events we are interested in
    XSelectInput(display, window, ExposureMask | KeyPressMask);
 
    // map (show) the window
    XMapWindow(display, window);
 
    // event loop
    while (1)
    {
        XNextEvent(display, &event);
 
        // // draw or redraw the window
        // if (event.type == Expose)
        // {
        //     XFillRectangle(display, window, DefaultGC(display, screen), 40, 	40, 110, 110);
        //     XDrawString(display, window, DefaultGC(display, screen), 50, 50, msg, strlen(msg));
        // }
        // // exit on key press
        // if (event.type == KeyPress)
        //     break;
    }
 
    // close connection to the server
    // XCloseDisplay(display);
 
    return (0);
 }
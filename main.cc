/*
 * Main file, currently for testing
 */

#include "Window.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
    Tests::runAll();

    QApplication app(argc, argv);

    Window window(720, 540);
    window.show();

    return app.exec();
}
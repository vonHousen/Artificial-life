/*
 * Main window to display simulation
 */

#include "Window.h"

Window::Window(int width, int height, QWidget *parent)
    : QWidget(parent), width_(width), height_(height)
{
    setWindowTitle(tr("Artificial Life"));
    setFixedSize(width, height);
}

Window::~Window()
{}
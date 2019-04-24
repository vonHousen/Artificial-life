/*
 * Main window to display simulation
 */

#ifndef ARTIFICIAL_LIFE_WINDOW_H
#define ARTIFICIAL_LIFE_WINDOW_H

#include <QtWidgets>

class Window : public QWidget
{
Q_OBJECT

public:
    explicit Window(int width, int height, QWidget *parent = 0);
    ~Window();

private:
    int width_;
    int height_;
};


#endif //ARTIFICIAL_LIFE_WINDOW_H

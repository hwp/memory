// main.cpp
// Main function.
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2013, All rights reserved.

#include <QApplication>

#include "memory.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Memory window;
    window.show();

    return app.exec();
}


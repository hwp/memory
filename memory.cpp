// memory.cpp
// Application window.
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2013, All rights reserved.

#include <QGridLayout>

#include "memory.h"

Memory::Memory(QWidget* parent) : QWidget(parent) {
  resize(600, 400);
  setWindowTitle("Memory Trainer");

  nod = new QLineEdit();
  delay = new QLineEdit();
  button = new QPushButton("&Start", this);
  number = new QLabel("Press button to start");

  QGridLayout* grid = new QGridLayout(this);

  grid->addWidget(new QLabel("Number of Digits:"), 0, 0);
  grid->addWidget(nod, 0, 1);
  grid->addWidget(new QLabel("Time Delay:"), 0, 2);
  grid->addWidget(delay, 0, 3);
  grid->addWidget(button, 0, 4);
  grid->addWidget(number, 1, 0, 3, 5);

  setLayout(grid);
}


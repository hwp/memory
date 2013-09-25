// memory.cpp
// Application window.
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2013, All rights reserved.

#include <QGridLayout>
#include <QFont>
#include <QApplication>
#include <QTextStream>

#include "memory.h"

Memory::Memory(QWidget* parent) : QWidget(parent) {
  resize(600, 400);
  setWindowTitle("Memory Trainer");

  nod = new QComboBox();
  for (int i = MIN_NOD; i <= MAX_NOD; i++) {
    nod->addItem(QString("%1").arg(i), i);
  }

  delay = new QComboBox();
  for (int i = MIN_DELAY; i <= MAX_DELAY; i++) {
    delay->addItem(QString("%1").arg(i), i);
  }

  button = new QPushButton("&Start", this);
  number = new QLabel("Press button to start");
  number->setAlignment(Qt::AlignCenter);
  QFont f;
  f.setPointSize(48);
  number->setFont(f);

  QGridLayout* grid = new QGridLayout(this);

  grid->addWidget(new QLabel("Number of Digits:"), 0, 0);
  grid->addWidget(nod, 0, 1);
  grid->addWidget(new QLabel("Time Delay (s):"), 0, 2);
  grid->addWidget(delay, 0, 3);
  grid->addWidget(button, 0, 4);
  grid->addWidget(number, 1, 0, 3, 5);

  setLayout(grid);

  connect(button, SIGNAL(clicked()), this, SLOT(start()));
}

void Memory::start() {
  number->setText(nod->currentText());
  QTextStream out(stdout);
  out << nod->currentText() << endl;

  startTimer(1000);
}


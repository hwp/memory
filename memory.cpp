// memory.cpp
// Application window.
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2013, All rights reserved.

#include <QGridLayout>
#include <QFont>
#include <QApplication>
#include <QTextEdit>

#include "memory.h"

Memory::Memory(QWidget* parent)
    : QWidget(parent), started(false) {
  resize(600, 400);
  setWindowTitle("Memory Trainer");

  nodbox = new QComboBox();
  for (int i = MIN_NOD; i <= MAX_NOD; i++) {
    nodbox->addItem(QString("%1").arg(i), i);
  }

  disbox = new QComboBox();
  for (int i = MIN_DELAY; i <= MAX_DELAY; i++) {
    disbox->addItem(QString("%1").arg(i), i);
  }

  intbox = new QComboBox();
  for (int i = MIN_DELAY; i <= MAX_DELAY; i++) {
    intbox->addItem(QString("%1").arg(i), i);
  }

  repbox = new QComboBox();
  repbox->addItem(QString("%1").arg(10), 10);
  repbox->addItem(QString("%1").arg(20), 20);
  repbox->addItem(QString("%1").arg(30), 30);

  button = new QPushButton("&Start", this);
  number = new QLabel("Press button to start");
  number->setAlignment(Qt::AlignCenter);
  QFont f;
  f.setPointSize(48);
  number->setFont(f);

  QGridLayout* grid = new QGridLayout(this);

  grid->addWidget(new QLabel("Number of Digits:"), 0, 0);
  grid->addWidget(nodbox, 0, 1);
  grid->addWidget(new QLabel("Replications:"), 0, 2);
  grid->addWidget(repbox, 0, 3);
  grid->addWidget(new QLabel("Display Time (s):"), 1, 0);
  grid->addWidget(disbox, 1, 1);
  grid->addWidget(new QLabel("Blank Time (s):"), 1, 2);
  grid->addWidget(intbox, 1, 3);
  grid->addWidget(button, 0, 4, 2, 1);
  grid->addWidget(number, 2, 0, 3, 5);

  setLayout(grid);

  connect(button, SIGNAL(clicked()), this, SLOT(start()));
}

void Memory::start() {
  if (!started) {
    nod = nodbox->itemData(nodbox->currentIndex()).toInt();
    dt = disbox->itemData(disbox->currentIndex()).toInt();
    it = intbox->itemData(intbox->currentIndex()).toInt();
    rep = repbox->itemData(repbox->currentIndex()).toInt();
    rc = 0;
    tc = 0;
    history.clear();
    button->setText("&Stop");
    tid = startTimer(1000);
  }
  else {
    killTimer(tid);
    button->setText("&Start");
    showHistory();
  }
  started = !started;
}

void Memory::showNumber() {
  QString t;
  for (int i = 0; i < nod; i++) {
    char c = '0' + rand() % 10;
    t.append(c);
  }
  history.push_back(t);
  number->setText(t);
}

void Memory::showBlank() {
  number->setText("");
}

void Memory::showHistory() {
  QWidget* popup = new QWidget();

  QGridLayout* grid = new QGridLayout(popup);
  QTextEdit *edit = new QTextEdit(this);
  grid->addWidget(edit, 0, 0);
  popup->setLayout(grid);

  foreach(QString h, history) {
    edit->append(h); 
  }

  popup->show();
}

void Memory::timerEvent(QTimerEvent *e) {
  Q_UNUSED(e);

  if (tc == 0) {
    rc++;
    if (rc == rep) {
      start();
      return;
    }
    showNumber();
  }
  else if (tc == dt) {
    showBlank();
  }
  tc = (tc + 1) % (dt + it);
}


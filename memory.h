// memory.h
// Header for application window.
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2013, All rights reserved.

#ifndef MEMORY_H_
#define MEMORY_H_

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

#define MIN_NOD 4
#define MAX_NOD 10
#define MIN_DELAY 1
#define MAX_DELAY 15

class Memory : public QWidget {
  Q_OBJECT

  public:
    explicit Memory(QWidget* parent = 0);

  public slots:
    void start();

  private:
    QComboBox* nod;
    QComboBox* delay;
    QPushButton* button;
    QLabel* number;
};

#endif  // MEMORY_H_


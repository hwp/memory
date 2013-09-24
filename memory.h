// memory.h
// Header for application window.
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2013, All rights reserved.

#ifndef MEMORY_H_
#define MEMORY_H_

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class Memory : public QWidget {
  public:
    explicit Memory(QWidget* parent = 0);

  private:
    QLineEdit* nod;
    QLineEdit* delay;
    QPushButton* button;
    QLabel* number;
};

#endif  // MEMORY_H_


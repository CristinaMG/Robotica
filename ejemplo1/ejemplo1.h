
#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include <QLCDNumber>

#include <thread>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "Hilo.h"

using namespace std;

class ejemplo1 : public QWidget, public Ui_Counter
{
Q_OBJECT

private:
    std::thread t1;
    int periodo;
    //std::thread t[10];
    
public:
    ejemplo1();
    virtual ~ejemplo1();
    bool active;
    static int cnt;
    Hilo hilo;
    //void contar();
  
public slots:
	void doButton();
    void tick();
    void doPeriod();

};

#endif // ejemplo1_H


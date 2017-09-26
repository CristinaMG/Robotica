#ifndef Hilo_H
#define Hilo_H

#include <QtGui>
#include <QLCDNumber>
#include <thread>

class Hilo: public QWidget
{
Q_OBJECT
private:
    int period;
    bool stopped;
public:
    Hilo();
    virtual ~Hilo();
    void run(std::function<void()> tick);
    void start();
    void pause();
    void setPeriod(int millis);
    
};
#endif

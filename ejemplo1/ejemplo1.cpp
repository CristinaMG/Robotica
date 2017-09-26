#include "ejemplo1.h"

//Se inicializa la variable estatica
int ejemplo1::cnt = 0;

//Constructor de ejemplo1
ejemplo1::ejemplo1(): Ui_Counter()
{
    //Entorno grafico QT
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );
    
    //Bandera control para el boton
    active = true;
    
    //Periodo
    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(doPeriod()));
    periodo = 1;
    lcdNumber_2->display(periodo);
    
    //Hilo contador
    t1 = std::move(std::thread(&Hilo::run, &hilo, std::bind(&ejemplo1::tick, this )));
}

//Destructor de ejemplo1
ejemplo1::~ejemplo1()
{
}

//Slot que para o inicializa el contador segun el estado en el que se encontrase
void ejemplo1::doButton()
{
	qDebug() << "click on button";
    if(active){
        hilo.pause();
        active = false;
    }else{
        hilo.start();
        active = true;
    }
        
}

//Metodo asociado al hilo para hacer el callback
void ejemplo1::tick()
{
    qDebug()<<"tick";
    while(active){
        lcdNumber->display(cnt);
        cnt++;
        sleep(periodo);
    }
}

//Slot que lee el contenido del cuadro de texto para cambiar el periodo del contador
void ejemplo1::doPeriod(){
    QString texto = lineEdit->text();
    bool ok;
    periodo = texto.toInt(&ok, 10);
    hilo.setPeriod(periodo);
    lcdNumber_2->display(periodo);
}


//////////////////Sesion 2//////////////////////
/*
void ejemplo1::contar() {
    int i=0;
    while (i<10) {
        t[i] = std::move ( std::thread ([i,&cnt]()  { 
            //qDebug() <<"["<<i<<"]"<<"While: "<<cnt<<(cnt/10);
            while (ejemplo1::cnt/10!=i){
                sleep(1);
            }; 
            while (cnt/10==i){
                qDebug() << "Soy hilo "<<i<<" n:"<< cnt;
                cnt++;
                //sleep(1000);
                //sleep(spinBox->value());
            }
                
            })); 
        i++;
    }
    for (auto&& h:t) 
        h.join();
    
}*/



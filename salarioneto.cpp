#include "salarioneto.h"
#include "ui_salarioneto.h"
#include <QDebug>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include "calculodsalario.h"
#include <QAction>
#include <QEvent>


SalarioNeto::SalarioNeto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SalarioNeto)
{
    ui->setupUi(this);

    connect(ui->actionCalcular, SIGNAL(triggered(bool)),
            this, SLOT(on_cmd_Calcular_clicked()));

}

SalarioNeto::~SalarioNeto()
{
    delete ui;
}

char SalarioNeto::selecJornada()
{
    if(this->ui->B_Matutino->isChecked()){
        return 'm';

    }else if(this->ui->B_Vespertino->isChecked()){
        return 'v';

    }else{
        return 'n';
    }
}

void SalarioNeto::MostrarEnPrograma()
{
    QString nombre = this->ui->lEdit_Name->text();
    int horas = this->ui->sBox_Horas->value();
    char jornada = this->selecJornada();

    CalculoDsalario rolPagos(nombre,horas,jornada);
    rolPagos.calcular();

    QString name = ui->lEdit_Name->text();
    QString hor = hor.number(horas);
    QString sal = sal.number(rolPagos.salario());
    QString des = des.number(rolPagos.descuento());
    QString saln = saln.number(rolPagos.salarioNeto());
    QString Lista[10];
    QString Dato = "Obrero: "+ name +"\n"
                    "Horas: "+ hor +"\n"
                    "Salatio: $"+ sal +"\n"
                    "Descuento(9.5%): $"+ des +"\n"
                    "Salario neto: $"+ saln +"\n"
                    "-----------------------\n\n";

    int contar = 0;
    qDebug() << contar;
    for(int x=contar;x<(contar+1);x++){
        Lista[x]=Dato;
    }

    for(int x=contar;x<(contar+1);x++){
        ui->out_resultado->setText("***  Datos del Salario  ***\n"
                                   + Lista[x]);
    }
    contar++;
    ui->lEdit_Name->clear();
    ui->lEdit_Name->setFocus();
    ui->sBox_Horas->setValue(1);
    ui->B_Matutino->setChecked(true);

}

void SalarioNeto::GuardarDatos()
{
    QString temporal = QDir::home().absolutePath() + "/New_Fil";
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),
                                                    temporal, "Archivo de Configuracion (*.cfg)");

    QFile archivo(fileName);
        if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream out(&archivo);
            out << ui->out_resultado->toPlainText();

            QMessageBox::information(this, tr("Mensaje"),tr("Guardado correctamente"));
        }else{
            QMessageBox::information(this, tr("Error"),tr("No guardo el archivo"));
        }
}

void SalarioNeto::AbrirDatos()
{
    QString Saver = QDir::home().absolutePath();
    QString file_name = QFileDialog::getOpenFileName(this,("Save File"),
                                                    Saver, "Archivo de Configuracion (*.cfg)");

    QFile File(file_name);
    if(!File.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this, tr("Error"),tr("El documento no fue abierto o no se pudo leer"));
        return;
    }

    QTextStream in(&File);
    QString Linea = in.readAll();
    ui->out_resultado->setText(Linea);

    QMessageBox::information(this, tr("Mensaje"),tr("Documento leido correctamente"));
}
//--------------------------------------------
void SalarioNeto::on_cmd_Calcular_clicked()
{
    MostrarEnPrograma();
}
//--------------------------------------------
void SalarioNeto::on_actionGuardar_triggered()
{
    GuardarDatos();
}

void SalarioNeto::on_actionAbrir_triggered()
{
    AbrirDatos();
}

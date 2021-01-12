#ifndef SALARIONETO_H
#define SALARIONETO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SalarioNeto; }
QT_END_NAMESPACE

class SalarioNeto : public QMainWindow
{
    Q_OBJECT

public:
    SalarioNeto(QWidget *parent = nullptr);
    ~SalarioNeto();

    char selecJornada();
    void MostrarEnPrograma();
    void GuardarDatos();
    void AbrirDatos();



private slots:
    void on_cmd_Calcular_clicked();

    void on_actionGuardar_triggered();
    void on_actionAbrir_triggered();

private:
    Ui::SalarioNeto *ui;
};
#endif // SALARIONETO_H

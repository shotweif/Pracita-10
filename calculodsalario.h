#ifndef CALCULODSALARIO_H
#define CALCULODSALARIO_H

#include <QObject>

class CalculoDsalario : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float salario READ salario)
    Q_PROPERTY(float descuento READ descuento)
    Q_PROPERTY(float salarioNeto READ salarioNeto)

private:
    int m_horas;
    QString nombre;
    char  m_jornada;

    float m_salario;
    float m_descuento;
    float m_salarioNeto;

    float const VALOR_HORA_VESPERTINO = 5.15;
    float const VALOR_HORA_MATUTINO   = 8.50;
    float const VALOR_HORA_NOCTURNO   = 12.65;
    float const PORCENTAJE_DESCUENTO  = 9.5;

public:
    explicit CalculoDsalario(QObject *parent = nullptr);
    CalculoDsalario(QString nombre, int horas, char jornadas);

        void calcular();


        float salario() const;
        float descuento() const;
        float salarioNeto() const;
};

#endif // CALCULODSALARIO_H

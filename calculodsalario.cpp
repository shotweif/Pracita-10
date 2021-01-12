#include "calculodsalario.h"

float CalculoDsalario::salario() const
{
    return m_salario;
}

float CalculoDsalario::descuento() const
{
    return m_descuento;
}

float CalculoDsalario::salarioNeto() const
{
    return m_salarioNeto;
}
//----------------------------------------------------------------------------------------------

CalculoDsalario::CalculoDsalario(QString nombre, int horas, char jornadas)
{
    this->nombre = nombre;
    this->m_horas = horas;
    this->m_jornada = jornadas;
}

void CalculoDsalario::calcular()
{
    float valorHora = 0;
    switch (this->m_jornada) {
        case 'v':
            valorHora = VALOR_HORA_VESPERTINO;
            break;

        case 'm':
            valorHora = VALOR_HORA_MATUTINO;
            break;

        case 'n':
            valorHora = VALOR_HORA_NOCTURNO;
            break;

        default:
            break;
    }
    m_salario = m_horas * valorHora;
    m_descuento = m_salario * PORCENTAJE_DESCUENTO/100;
    m_salarioNeto = m_salario - m_descuento;
}

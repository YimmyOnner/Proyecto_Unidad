#include <stdio.h>
#include "asistencia.h"
#include "reports.h"

void registrarAsistencia(char curso[], int grupo)
{
    char estudiantes[3][10][30] = {
        {"Ana", "Juan", "Maria", "Carlos", "Sofia", "Luis", "Paola", "Diego", "Elena", "Miguel"},
        {"Jimmy", "Onner", "Elvis", "Hernan", "Torres", "Soto", "Medina", "Reyes", "Flores", "Guzman"},
        {"Coronel", "Lopez", "Sebastian", "Mendoza", "Suarez", "Messi", "Adrian", "Vega", "Leonardo", "Aguirre"}};

    char estados[10];
    char mes[20], dia[20];

    // Se pide la fecha UNA sola vez aquí
    printf("\n--- CONFIGURACION DE FECHA PARA EL REPORTE DIARIO ---\n");
    printf("Ingrese Mes: ");
    scanf("%s", mes);
    printf("Ingrese Dia: ");
    scanf("%s", dia);

    printf("\n--- TOMA DE ASISTENCIA ---\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Asistio %s? (P/A): ", estudiantes[grupo][i]);
        scanf(" %c", &estados[i]);
    }

    // ENVIAR AL ARCHIVO SEPARADO
    escribirReporteFinal(curso, mes, dia, estudiantes[grupo], estados);

    printf("\n[OK] Datos enviados al reporte por separado.\n");
}

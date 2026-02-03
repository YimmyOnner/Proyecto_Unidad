#include <stdio.h>
#include "asistencia.h"
#include "reports.h"

void registrarAsistencia(char docente[], char curso[], int grupo) {
    char estudiantes[3][10][30] = {
        {"Ana","Juan","Maria","Carlos","Sofia","Luis","Paola","Diego","Elena","Miguel"},
        {"Jimmy","Onner","Elvis","Hernan","Torres","Soto","Medina","Reyes","Flores","Guzman"},
        {"Coronel","Lopez","Sebastian","Mendoza","Suarez","Messi","Adrian","Vega","Leonardo","Aguirre"}
    };

    char estados[10], mes[20], dia[20];
    
    printf("\n--- CONFIGURACION DE REPORTE ---\n");
    printf("Ingrese Mes: "); scanf("%s", mes);
    printf("Ingrese Dia: "); scanf("%s", dia);

    printf("\n--- PASANDO LISTA (Docente: %s) ---\n", docente);
    for (int i = 0; i < 10; i++) {
        printf("%s (P/A): ", estudiantes[grupo][i]);
        scanf(" %c", &estados[i]);
    }

    // Enviamos los 6 datos al generador de reportes
    escribirReporteFinal(docente, curso, mes, dia, estudiantes[grupo], estados);
}

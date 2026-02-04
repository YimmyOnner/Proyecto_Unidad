#include <stdio.h>
#include "asistencia.h"
#include "reports.h"

void registrarAsistencia(char docente[], char curso[], int grupo) {
    char estudiantes[3][10][30] = {
        {"Ana","Juan","Maria","Carlos","Sofia","Luis","Paola","Diego","Elena","Miguel"},
        {"Jimmy","Onner","Elvis","Hernan","Torres","Soto","Medina","Reyes","Flores","Guzman"},
        {"Coronel","Lopez","Sebastian","Mendoza","Suarez","Messi","Adrian","Vega","Leonardo","Aguirre"}
    };

    char estados[10];
    char mes[20], dia[20];

    // Datos de la sesión
    printf("\n--- CONFIGURACION DE FECHA ---\n");
    printf("Mes: "); scanf("%s", mes);
    printf("Dia: "); scanf("%s", dia);

    // BLOQUE DE ASISTENCIA ACTUALIZADO (P/A/J)
    printf("\n--- PASANDO LISTA (Docente: %s) ---\n", docente);
    printf("Opciones: [P] Presente | [A] Ausente | [J] Justificado\n\n");

    for (int i = 0; i < 10; i++) {
        do {
            printf("%-15s (P/A/J): ", estudiantes[grupo][i]);
            scanf(" %c", &estados[i]);
            
            // Validamos que solo ingrese una de las 3 opciones (mayúscula o minúscula)
            if (estados[i] != 'P' && estados[i] != 'p' && 
                estados[i] != 'A' && estados[i] != 'a' && 
                estados[i] != 'J' && estados[i] != 'j') {
                printf("  [!] Error: Use solo P, A o J.\n");
            } else {
                break; // Entrada válida
            }
        } while (1);
    }

    // Enviamos al reporte final (reports.c ya está preparado para imprimir el caracter que reciba)
    escribirReporteFinal(docente, curso, mes, dia, estudiantes[grupo], estados);
}

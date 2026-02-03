#include <stdio.h>
#include "reports.h"

void escribirReporteFinal(char curso[], char mes[], char dia[], char nombres[10][30], char estados[10]) {
    FILE *fp = fopen("reports.txt", "a");
    if (fp == NULL) return;

    fprintf(fp, "==========================================\n");
    fprintf(fp, "REPORTE SEMANAL - CURSO: %s\n", curso);
    fprintf(fp, "FECHA: %s de %s\n", dia, mes);
    fprintf(fp, "------------------------------------------\n");
    fprintf(fp, "%-20s | %s\n", "ESTUDIANTE", "ASISTENCIA");
    fprintf(fp, "------------------------------------------\n");

    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%-20s | %c\n", nombres[i], estados[i]);
    }

    fprintf(fp, "==========================================\n\n");
    fclose(fp);
}

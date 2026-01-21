#include <stdio.h>

// Estructura para cursos
struct Curso {
    char nombre[50];
    char horario[30];
    int total_clases;
    int asistencias;
};

// Prototipo
void generarReporte(struct Curso cursos[], int cantidad);

int main() {

    struct Curso cursos[3] = {
        {"Programacion en C", "08:00 - 10:00", 20, 18},
        {"Base de Datos", "10:00 - 12:00", 20, 16},
        {"Sistemas Operativos", "14:00 - 16:00", 20, 19}
    };

    generarReporte(cursos, 3);

    return 0;
}

void generarReporte(struct Curso cursos[], int cantidad) {

    FILE *archivo;
    int i;
    float porcentaje;

    archivo = fopen("reporte_asistencia.txt", "w");

    if (archivo == NULL) {
        printf("Error al crear el archivo\n");
        return;
    }

    fprintf(archivo, "===== REPORTE DE ASISTENCIA =====\n\n");

    for (i = 0; i < cantidad; i++) {
        porcentaje = (cursos[i].asistencias * 100.0) / cursos[i].total_clases;

        fprintf(archivo, "Curso: %s\n", cursos[i].nombre);
        fprintf(archivo, "Horario: %s\n", cursos[i].horario);
        fprintf(archivo, "Clases Totales: %d\n", cursos[i].total_clases);
        fprintf(archivo, "Asistencias: %d\n", cursos[i].asistencias);
        fprintf(archivo, "Porcentaje de Asistencia: %.2f%%\n", porcentaje);
        fprintf(archivo, "-----------------------------\n");
    }

    fclose(archivo);

    printf("Reporte generado correctamente en 'reporte_asistencia.txt'\n");
}

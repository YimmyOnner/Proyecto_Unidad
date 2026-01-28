#include <stdio.h>
#include "Grades.h"
#include <string.h>

void mostrarCursosDocente(Docente *docente) {
    int opcion;
    do {
        printf("\nCursos del Docente: %s (ID: %d)\n", docente->nombre, docente->id);
        if (docente->numCursos == 0) {
            printf("El docente no tiene cursos asignados.\n");
        } else {
            for (int i = 0; i < docente->numCursos; i++) {
                printf("------------------------\n");
                printf("%d. Curso: %d, Materia: %s\n", i + 1, docente->cursos[i].id, docente->cursos[i].nombre);
            }
        }
        printf("\n--------------------------\n");
        printf("Opciones:\n");
        printf("1. Ver horario del curso\n");
        printf("2. Cerrar sesion\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1:
                //Llamar la fucion
                
                break;
            case 2:
                printf("Cerrando sesion...\n");
                break;
            default:
                printf("Opcion no válida.\n");
                break;
        }
    } while (opcion != 2);
}

void cargarCursosDesdeCSV(Docente *docente) {
    char filename[20];
    sprintf(filename, "cursos%d.csv", docente->id);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo %s. Iniciando con cursos vacios.\n", filename);
        docente->numCursos = 0;
        return;
    }
    docente->numCursos = 0;
    char linea[200];
    while (fgets(linea, sizeof(linea), fp) && docente->numCursos < 10) {
        int id;
        char nombre[100];
        if (sscanf(linea, "%d,%99[^\n]", &id, nombre) == 2) {
            docente->cursos[docente->numCursos].id = id;
            strcpy(docente->cursos[docente->numCursos].nombre, nombre);
            docente->numCursos++;
        }
    }
    fclose(fp);
}

void guardarCursosEnCSV(Docente *docente) {
    char filename[20];
    sprintf(filename, "cursos%d.csv", docente->id);
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error al guardar cursos en %s.\n", filename);
        return;
    }
    for (int i = 0; i < docente->numCursos; i++) {
        fprintf(fp, "%d,%s\n", docente->cursos[i].id, docente->cursos[i].nombre);
    }
    fclose(fp);
}


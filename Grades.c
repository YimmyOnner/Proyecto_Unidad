#include <stdio.h>
#include <string.h>
#include "grades.h"

void cargarCursosDesdeCSV(Docente *docente) {
    FILE *file = fopen("cursos.csv", "r");
    if (!file) return;

    char line[100];
    int id_doc_csv;
    char nombre_curso[50];
    int h1, h2;

    while (fgets(line, sizeof(line), file)) {
        // Suponiendo formato: ID_DOCENTE,NOMBRE_CURSO,HORARIO1,HORARIO2
        sscanf(line, "%d,%[^,],%d,%d", &id_doc_csv, nombre_curso, &h1, &h2);

        // SOLO guardamos el curso si el ID coincide con el del docente logueado
        if (id_doc_csv == docente->id) {
            strcpy(docente->cursos[docente->numCursos].nombre, nombre_curso);
            docente->cursos[docente->numCursos].horario1 = h1;
            docente->cursos[docente->numCursos].horario2 = h2;
            docente->numCursos++;
        }
    }
    fclose(file);
}

void guardarCursosEnCSV(Docente *docente) {
    char archivo[20];
    sprintf(archivo, "cursos%d.csv", docente->id);

    FILE *fp = fopen(archivo, "w");

    for (int i = 0; i < docente->numCursos; i++) {
        fprintf(fp, "%d,%s,%d,%d\n",
            docente->cursos[i].id,
            docente->cursos[i].nombre,
            docente->cursos[i].horario1,
            docente->cursos[i].horario2);
    }

    fclose(fp);
}

void mostrarCursosDocente(Docente *docente) {
    printf("\nCURSOS DEL DOCENTE %s\n", docente->nombre);
    for (int i = 0; i < docente->numCursos; i++) {
        printf("%d. %s (Horarios %d y %d)\n",
            i + 1,
            docente->cursos[i].nombre,
            docente->cursos[i].horario1,
            docente->cursos[i].horario2);
    }
}

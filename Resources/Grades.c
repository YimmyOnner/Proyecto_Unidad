#include <stdio.h>
#include <string.h>
#include "grades.h"

void cargarCursosDesdeCSV(Docente *docente) {
    char archivo[20];
    sprintf(archivo, "cursos%d.csv", docente->id);

    FILE *fp = fopen(archivo, "r");
    docente->numCursos = 0;

    if (!fp) {
        printf("No se pudo abrir %s\n", archivo);
        return;
    }

    while (fscanf(fp, "%d,%99[^,],%d,%d\n",
        &docente->cursos[docente->numCursos].id,
        docente->cursos[docente->numCursos].nombre,
        &docente->cursos[docente->numCursos].horario1,
        &docente->cursos[docente->numCursos].horario2) == 4) {

        docente->numCursos++;
    }

    fclose(fp);
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

void agregarCurso(Docente *docente) {
    if (docente->numCursos >= 10) return;

    Curso *c = &docente->cursos[docente->numCursos];

    printf("ID del curso: ");
    scanf("%d", &c->id);
    getchar();

    printf("Nombre del curso: ");
    fgets(c->nombre, 100, stdin);
    c->nombre[strcspn(c->nombre, "\n")] = 0;

    printf("Horario 1 (1-6): ");
    scanf("%d", &c->horario1);

    printf("Horario 2 (1-6): ");
    scanf("%d", &c->horario2);

    docente->numCursos++;
    guardarCursosEnCSV(docente);
}


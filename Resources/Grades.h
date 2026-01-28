#ifndef GRADES_H
#define GRADES_H

#include <stdio.h>

// Estructura para representar un curso
typedef struct {
    int id;
    char nombre[100];
} Curso;

typedef struct {
    int id;
    char nombre[100];
    Curso cursos[10];
    int numCursos;
} Docente;

void mostrarCursosDocente(Docente *docente);
void cargarCursosDesdeCSV(Docente *docente);
void guardarCursosEnCSV(Docente *docente);

#endif // GRADES_H

#ifndef GRADES_H
#define GRADES_H

typedef struct
{
    int id;
    char nombre[100];
    int horario1;
    int horario2;
} Curso;

typedef struct
{
    int id;
    char nombre[100];
    Curso cursos[10];
    int numCursos;
} Docente;

void cargarCursosDesdeCSV(Docente *docente);
void guardarCursosEnCSV(Docente *docente);
void mostrarCursosDocente(Docente *docente);
void agregarCurso(Docente *docente);

#endif

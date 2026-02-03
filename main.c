#include <stdio.h>
#include <string.h>
#include "grades.h"
#include "horarios.h"
#include "asistencia.h"
#include "reports.h"

// Estructura de usuario para el login
typedef struct {
    char username[20];
    char password[20];
    int id;
    char nombreReal[50];
} Usuario;

void ejecutarHorario(int h) {
    switch (h) {
        case 1: horario1(); break;
        case 2: horario2(); break;
        case 3: horario3(); break;
        case 4: horario4(); break;
        case 5: horario5(); break;
        case 6: horario6(); break;
    }
}

int main() {
    Usuario DB[3] = {
        {"docente1", "pass1", 1, "Juan Perez"},
        {"docente2", "pass2", 2, "Maria Garcia"},
        {"docente3", "pass3", 3, "Carlos Lopez"}
    };

    char user_input[20], pass_input[20];
    int autenticado = -1;

    // --- BLOQUE DE LOGIN ---
    printf("=== LOGIN DE DOCENTES ===\n");
    printf("Usuario: "); scanf("%s", user_input);
    printf("Contrasena: "); scanf("%s", pass_input);

    for (int i = 0; i < 3; i++) {
        if (strcmp(user_input, DB[i].username) == 0 && strcmp(pass_input, DB[i].password) == 0) {
            autenticado = i;
            break;
        }
    }

    if (autenticado == -1) {
        printf("\nError: Usuario o contrasena incorrectos.\n");
        return 1;
    }

    // --- CARGA DE DATOS DEL DOCENTE ---
    printf("\nBienvenido(a), %s\n", DB[autenticado].nombreReal);
    Docente docente = {DB[autenticado].id, ""};
    strcpy(docente.nombre, DB[autenticado].nombreReal);

    cargarCursosDesdeCSV(&docente);
    mostrarCursosDocente(&docente);

    int curso_idx, opcionHorario;
    printf("\nSeleccione curso (numero): ");
    scanf("%d", &curso_idx);
    curso_idx--; // Ajuste para el índice del arreglo

    printf("\nSeleccione horario (1 o 2): ");
    scanf("%d", &opcionHorario);

    int h_id = (opcionHorario == 1) ? docente.cursos[curso_idx].horario1 : docente.cursos[curso_idx].horario2;

    // --- FLUJO DE EJECUCION ---

    // 1. Muestra la selección visual (Mes/Día en pantalla según tus funciones originales)
    ejecutarHorario(h_id);

    // 2. Llama a la asistencia, la cual pedirá los datos del reporte y llamará a reports.c
    registrarAsistencia(docente.cursos[curso_idx].nombre, curso_idx);

    printf("\nProceso finalizado con exito.\n");
    return 0;
}

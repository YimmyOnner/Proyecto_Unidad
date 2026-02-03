#include <stdio.h>
#include <string.h>
#include "grades.h"
#include "horarios.h"
#include "asistencia.h"
#include "reports.h"

typedef struct {
    char username[20];
    char password[20];
    int id; 
    char nombreReal[50];
} Usuario;

int main() {
    // Cada docente tiene su ID único para filtrar sus cursos
    Usuario DB[3] = {
        {"docente1", "pass1", 101, "Juan Perez"},
        {"docente2", "pass2", 102, "Maria Garcia"},
        {"docente3", "pass3", 103, "Carlos Lopez"}
    };

    char u_in[20], p_in[20];
    int auth = -1;

    printf("=== LOGIN ===\nUsuario: "); scanf("%s", u_in);
    printf("Pass: "); scanf("%s", p_in);

    for (int i = 0; i < 3; i++) {
        if (strcmp(u_in, DB[i].username) == 0 && strcmp(p_in, DB[i].password) == 0) {
            auth = i; break;
        }
    }

    if (auth == -1) { printf("Login fallido.\n"); return 1; }

    Docente d;
    d.id = DB[auth].id;
    strcpy(d.nombre, DB[auth].nombreReal);
    d.numCursos = 0;

    // Carga solo los cursos del ID logueado (ej: 101)
    cargarCursosDesdeCSV(&d); 
    mostrarCursosDocente(&d);

    int c_sel, h_opt;
    printf("\nSeleccione curso (numero): "); scanf("%d", &c_sel);
    c_sel--;

    printf("Horario (1 o 2): "); scanf("%d", &h_opt);
    int h_id = (h_opt == 1) ? d.cursos[c_sel].horario1 : d.cursos[c_sel].horario2;

    // Se acabó el error "undefined reference" si incluyes horarios.h y horarios.c
    ejecutarHorario(h_id); 
    
    // LLAMADA CLAVE: Pasa 3 argumentos exactamente
    registrarAsistencia(d.nombre, d.cursos[c_sel].nombre, c_sel);

    printf("\nSistema: Proceso completado.\n");
    return 0;
}

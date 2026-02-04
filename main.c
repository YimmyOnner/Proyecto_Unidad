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
    // Base de datos de ejemplo
    Usuario DB[3] = {
        {"docente1", "pass1", 101, "Juan Perez"},
        {"docente2", "pass2", 102, "Maria Garcia"},
        {"docente3", "pass3", 103, "Carlos Lopez"}
    };

    char u_in[20], p_in[20];
    int auth = -1;
    int intentos = 3; // Definimos el máximo de intentos

    printf("===== Sistema de Control de Asistencia por Curso =====\n");

    // CICLO DE LOGIN (Máximo 3 intentos)
    for (int intento_actual = 1; intento_actual <= intentos; intento_actual++) {
        printf("\n========== LOGIN (Intento %d de %d) =========\n", intento_actual, intentos);
        printf("Usuario: "); 
        scanf("%s", u_in);
        printf("Contrasena: "); 
        scanf("%s", p_in);

        // Verificamos en la base de datos
        for (int i = 0; i < 3; i++) {
            if (strcmp(u_in, DB[i].username) == 0 && strcmp(p_in, DB[i].password) == 0) {
                auth = i; 
                break;
            }
        }

        // Si auth ya no es -1, significa que el login fue exitoso
        if (auth != -1) {
            printf("\nLogin exitoso! Bienvenido(a) %s.\n", DB[auth].nombreReal);
            break; // Salimos del ciclo de intentos
        } else {
            printf("Usuario o contrasena incorrectos.");
            if (intento_actual < intentos) {
                printf(" Te quedan %d intentos.\n", intentos - intento_actual);
            }
        }
    }

    // Si después del ciclo auth sigue siendo -1, cerramos el programa
    if (auth == -1) {
        printf("\nHa superado el numero maximo de intentos. El sistema se cerrara.\n");
        return 1; 
    }

    Docente d;
    d.id = DB[auth].id;
    strcpy(d.nombre, DB[auth].nombreReal);
    d.numCursos = 0;

    // Carga solo los cursos del ID logueado (ej: 101)
    // Dependiendo del ID del Docente
    cargarCursosDesdeCSV(&d); 
    mostrarCursosDocente(&d);

    int c_sel, h_opt;

    // VALIDACIÓN PARA CURSOS
    do {
        printf("\nSeleccione curso (1 a %d): ", d.numCursos);
        scanf("%d", &c_sel);
        if (c_sel < 1 || c_sel > d.numCursos) {
            printf("[!] Error: El numero %d no es valido. Intente de nuevo.\n", c_sel);
        }
    } while (c_sel < 1 || c_sel > d.numCursos);
    c_sel--; // Ajuste para el índice del arreglo

    // VALIDACIÓN PARA HORARIOS (Solo 1 o 2)
    do {
        printf("Horario (1 o 2): ");
        scanf("%d", &h_opt);
        if (h_opt != 1 && h_opt != 2) {
            printf("[!] Error: Seleccion invalida. Debe ser 1 o 2 (Ingreso: %d).\n", h_opt);
        }
    } while (h_opt != 1 && h_opt != 2);

    // Asignación de h_id basada en la opción válida
    int h_id = (h_opt == 1) ? d.cursos[c_sel].horario1 : d.cursos[c_sel].horario2;

    // Se acabó el error "undefined reference" si incluyes horarios.h y horarios.c
    ejecutarHorario(h_id); 
    
    // LLAMADA CLAVE: Pasa 3 argumentos exactamente
    registrarAsistencia(d.nombre, d.cursos[c_sel].nombre, c_sel);

    printf("\nSistema: Proceso completado.\n");
    return 0;
}

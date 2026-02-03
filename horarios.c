#include <stdio.h>
#include "horarios.h"

/* ========= FUNCION PARA SELECCIONAR OPCIONES ========= */
int seleccionarOpcion(char titulo[], char opciones[][20], int total) {
    int opcion, i;
    do {
        printf("\n%s\n", titulo);
        for (i = 0; i < total; i++) {
            printf("%d. %s\n", i + 1, opciones[i]);
        }
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        if (opcion < 1 || opcion > total) {
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion < 1 || opcion > total);

    return opcion - 1;
}

/* ========= FUNCION BASE PARA GENERAR HORARIO ========= */
// Nota: Esta función imprime la selección en pantalla.
void generarHorario(char horas[][20], int totalHoras) {
    char meses[5][20] = {"Enero","Febrero","Marzo","Abril","Mayo"};
    char dias[5][20]  = {"Lunes","Martes","Miercoles","Jueves","Viernes"};

    int mes  = seleccionarOpcion("Seleccione Mes:", meses, 5);
    int dia  = seleccionarOpcion("Seleccione Dia:", dias, 5);
    int hora = seleccionarOpcion("Seleccione Rango Horario:", horas, totalHoras);

    printf("\n------------------------------------------\n");
    printf("HORARIO REGISTRADO:\n");
    printf("Fecha: %s, %s\n", meses[mes], dias[dia]);
    printf("Hora:  %s\n", horas[hora]);
    printf("------------------------------------------\n");
}

/* ========= FUNCIONES DE HORARIOS ESPECIFICOS ========= */

void horario1() {
    char horas[2][20] = {"07:30 - 09:00","09:00 - 10:30"};
    generarHorario(horas, 2);
}

void horario2() {
    char horas[2][20] = {"10:30 - 12:00","12:00 - 13:00"};
    generarHorario(horas, 2);
}

void horario3() {
    char horas[3][20] = {"07:30 - 08:30","08:30 - 09:30","09:30 - 10:30"};
    generarHorario(horas, 3);
}

void horario4() {
    char horas[2][20] = {"08:00 - 10:00","11:00 - 13:00"};
    generarHorario(horas, 2);
}

void horario5() {
    char horas[3][20] = {"07:30 - 09:30","09:30 - 11:30","11:30 - 13:00"};
    generarHorario(horas, 3);
}

void horario6() {
    char horas[2][20] = {"08:30 - 10:00","10:00 - 11:30"};
    generarHorario(horas, 2);
}

/* ========= FUNCION DE ENLACE PARA EL MAIN ========= */
// Esta es la función que te faltaba y causaba el error de compilación
void ejecutarHorario(int h_id) {
    switch (h_id) {
        case 1: horario1(); break;
        case 2: horario2(); break;
        case 3: horario3(); break;
        case 4: horario4(); break;
        case 5: horario5(); break;
        case 6: horario6(); break;
        default: 
            printf("\n[Error] ID de horario (%d) no reconocido.\n", h_id); 
            break;
    }
}

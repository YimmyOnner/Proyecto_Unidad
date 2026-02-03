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
    } while (opcion < 1 || opcion > total);

    return opcion - 1;
}

/* ========= FUNCION BASE PARA GENERAR HORARIO ========= */
void generarHorario(char horas[][20], int totalHoras) {
    char meses[5][20] = {"Enero","Febrero","Marzo","Abril","Mayo"};
    char dias[5][20]  = {"Lunes","Martes","Miercoles","Jueves","Viernes"};

    int mes  = seleccionarOpcion("Mes:", meses, 5);
    int dia  = seleccionarOpcion("Dia:", dias, 5);
    int hora = seleccionarOpcion("Hora:", horas, totalHoras);

    printf("\nHORARIO SELECCIONADO:\n");
    printf("%s - %s - %s\n", meses[mes], dias[dia], horas[hora]);
}

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

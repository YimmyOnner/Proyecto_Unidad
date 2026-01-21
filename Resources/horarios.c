#include <stdio.h>
#include <string.h>

int main() {
    int opcionMes, opcionDia, opcionHora;
    char mes[15], dia[15], hora[20];

    /* Selección del mes */
    printf("=== SELECCION DE HORARIO ===\n\n");
    printf("Mes:\n");
    printf("1. Enero\n");
    printf("2. Febrero\n");
    printf("3. Marzo\n");
    printf("Seleccione el mes: ");
    scanf("%d", &opcionMes);

    if (opcionMes == 1)
        strcpy(mes, "Enero");
    else if (opcionMes == 2)
        strcpy(mes, "Febrero");
    else if (opcionMes == 3)
        strcpy(mes, "Marzo");
    else
        strcpy(mes, "Mes no valido");

    /* Selección del día */
    printf("\nDia:\n");
    printf("1. Lunes\n");
    printf("2. Martes\n");
    printf("3. Miercoles\n");
    printf("4. Jueves\n");
    printf("5. Viernes\n");
    printf("Seleccione el dia: ");
    scanf("%d", &opcionDia);

    if (opcionDia == 1)
        strcpy(dia, "Lunes");
    else if (opcionDia == 2)
        strcpy(dia, "Martes");
    else if (opcionDia == 3)
        strcpy(dia, "Miercoles");
    else if (opcionDia == 4)
        strcpy(dia, "Jueves");
    else if (opcionDia == 5)
        strcpy(dia, "Viernes");
    else
        strcpy(dia, "Dia no valido");

    /* Selección de la hora */
    printf("\nHora:\n");
    printf("1. 07:00 - 09:00\n");
    printf("2. 09:00 - 11:00\n");
    printf("3. 11:00 - 13:00\n");
    printf("4. 14:00 - 16:00\n");
    printf("Seleccione la hora: ");
    scanf("%d", &opcionHora);

    if (opcionHora == 1)
        strcpy(hora, "07:00 - 09:00");
    else if (opcionHora == 2)
        strcpy(hora, "09:00 - 11:00");
    else if (opcionHora == 3)
        strcpy(hora, "11:00 - 13:00");
    else if (opcionHora == 4)
        strcpy(hora, "14:00 - 16:00");
    else
        strcpy(hora, "Hora no valida");

    /* Mostrar horario completo */
    printf("\nHorario seleccionado:\n");
    printf("%s - %s - %s\n", mes, dia, hora);
}

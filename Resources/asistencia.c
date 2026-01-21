#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char nombres[50][50];
    char asistencia[50];

    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEstudiante %d\n", i + 1);

        printf("Nombre: ");
        scanf("%s", nombres[i]);

        printf("Asistencia (P = Presente, A = Ausente): ");
        scanf(" %c", &asistencia[i]);
    }

    printf("\n--- LISTA DE ASISTENCIA ---\n");
    for (i = 0; i < n; i++) {
        printf("%s - ", nombres[i]);

        if (asistencia[i] == 'P' || asistencia[i] == 'p') {
            printf("Presente\n");
        } else {
            printf("Ausente\n");
        }
    }

    return 0;
}

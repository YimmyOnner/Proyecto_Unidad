#include <stdio.h>

int main() {
    // Arreglo con 10 nombres de estudiantes
    char estudiantes[10][30] = {
        "Ana Perez",
        "Juan Lopez",
        "Maria Gomez",
        "Carlos Ruiz",
        "Sofia Torres",
        "Luis Andrade",
        "Paola Molina",
        "Diego Castro",
        "Elena Rivas",
        "Miguel Herrera"
    };

    // Mostrar los nombres
    for (int i = 0; i < 10; i++) {
        printf("Estudiante %d: %s\n", i + 1, estudiantes[i]);
    }

    return 0;
}

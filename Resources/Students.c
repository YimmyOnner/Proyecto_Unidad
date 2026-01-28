#include <stdio.h>

int main() {
    // Definir 3 grupos de estudiantes, cada uno con 10 estudiantes
    char estudiantes[3][10][30] = {
        {  
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
        },
        {  
            "Jimmy",
            "Onner",
            "Elvis",
            "Hernan",
            "Torres",
            "Soto",
            "Medina",
            "Reyes",
            "Flores",
            "Guzman"
        },
        {  
            "Coronel",
            "Lopez",
            "Sebastian",
            "Mendoza",
            "Suarez",
            "Messi",
            "Adrian",
            "Vega",
            "Leonardo",
            "Aguirre"
        }
    };

    // muestra los nombres de todos los grupos
    for (int grupo = 0; grupo < 3; grupo++) {
        printf("\n--- Grupo %d ---\n", grupo + 1);
        for (int i = 0; i < 10; i++) {
            printf("Estudiante %d: %s\n", i + 1, estudiantes[grupo][i]);
        }
    }

    return 0;
}

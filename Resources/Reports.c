#include <stdio.h>
#include <string.h>


struct Report{
    char curso[100];
    char hora[100];
    int asistencia;
    int total_clases;

};
void generarReportes(struct Report reports[], int cantidad);

int main(){

   struct Report reports[4] = {
    {"Matematicas Discretas","08h00 - 13h00",20,28},
    {"Programacion", "10h30 - 13h30", 20, 26},
    {"Comunicacion", "09h30 - 11h30", 20, 29},/* data */
    {"Algebra Lineal", "08h30 - 13h30", 20, 25}
   };

   generarReportes(reports, 4);
   
}

void generarReportes(struct Report reports[], int cantidad){
    FILE * nomb;
    float porcentaje= 123;


    nomb= fopen("Documento.csv", "w");
    if (nomb == NULL) {
        printf("Error al crear el archivo\n");
        return;
    }

    fprintf(nomb,"==== REPORTE DE ASISTENCIA ===== \n\n");

    for(int i=0; i < cantidad; i++){
    fprintf(nomb, "");

    porcentaje = (reports[i].asistencia * 100.0) / reports[i].total_clases;

    fprintf(nomb,"Curso: %s\n", reports[i].curso);
    fprintf(nomb,"Horario %s\n", reports[i].hora);
    fprintf(nomb,"Asistencia %i\n", reports[i].asistencia);
    fprintf(nomb,"Total de Clases %i\n", reports[i].total_clases);
    fprintf(nomb,"Porcentaje de Asistencia %f%%\n", porcentaje);
    fprintf(nomb,"============================================\n");
    
    }
    fclose(nomb);

    printf("\n Informcacion Introducida en el 'Documento.csv', revisar porfavor \n");

}

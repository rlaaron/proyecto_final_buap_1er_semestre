#include <stdio.h>
#include <stdlib.h>





int main() {

    system("color FD");
    int opt;
    char temp[10];
    char producto[100];


    do
    {
        printf("MENU DE OPCIONES: \n");
        printf("1.-Ingresar productos: \n");
        printf("2.-Borrar lista: \n");
        printf("3.-Leer productos: \n");
        printf("4.- SALIR\n");
        printf("INGRESE OPCION DESEADA: \n");
        fgets(temp,10, stdin);
        opt= atoi(temp);
        switch (opt)
        {
            case 1: 
                {
                    
                    FILE * flujo = fopen("datos.txt", "a");
                    if (flujo == NULL) {
                        perror ("Error en la creacion del archivo\n\n");
                    } else {
                        printf("INGRESE EL PRODUCTO: ");
                        scanf("%s", &producto);
                        fprintf(flujo, "%s",producto);
                        fputc('\n', flujo);
                        fflush(flujo);
                        fclose(flujo);
                    }
                    
                    printf("Articulo agregado con exito!!!! \n\n\n");
                    
                    
                    break;
                }
            case 2: 
                {
                    
                    FILE * flujo = fopen("datos.txt", "w");
                    if (flujo == NULL) {
                        perror ("Error en la creacion del archivo\n\n");
                    } else {
                        
                        fputs("LISTA DE SUPER: ", flujo);
                        fputc('\n', flujo);
                        fflush(flujo);
                        fclose(flujo);
                    }
                    printf("LISTA BORRADA CON EXITO!!!! \n\n\n");
                    
                    
                    break;
                }
            case 3:
                {

                    FILE * flujo = fopen("datos.txt", "rb");

                    char caracter;
                    printf("EL CONTENIDO DE SU LISTA ES: \n");
                    while (feof(flujo) == 0) {
                        caracter = fgetc(flujo);
                        printf("%c", caracter);
                    }

                    fclose(flujo);
                    printf("LECTURA EXISTOSA!!\n\n\n ");

                    system("pause");
                    break;
                }
            case 4:
                {

                    break;
                }
            
        }
    } while (opt != 4);


    
    printf("se termino el programa\n");

    system("pause");
    return 0;
}
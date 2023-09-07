#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

struct datos{
    int cedula;
    char nombre[20];
    char apellido[20];
    int edad;
    char profesion[20];
    char lugar[20];
    char direccion[20];
    char telefono[20];

};

void inicializarAlumnos(struct datos *Alumnos, int *lugares, int cantAlumnos){
    int i;

    for (i=0;i<cantAlumnos;i++){
        Alumnos[i].cedula = 0;
        strcpy(Alumnos[i].nombre, "-");
        strcpy(Alumnos[i].apellido, "-");
        Alumnos[i].edad = 0;
        strcpy(Alumnos[i].profesion, "-");
        strcpy(Alumnos[i].lugar, "-");
        strcpy(Alumnos[i].direccion, "-");
        strcpy(Alumnos[i].telefono, "-");

        lugares[i] = 0;
    }

    for (i=0;i<cantAlumnos;i++){
        printf("Alumno %i:\n",i+1);
        printf("Cédula: %i\n",Alumnos[i].cedula);
        printf("Nombre: %s\n",Alumnos[i].nombre);
        printf("Apellido: %s\n",Alumnos[i].apellido);
        printf("Edad: %i\n",Alumnos[i].edad);
        printf("Profesión: %s\n",Alumnos[i].profesion);
        printf("Lugar de Nacimiento: %s\n",Alumnos[i].lugar);
        printf("Dirección: %s\n",Alumnos[i].direccion);
        printf("Telefono: %s\n",Alumnos[i].telefono);
        puts("--------------------------");
    }
}

/////VERIFICA QUE LA CEDULA SEA DE 3 DIGITOS
int validarCedula(int cedula) {
    // Verificar si el código tiene exactamente cinco dígitos
    if (cedula >= 100 && cedula <= 999) {
        return 1; // Código válido
    } else {
        return 0; // Código no válido
    }
}

/////VERIFICA QUE LA CEDULA SEA ÚNICA E IRREPETIBLE
int verificarCedulaUnica(struct datos *Alumnos, int cantAlumnos, int cedula) {
    for (int i = 0; i < cantAlumnos; i++) {
        if (Alumnos[i].cedula == cedula) {
            return 0;  // Cédula repetida, no es única
        }
    }
    return 1;  // Cédula única
}

void cargarAlumnos(struct datos *Alumnos,int *lugares, int cantAlumnos){
    int i,j,op,vacio;
    vacio = 0;
    j = 1;

    puts("///////////////////////////");
    puts("////Lugares disponibles////");
    puts("///////////////////////////");

    for (i=0;i<cantAlumnos;i++){

        if(lugares[i]==0){
            printf("%d. Lugar Disponible\n",i+1);

            j = j + 1;
            vacio = vacio + 1;
        }else if(lugares[i]==1){
            printf("%d. Lugar Ocupado\n",i+1);
            j = j + 1;
        }
    }
        printf("%i. Salir\n",j);

    if (vacio == 0){
        system("cls");
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!");
        puts("No hay lugares disponibles");
        puts("intente borrar algun alumno");
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!");
        system("pause");
        return 0;
    }else{
        puts("-----------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opcion no valida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Opcion: ");
            scanf("%d",&op);
        }

        if (op == j){
            return 0;
        }else{
            for(i=0;0<cantAlumnos;i++){
                if((op-1)==i){
                    if(lugares[i]==1){
                        system("cls");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("El lugar %d está ocupado por %s\n",i+1,Alumnos[i].nombre);
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("--------------------------------------");
                        system("pause");
                        return 0;
                    }else if(lugares[i]==0){
                        int cedula;
                        system("cls");
                        printf("Ingrese la cedula: ");
                        scanf("%i", &cedula);
                        fflush(stdin);
                        while(validarCedula(cedula)==0){
                            system("cls");
                            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            puts("Cedula invalida (debe tener 3 digitos)");
                            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            system("pause");
                            system("cls");
                            printf("Ingrese la cedula: ");
                            scanf("%i", &cedula);
                            fflush(stdin);
                        }
                        while(verificarCedulaUnica(Alumnos, cantAlumnos, cedula) == 0) {
                            system("cls");
                            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            puts("Esa cedula ya está ocupada, ingrese otra...");
                            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            system("pause");
                            system("cls");
                            printf("Ingrese la cedula: ");
                            scanf("%i", &cedula);
                            fflush(stdin);
                        }
                        Alumnos[i].cedula = cedula;

                        fflush(stdin);
                        printf("Ingrese el nombre del alumno: ");
                        gets(Alumnos[i].nombre);
                        fflush(stdin);
                        printf("Ingrese el apellido del alumno: ");
                        gets(Alumnos[i].apellido);
                        printf("Ingrese la edad del alumno: ");
                        scanf("%i",&Alumnos[i].edad);
                        while (Alumnos[i].edad>100 || Alumnos[i].edad<0){
                            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            puts("Edad invalida, intente otro...");
                            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                            printf("Ingrese la edad del alumno: ");
                            scanf("%i",&Alumnos[i].edad);
                        }
                        fflush(stdin);
                        printf("Ingrese la profesión del alumno: ");
                        gets(Alumnos[i].profesion);
                        fflush(stdin);
                        printf("Ingrese el lugar de nacimiento: ");
                        gets(Alumnos[i].lugar);
                        fflush(stdin);
                        printf("Ingrese la dirección: ");
                        gets(Alumnos[i].direccion);
                        fflush(stdin);
                        printf("Ingrese el telefono: ");
                        gets(Alumnos[i].telefono);
                        puts("--------------------------");

                        lugares[i] = 1;

                        return 0;
                        }
                    }
            }
        }
    }
}

void borrarAlumnos(struct datos *Alumnos, int *lugares, int cantAlumnos){
    int i,j,op;

    j = 1;

    puts("///////////////////////////");
    puts("////Alumnos Registrados////");
    puts("///////////////////////////");
    puts("\n¿Qué alumno desea eliminar?\n");
    puts("Alumnos disponibles: ");
    for (i=0;i<cantAlumnos;i++){
        if(lugares[i]==1){
            printf("%d. %s %s\n",i+1,Alumnos[i].nombre,Alumnos[i].apellido);
            j = j + 1;
        }else if(lugares[i]==0){
            printf("%d. Lugar Disponible\n",i+1);
            j = j + 1;
        }
    }
    printf("%i. Salir \n",j);
    puts("-----------------");
    printf("Elegir opción: ");
    scanf("%d",&op);

    while (op>j || op<1){
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        puts("Opción invalida, intente de nuevo...");
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        printf("Elegir opción: ");
        scanf("%d",&op);
    }

    if(op == j){
        return 0;
    }else{
        for(i=0;i<cantAlumnos;i++){
        if((op-1)==i){
            if(lugares[i]==0){
                system("cls");
                puts("Este lugar ya estaba vacio");
                puts("--------------------------");
            }else if(lugares[i]==1){
                Alumnos[i].cedula = 0;
                strcpy(Alumnos[i].nombre, "-");
                strcpy(Alumnos[i].apellido, "-");
                Alumnos[i].edad = 0;
                strcpy(Alumnos[i].profesion, "-");
                strcpy(Alumnos[i].lugar, "-");
                strcpy(Alumnos[i].direccion, "-");
                strcpy(Alumnos[i].telefono, "-");

                lugares[i] = 0;

                system("cls");
                puts("¡Alumno eliminado con éxito!");
                }
            }
        }
    }
}

void mostrarAlumnos(struct datos *Alumnos, int *lugares, int cantAlumnos){
    int i,j,op;

    j = 1;

    puts("//////////////////////////");
    puts("////Alumno Registrados////");
    puts("/////////////////////////");
    puts("\n¿Qué alumno desea mostrar?\n");
    puts("Alumnos disponibles: ");

    for (i=0;i<cantAlumnos;i++){
        if(lugares[i]==1){
            printf("%d. %s %s\n",i+1,Alumnos[i].nombre,Alumnos[i].apellido);
            j = j + 1;
        }else if(lugares[i]==0){
            printf("%d. Lugar Disponible\n",i+1);
            j = j + 1;
        }
    }
    printf("%i. Salir \n",j);
    puts("-----------------");
    printf("Elegir opción: ");
    scanf("%d",&op);

    while (op>j || op<1){
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        puts("Opción invalida, intente de nuevo...");
        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        printf("Elegir opción: ");
        scanf("%d",&op);
    }

    if(op == j){
        puts("--------------------------------");
        system("pause");
        return 0;
    }else{
        for(i=0;i<cantAlumnos;i++){
            if((op-1)==i){
                if(lugares[i]==0){
                    system("cls");
                    puts("Vacio, no hay nada para mostrar...");
                    puts("----------------------------------");
                    system("pause");
                }else if(lugares[i]==1){
                    system("cls");
                    printf("Alumno N° %i\n",i+1);
                    printf("Cédula: %i\n",Alumnos[i].cedula);
                    printf("Nombre: %s %s\n",Alumnos[i].nombre,Alumnos[i].apellido);
                    printf("Edad: %i\n",Alumnos[i].edad);
                    printf("Profesión: %s\n",Alumnos[i].profesion);
                    printf("Lugar de Nacimiento: %s\n",Alumnos[i].lugar);
                    printf("Dirección: %s\n",Alumnos[i].direccion);
                    printf("Telefono: %s\n",Alumnos[i].telefono);
                    puts("-------------------------------------");
                    system("pause");
                }
            }
        }
    }
}

int main()
{
    int op,iniciar,bandera,cantAlumnos;

    struct datos *Alumnos;
    int *lugares;

    setlocale(LC_ALL, "");
    srand(time(NULL));


    do{
        system("cls");
        puts("////////////////////////");
        puts("////Registro Alumnos////");
        puts("////////////////////////");
        puts("Menú: ");
        puts("1. Iniciar/Limpiar registros");
        puts("2. Agregar alumno");
        puts("3. Eliminar alumno");
        puts("4. Mostrar registro");
        puts("5. Salir");
        puts("-----------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while (op>5 || op<1){
                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                puts("Opcion no valida, intente de nuevo...");
                puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                printf("Opcion: ");
                scanf("%d",&op);
        }

        switch(op){
            case 1:
                system("cls");
                puts("Iniciando los registros, espere...");
                sleep(2);
                system("cls");
                puts("//////////////////////////////////");
                puts("¿Cuántos alumnos tiene inscriptos?");
                printf("Ingrese el dato: ");
                scanf("%d",&cantAlumnos);
                Alumnos = (struct datos *)malloc(cantAlumnos * sizeof(struct datos));
                lugares = (int *)malloc(cantAlumnos * sizeof(int));
                puts("//////////////////////////////////");
                system("pause");
                inicializarAlumnos(Alumnos,lugares,cantAlumnos);
                system("cls");
                puts("¡Registros limpios!");
                sleep(2);
                puts("-------------------");
                system("pause");
                system("cls");
                puts("Volviendo al menú...");
                sleep(2);
                iniciar = 1;
                break;
            case 2:
                system("cls");
                    if (iniciar != 1){
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("Debe inicializar los registros...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("----------------------------------");
                        system("pause");
                    }else{
                        cargarAlumnos(Alumnos,lugares,cantAlumnos);
                        system("cls");
                    }
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                break;
            case 3:
                system("cls");
                    if(iniciar != 1){
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("Debe inicializar los registros...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("----------------------------------");
                        system("pause");
                    }else{
                        borrarAlumnos(Alumnos,lugares,cantAlumnos);
                    }
                system("cls");
                puts("Volviendo al menú...");
                sleep(2);
                break;
            case 4:
                system("cls");
                    if (iniciar != 1){
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("Debe inicializar los registros...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("----------------------------------");
                        system("pause");
                    }else{
                        mostrarAlumnos(Alumnos,lugares,cantAlumnos);
                    }
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                break;
            case 5:
                return 0;
                break;
        }
    }while(bandera!=1);

    return 0;
}

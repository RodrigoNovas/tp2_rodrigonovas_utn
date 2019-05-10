#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define EXIT 5
#define CHARSIZE 50

#include "EMPLEADO.H"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int id = 0, sector, menu, order, idToFind, index, returnNum,
            quantityOfEmployees = 0,
            isEmployeeSuccesful;
    float salary;
    char name[CHARSIZE];
    char lastname[CHARSIZE];
    eEmployee employee[SIZE];

    do {
        printf("--------------------------- Menu ---------------------------\n");
        printf("| 1 - ALTA de empleado                                     |\n");
        printf("|                                                          |\n");
        printf("| 2 - MODIFICAR empleado                                   |\n");
        printf("|                                                          |\n");
        printf("| 3 - BAJA de empleado                                     |\n");
        printf("|                                                          |\n");
        printf("| 4 - INFORMAR empleado/s                                  |\n");
        printf("|                                                          |\n");
        printf("| 5 - SALIR                                                |\n");
        printf("------------------------------------------------------------\n");
        fflush(stdin);
        scanf("%d", &menu);
        if (!isValidMenu(menu, 1, 5)) {
            printf("El numero ingresado no es valido.\n");
            menu = 0;
        }
        switch (menu) {
            case 1:
                if (quantityOfEmployees == 0)
                    initEmployees(employee, SIZE);
                if (getFreeSpace(employee, SIZE) != -1)
                    id++;
                printf("------------------------------------------------------------\n");
                getStringLettersOnly(name, "Ingrese el nombre:\n", CHARSIZE, 3);
                printf("------------------------------------------------------------\n");
                getStringLettersOnly(lastname, "Ingrese el apellido:\n", CHARSIZE, 3);

                printf("------------------------------------------------------------\n");
                getEntero(&sector, "Ingrese el sector:\n", "ERROR: Solo numeros entre 1 y 300\n",
                          1, 300, 3);
                printf("------------------------------------------------------------\n");
                getFloat(&salary, "Ingrese el salario:\n", "ERROR: Un salario no puede ser negativo.\n",
                         1, pow(2, 1024), 3);
                isEmployeeSuccesful = addEmployee(employee, SIZE, id, name, lastname, salary, sector);
                if (isEmployeeSuccesful == 0) {
                    quantityOfEmployees++;
                }
                break;
            case 2:
                if (quantityOfEmployees > 0) {
                    getEntero(&idToFind, "Ingrese el ID del empleado que desea modificar\n",
                              "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                              0, SIZE, 3);
                    index = findEmployeeById(employee, SIZE, idToFind);

                    if (index != -1 && idToFind != -1) {
                        printf("------------------------------------------------------------\n");
                        getStringLettersOnly(name, "Ingrese el nombre:\n", CHARSIZE, 3);
                        printf("------------------------------------------------------------\n");
                        getStringLettersOnly(lastname, "Ingrese el apellido:\n", CHARSIZE, 3);

                        printf("------------------------------------------------------------\n");
                        getEntero(&sector, "Ingrese el sector:\n", "ERROR: Solo numeros entre 0 y 300\n",
                                  1, 300, 3);
                        printf("------------------------------------------------------------\n");
                        getFloat(&salary, "Ingrese el salario:\n", "ERROR: Un salario no puede ser negativo.\n",
                                 1, pow(2, 1024), 3);
                        modifyEmployee(employee, SIZE, idToFind, name, lastname, salary, sector);
                    }
                }
                break;
            case 3:
                if (quantityOfEmployees > 0) {
                    idToFind = getEntero(&idToFind, "Ingrese el ID del empleado que desea eliminar\n",
                                         "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                                         0, SIZE, 3);
                    isEmployeeSuccesful = removeEmployee(employee, SIZE, id);
                    if (isEmployeeSuccesful == 0) {
                        quantityOfEmployees--;
                        id--;
                    }


                }
                break;
            case 4:
                if (quantityOfEmployees > 0) {
                    do {
                        system("cls");
                        fflush(stdin);
                        printf("--------------------------- Menu --------------------------------------------------\n");
                        printf("| 1 - Empleados/s ordenados alfabeticamente p/apellido                            |\n");
                        printf("|                                                                                 |\n");
                        printf("| 2 - Empleados/s Total, promedio de salarios y empleados que superan el promedio |\n");
                        printf("-----------------------------------------------------------------------------------\n");
                        scanf("%d", &menu);
                        if (!isValidMenu(menu, 1, 2)) {
                            printf("El numero ingresado no es valido.\n");
                            menu = 0;
                        }


                    } while (menu != 1 && menu != 2);
                    switch (menu) {
                        case 1:
                            fflush(stdin);
                            returnNum = getEntero(&order,
                                                  "Ingrese el orden de ordenamiento 1 para ascendente y 0 para descendente:  \n",
                                                  "ERROR: Solo numeros entre 0 y 1(inclusive) estan perimitidos.\n",
                                                  0, 1, 3);
                            if (returnNum != -1) {
                                toUpperLastNameAndName(employee, SIZE);
                                sortBySectorLastNameAndName(employee, SIZE, order);
                                printEmployees(employee, SIZE);
                            }
                            break;
                        case 2:
                            printf("----------------------------------------------------------------------------------\n");
                            printf("| Total de empleados: %d\n", quantityOfEmployees);
                            printf("| Total de salarios: %.2lf\n", getAllSalaries(employee, SIZE));
                            printf("| Promedio de salarios de todos los empleados: %d\n", getAverageSalaries(employee, SIZE));
                            printf("| Empleados que superna la media salarial: %d\n", employeesAboveAverage(employee, SIZE));
                            printf("----------------------------------------------------------------------------------\n");
                            break;
                    }


                }
                break;
        }

    } while (menu != EXIT);
    return 0;

}

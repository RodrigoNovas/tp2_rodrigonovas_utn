#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "EMPLEADO.H"

static int getI(int *pBuffer) {

    return scanf("%d", pBuffer);

}

static char getC(char *pBuffer) {
    fflush(stdin);

    return scanf("%c", pBuffer);


}

static float getF(float *pBuffer) {

    return scanf("%f", pBuffer);

}

//CAMBIAR NOMBRE A MAYUS
void PASARMAYUS(eEmployee employee[], int len) {
    int i;
    int j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(employee[i].lastName); ++j) {
            employee[i].lastName[j] = toupper(employee[i].lastName[j]);
        }
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(employee[i].name); ++j) {
            employee[i].name[j] = toupper(employee[i].name[j]);
        }
    }
}

//CONSEGUIR ENTERO
int getEntero(int *pInt, char msg[], char msgError[], int min, int max, int retries) {
    int returnNum = -1;
    int bufferInt = 0;
    if (pInt != NULL && msg != NULL && msgError != NULL && min <= max && retries >= 0) {
        do {
            retries--;
            printf("%s", msg);
            fflush(stdin);
            if (getI(&bufferInt) && bufferInt >= min && bufferInt <= max) {
                *pInt = bufferInt;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (retries > 0);

    }
    return returnNum;


}

//CONSEGUIR FLOTANTE
int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int retries) {
    int returnNum = -1;
    float bufferFloat = 0;
    if (pFloat != NULL && msg != NULL && msgError != NULL && min <= max && retries >= 0) {
        do {
            retries--;
            printf("%s", msg);
            fflush(stdin);
            if (getF(&bufferFloat) && bufferFloat >= min && bufferFloat <= max) {

                *pFloat = bufferFloat;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (retries > 0);

    }
    return returnNum;


}


//ES LETRA
int isLetter(char c[]) {
    int i = 0;
    if (c[0] == ' ' || c[0] == '\r')
        return 0;
    while (c[i] != '\0') {
        if (!(c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z') && c[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}

//CONSEGUIR STRING

void getString(char input[], char msg[]) {
    fflush(stdin);
    printf("%s", msg);
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = 0;
}

//VONSEGUIR STRING
int getStringLettersOnly(char *input, char *msg, int len, int retries) {
    char aux[len];
    do {
        getString(aux, msg);
        if (isLetter(aux)) {
            strcpy(input, aux);
            return 1;
        } else {
            retries--;
            printf("Error nombre deben ser solo letras y no puede estar vacio!.\n");
        }

    } while (retries >= 0);
    return 0;
}



int getFreeSpace(eEmployee employee[], int len) {

    int i;
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 1) {
            return i;
        }
    }
    printf("No hay espacio en el array para agregar mas empleados.\n");
    return -1;

}

//INICIAR EMPLEADO

int initEmployees(eEmployee *employee, int len) {
    int i;
    for (i = 0; i < len; i++) {
        employee[i].isEmpty = 1;
    }
    return -1;

}

//AÑADIR EMPLEADOS

int addEmployee(eEmployee *employee, int len, int id, char name[], char lastName[], float salary, int sector) {
    int i;
    i = getFreeSpace(employee, len);
    if (i != -1) {
        employee[i].isEmpty = 0;
        employee[i].id = id;
        strcpy(employee[i].name, name);
        strcpy(employee[i].lastName, lastName);
        employee[i].salary = salary;
        employee[i].sector = sector;
        return 0;
    }
    return -1;
}


//ENCONTRAR EMPLEADOS

int findEmployeeById(eEmployee employee[], int len, int id) {
    int i;
    for (i = 0; i < len; i++) {
        if (id == employee[i].id) {
            return i;

        }
    }
    printf("No hay empleados con el ID:%d en el array.\n", id);
    return -1;
}

//VALIDAR MENU

int isValidMenu(int menu, int min, int max) {
    if (menu >= min && menu <= max) {
        return 1;
    } else
        return 0;
}

//IMPRIMIR EMPLEADO

void printEmployees(eEmployee employee[], int len) {
    int i;
    system("cls");
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 0) {
            printf("------------------------------------------------------------\n");
            printf("| ID        |    %d\n", employee[i].id);
            printf("| Nombre    |    %s\n", employee[i].name);
            printf("| Apellido  |    %s\n", employee[i].lastName);
            printf("| Salario   |    %f\n", employee[i].salary);
            printf("| Sector    |    %d\n", employee[i].sector);
            printf("------------------------------------------------------------\n");
        }
    }


}

//ORDENAR POR SECTOR Y NOMBRE

void sortBySectorLastNameAndName(eEmployee *employee, int len, int order) {
    int i;
    int j;
    eEmployee auxEmployee;

    if (order == 1) {
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (employee[i].sector > employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) > 0 &&
                    employee[i].sector == employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0 &&
                           employee[i].sector == employee[j].sector) {
                    if (strcmp(employee[i].name, employee[j].name) > 0) {
                        auxEmployee = employee[i];
                        employee[i] = employee[j];
                        employee[j] = auxEmployee;
                    }

                }

            }

        }
    }
    if (order == 0) {
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (employee[i].sector < employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) < 0 &&
                    employee[i].sector == employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0 &&
                           employee[i].sector == employee[j].sector) {
                    if (strcmp(employee[i].name, employee[j].name) < 0) {
                        auxEmployee = employee[i];
                        employee[i] = employee[j];
                        employee[j] = auxEmployee;
                    }

                }

            }

        }
    }


}


//REMOVER EMPLEADOS

int removeEmployee(eEmployee *employee, int len, int id) {
    char tempChar;
    int i, returnNum = -1;
    printf("Esta seguro que desea eliminar el registro (Y/N): \n");
    getC(&tempChar);
    tempChar = toupper(tempChar);
    if (tempChar == 'Y') {
        for (i = 0; i < len; i++) {
            if (id == employee[i].id) {
                employee[i].isEmpty = 1;
                returnNum = 0;
                return returnNum;
            }
            returnNum = -1;
        }
        if (returnNum != 0) {
            printf("Registro no encontrado");
            returnNum = 0;
            return returnNum;
        }
    } else {
        system("cls");
        printf("Operacion cancelada-\n");
        return returnNum;
    }

}


//INFORME

int getAverageSalaries(eEmployee *employee, int len) {
    int i, averageSalaries = 0, rangeOfNotEmptyEmployees = 0;
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 0) {
            averageSalaries += employee[i].salary;
            rangeOfNotEmptyEmployees++;
        }
    }
    return averageSalaries / rangeOfNotEmptyEmployees;
}

//AVERAGE EMPLEADO

int employeesAboveAverage(eEmployee *employee, int len) {
    int getAverageSalary = getAverageSalaries(employee, len);
    int i, employessAboveAverage = 0;
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 0 && employee[i].salary > getAverageSalary) {
            employessAboveAverage++;

        }
    }
    return employessAboveAverage;


}


//MODIFICAR EMPLEADOS

int modifyEmployee(eEmployee *employee, int len, int id, char name[], char lastName[], float salary, int sector) {
    int i;
    for (i = 0; i < len; ++i) {
        if (employee[i].id == id && employee[i].isEmpty == 0) {
            employee[i].isEmpty = 0;
            employee[i].id = id;
            strcpy(employee[i].name, name);
            strcpy(employee[i].lastName, lastName);
            employee[i].salary = salary;
            employee[i].sector = sector;
            printf("Operacion realizada con exito ID %d fue modificado.\n", employee[i].id);
            return 0;
        }
    }
    printf("Operacion cancelada, no se pudo modificar al empleado.\n");
    return -1;
}

//CONSEGUIR TODOS LOS SALARIOS

float getAllSalaries(eEmployee *employee, int len) {
    float salaries = 0;
    int i;
    for (i = 0; i < len; ++i) {
        if (employee[i].isEmpty == 0)
            salaries += employee[i].salary;

    }
    return salaries;
}

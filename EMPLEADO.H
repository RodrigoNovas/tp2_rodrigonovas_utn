#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct {
    int id;
    char name[25];
    char lastName[15];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;
/**
 * Gets int
 * @param pInt *pInt pointer to int variable.
 * @param msg msg* Pointer to array of chars
 * @param msgError msgError* Pointer to array of chars
 * @param min int minimum of number to enter
 * @param max int maximum of number to enter
 * @param retries int amount of retries user has
 * @return int returns (-1) if Error [Not between min and max or not number] - (0) if OK
 *
 */
int getEntero(int *,char [], char [], int ,int, int);
/**
 * Gets float
 * @param pFloat *pFloat pointer to float variable
 * @param msg *msg pointer to array of chars
 * @param msgError *msgError pointer to array of chars
 * @param min int minimum of number to enter
 * @param max int maximum of number to enter
 * @param retries int amount of retries user has
 * @return float returns (-1) if Error [Not between min and max or not number] - (0) if OK
 */
int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int retries);
static int getI(int* );
static float getF(float *);
static char getC(char *);
int getChar(char *, char msg[], char msgError[], char minChar, char maxChar, int reintentos);

/**
 * Checks if it is a letter(includes space)
 * @param c c* Pointer to array of chars
 * @return int return 1 if its a letter or 0 if it is there a space or enter in the first element or if it is not a letter
 */
int isLetter(char c[]);
/**
 * String getter
 * @param mensaje *msg pointer to array of chars
 * @param input *input pointer to array of chars
 */
void getString(char input[], char msg[]);
/**
 * String getter for letters(includes space) only
 * @param input *input pointer to array of chars
 * @param msg *msg pointer to array of chars
 * @param len int size of array
 * @param retries int amount of times user can retry entry
 * @return int returns 1 if it is all letters(includes space) or 0 if not
 */
int getStringLettersOnly(char *input, char *msg, int len, int retries);
/**
 * Gets free space within the array
 * @param employee *eEmployee pointer to an array of structs of type eEmployee
 * @param len int size of array
 * @return int index of first free space in array, 0 if there is no freespace
 */
int getFreeSpace(eEmployee[],int);
/**
 * Initializes the array of structs of employees, settings isEmpty variable to 1
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int returns -1 if array was successfully initialize
 */
int initEmployees(eEmployee *, int);
/**
 * Checks if the menu was valid
 * @param menu int menu number
 * @param min int minimum number included
 * @param max int maximum number included
 * @return int returns 1 if the menu is valid 0 otherwise
 */
int isValidMenu(int menu,int min, int max);
/**
 * Adds an employee to the first free space of the array
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of employee
 * @param sector int sector of employee
 * @return int returns 0 if employee was successfully added, returns -1 otherwise
 */
int addEmployee(eEmployee[], int len, int id, char name[],char lastName[],float salary,int sector);
/**
 * Prints employees
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 */
void printEmployees(eEmployee *, int);
/**
 * Sorts employees first by sector then by last name and finally by name
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param order int 1 for ascending order 0 for descending order
 */
void sortBySectorLastNameAndName(eEmployee *employee, int len, int order);
/**
 * Finds employee by it's id
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee
 * @return returns index to position of the array where id is, returns -1 if there was no employee with that id
 */
int findEmployeeById(eEmployee employee[],int len, int id);
/**
 * Removes employee by id ask for char input Y or y for deletion otherwise operation is cancelled
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee to delete
 * @return int returns 0 if registry was deleted -1 if Error[registry not found or operation cancelled]
 */
int removeEmployee(eEmployee* employee, int len,int id);
/**
 * Gets average salaries of employees
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int average of all salaries in array of employees
 */
int getAverageSalaries(eEmployee *employee, int len);
/**
 * Gets the employees that are above average salary
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int returns employees that are above average salary
 */
int employeesAboveAverage(eEmployee* employee,int len);
/**
 * Turns to upper every single letter of name and last name.
 * @param employee eEmployee* Pointer to array of employees
 * @param len int size of array
 */
void PASARMAYUS(eEmployee employee[], int len);
/**
 * Modifies employee selected by the id
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of employee
 * @param sector int sector of employee
 * @return returns 0 if employee was deleted -1 if operation was cancelled
 */
int modifyEmployee(eEmployee[],int len, int id, char name[],char lastName[],float salary,int sector);
/**
 * Gets total of all salaries
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int total of salaries
 */
float getAllSalaries(eEmployee[],int len);



#endif // EMPLEADO_H_INCLUDED

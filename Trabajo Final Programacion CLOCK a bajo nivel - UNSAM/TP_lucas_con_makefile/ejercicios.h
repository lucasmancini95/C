

//MACROS para accion del CLOCK:
#define PUERTO_BASE 0x70 /* RTC */
#define CANTIDAD_REGISTROS_1 14
#define CANTIDAD_REGISTROS_RTC 10

//MACROS por items:
//item 3
#define CARACTER_PULSO "*"
#define CARACTER_DELAY "__"
#define MASCARA_FRECUENCIA_SQW 0x0F //se ingresa en hexa (el valor se va a usar de mascar con el registro A) segun tabla del datasheet --> 1111 => 2Hz
//item 4
#define PUERTO_IMPRESORA 0x378
#define PUERTO_PARALELO_CONTROL 0x379
#define DELAY_STROBE 1

// FUNCIONES:
void ejercicio_1();
void ejercicio_2();
void ejercicio_3();
void ejercicio_4();

void imprime_bcd(unsigned char reg); //impime el dato pasado como un bcd - es estatica
void imprime_bcd_dinamico(unsigned char reg);
int cantidad_de_unos(unsigned char reg);
void alarma_determinada_teclado();
void alarma_cada_minuto();

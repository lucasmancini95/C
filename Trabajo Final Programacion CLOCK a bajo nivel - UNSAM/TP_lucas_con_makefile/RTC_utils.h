
#define PUERTO_BASE 0x70

// FUNCIONES:
void perm(unsigned long base, unsigned long cantidad, int permiso); // Esta funcion otorga/quita (segun <permiso> sea 1/0) privilegios a <cantidad> de puertos a partir del puerto <base>
unsigned char in (unsigned char reg); //Esta funcion lee un byte del registro del RTC cuyo nro se recibe
void out (unsigned char valor, unsigned char reg); // Esta funcion escribe el byte recibido al registro del RTC cuyo nro se recibe
void check_uip_state(); // Checkear el estado del UIP, si está en 1 (actualizando los registros anteriores) espera 1984μs, si esta en 0 hay al menos 244μs para trabajar

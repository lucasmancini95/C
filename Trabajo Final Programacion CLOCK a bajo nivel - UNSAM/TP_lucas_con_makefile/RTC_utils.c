
#include "unistd.h"
#include "sys/io.h"
#include "sys/perm.h"
#include "stdio.h"
#include "stdlib.h"
#include "RTC_utils.h"

/* Esta funcion otorga/quita (segun <permiso> sea 1/0) privilegios a <cantidad> de puertos a partir del puerto <base> */
void perm(unsigned long base, unsigned long cantidad, int permiso){
  if (ioperm(base, cantidad, permiso) != 0) {
    perror("ioperm");
    exit(1);
  }
}

/* Esta funcion lee un byte del registro del RTC cuyo nro se recibe */
unsigned char in (unsigned char reg){
  outb (reg, PUERTO_BASE);
  return inb(PUERTO_BASE + 1);
}

/* Esta funcion escribe el byte recibido al registro del RTC cuyo nro se recibe */
void out (unsigned char valor, unsigned char reg){
  outb (reg, PUERTO_BASE);
  outb (valor, PUERTO_BASE + 1);
}

// Checkear el estado del UIP, si está en 1 (actualizando los registros anteriores) espera 1984μs, si esta en 0 hay al menos 244μs para trabajar
void check_uip_state(){
  unsigned char a;
  a = in (0x0A); // se revisa el registro 10 para ver si se es esta por pasar de 59--> 00 en algun registro
  if((a & 0x80) != 0)  //0x80 --> 10000000
  usleep(1984);
}

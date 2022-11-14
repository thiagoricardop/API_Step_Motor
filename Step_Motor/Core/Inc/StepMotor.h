/**
   API para motor de passo
   14/11/2022 Universidade Federal de Minas Gerais
 * original authors:  Arthur Araújo Comarelli Salles e Thiago Ricardo Oliveira Pinto
   ----------------------------------------------------------------------
    Programa feito para controle de um  motor de passo do tipo 28BYJ-48.
    Necessário, também, o ci Uln2003 para garantir o funcionamento do motor.

    Esta API foi desenvolvida como trabalho da disciplina de Programação de
    Sistemas Embarcados da UFMG – Prof. Ricardo de Oliveira Duarte –
    Departamento de Engenharia Eletrônica”
   ----------------------------------------------------------------------
 */

#include "stm32f4xx_hal.h"
#include <stdint.h>

void stepper_set_rpm (int rpm);  // Set rpm--> max 13, min 1,,,  went to 14 rev/min

void stepper_half_drive (int step); //Define 1 sequence for half-drive

void stepper_any_angle (float angle, int direction, int rpm); //Motor works for any angle

void stepper_90_clock (int rpm); //motor works for 90 deegrees clockwise

void stepper_90_anticlock (int rpm); //motor works for 90 deegrees anticlockwise

void stepper_clock (int rpm); //motor works for 360 deegrees clockwise

void stepper_anticlock (int rpm); //motor works for 360 deegrees anticlockwise

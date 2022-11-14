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


#include "StepMotor.h"

#define stepsperrev 4096


void stepper_set_rpm (int rpm)  // Set rpm--> max 13, min 1,,,  went to 14 rev/min
{
	HAL_Delay(60000*2/stepsperrev/rpm);
}

void stepper_half_drive (int step)
{
	switch (step){
		case 0:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 1:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 2:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 3:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 4:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);   // IN4
			  break;

		case 5:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // IN4
			  break;

		case 6:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // IN4
			  break;

		case 7:
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);   // IN1
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);   // IN2
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);   // IN3
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // IN4
			  break;

		}
}

void stepper_any_angle (float angle, int direction, int rpm) //0 = clockwise 1 = anti-clockwise
{
	float anglepersequence = 0.703125;  // 360 = 512 sequences
	int numberofsequences = (int) (angle/anglepersequence);

	for (int seq=0; seq<numberofsequences; seq++)
	{
		if (direction == 0)  // for clockwise
		{
			for (int step=7; step>=0; step--)
			{
				stepper_half_drive(step);
				stepper_set_rpm(rpm);
			}

		}

		else if (direction == 1)  // for anti-clockwise
		{
			for (int step=0; step<8; step++)
			{
				stepper_half_drive(step);
				stepper_set_rpm(rpm);
			}
		}
	}
}

void stepper_90_clock (int rpm){
	int numberofsequences = 128;

	for (int seq=0; seq<numberofsequences; seq++)
	{
			for (int step=7; step>=0; step--) //clockwise
			{
				stepper_half_drive(step);
				stepper_set_rpm(rpm);
			}

		}
}

void stepper_90_anticlock (int rpm){
		int numberofsequences = 128;

		for (int seq=0; seq<numberofsequences; seq++)
		{
			for (int step=0; step<8; step++) //anti-clockwise
			{
				stepper_half_drive(step);
				stepper_set_rpm(rpm);
			}
		}
}

void stepper_clock (int rpm){
	int numberofsequences = 512;

	for (int seq=0; seq<numberofsequences; seq++)
	{
			for (int step=7; step>=0; step--) //clockwise
			{
				stepper_half_drive(step);
				stepper_set_rpm(rpm);
			}

		}
}

void stepper_anticlock (int rpm){
		int numberofsequences = 512;

		for (int seq=0; seq<numberofsequences; seq++)
		{
			for (int step=0; step<8; step++) //anti-clockwise
			{
				stepper_half_drive(step);
				stepper_set_rpm(rpm);
			}
		}
}

# API para controle de Step Motor
Este projeto foi desenvolvido como atividade avaliativa da disciplina de Programação de Sistemas Embarcados da UFMG – Prof. Ricardo de Oliveira Duarte – Departamento de Engenharia Eletrônica.
# Descrição
O projeto consiste na implementação de funções para a funcionalidade e controle de um Step Motor, a partir da utilização de um STM32F41xx. Foram implementadas funções para diversas situações de uso do motor.
# Requistos para implementação do projeto
* Microcontrolador STM32F41xx;
* 28BYJ-48 motor de passo 5V ou similar (unipolar 4 derivações);
* Driver ULN2003 IC ou similar;
* Fonte de alimentação externa de 5V.
# Funções desenvolvidas para a API
**stepper_set_rpm :**  
Define o rpm utilizado para o motor de passo  
  
**stepper_half_drive :**  
Um motor de passo divide a rotação completa em número de etapas iguais. Motores de passo geralmente vêm com um IC ULN2003. Este IC é usado para acionar o motor porque os pinos do microcontrolador são incapazes de fornecer corrente suficiente para acionar esses motores. Existem três tipos diferentes de modos de passo usados para motores de passo, Wave Drive, Full Drive e Half Drive. Baseamos este projeto no método Half Drive, nele, as fases são energizadas alternadamente. Este modo é usado para aumentar a resolução angular do motor, mas o torque é reduzido. O motor leva 4096 PASSOS para completar 1 revolução, o que significa 2048/8 = 512 sequências por Revolução. A função stepper_half_drive implementa esse método.  
  
**stepper_any_angle :**  
Função dedicada a realizar um giro de uma angulação definida.  
  
**stepper_90_clock e stepper_90_anticlock :**  
Funções criadas para que o motor de passo realize 1/4 de volta, ou 90º. Uma função para cada sentido, horário e anti-horário.  
  
**stepper_clock e stepper_anticlock :**  
Funções criadas para que o motor de passo realize uma volta completa, ou 360º. Uma função para cada sentido, horário e anti-horário.  

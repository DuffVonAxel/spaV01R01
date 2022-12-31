# Algoritmo de Posição Solar - Solar Position Algorithm (SPA)

## Desenvolvido Originalmente por:
### Afshin Michael Andreas (afshin_andreas@nrel.gov)
---
## Baseado no:
### *NREL technical report "Solar Position Algorithm for Solar Radiation Application" by I. Reda & A. Andreas*
(https://midcdmz.nrel.gov/spa/)

---
## Nos laboratórios de:
### *Metrology Laboratory* 
### *Solar Radiation Research Laboratory*
### *National Renewable Energy Laboratory*
---
## Adaptado para ESP-32 por:
### Duff Von Axel
---
## Aplicação
Este algoritmo calcula os ângulos solares de zênite e azimute no período do ano -2000 a 6000, com incertezas de +/- 0,0003 graus com base na data, hora e localização na Terra. (Referência: Reda, I.; Andreas, A., Algoritmo de posição solar para aplicações de radiação solar, Energia solar. Vol. 76(5), 2004; pp. 577-589).

O APP atual serve de base e para verificação do funcionamento de todas as tabelas, sub-rotinas e funções de cálculos.

---
## Futuro
A próxima implementação será incorporado um módulo GPS para adquirir dados automáticos para as variáveis:

* Ano;
* Mês;
* Dia;
* Hora;
* Minuto;
* Segundo;
* Fuso horário;
* Latitude;
* Longitude;
* Elevação.

O passo seguinte requer um módulo para as variáveis:
* Pressão;
* Temperatura.

Será estudado como automatizar as variáveis:
* delta_ut1;
* delta_t;
* slope;
* azm_rotation;
* atmos_refract.


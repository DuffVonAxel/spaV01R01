#include <stdio.h>                                          // Acesso ao padrao do 'printf'.
#include "freertos/FreeRTOS.h"                              // Acesso aos termos.
#include "freertos/task.h"                                  // Acesso as prioridades da TASK.
#include "spa.c"                                            // Inclui biblioteca do algoritmo

static const char *TAG = "SPA";                             // Nome da Task.

void app_main(void)                                         // Aplicacao principal.
{
    spa_data spa;                                           // Declaracao da estrutura do SPA (struct).
    int result;                                             // Variavel para retorno do codigo de erro.
    float min, sec;                                         // Variavel para calculo.

    /* Entrada dos dados na estrutura para processar. */
    spa.year          = 2003;                               // Ano.
    spa.month         = 10;                                 // Mes.
    spa.day           = 17;                                 // Dia.
    spa.hour          = 12;                                 // Horas.
    spa.minute        = 30;                                 // Minutos.
    spa.second        = 30;                                 // Segundos.
    spa.timezone      = -7.0;                               // Fuso horario.
    spa.delta_ut1     = 0;                                  // Variacao...  (?)
    spa.delta_t       = 67;                                 // Variacao...  (?)
    spa.longitude     = -105.1786;                          // Logitude.
    spa.latitude      = 39.742476;                          // Latitude.
    spa.elevation     = 1830.14;                            // Elevacao.
    spa.pressure      = 820;                                // Pressao.
    spa.temperature   = 11;                                 // Temperatura.
    spa.slope         = 30;                                 // Rampa.       (?)
    spa.azm_rotation  = -10;                                // Rotacao do azimute.
    spa.atmos_refract = 0.5667;                             // Refracao atmosferica.
    spa.function      = SPA_ALL;                            // Funcao a ser executada.

    result = spa_calculate(&spa);                           // Chama a funcao.

    if (result == 0)                                        // Verifica a existencia de erro(s).
    {
        printf("Julian Day:    %.6f\n",spa.jd);
        printf("L:             %.6e degrees\n",spa.l);
        printf("B:             %.6e degrees\n",spa.b);
        printf("R:             %.6f AU\n",spa.r);
        printf("H:             %.6f degrees\n",spa.h);
        printf("Delta Psi:     %.6e degrees\n",spa.del_psi);
        printf("Delta Epsilon: %.6e degrees\n",spa.del_epsilon);
        printf("Epsilon:       %.6f degrees\n",spa.epsilon);
        printf("Zenith:        %.6f degrees\n",spa.zenith);
        printf("Azimuth:       %.6f degrees\n",spa.azimuth);
        printf("Incidence:     %.6f degrees\n",spa.incidence);

        min = 60.0*(spa.sunrise - (int)(spa.sunrise));
        sec = 60.0*(min - (int)min);
        printf("Sunrise:       %02d:%02d:%02d Local Time\n", (int)(spa.sunrise), (int)min, (int)sec);

        min = 60.0*(spa.sunset - (int)(spa.sunset));
        sec = 60.0*(min - (int)min);
        printf("Sunset:        %02d:%02d:%02d Local Time\n", (int)(spa.sunset), (int)min, (int)sec);

    } else printf("SPA Error Code: %d\n", result);

    while (1)
    {
        vTaskDelay(10);
    }
    
}

/* Resultado esperado:
Julian Day:    2452930.312847
L:             2.401826e+01 degrees
B:             -1.011219e-04 degrees
R:             0.996542 AU
H:             11.105902 degrees
Delta Psi:     -3.998404e-03 degrees
Delta Epsilon: 1.666568e-03 degrees
Epsilon:       23.440465 degrees
Zenith:        50.111622 degrees
Azimuth:       194.340241 degrees
Incidence:     25.187000 degrees
Sunrise:       06:12:43 Local Time
Sunset:        17:20:19 Local Time
*/
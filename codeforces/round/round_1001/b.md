Lo primero es que para que no se detenga ningun reloj, debemos ir por todos e ir actualizando, si o si. Da igual por donde empecemos debemos ir en ciclo para poder volver a cada uno e ir actualizando, entonces para cualquier reloj nos hace falta recorrer los n relojes para volver a actualizar el tiempo de dicho reloj.
Entonces hay dos opciones en cada reloj para volver hacia el, ir por la derecha e ir por la izquierda, si va por la derecha le toma (n - i - 1) * 2 volver ahi. Y si va por la izquierda le toma i*2 volver. 

Finalmente probamos si todos los relojes le da tiempo de volver, en caso haya al menos uno que no le de tiempo, la respuesta es no directamente.

Caso contrario la respuesta es si.
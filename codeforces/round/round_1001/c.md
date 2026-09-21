Primera idea es fuerza bruta con recursividad en ambos casos al invertir o no invertir, e ir poniendo la maxima suma del array en todo momento, pero las operaciones son simetricas
1° operacion:
a2-a1; a3-a2; .... ; an - an-1; cuya suma es an - a1
2° operacion:
invertir array:
an, an-1, .... a1
an-1 - an; an-2- an-1... ; a1 - a2; entonces la suma es exactamente a1-an

por lo tanto al actualizar el maximo simplemente verificamos el maximo si es sum o -*sum 
entonces ya no se recorre ambas opciones, haciendo un arbol binario hasta que quede un elemnto, sino que al final sale en O(n) ya que solo tomamos una opcion, y va disminuyendo la cantidad de elementos hasta que sea 1
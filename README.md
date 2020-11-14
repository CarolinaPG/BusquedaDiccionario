# BusquedaDiccionario

## ¿Qué hace?
Agregar palabras en un diccionario y guardar una lista de palabras 
para buscarlas dentro del diccionario.

### ¿Qué muestra? 
Muestra el estado de la palabra, es decir, si la palabra de la lista 
se encuentra en el diccionario se tiene que el estado de la palabra es 
"ESTA" y se guardan las posiciones de la palabra en el arreglo donde se
guardó la lista a buscar.

En el caso que la palabra no se encuentre en el diccionario el estado 
es "NOESTA" y la posición en la lista se retorna con signo negativo.

##Restricciones:
* Una palabra a buscar puede ser escrita máximo 3 veces.
* Es sensible a mayúsculas y minúsculas.

### Bugs:
* En el diccionario no se deberían poder repetir palabras
* No debería ser sensible a las mayúsculas (no se ha probado con tíldes)
* Sería bueno que el diccionario se guarde en un documento y cargue la lista
  al inicio dándole la opción al usuario si quiere agregar palabras al 
  diccionario o no (sería más cercano a la realidad) 

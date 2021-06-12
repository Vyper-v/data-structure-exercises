
# Ejercicios para implementar estructuras de datos

## Doubly Linked List
Implemente una representacion de un reproductor de musica con listas doblemente enlazadas que muestre por pantalla 
  - Canción actual
  - Opción para ir a la canción anterior
  - Opción para ir a la canción siguiente
   
Use esta estructura como referencia:
```cpp
struct song
{
  std::string songName;
  std::string authorName;
};
```
interfaz de usuario de referencia:

```
Presione 'a' para cancion anterior
Presione 'b' para cancion siguiente

    <<  previus   next >> 

Actual Song:    Bottom Feeders
Author:         Drexciya
```
#include <iostream>
#include "album.hpp"
#include "List/Double/DoublyLinked.hpp"
using namespace std;

/* Implemente una representacion de un reproductor de musica con listas doblemente enlazadas
   que muestre por pantalla 
    - la cancion actual
    - una opción para ir a la canción anterior
    - una opción para ir a la canción siguiente
   
  Use esta estructura como referencia:
    struct song
    {
      std::string songName;
      std::string authorName;
    };
 */

int main(int argc, char const *argv[])
{
  ListADT<song> *music_player = new DoublyLinked<song>;
  int actual = 0;
  char option;
  song NeptunesLair[21];
  NeptunesLair[0] = song("Intro: Temple of Dos De Agua", "Drexciya");
  NeptunesLair[1] = song("Species of the Pod", "Drexciya");
  NeptunesLair[2] = song("Andreaen Sand Dunes", "Drexciya");
  NeptunesLair[3] = song("Running out of Space", "Drexciya");
  NeptunesLair[4] = song("Habitat of Negative", "Drexciya");
  NeptunesLair[5] = song("Universal Element", "Drexciya");
  NeptunesLair[6] = song("Drifting into a Time of No Future", "Drexciya");
  NeptunesLair[7] = song("Polynomo Plexusgel", "Drexciya");
  NeptunesLair[8] = song("Surface Terrestial Colonization", "Drexciya");
  NeptunesLair[9] = song("Funk Release Valve", "Drexciya");
  NeptunesLair[10] = song("Organic Hydropoly Spores", "Drexciya");
  NeptunesLair[11] = song("Draining of the Tanks", "Drexciya");
  NeptunesLair[12] = song("Devil Ray Cove", "Drexciya");
  NeptunesLair[13] = song("Fusion Flats", "Drexciya");
  NeptunesLair[14] = song("Triangular Hydrogen Strain", "Drexciya");
  NeptunesLair[15] = song("Oxyplasmic Gyration Beam", "Drexciya");
  NeptunesLair[16] = song("Quanttum Hydrodynamics", "Drexciya");
  NeptunesLair[17] = song("Lost Vessel", "Drexciya");
  NeptunesLair[18] = song("Bottom Feeders", "Drexciya");
  NeptunesLair[19] = song("Jazzy Fluids", "Drexciya");
  NeptunesLair[20] = song("C to he Power of X+C to the power of X=unknown", "Drexciya");

  for (int i = 0; i < 21; i++)
  {
    music_player->addToTail(NeptunesLair[i]);
  }
  do
  {
    cout << "Presione 'a' para cancion anterior" << endl;
    cout << "Presione 'b' para cancion siguiente" << endl;
    cout << "    <<  previus"
         << "   next >>" << endl;
    cout << "Actual Song:    " << music_player->get(actual).songName << endl;
    cout << "Author:         " << music_player->get(actual).authorName << endl;
    cin >> option;
    option = tolower(option);
    switch (option)
    {
    case 'a':
      actual--;
      break;
    case 'd':
      actual++;
      break;
    default:
      cout << "Presione 'a' para cancion anterior" << endl;
      cout << "Presione 'b' para cancion siguiente" << endl;
      break;
    }
  } while (actual >= 0 && actual < music_player->size() && option == 'a' && option == 'd');

  return 0;
}

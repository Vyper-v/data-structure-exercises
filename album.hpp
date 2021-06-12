#include <string>
#ifndef ALBUM_HPP
#define ALBUM_HPP
struct song
{
  std::string songName;
  std::string authorName;

  song(){
    this->authorName = "";
    this->songName = "";
  }
  song(std::string songName,std::string authorName)
  {
    this->authorName = authorName;
    this->songName = songName;
  }

  bool operator==(song &a1)
  {
    return this->authorName == a1.authorName && this->songName == a1.songName;
  }
   bool operator==(song *a1)
  {
    return this->authorName == a1->authorName && this->songName == a1->songName;
  }
};
#endif // !ALBUM_HPP

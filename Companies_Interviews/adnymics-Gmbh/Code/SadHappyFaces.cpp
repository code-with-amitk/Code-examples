//Sad Face      :(
//Happy Face    :)

//std headers
#include <iostream>
#include <vector>
#include <array>

class Solution {
public:
  std::array<uint64_t, 2> SadHappyFaces (std::string strInput) {

    uint64_t u64Sad = 0, u64Happy = 0;
    std::array<uint64_t, 2> rgSadHappy;

    for (auto& ch:strInput) {
      if (ch == ':' and *(&ch+1) == ')')
        ++u64Happy;
      if (ch == ':' and *(&ch+1) == '(')
        ++u64Sad;
    }

    rgSadHappy[0] = u64Happy;
    rgSadHappy[1] = u64Sad;
    return rgSadHappy;
  }
};

int main() {
  std::string strInput = ":())):::(:(:):)(:(:)";    //3,4   Happy,Sad
  //std::string strInput = ":):(";    //1,1
  //std::string strInput = "";        //0,0
  //std::string strInput = ":::::::::::))))))))<<<<>>:))";  //2,0
  Solution oSolution;
  std::array<uint64_t, 2> rgSadHappy;
  rgSadHappy = oSolution.SadHappyFaces (strInput);
  std::cout << "Happy Faces : " << rgSadHappy[0] << std::endl;
  std::cout << "Sad Faces : " << rgSadHappy[1] << std::endl;
  return 0;
}

/*
$ g++ SadHappyFaces.cpp -Wall
$ ./a.out
Happy Faces : 3
Sad Faces : 4
*/

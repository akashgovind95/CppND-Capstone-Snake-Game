#include <iostream>
#include <fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"


int Game::counter=0;
int main() {
  int usrInput = 0;
  while(1){
    std::cout<<"----MENU----"<<std::endl;
    std::cout<<"1. Play"<<std::endl;
    std::cout<<"2. View High Score"<<std::endl;
    std::cout<<"3. Exit"<<std::endl;
    std::cout<<"Awaiting input....";
    std::cin>>usrInput;
    if(usrInput ==1){
      constexpr std::size_t kFramesPerSecond{60};
      constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
      constexpr std::size_t kScreenWidth{640};
      constexpr std::size_t kScreenHeight{640};
      constexpr std::size_t kGridWidth{32};
      constexpr std::size_t kGridHeight{32};

      Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
      Controller controller;
      Game game(kGridWidth, kGridHeight);
      game.Run(controller, renderer, kMsPerFrame);
      std::cout << "Game has terminated successfully!\n";
      std::cout << "Score: " << game.GetScore() << "\n";
      std::cout << "Size: " << game.GetSize() << "\n";
    }
    else if (usrInput==2) {

      std::ifstream input("hs.txt");
      std::string tempScore="";
      int highScore = 0 ;
      input>>tempScore;
      if(tempScore!="")
        highScore = std::stoi(tempScore);
      std::cout << "High Score: " << highScore << "\n";

    }
    else if (usrInput==3){
      std::cout<<"Exiting..."<<std::endl;
      return 0;
    }
    else
      std::cout<<"Please enter a valid option"<<std::endl;

    std::cout<<"\n\n";
  }
  

  return 0;
}
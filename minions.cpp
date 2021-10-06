#include <iostream>
using namespace std;
#include <thread>
#include <vector>

void printMinion(int x){
std::cout << "Hello! I am minion " << x << " " << std::endl;
std::cout << "\n" << std::endl;

}

void printOverlord(){
cout<<"Hello Minions! I am the Overlord!";
}


int main (int argc, char** argv) {
 /*if (argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" <nbminions>\n";
    return -1;
  }*/

int runAmount = 0;

if (argv[1] == NULL){
  cout << "No arguement passed running base case ";
  cout << "\n";
  runAmount = 40;

}
else{
 runAmount = atoi(argv[1]);
}

  std::vector<std::thread> mythreads;

  for (int i=1; i<=runAmount; ++i){
    std::thread mythread (printMinion, i);

    mythreads.push_back(std::move(mythread));

  }

for (auto & t : mythreads){
if (t.joinable())
  t.join();
else
  std::cout<<"t is not joinable\n";

}

std::thread LastThread(printOverlord);
LastThread.join();

  return 0;
}

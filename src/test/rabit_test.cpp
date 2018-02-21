#include<rabit.h>

using namespace rabit;
const int N  = 3;
int main(int argc, char *argv[]) {
  int a[N];
  rabit::Init(argc, argv);
  for (int i = 0; i < N; ++i) {
    a[i] = rabit::GetRank() + i;
  }
  printf("@node[%d] before-allreduce: a={%d, %d, %d}\n",
         rabit::GetRank(), a[0], a[1], a[2]);
  // allreduce take max of each elements in all processes
  Allreduce<op::Max>(&a[0], N);
  printf("@node[%d] after-allreduce-max: a={%d, %d, %d}\n",
         rabit::GetRank(), a[0], a[1], a[2]);
  // second allreduce that sums everything up
  Allreduce<op::Sum>(&a[0], N);
  printf("@node[%d] after-allreduce-sum: a={%d, %d, %d}\n",
         rabit::GetRank(), a[0], a[1], a[2]);


  std::string s;
  if (rabit::GetRank() == 0) s = "hello world";
    printf("@node[%d] before-broadcast: s=\"%s\"\n",
      	               rabit::GetRank(), s.c_str());
  // broadcast s from node 0 to all other nodes
  rabit::Broadcast(&s, 0);
  printf("@node[%d] after-broadcast: s=\"%s\"\n",
  		rabit::GetRank(), s.c_str());

  printf("@node[%d] after-allreduce-sum: a={%d, %d, %d}\n",
         rabit::GetRank(), a[0], a[1], a[2]);

  rabit::Finalize();

  return 0;
}


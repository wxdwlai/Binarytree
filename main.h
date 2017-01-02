#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<int> s;
    double e = 3.14;
    BinaryTree<double> st(e);
    s.Show();
    st.Show();
  cout<<s.IsEmpty()<<endl;
  cout<<st.IsEmpty()<<endl;
    return 0;
}

#include<iostream>
#include <algorithm>
using namespace std;
#include<vector>
vector < vector < int >*>*vec;
const int size = 5 ;
char undirectedGraph[size][size];
vector<vector<int> > sortvector;
vector < vector < int >*>*getGreedySet(vector < vector < int >*>*_vec, int n)
{
    cout<<(char)(65 + n)<<endl;
    vector < vector < int >*>::iterator it1;
    vector < int >::iterator it2;
    bool linkext = false;
    for (it1 = _vec->begin(); it1 != _vec->end(); it1++)  //外集合
    {
        vector < int >*temp1 = *it1;
        int link = 0;
        for (it2 = temp1->begin(); it2 != temp1->end(); it2++)
        {
            if (undirectedGraph[n][*it2] == '1')
            {
                link++;
                break;
            }
// cout<<"("<<*it2<<","<<n<<")";
        }
        if (link == 0)
        {
            temp1->push_back(n);
            linkext = true;
            break;

        }


    }

    if (!linkext)
    {
        vector < int >*nodeset = new vector < int >();
        nodeset->push_back(n);

        _vec->push_back(nodeset);

    }
    return _vec;
};
int charToInt(char cr)
{
    if(cr=='1')
        return 1;
    else
        return 0;
}

int getDegreeOfNode(int i)
{
    int result=0;
    for(int j=i+1; j<sortvector.size(); j++)
    {

        int x=sortvector[i][1];
        int y=sortvector[j][1];

        result+=charToInt(undirectedGraph[x][y]);
    }

    for(int m=0; m<i; m++)
    {
        int x=sortvector[m][1];
        int y=sortvector[i][1];

        result+=charToInt(undirectedGraph[x][y]);
    }

    return result;
}

int getinitDegreeOfNode(int i)
{
    int result=0;
    for(int j=i+1; j<size; j++)
    {
        result+=charToInt(undirectedGraph[i][j]);

    }
    for(int m=0; m<i; m++)
    {
        result+=charToInt(undirectedGraph[m][i]);
    }

    return result;
}
bool greaterMark(vector<int> a,vector<int> b)
{
    return a[0]> b[0];
}

int main()
{
    vec = new vector < vector < int >*>();

    vector < int >*nodeset = new vector < int >();
    vector < vector < int >*>::iterator it1;
    vector < int >::iterator it2;
    cout <<
         "请输入无向图顶点连接情况：\n(1表示连通，0表示未连通)"
         << endl;
    cout << " >";
    for (int i = 0; i < size; i++) cout << (char)(65 + i);
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << (char)(65 + i) << ">";
        cin >> undirectedGraph[i];

    }


    for (int i = 0; i < size; i++)
    {
        vector<int> temp;
        temp.push_back(getinitDegreeOfNode(i));
        temp.push_back(i);

        sortvector.push_back(temp);
    }
    while(sortvector.size()>0)
    {
        std::sort(sortvector.begin(),sortvector.end(),greaterMark);//对无向图进行按照度大小排序

        vec = getGreedySet(vec, sortvector[0][1]);
        sortvector.erase(sortvector.begin());
        int i=sortvector.size();
        for(int j=0; j<i; j++)
        {
            sortvector[j][0]=getDegreeOfNode(j);
        }
    }

    cout << "\n个数最少且元素间不相连的子集有:" << endl;
    for (it1 = vec->begin(); it1 != vec->end(); it1++)
    {
        vector < int >*temp1 = *it1;

        for (it2 = temp1->begin(); it2 != temp1->end(); it2++)
        {
            cout << (char)(65 + *it2);
        }
        cout << "  ";
    }
}



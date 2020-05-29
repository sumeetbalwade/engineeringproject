#include<iostream>
#include<limits.h>
#define MAX 10

using namespace std;

class spanning_tree
{
private:
    int graph[MAX][MAX],stree[MAX][MAX];
    int no_of_vertex;
public:
    spanning_tree(/* args */) 
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                graph[i][j]=stree[i][j]=0;
            }
            
        }
        
    }
    
    void prism_algorithm();
};

void spanning_tree::prism_algorithm()
{
    int cost[MAX][MAX];
    int diatance[no_of_vertex],visited[no_of_vertex],from[no_of_vertex];
    int min_distance,i,j; 
    int n=no_of_vertex-1;

    for ( i = 0; i < no_of_vertex; i++)
    {
        for ( j = 0; j < no_of_vertex; j++)
        {
            if(graph[i][j]==0)
            {
                cost[i][j]=INT_MAX;
            }
            else
            {
                cost[i][j]=a[i][j];
            }
            
        }
        
    }

    visited[0]=1;
    distance[0]=0;
    from[0]=0;

    for ( i = 0; i < no_of_vertex; i++)
    {
        visited[i]=0;
        distance[i]=cost[0][i];
        from[i]=0;

    }

    while (n>0)
    {
        min_distance=INT_MAX;
        for ( i = 0; i < no_of_vertex; i++)
        {
            if (visited[i]==0 && min > distance[i])
            {
                min_distance=diatance[i];
                v=i;
            }

        }

        
        
    }
    
    

    

    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

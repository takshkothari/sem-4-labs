#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int a[100];
    int top;
} stack;

typedef struct {
    int n;
    int **adjL;
} graph;

void push(stack *s, int x){
    (s->a)[++(s->top)] = x;
}

void insert(int *list, int x){
    int i = 0;
    while(list[i] != -1)
        i++;
    list[i] = x;
    list[i+1] = -1;
}

graph create(int n){
    graph g;
    g.n = n;
    int i, x, j;
    g.adjL = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++){
        g.adjL[i] = (int *)malloc(n * sizeof(int));
        g.adjL[i][0] = -1;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i != j){
                printf("edge from %d to %d? ", i, j);
                scanf("%d", &x);
                if(x == 1)
                    insert(g.adjL[i], j);
            }
        }
    }
    return g;
}

void dfs(graph g, int *v, stack *s, int in){
    v[in] = 1;
    int *list = g.adjL[in];
    int i = 0;
    while(list[i] != -1){
        if(v[list[i]] == 0)
            dfs(g, v, s, in + 1);
        i++;
    }
    push(s, in);
}

int check(int a[], int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x)
            return 1;
    }
    return 0;
}

void srcRem(graph *g, int *rem, int *in){
    int i, j, min = 100;
    int *list;
    int *deg = (int*)calloc(g->n, sizeof(int));
    for(i = 0; i < g -> n; i++){
        j = 0;
        list = g->adjL[i];
        if (!check(rem,*in,i)) {
            while (list[j] != -1) {
                if (!check(rem,*in,list[j]))
                    deg[list[j]]++;
                j++;
            }    
        }
        else
            deg[i] = -1;
    }
    for (i = 0; i < g -> n; i++) {
        if (deg[i] < min && deg[i] != -1) {
            min = deg[i];
            j = i;
        }
    }
    rem[*in] = j;
    *in = *in + 1;
    printf("%d ", j);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

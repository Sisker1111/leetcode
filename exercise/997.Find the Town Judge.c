 
struct graph {
  int in_degree;
  int out_degree;
  int number;
  struct graph *link[80]; 
  // struct graph **link; 
};

struct graph *createNode(int n) {
  struct graph *node = (struct graph *)malloc(sizeof(struct graph));
  node->in_degree = 0;
  node->out_degree = 0;
  node->number = n;
  // node->link = (struct graph **)malloc(10 * sizeof(struct graph*));
  return node;
}
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    if( N == 1 )
        return 1;
    if( trustSize < 1 )
        return -1;
    struct graph **exist = (struct graph **)calloc(N+1,sizeof(struct graph*));
    for(int i=0; i<trustSize; i++){
        struct graph *node_0, *node_1;
        if( !exist[trust[i][0]]  ){
            node_0 = createNode(trust[i][0]);
            exist[trust[i][0]] = node_0;
        }
        else 
            node_0 = exist[trust[i][0]];
        if( !exist[trust[i][1]]  ){
            node_1 = createNode(trust[i][1]);
            exist[trust[i][1]] = node_1;
        }
        else 
            node_1 = exist[trust[i][1]];
        
        // if( node_0->out_degree )
        //     node_0->link = (struct graph **)realloc(node_0->link, ( node_0->out_degree+1 )*sizeof(struct graph*));
        node_0->link[(node_0->out_degree)++] = node_1;
        node_1->in_degree += 1;
    }
    
   for(int i=1; i<=N; i++){
       if( exist[i] )
            if( exist[i]->in_degree == N-1 && exist[i]->out_degree == 0 )
                 return exist[i]->number;
   }
    return -1;

}
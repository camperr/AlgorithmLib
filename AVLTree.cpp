/*
 * Author:  nzh@UESTC
 */
#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;
struct Node{
    int w;
    Node *lChild,*rChild;
};
typedef Node *BiTree;
class BSTree{
    public:
        BSTree(){
            root=NULL;
        }
        bool InsertNode(BiTree bt,BiTree &r);
        bool InsertValue(BiTree r);
        void Delete(BiTree &r);
        BiTree DeleteNode(int w,BiTree &r);
        BiTree DeleteValue(int w);
        void Show(BiTree r);
        void Show();
    private:
        BiTree root;
};
bool BSTree::InsertValue(BiTree r){
    return InsertNode(r,root);
}
bool BSTree::InsertNode(BiTree bt,BiTree &r){
    if(!r){
        r=bt;
        return false;
    }else if(bt->w == r->w) return true;
    else if(bt->w < r->w) return InsertNode(bt,r->lChild);
    else return InsertNode(bt,r->rChild);
}
BiTree BSTree::DeleteNode(int w,BiTree &r){
    if(!r) return NULL;
    else if(w == r->w) Delete(r);
    else if(w < r->w) DeleteNode(w,r->lChild);
    else DeleteNode(w,r->rChild);
}
void BSTree::Delete(BiTree &r){
    BiTree t=r;
    if(!r->rChild){
        r=r->lChild;
    }else if(!r->lChild){
        r=r->rChild;
    }else{
        InsertNode(r->rChild,r->lChild);
        r=r->lChild;
    }
    delete t;
}
BiTree BSTree::DeleteValue(int w){
    return DeleteNode(w,root);
}
void BSTree::Show(BiTree r){
    if(!r) return;
    Show(r->lChild);
    printf("%d ",r->w);
    Show(r->rChild);
}
void BSTree::Show(){
    if(!root) printf("NULL\n");
    Show(root);
    puts("");
}
BSTree bs;
int main(){
    int n,i,j;
    int d,m;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&d);
        BiTree bt=new Node;
        bt->w=d;
        bt->lChild=NULL;
        bt->rChild=NULL;
        bs.InsertValue(bt);
    }
    scanf("%d",&m);
    bs.Show();
    for(i=0;i<m;i++){
        scanf("%d",&d);
        bs.DeleteValue(d);
        bs.Show();
    }
}

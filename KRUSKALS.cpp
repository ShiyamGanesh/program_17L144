#include<bits/stdc++.h> 
using namespace std; 
typedef pair<int,int>iPair; 
struct MinSpanTree{ 
    int vt,ed; 
    vector<pair<int,iPair> >edg; 
    MinSpanTree(int vt,int ed){ 
        this->vt=vt; 
        this->ed=ed; 
    } 
    void insertgph(int u,int v,int w){ 
        edg.push_back({w,{u,v}}); 
    } 
    int kruskal(); 
};
struct connected{ 
    int *p,*r; 
    int n,i; 
    connected(int n) {
        this->n=n;
        p=new int[n+1]; 
        r=new int[n+1]; 
        for(i=0;i<=n;i++){ 
            r[i]=0;
            p[i]=i; 
        } 
    }
    int find(int uv) {
        if(uv!=p[uv]) 
            p[uv]=find(p[uv]); 
        return p[uv]; 
    }
    void Union(int pq,int rs){ 
        pq=find(pq),rs=find(rs);
        if(r[pq]>r[rs]) 
            p[rs] = pq; 
        else
            p[pq]=rs; 
        if(r[pq]==r[rs]) 
            r[rs]++; 
    } 
};
int MinSpanTree::kruskal(){ 
    int m=0;
    sort(edg.begin(),edg.end());
    connected ds(vt);
    vector<pair<int,iPair> >::iterator it; 
    for (it=edg.begin();it!=edg.end();it++){ 
        int u=it->second.first; 
        int v=it->second.second; 
        int su=ds.find(u); 
        int sv=ds.find(v);
        if (su!=sv){
            cout<<u<<" - "<<v<<endl;
            m+=it->first;
            ds.Union(su,sv); 
        } 
    } 
    return m; 
}
int main(){
    int vt,ed,i,u,v,w;
    cout<<"ENTER THE SIZE OF VERTICES AND EDGE: ";
    cin>>vt>>ed;
    MinSpanTree g(vt,ed);
    for(i=0;i<ed;i++){
    	cin>>u>>v>>w;
    	g.insertgph(u,v,w); 
    }
    cout<<"EDGES OF MINIMUM SPANNING TREE:\n";
    cout<<"\nTOTAL COST= "<<g.kruskal(); 
    return 0; 
}

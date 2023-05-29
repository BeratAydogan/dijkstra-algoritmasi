#include <iostream>

using namespace std;

#define INF 999
int V,uni,zamanlar[100][100];
int sure[100];
bool gecildi[100]={0};
int parent[100];


void init(){
	for(int i=0;i<V;i++){
		parent[i]=i;
		sure[i]=INF;
	}
	sure[uni]=0;
}


int getEnKisa(){
	int enKucuk=999;
	int enKucukNokta=0;
	for(int i=0;i<V;i++){
		if(!gecildi[i] && sure[i]<enKucuk){//geçilmeyen en küçüğü aldığı için dijkstranın diğer adımlarında hep aynı noktadan başlamıyor
			enKucuk=sure[i];
			enKucukNokta=i;
		}
	}
	return enKucukNokta;
}

void dijkstra(){
	for (int i=0;i<V;i++){//her döndüğünde geçilmeyen diğer noktaları alır ve tüm çizgenin algoritması ortaya çıkar...
		int enkisa= getEnKisa();
		gecildi[enkisa]=1;
		
		for(int adj=0;adj<V;adj++){
			if(zamanlar[enkisa][adj]!=INF && 
			sure[adj]>sure[enkisa]+zamanlar[enkisa][adj]){
		
			sure[adj]=sure[enkisa]+zamanlar[enkisa][adj];
			parent[adj]=enkisa;
			}
		}
	}
}


void ekranaYaz(){
	cout<<"Nokta:\t\t\tSure(dk)\t\t\tYol\t\t\t\n";
	for(int i=0;i<V;i++){
		cout<<i+1<<"\t\t\t"<<sure[i]<<"\t\t\t"<<" ";
		
		cout<<i+1<<" ";
		
		int parnode=parent[i];
		
		while(parnode!=uni){
			cout<<" --> "<<parnode+1<<" ";
			parnode=parent[parnode];
		}
		cout<<"-->"<<uni+1<<endl;
	}
}

int main() {
V=8;
	cout<<"1-Ev\n2-Kadikoy\n3-Uskudar\n4-Cengelkoy\n5-Bulgurlu\n6-Umraniye\n7-Ihlamurkuyu\n8-Universite\n\n";

	cout<<"Mesafeleri Giriniz: "<<endl;
	
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cin>>zamanlar[i][j];
		}
	}
	cout<<"\n\n1-Ev\n2-Kadikoy\n3-Uskudar\n4-Cengelkoy\n5-Bulgurlu\n6-Umraniye\n7-Ihlamurkuyu\n8-Universite\n";

	cout<<"Gitmek istediginiz yeri seciniz: ";
	cin>>uni;
	uni-=1;
	init();
	dijkstra();
	ekranaYaz();
	return 0;
}


/* 
0 54 36 27 19 24 999 999 
54 0 62 999 999 999 999 74
36 62 0 47 16 999 999 51
27 999 47 0 999 999 999 37
19 999 16 999 0 33 999 38
24 999 999 999 33 0 28 38
999 999 999 999 999 28 0 40
999 74 51 37 38 38 40 0 

*/




#include <bits/stdc++.h>
using namespace std;
class Library{
public:
    long long int no_of_books;
    long long int signup_time;
    long long int shipment; //shipment in a day
    vector<long int> typesofbooks;
};
int main() {
    fstream myfile("f_libraries_of_the_world.txt", std::ios_base::in);
    long long int books,libraries,scanning_days;
    myfile>>books>>libraries>>scanning_days;
    vector<int> book;
    int w;
    for(int i=0;i<books;i++){
        myfile>>w;
        book.push_back(w);
    }
    Library library[libraries];
    for(int i=0;i<libraries;i++){
        long int x,y,z,q;
        myfile>>x>>y>>z;
        library[i].no_of_books=x;
        library[i].signup_time=y;
        library[i].shipment=z;
        for(int j=0;j<library[i].no_of_books;j++){
            myfile>>q;
            // myfile>>library[i].typesofbooks[j];
            library[i].typesofbooks.push_back(q);
        }
    }
    long long int ans=0,days=scanning_days;
    long int i=0;
    while(days-library[i].signup_time>0){
        ans++;
        days-=library[i].signup_time;
        i++;
    }
    fstream outfile;
    outfile.open("output_F.txt");
    outfile<<ans<<endl;
    for(int i=0;i<ans;i++){
        outfile<<i<<" ";
        scanning_days-=library[i].signup_time;
        long long int y=scanning_days*library[i].shipment;
        if(y>library[i].no_of_books){
            outfile<<library[i].no_of_books<<endl;
            for(int j=0;j<library[i].no_of_books;j++){                // if(visited[library[i].typesofbooks[j]]){
                outfile<<library[i].typesofbooks[j]<<" ";
            }
        }
        else{
            outfile<<y<<endl;
            for(int j=0;j<y;j++){
                outfile<<library[i].typesofbooks[j]<<" ";
            }
        }
        outfile<<endl;   
    }

}

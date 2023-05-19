#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<sstream>

using namespace std;

const int MAX=52;
class Random
{
    //String randomizer
    public:
        string string_gen(int size)
        {
            char alphabet[MAX]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            string res=" ";
            for(int i=0;i<size;i++)
            {
                res=res+alphabet[rand()% MAX];
            }
            return res;
        }   
    
    public:
        vector<int> random_num(int size)
        {
            int number[]={0,1,2,3,4,5,6,7,8,9};
            vector<int> res(size);
            for(int i=0;i<size;i++)
            {
                res[i]=number[rand()%10];
            }
            return res;
        }

        vector<int> print_num(vector<int>&rand,int size){
            for(int j=0;j<size;j++){
                cout<<rand[j]<<" ";
            }
            return rand;
        }
    
    public:
        string sp_char_gen(int size){
            char sp_char[]={'@','#','$','^','&','*','!','~','/','*','-'};
            int iter_size=sizeof(sp_char)/sizeof(sp_char[0]);
            string res=" ";
            for(int k=0;k<size;k++){
                res=res+sp_char[rand()%iter_size];
            }
            return res;
        }
    
    public:
        string convert_to_string(vector<int>&rand,int size){
            stringstream st;
            for(int i=0;i<rand.size();i++){
                st<<rand[i];
            }
            return st.str();
        }
    
    public:
        string final_conv(string str1, string str2, string str3, int size){
            string res=str1+str2+str3;
            string final_str=" ";
            for(int i=0;i<size;i++)
            {
                final_str=final_str+res[rand()%(size*3)];
            }
            return final_str;
        }
};

int main(){
    srand(time(NULL));
    string str1,str2,str3;
    Random r;
    int size;
    char c;
    
    cout<<"Enter the size of the password: "<<endl;
    cin>>size;
    vector<int> randomNumbers=r.random_num(size);
    
    cout<<"Would you like to have special charcters in your password?:(y/n)"<<endl;
    cin>>c;
    if(c=='y')
    {
        //Password generator should have- string, number, special characters
        // Random string genertor
        // Number generator- string convert
        // Random charcters generator- string convert
        // Finally I would place them in any particular order
        str1=r.string_gen(size);
        cout<<"The Random String is: "<<str1<<endl;
        
        cout<<"Random numbers are: ";
        r.print_num(randomNumbers,size);
        cout<<endl;
        str2=r.convert_to_string(randomNumbers,size);
        cout<<str2<<endl;

        str3=r.sp_char_gen(size);
        cout<<"Random charcters are: "<<str3<<endl;

        cout<<"The password generated is: "<<r.final_conv(str1,str2,str3,size);
    }
    return 0;
}
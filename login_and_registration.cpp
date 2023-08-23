#include<iostream>
#include<fstream>
using namespace std;

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    string usercmd;     //what the user wants to do
    string username, password, q1, q2, q3;     //values and questions found in the file
    string input_name, input_password, input_q1, input_q2, input_q3;    //what the user gives in as input
    string reg_name, reg_password, reg_q1, reg_q2, reg_q3;  //what the user is giving as input while registering
    // int checker = 0;

    //displaying the front page and displaying the options available
    while(1){

        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Welcome to the C++ login and registration page"<<endl;
        cout<<"Pick any one of the following options: "<<endl;
        cout<<"1. LOGIN"<<endl;
        cout<<"2. REGISTER"<<endl;
        cout<<"3. FORGOT PASSWORD"<<endl;
        cout<<"4. EXIT"<<endl;

        cin>>usercmd;

        //if user decides to exit the page
        if(usercmd == "4"){
            return 0;
        }

        //if user decides to register
        if(usercmd == "2"){
            //first we open/create a file for registration, we name it reg.txt
            ofstream a("reg.txt");
            //we use ofstream for getting stored data from reg.txt and it should be inside the same file as of .exe file

            //if the file does not open, then it is not present in the folder
            if(!a.is_open()){
                cout<<"could not open the file"<<endl;
                return 0;
            } 

            //entering the desired data and storing them into the variables we created
            cout<<"Enter the Username: ";
            cin>>reg_name;
            cout<<"Enter the password: ";
            cin>>reg_password;
            cout<<"For security reasons, we have to ask you to enter the answer to the following: "<<endl;
            cout<<"Enter your favorite color: ";
            cin>>reg_q1;
            cout<<"Enter your name: ";
            cin>>reg_q2;
            cout<<"Enter your birthday: ";
            cin>>reg_q3;

            //Storing the registered data into the file we created
            a<<reg_name;
            a<<'\n';
            a<<reg_password;
            a<<'\n';
            a<<reg_q1;
            a<<'\n';
            a<<reg_q2;
            a<<'\n';
            a<<reg_q3;
            a<<'\n';

            //closing the file to avoid any wastage of memory and unwanted data
            a.close();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"The registration is successful!"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            return 0;
            // checker++;
        }

        //if user decides to login
        if(usercmd == "1"){
            //open the file reg.txt
            ifstream b("reg.txt");
            if(!b.is_open()){
                cout<<"The file cannot be opened"<<endl;
                return 0;
                //this means that there is no file of the above name inside the folder containing the .exe file
            }
            getline(b,username,'\n');   //'\n' ensures that we only take one line atmax as the input and dont take other strings at other lines as the input
            getline(b,password,'\n');
            b.close();  //ofc, closing the file to avoid any unnecessary value addition

            //comparing the values founf in the file to the values entered by the user
            while(1){
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"Enter your username here: ";
                cin>>input_name;
                cout<<"Enter your password here: ";
                cin>>input_password;
                cout<<endl;
                cout<<endl;
                cout<<endl;

                if(input_name == username && input_password == password){
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"Logged in successfully!"<<endl;
                    cout<<"Welcome "<<username<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    // checker++;
                    break;
                }
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout<<"something went wrong"<<endl;
                cout<<"please check your login credentials and try again"<<endl;
                cout<<"Try the forgot password option if required"<<endl;
                cout<<endl;
                cout<<endl;
                cout<<endl;
                // checker++;
                main();
            }
            return 0;
        }

        //if the user forgets password
        if(usercmd == "3"){
            //open the reg.txt file and read the inputs in the file
            ifstream c("reg.txt");
            //if the file is not created or is not in the same folder
            if(!c.is_open()){
                cout<<"cannot open the file"<<endl;
                return 0;
            }
            getline(c,username,'\n');
            getline(c,password,'\n');
            getline(c,q1,'\n');
            getline(c,q2,'\n');
            getline(c,q3,'\n');
            c.close();

            string str;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Forgot password?"<<endl;
            cout<<"Please enter your username here: ";
            cin>>input_name;
            cout<<endl;
            cout<<endl;
            cout<<endl;

            while(1){
                if(input_name!=username){
                    cout<<"This username does not exist"<<endl;
                    main();
                }
                else{
                    cout<<"To receive your password, answer the following questions correctly"<<endl;
                    cout<<"Enter your favorite color: ";
                    cin>>input_q1;
                    cout<<"Enter your name: ";
                    cin>>input_q2;
                    cout<<"Enter your birthday: ";
                    cin>>input_q3;

                    //comparing the entered values to the values inside the file
                    if(input_q1==q1 && input_q2==q2 && input_q3==q3){
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"We have confirmed your identity "<<username<<endl;
                        cout<<"This is your password: "<<password<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        return 0;
                    }
                    else{
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"The answers do not match the database"<<endl;
                        cout<<"Please try again"<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        main();
                    }
                }
            }
            return 0;
        }

    }

    return 0;
}

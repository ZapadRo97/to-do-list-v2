#include <iostream>
#include <fstream>
#include <string>
#include "item.h"
#include "list.h"
#include "listtemplate.h"
#include "error.h"

//TODO: Create ListTemplate and make ListText and ListReminder

using namespace std;

int main()
{
    //List OnlyList("List1", 10);
    //OnlyList.AddListItem(0, "Thing1");
    //OnlyList.AddListItem(1, "Thing2");
    //OnlyList.AddListItem(2, "Thing3");
    //OnlyList.DeleteListItem(0);
    //OnlyList.ToggleListItem(1);
    //OnlyList.DeleteList();
    //OnlyList.showItems();

    fstream todos;
    //Menu
    cout<<"Commands: \n1 - Create List \n2 - Add Item In List \n"
        "3 - Toggle Item Status \n4 - Delete Item From List \n5 - Show List \n"
        "6 - Delete List \n7 - Load List From File WIP \n8 - Save List To File WIP \n9 - EXIT";
    int choice;
    List OnlyList("###", 1);
    ListTemplate <ItemText> SecondList("###", 1);
    ListTemplate <ItemReminder> ThirdList("###", 1);
    int ThisNumberOfItems = 0;
    int index = 0;
    int lit_type = 0;
    cout<<endl;
    //TODO: FIX Delete and Toggle Completed on Reminder type
    while(1)
    {
        cin>>choice;
        if(choice == 1)
        {
            //TODO: Make NumberOfItems string and check for wrong inputs
            cout<<"Enter 0 for Mixed list, 1 for Text list, 2 for Reminder list: ";
            cin>>lit_type;
            if(lit_type == 0)
            {
                string ListName="";
                unsigned int NumberOfItems = 0;
                cout<<"Enter List Name: ";
                cin>>ListName;
                cout<<"Enter Max Number of Items: ";
                cin>>NumberOfItems;
                try{
                    if(ListName == "")
                    throw Error(2);
                    if(NumberOfItems == 0)
                    throw Error(3);
                    List TempList(ListName, NumberOfItems);
                    OnlyList = TempList;
                    ThisNumberOfItems = NumberOfItems;
                    index = 0;
                }
                catch(Error ex){
                    ex.Tratare();
                }
                /*if(ListName != "" && NumberOfItems != 0)
                {
                    List TempList(ListName, NumberOfItems);
                    OnlyList = TempList;
                    ThisNumberOfItems = NumberOfItems;
                    index = 0;
                }
                else
                {
                    cout<<"Invalid Input";
                }*/
            }
            else if(lit_type == 1)
            {
                string ListName="";
                unsigned int NumberOfItems = 0;
                cout<<"Enter List Name: ";
                cin>>ListName;
                cout<<"Enter Max Number of Items: ";
                cin>>NumberOfItems;

                if(ListName != "" && NumberOfItems != 0)
                {
                    ListTemplate <ItemText> TempList(ListName, NumberOfItems);
                    SecondList = TempList;
                    ThisNumberOfItems = NumberOfItems;
                    index = 0;
                }
                else
                {
                    cout<<"Invalid Input";
                }
            }
            else if(lit_type == 2)
            {
                string ListName="";
                unsigned int NumberOfItems = 0;
                cout<<"Enter List Name: ";
                cin>>ListName;
                cout<<"Enter Max Number of Items: ";
                cin>>NumberOfItems;
                if(ListName != "" && NumberOfItems != 0)
                {
                    ListTemplate <ItemReminder> TempList(ListName, NumberOfItems);
                    ThirdList = TempList;
                    ThisNumberOfItems = NumberOfItems;
                    index = 0;
                }
                else
                {
                    cout<<"Invalid Input";
                }
            }
            else
            {
                cout<<"Invalid Input"<<endl;
            }
        }
        else if(choice == 2)
        {
            if(lit_type == 0)
            {
                if(OnlyList.Exists())
                {
                    int another_choice;
                    string TextItem = "";
                    cout<<"Enter 0 for text item and 1 for reminder item: ";
                    cin>>another_choice;
                    cout<<"Enter todo: ";
                    cin.ignore();
                    getline(cin, TextItem);
                    if(TextItem != "")
                    {
                        if(another_choice == 0)
                            OnlyList.AddListItem(index, TextItem);
                        else
                        {
                            Date item_date;
                            int yet_another_choice;
                            cout<<"Enter 0 for today and 1 for another day: ";
                            cin>>yet_another_choice;
                            if(!yet_another_choice)
                            {
                                int hour, minute;
                                cout<<"Enter hour and minute separated by space: ";
                                cin>>hour>>minute;
                                item_date.SetDate(hour, minute);
                            }
                            else
                            {
                                int hour, minute;
                                cout<<"Enter hour and minute separated by space: ";
                                cin>>hour>>minute;
                                item_date.SetDate(hour, minute);
                                cout<<"Enter day, month, year separated by space: ";
                                int day, month, year;
                                cin>>day>>month>>year;
                                item_date.SetDate(day, month, year);
                            }

                            //cin>>item_date; //to overload >> for this to work
                            OnlyList.AddListItem(index, TextItem, item_date);
                        }
                        index++;
                    }
                    else
                    {
                        cout<<"Invalid Input";
                        cout<<endl;
                    }
                }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }


            }

            else if(lit_type == 1)
            {
                if(SecondList.Exists())
                {
                    //text
                    string TextItem = "";
                    cout<<"Enter todo: ";
                    cin.ignore();
                    getline(cin, TextItem);
                    if(TextItem != ""){
                        SecondList.AddListItem(index, TextItem);
                    }
                    else{
                        cout<<"Invalid Input";
                        cout<<endl;
                    }
                }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }

            else if(lit_type == 2)
            {
                if(ThirdList.Exists())
                {
                    //reminder
                    string TextItem = "";
                    cout<<"Enter todo: ";
                    cin.ignore();
                    getline(cin, TextItem);
                    if(TextItem != ""){
                        Date item_date;
                            int yet_another_choice;
                            cout<<"Enter 0 for today and 1 for another day: ";
                            cin>>yet_another_choice;
                            if(!yet_another_choice)
                            {
                                int hour, minute;
                                cout<<"Enter hour and minute separated by space: ";
                                cin>>hour>>minute;
                                item_date.SetDate(hour, minute);
                            }
                            else
                            {
                                int hour, minute;
                                cout<<"Enter hour and minute separated by space: ";
                                cin>>hour>>minute;
                                item_date.SetDate(hour, minute);
                                cout<<"Enter day, month, year separated by space: ";
                                int day, month, year;
                                cin>>day>>month>>year;
                                item_date.SetDate(day, month, year);
                            }

                            //cin>>item_date; //to overload >> for this to work
                            ThirdList.AddListItem(index, TextItem, item_date);
                    }
                    else{
                        cout<<"Invalid Input";
                        cout<<endl;
                    }
                }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }


        }
        else if(choice == 3)
        {
            if(lit_type == 0){
                if(OnlyList.Exists())
                    {//TODO: THAT 0 STANDS FOR TYPE
                    int position;
                    int another_choice;
                    cout<<"Enter 0 for text or 1 for reminder: ";
                    cin>>another_choice;
                    cout<<"Enter element position: ";
                    cin>>position;
                    OnlyList.ToggleListItem(position, another_choice);
                    }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }
            else if(lit_type == 1){
                if(SecondList.Exists()){
                    int position;
                    cout<<"Enter element position: ";
                    cin>>position;
                    SecondList.ToggleListItem(position);
                }
                else{
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }
            else if(lit_type == 2){
                if(ThirdList.Exists()){
                    int position;
                    cout<<"Enter element position: ";
                    cin>>position;
                    ThirdList.ToggleListItem(position);
                }
                else{
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }

        }
        else if(choice == 4)
        {
            if(lit_type == 0){
                if(OnlyList.Exists())
                { //TODO: THAT 0 STANDS FOR TYPE
                    int position;
                    int another_choice;
                    cout<<"Enter 0 for text or 1 for reminder: ";
                    cin>>another_choice;
                    cout<<"Enter element position: ";
                    cin>>position;
                    OnlyList.DeleteListItem(position, another_choice);
                }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }
            else if(lit_type == 1){
                if(SecondList.Exists()){
                    int position;
                    cout<<"Enter element position: ";
                    cin>>position;
                    SecondList.DeleteListItem(position);
                }
                else{
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }
            else if(lit_type == 2){
                if(ThirdList.Exists()){
                    int position;
                    cout<<"Enter element position: ";
                    cin>>position;
                    ThirdList.DeleteListItem(position);
                }
                else{
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }

        }
        else if(choice == 5)
        {
            if(lit_type == 0)
            {
                try{
                    if(!OnlyList.Exists())
                        throw Error(4);
                        OnlyList.showList();
                        cout<<endl;
                        OnlyList.showItems();
                }
                catch(Error ex){
                   ex.Tratare();
                }
                /*if(OnlyList.Exists())
                {
                    //show items
                    OnlyList.showList();
                    cout<<endl;
                    OnlyList.showItems();
                }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }*/
            }
            else if(lit_type == 1)
            {
                if(SecondList.Exists())
                {
                    //show items
                    SecondList.showList();
                    cout<<endl;
                    SecondList.showItems();
                }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }
            else if(lit_type == 2)
            {
                if(ThirdList.Exists())
                {
                    //show items
                    ThirdList.showList();
                    cout<<endl;
                    ThirdList.showItems();
                }
                else
                {
                    cout<<"You must create a list first";
                    cout<<endl;
                }
            }

        }
        else if(choice == 6)
        {
            if(lit_type == 0){
                if(OnlyList.Exists())
                {
                    string answer;
                    cout<<"The list will be lost forever (a very long time). Are you sure (Y/N)? ";
                    cin>>answer;
                    if(answer == "Y")
                        OnlyList.DeleteList();
                }
                else
                {
                    cout<<"You have nothing to delete";
                    cout<<endl;
                }
            }
            else if(lit_type == 1){
                if(SecondList.Exists()){
                    string answer;
                    cout<<"The list will be lost forever (a very long time). Are you sure (Y/N)? ";
                    cin>>answer;
                    if(answer == "Y")
                        SecondList.DeleteList();
                }
                else{
                    cout<<"You have nothing to delete";
                    cout<<endl;
                }
            }
            else if(lit_type == 2){
                if(ThirdList.Exists()){
                    string answer;
                    cout<<"The list will be lost forever (a very long time). Are you sure (Y/N)? ";
                    cin>>answer;
                    if(answer == "Y")
                        ThirdList.DeleteList();
                }
                else{
                    cout<<"You have nothing to delete";
                    cout<<endl;
                }
            }

        }
        else if(choice == 7)
        {
            //read
            //todos.open("todos.txt");
            //todos>>OnlyList;
            //
            //todos.close();
        }
        else if(choice == 8)
        {
            //write
            //if(OnlyList.Exists()){
            //    todos.open("todos.txt", std::ofstream::out | std::ofstream::trunc);
            //    todos<<OnlyList;
            //    todos.close();
            //}
            //else{
            //    cout<<"You have no list!";
            //    cout<<endl;
            //}

        }
        else if(choice == 9)
        {
            break;
        }
        else
        {
            cout<<"Wrong choice, try again. \n";
        }
    }



    //cout << "Hello world!" << endl;
    return 0;
}

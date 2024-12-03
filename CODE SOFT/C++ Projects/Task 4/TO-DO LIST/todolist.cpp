#include <bits/stdc++.h>
using namespace std ;
// Structure For our task
class Task
{
    public :
        string description ;
        bool completed ;
        Task(string des, bool com)
        {
            description = des ;
            completed = com ;
        }
} ;
// Structure for our Todolist
class ToDoList
{
    private :
        vector <Task> tasks ;
    public :
        void addTask(const string& description)
        {
            Task newTask(description, false) ;
            tasks.push_back(newTask) ;
            cout << "Task Added Successfully." << endl ;
        }
        void viewTask()
        {
            if(tasks.empty())
            {
                cout << "No Task in the list." << endl ;
            }
            else
            {
                cout << "To-Do LIST : " << endl ;
                for(int i = 0 ; i < tasks.size() ; i ++)
                {
                    cout << i+1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << endl ;
                }
            }
        }
        void marskTaskCompleted(int taskIndex)
        {
            if(tasks.empty())
            {
                cout << "No Task in the list." << endl ;
            }
            else if(taskIndex >= 1 and taskIndex <= tasks.size())
            {
                tasks[taskIndex - 1].completed = true ;
                cout << "Task Marked as Completed." << endl ;
            }
            else
            {
                cout << "Invalid Task Index. Please Enter a Valid task Index." << endl ;
            }
        }
        void removeTask(int taskIndex)
        {
            if(tasks.empty())
            {
                cout << "No Task in the list." << endl ;
            }
            else if(taskIndex >= 1 and taskIndex <= tasks.size())
            {
                tasks.erase(tasks.begin() + taskIndex-1) ;
                cout << "Task Removed Successfully." << endl ;
            }
            else
            {
                cout << "Invalid Task Index. Please Enter a Valid task Index." << endl ;
            }
        }
} ;
// Display
void displayMenu()
{
    cout << endl ;
    cout << "TO-DO LIST MANAGER" << endl ;
    cout << "1. Add Task" << endl ;
    cout << "2. Vies Tasks" << endl ;
    cout << "3. Mark Task as Completed" << endl ;
    cout << "4. Remove Task" << endl ;
    cout << "0. Quit" << endl ;
    cout << endl ;
}
// Main todolist fn
void TODOLIST()
{
    cout << "===========================    WELCOME    ===========================" << endl ;
    cout << "=========================        to          ========================" << endl ;
    cout << "===========================  TO DO LIST   ===========================" << endl ;
    ToDoList todolist ;
    int choice ;
    do
    {
        displayMenu() ;
        cout << "Enter Your Choice : " ;
        cin >> choice ;
        switch (choice)
        {
            case 1:
            {
                cout << "Enter Task Description : " ;
                cin.ignore() ;
                string description ;
                getline(cin, description) ;
                todolist.addTask(description) ;
            }
                break;
            case 2 :
            {
                todolist.viewTask() ;
            }
                break ;
            case 3 :
            {
                int taskIndex ;
                cout << "Enter the Index of the Task to Mark as Completed : " ;
                cin >> taskIndex ;
                todolist.marskTaskCompleted(taskIndex) ;
            }
                break ;
            case 4 :
            {
                int taskIndex ;
                cout << "Enter the Index of the Task to Remove : " ;
                cin >> taskIndex ;
                todolist.removeTask(taskIndex) ;
            }
                break ;
            case 0 :
            {
                cout << "Exiting the Program." << endl ;
            }
                break ; 
            
            default: 
            {
                cout << "Invalid Choice. Please Try Again." << endl ;
            }
                break;
        }
    } while (choice != 0);
    cout << endl << "=============================  END  =============================" << endl ;
}
// Main fn
int main ()
{
    TODOLIST() ;
    return 0 ;
}
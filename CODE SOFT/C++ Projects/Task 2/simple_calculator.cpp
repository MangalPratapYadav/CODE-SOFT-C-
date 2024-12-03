#include <bits/stdc++.h>
using namespace std;
void welcome() 
{
    cout << "=============================  WELCOME  =============================" << endl;
    cout << "===========================       to       ==========================" << endl;
    cout << "========================  SIMPLE CALCULATOR =========================" << endl;
    cout << endl;
}
void displayChoices() 
{
    cout << "Choices: " << endl;
    cout << "       Enter (+) to Add" << endl;
    cout << "       Enter (-) to Subtract" << endl;
    cout << "       Enter (*) to Multiply" << endl;
    cout << "       Enter (/) to Divide" << endl;
    cout << "       Enter (^) to Power" << endl;
    cout << "       Enter (%) to Modulo" << endl;
    cout << "       Enter (Q/q) to Exit." << endl;
    cout << endl;
}
bool isValidOperation(char operation) 
{
    return (operation == '+' || operation == '-' || operation == '*' || 
            operation == '/' || operation == '^' || operation == '%' ||
            operation == 'Q' || operation == 'q');
}
void simple_calculator() 
{
    welcome();
    char operation;
    do {
        float first_operand;
        float second_operand;
        cout << "Enter the First Operand: ";
        cin >> first_operand;

        displayChoices();
        cout << "You Chosen: ";
        cin >> operation;
        
        while (!isValidOperation(operation)) 
        {
            cout << "Please Choose a Valid Operator: ";
            cin >> operation;
        }

        if (operation == 'Q' || operation == 'q') 
        {
            break;
        }

        cout << "Enter the Second Operand: ";
        cin >> second_operand;

        float result = 0;
        switch (operation) 
        {
            case '+':
                result = first_operand + second_operand;
                cout << "Result = " << result << endl;
                break;
            case '-':
                result = first_operand - second_operand;
                cout << "Result = " << result << endl;
                break;
            case '*':
                result = first_operand * second_operand;
                cout << "Result = " << result << endl;
                break;
            case '/':
                if (second_operand == 0) 
                {
                    cout << "Math Error: Division by zero." << endl;
                } 
                else 
                {
                    result = first_operand / second_operand;
                    cout << "Result = " << result << endl;
                }
                break;
            case '^':
                result = pow(first_operand, second_operand);
                cout << "Result = " << result << endl;
                break;
            case '%':
                if ((int)second_operand == 0) 
                {
                    cout << "Math Error: Modulo by zero." << endl;
                } 
                else 
                {
                    result = (int)first_operand % (int)second_operand;
                    cout << "Result = " << result << endl;
                }
                break;
        }
    } while (operation != 'Q' && operation != 'q');
    cout << endl << "=============================  BYE  =============================" << endl;
}
int main() {
    simple_calculator();
    return 0;
}

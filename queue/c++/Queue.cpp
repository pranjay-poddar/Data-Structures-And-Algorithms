#include <iostream>
#include <climits>
#include <conio.h>

using namespace std;

class Queue
{
    private:
        int *ar, max, front, rear;
    public:
        Queue(int max)
        {
            this->max = max;
            front = rear = -1;
            ar = new int[max];
        }

        int push(int n)
        {
            if ( isFull() )return -1;
            ar[++rear] = n;
            return rear;
        }

        int Pushfront(int n)
        {
            if ( isFull() )return -1;
            for(int i = rear + 1; i > 0; i--)
            {
                ar[i] = ar[i - 1];
            }
            ar[0] = n;
            rear++;
            return 0;
        }

        int pop()
        {
            if ( isEmpty() )
            {
                reset();
                return -1;
            }
            int val = ar[++front];
            if ( isEmpty() )
            {
                reset();
            }
            for(int i = front; i < rear; i++)
            {
                ar[i] = ar[i + 1];
            }
            rear--;
            return val;
        }

        int PopBack()
        {
            if ( isEmpty() ) return -1;
            return ar[rear--];   
        }

        int display()
        {
            if ( isEmpty() ) return -1;
            for(int i = 0; i <= rear; i++)
            {
                cout << ar[i] << " ";
            }
            cout << endl;
            return 0;
        }

        void reset()
        {
            front = rear = -1;
        }

        int peak()
        {
            if ( isEmpty() )return INT_MIN;
            return ar[0];
        }

        int PeakBack()
        {
            if ( isEmpty() ) return INT_MIN;
            return ar[rear];
        }

        bool isEmpty()
        {
            return rear == - 1;
        }

        bool isFull()
        {
            return rear == max - 1;
        }

        int getsize()
        {
            if ( isEmpty() ) return -1;
            return rear - front;
        }
};

int main(void)
{
    system("cls");
    int limit, ch;
    cout << "Enter capacity of queue" << endl;
    cin >> limit;
    Queue queue(limit);
    cout << "Queue created...Press enter to continue..." << endl;
    getch();
    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "1\t-\tPush at last" << endl;
        cout << "2\t-\tPush at front" << endl;
        cout << "3\t-\tRemove from front" << endl;
        cout << "4\t-\tRemove from back" << endl;
        cout << "5\t-\tPeak from front" << endl;
        cout << "6\t-\tPeak from back" << endl;
        cout << "7\t-\tDisplay all elements" << endl;
        cout << "8\t-\tSize" << endl;
        cout << "9\t-\tExit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        system("cls");
        switch(ch)
        {
            case 1: 
            {
                if ( queue.isFull() )
                {
                    cout << "Queue is full" << endl;
                }
                else
                {
                    int n;
                    cout << "Enter a number to push: ";
                    cin >> n;
                    queue.push(n);
                }
                break;
            }
            case 2: 
            {
                if ( queue.isFull() )
                {
                    cout << "Queue is full" << endl;
                }
                else
                {
                    int n;
                    cout << "Enter a number to push: ";
                    cin >> n;
                    queue.push(n);
                }
                break;
            }
            case 3: 
            {
                int val = queue.pop();
                if ( val == -1 )
                {
                    cout << "Queue is empty" << endl;
                }
                else
                {
                    cout << "Value removed successfully" << endl;
                }
                break;
            }
            case 4: 
            {
                int val = queue.PopBack();
                if ( val == -1 )
                {
                    cout << "Queue is empty" << endl;
                }
                else
                {
                    cout << "Value removed successfully" << endl;
                }
                break;
            }
            case 5: 
            {
                int val = queue.peak();
                if ( val == INT_MIN )
                {
                    cout << "Queue is empty" << endl;
                }
                else
                {
                    cout << "Value at front = " << val << endl;
                }
                break;
            }
            case 6: 
            {
                int val = queue.PeakBack();
                if ( val == INT_MIN )
                {
                    cout << "Queue is empty" << endl;
                }
                else
                {
                    cout << "Value at front = " << val << endl;
                }
                break;
            }
            case 7: 
            {
                if ( queue.display() == -1 )
                {
                    cout << "Queue is empty" << endl;
                }
                break;
            }
            case 8: 
            {
                int size = queue.getsize();
                if ( size == -1 )
                {
                    cout << "Queue is empty" << endl;
                }
                else
                {
                    cout << "Number of elements present = " << size << endl;
                }
                break;
            }
            case 9: 
            {
                cout << "Thank you for using this application..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice" << endl;
            }
        }
        if(ch != 9)
        {
            cout << "Press enter to continue..." << endl;
            getch();
        }
    }while(ch != 9 );
    return 0;
}

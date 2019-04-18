#include "Trapezium.cpp"

#include <iostream>

using namespace std;

int main() {
    int num = 0;
    cout << "num of figures" << endl;
    cin >> num;
    Trapezium *arr = new Trapezium [num];
    for (int i = 0; i < num; i++)
    {
        cout << "Input Side1" << endl;
        cin >> arr[i].Side1;
        cout << "Input Side2" << endl;
        cin >> arr[i].Side2;
        cout << "Input Base1" << endl;
        cin >> arr[i].Base1;
        cout << "Input Base2" << endl;
        cin >> arr[i].Base2;
    }
    while(true)
    {
        int variant = 0;
        cout << endl;
        cout << "0 Exit" << endl;
        cout << "1 Get Info" << endl;
        cout << "2 Resize" << endl;
        cout << "3 Compare" << endl;
        cout << "0 Exit" << endl;
        cin >> variant;
        switch(variant)
        {
            case 0: return 0;
            case 1:
                for(int i = 0; i < num; i++)
                    arr[i].GetInfo();
                break;
            case 2:
                cout << "Input num of figure" << endl;
                int a;
                cin >> a;
                cout << "Input coeficient" << endl;
                int b;
                cin >> b;
                arr[a].Resize(b);
                break;
            case 3:
                cout << "input 2 indexes to compare" << endl;
                int c = 0;
                int d = 0;
                cin >> c;
                cin >> d;
                cout << Trapezium::SimilarFigures(arr[a], arr[b]);
                break;
        }
    }
    delete[] arr;
}
